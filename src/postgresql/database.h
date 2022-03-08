#pragma once
#include <vector>
#include <fstream>
#include "data_dictionary.h"
#include <sqlpp11/postgresql/connection.h>
#include <mustache.hpp>

namespace pg {
    namespace generator {        

        class database{
            std::string catalog;
            sqlpp::postgresql::connection &db;            
            std::vector<std::string> schemas;
            std::vector<std::string> namespaces;

            std::vector<kainjow::mustache::data> outputViews;


            public:
                database(sqlpp::postgresql::connection &db, const std::string &catalog, const std::string &desired_namespace);
                void generate();
                void gather_view_info( const std::string &schema );

                void render(std::ofstream& out);
        };
    }
}