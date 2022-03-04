add_executable( sqlpp11pggen main.cpp config.cpp data_dictionary.cpp)
target_link_libraries(sqlpp11pggen 
                      sqlpp11::sqlpp11
                      sqlpp11::postgresql
                      OpenSSL::SSL
                      OpenSSL::Crypto               
                      pthread
)
