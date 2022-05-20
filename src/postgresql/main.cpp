#include <fstream>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/postgresql/connection.h>
#include "data_dictionary.h"
#include "config.h"
#include <mustache.hpp>
#include "database.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        Config config(argc, argv);
        auto conf = *config.get_db_config();
        auto connectionString = "postgres://" + conf.user + ":PASSWORD@" + conf.host + ":" + conf.port + "/" + conf.dbname;
        cout << "Connecting to" << connectionString << endl;

        sqlpp::postgresql::connection db(config.get_db_config());

        pg::generator::database generator(db,config.get_db_config()->dbname,config.get_namespace());
        generator.generate();
        ofstream output(config.get_filename());
        generator.render(output);

        kainjow::mustache::mustache tmp{"Hello {{thething}}"};
        cout << tmp.render({"thething", "Blurg"}) << endl;
        return 0;
    } catch( std::exception &err ){
        cerr << "Program run failed: " << err.what() << endl;
        return 1;
    }
}