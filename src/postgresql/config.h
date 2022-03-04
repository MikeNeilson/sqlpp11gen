#pragma once
#include <string>
#include <memory>
#include <sqlpp11/postgresql/connection_config.h>

using db_config_ptr = std::shared_ptr<sqlpp::postgresql::connection_config>;

class Config {
    db_config_ptr db_config;
    std::string output_filename;
    std::string output_namespace;

    public:
        Config(int argc, char **argv);
        const db_config_ptr get_db_config() const;
        const std::string& get_filename() const;
        const std::string& get_namespace() const;

};