#pragma once
#include <vector>
#include <fstream>
#include "data_dictionary.h"
#include <sqlpp11/postgresql/connection.h>

namespace pg {
    namespace generator {        

        class database{
            std::string catalog;
            sqlpp::postgresql::connection &db;            
            std::vector<std::string> schemas;


            public:
                database(sqlpp::postgresql::connection &db, const std::string &catalog);
                void generate();
                void gather_view_info( const std::string &schema );

                void render(std::ofstream& out);
        };
    }
}