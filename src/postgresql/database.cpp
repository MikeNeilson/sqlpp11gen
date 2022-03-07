#include "database.h"
#include <iostream>
#include <sqlpp11/sqlpp11.h>
#include <string>

using namespace std;
using namespace sqlpp;
auto &views = pg::information_schema::views;
auto &columns = pg::information_schema::columns;
auto &schemata = pg::information_schema::schemata;
namespace pg {
    namespace generator {
        database::database(sqlpp::postgresql::connection &db, const std::string& catalog) : db(db), catalog(catalog) {
            for( auto &schema: db(select(all_of(schemata))
                         .from(schemata)
                         .where(schemata.schema_name.not_in("pg_catalog","public","information_schema")
                        ))) {
                    cout << "Checking " << schema.schema_name << endl;
                    schemas.push_back(schema.schema_name);
                    
                }    
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
                    for( auto &res_columns: db(select(all_of(columns))
                                                .from(columns)
                                                .where( columns.table_name == result.table_name))) {
                        cout << "\t" << res_columns.column_name << ":" << res_columns.data_type << ":" << res_columns.is_nullable << endl;
                    }        
                }
        }


        void database::render(ofstream &out) {

        }
    }
}