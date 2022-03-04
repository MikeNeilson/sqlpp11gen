#include "config.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sqlpp11/postgresql/connection_config.h>
#include <optionparser.h>

using namespace std;

struct Arg : public option::Arg {
  static option::ArgStatus Required(const option::Option& option, bool msg)
  {
    if (option.arg != 0)
      return option::ARG_OK;
    if (msg) cerr << "Option '" << option << "' requires an argument" << endl;
    return option::ARG_ILLEGAL;
  }
};

enum optionIndex {UNKNOWN, HELP, HOST, PORT, USERNAME, PASSWORD, DBNAME, NAMESPACE, OUTPUT};
const option::Descriptor usage[] = {
    { UNKNOWN,    0,"", "",          option::Arg::None,    "USAGE: example_arg [options]\n\n"
                                                            "Options:" },
    { HELP,       0,"", "help",      Arg::Required,     "  \t-h,--help  \tPrint usage and exit." },
    { HOST,       0,"h","host",      Arg::Required, "  \t-h,--host=hostname  \thostname of postgres server. Defaults to localhost"},
    { PORT,       0,"p","port",      Arg::Required, "  \t-p <port>,--port=<port>  \tenvironment variable prefix. defaults to 5432"},
    { USERNAME,   0,"u","user",      Arg::Required,         "  \t-u <username>,--user=<username>  \tusername for Postgres server"},
    { PASSWORD,   0,"a","password",  Arg::Required,         "  \t-a <password>,--password=<password>  \tpassword for the user"},
    { DBNAME,     0,"d","database",  Arg::Required,         "  \t-d <databasename>,--database=<databasename>  \tdatabasename"},
    { NAMESPACE,  0,"n","namespace", Arg::Optional, "  \t-n,--namespace=  \tnamespace to prefix with. defaults to database name in lowercase."},
    { OUTPUT,     0,"o","output",    Arg::Optional, "  \t-o,--output=  \tname of file to output to. Defaults to <database name in lowercase>.h"},
    { 0, 0, 0, 0, 0, 0 }
};

inline string tolower(string in){
    transform(in.begin(),in.end(),in.begin(),[](char c){ return std::tolower(c);});
    return in;
}

inline string trim( string in ) {  
    auto ltrim = in.find_first_not_of(" \n\r\t");
    if( ltrim != string::npos ){
        in = in.substr(ltrim);
    }
    auto rtrim = in.find_last_not_of(" \n\r\t");
    if( rtrim != string::npos ){
        in = in.substr(0,rtrim+1);
    }
    
    return in;
}

Config::Config(int argc, char **argv) {
    argc -= (argc>0);
    argv += (argv>0);
    option::Stats stats(usage, argc,argv);    
    option::Option options[stats.options_max], buffer[stats.buffer_max];
    option::Parser parser(usage,argc,argv,options,buffer);

    if( parser.error() ) {
        throw runtime_error("Bad parameters");
    }

    if( options[HELP].count() > 0 ){
        cout << "Help called." << endl;
        exit(0);
    }

    db_config = std::make_shared<sqlpp::postgresql::connection_config>();    
    db_config->application_name="SqlppCodeGen";    
    db_config->user = trim(options[USERNAME].arg);
    db_config->password = trim(options[PASSWORD].arg);
    db_config->dbname = trim(options[DBNAME].arg);
    db_config->host = "localhost";    
    db_config->port = 5432;    
    
    if( options[HOST]){
        db_config->host = string(options[HOST].arg);
    }
    
    if( options[PORT]){
        db_config->port=atoi(options[PORT].arg);
    } 

    this->output_namespace = trim(tolower(options[DBNAME].arg));
    this->output_filename = trim(tolower(options[DBNAME].arg) + ".h");
}
    
const db_config_ptr Config::get_db_config() const{
    return this->db_config;
}
        
const std::string& Config::get_filename() const{
    return this->output_filename;
}
        
const std::string& Config::get_namespace() const{
    return this->output_namespace;
}