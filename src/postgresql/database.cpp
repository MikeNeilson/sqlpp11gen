#include "database.h"
#include <iostream>
#include <sqlpp11/sqlpp11.h>
#include <string>
#include <sstream>
#include <map>
#include <mustache.hpp>

using namespace std;
using namespace sqlpp;
using namespace kainjow::mustache;
auto &views = pg::information_schema::views;
auto &columns = pg::information_schema::columns;
auto &schemata = pg::information_schema::schemata;

namespace pg {
    namespace generator {
        
        map<string,string> data_type_map{
            {"int","sqlpp::integral"},
            {"integer","sqlpp::integral"},
            {"bigint","sqlpp::integral"},
            {"float","sqlpp::floating_point"},
            {"double","sqlpp::floating_point"},
            {"double precision","sqlpp::floating_point"},
            {"text","sqlpp::text"},
            {"character varying","sqlpp::text"},
            {"character","sqlpp::text"},
            {"binary","sqlpp::text"},
            {"timestamp with time zone","sqlpp::time_point"},
            {"timestamp without time zone","sqlpp::time_point"},
            {"boolean","sqlpp::boolean"}
        };

        
        database::database(sqlpp::postgresql::connection &db, const string& catalog, const string &desired_namespace) : db(db), catalog(catalog) {
            for( auto &schema: db(select(all_of(schemata))
                         .from(schemata)
                         .where(schemata.schema_name.not_in("pg_catalog","public","information_schema")
                        ))) {
                    cout << "Checking " << schema.schema_name << endl;
                    schemas.push_back(schema.schema_name);                    
            }
            namespaces = split<string>(desired_namespace,':'); 
        }
        
        void database::generate() {
            
            for( auto &schema: this->schemas ) {
                gather_view_info(schema);
                // types?
                // tables
                // routines
            }       
        }

        void database::gather_view_info( const std::string &schema ) {
            
            
            for( auto &result: db(select(all_of(views))
                                                .from(views)
                                                .where( 
                                                    views.table_catalog == this->catalog
                                                    and
                                                    views.table_schema == schema
                                                    ))) {
                    cout << result.table_schema << "." << result.table_name << endl;
                    data view{data::type::object};
                    view["schema_name"] = result.table_catalog.text;
                    view["view_name"] = result.table_name.text;
                    data fields{data::type::list};
                    for( auto &res_columns: db(select(all_of(columns))
                                                .from(columns)
                                                .where( columns.table_name == result.table_name))) {
                        cout << "\t" << res_columns.column_name << ":" << res_columns.data_type << ":" << res_columns.is_nullable << endl;                        
                        data field{{data::type::object}};
                        field["name"] = res_columns.column_name.text;
                        field["traits"] = data_type_map[res_columns.data_type.text];
                                                
                        fields << field;
                        
                    }   
                    view.set("fields",fields);   
                    outputViews.push_back(view);
                }
        }


        void database::render(ofstream &out) {
            cout << "Information gathered, rending header file." << endl;
            stringstream file_data;
            ifstream file("field.mustache");
            file_data << file.rdbuf();            
            kainjow::mustache::mustache tmpl(file_data.str());
            if( !tmpl.is_valid() ) {
                cerr << tmpl.error_message() << endl;
            }

            tmpl.set_custom_escape([](const std::string &r){return r;});

            out << "#pragma once" << endl;
            out << "#include <sqlpp11/sqlpp11.h>" << endl << endl;
            for( auto &ns: namespaces ) {
                out << "namespace " << ns << " { ";
            }
            out << endl;
            out << "\t namespace views {" << endl;
            for(auto &view: outputViews){            
                tmpl.render(view,[&out](const string &rendered){                    
                    out << rendered;
                });
            }
            out << "\t }" << endl;

            out << "/* tables */" << endl;
            out << "/* routines */" << endl;

            for( auto &ns: namespaces ) {
                out << "} ";
            }
            out << endl << endl;
        }
    }
}