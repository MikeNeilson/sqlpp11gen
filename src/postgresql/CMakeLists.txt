add_executable( sqlpp11pggen main.cpp config.cpp data_dictionary.cpp database.cpp)
target_link_libraries(sqlpp11pggen 
                      sqlpp11::sqlpp11
                      sqlpp11::postgresql
                      OpenSSL::SSL
                      OpenSSL::Crypto               
                      pthread
)
file(COPY field.mustache DESTINATION ${CMAKE_BINARY_DIR}/)
