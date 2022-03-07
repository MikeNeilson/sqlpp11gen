#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/postgresql/connection.h>
#include "data_dictionary.h"
#include "config.h"
#include <mustache.hpp>

using namespace std;
using namespace sqlpp;
auto &views = pg::information_schema::views;
auto &columns = pg::information_schema::columns;
auto &schemata = pg::information_schema::schemata;
int main( int argc, char *argv[] ){        
    Config config(argc,argv);

    cout << "Connecting to " << config.get_db_config() << endl;
    sqlpp::postgresql::connection db(config.get_db_config());    


    for( auto &schemas: db(select(all_of(schemata))
                         .from(schemata)
                         .where(schemata.schema_name.not_in("pg_catalog","public","information_schema")
                        ))) {
        cout << "Checking " << schemas.schema_name << endl;
        for( auto &result: db(select(all_of(views))
                                    .from(views)
                                    .where( 
                                        views.table_catalog == schemas.schema_name))) {
            cout << result.table_schema << "." << result.table_name << endl;
            for( auto &res_columns: db(select(all_of(columns))
                                        .from(columns)
                                        .where( columns.table_name == result.table_name))) {
                cout << "\t" << res_columns.column_name << ":" << res_columns.data_type << ":" << res_columns.is_nullable << endl;
            }
    }    
    }
    

    kainjow::mustache::mustache tmp{"Hello {{thething}}"};
    cout << tmp.render({"thething", "Blurg"}) << endl;

    return 0;
}