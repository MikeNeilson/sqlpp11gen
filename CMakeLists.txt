cmake_minimum_required(VERSION 3.0)
project(sqlpp11gen VERSION 1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".so" ".a")
set(BUILD_SHARED_LIBS on)
set(PostgreSQL_TYPE_INCLUDE_DIR "/usr/include/postgresql/")
find_package(OpenSSL REQUIRED)
add_subdirectory(src)
configure_file(src/postgresql/field.mustache field.mustache COPYONLY)
configure_file(src/postgresql/table.mustache tables.mustache COPYONLY)