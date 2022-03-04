#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/postgresql/connection.h>
#include "data_dictionary.h"
#include "config.h"

using namespace std;
int main( int argc, char *argv[] ){        
    Config config(argc,argv);

    cout << "Connecting to " << config.get_db_config() << endl;
    sqlpp::postgresql::connection db(config.get_db_config());
    

    return 0;
}