#pragma once
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/table.h>

namespace pg {
    namespace information_schema {

        struct table_catalog {
            struct _alias_t {
                static constexpr const char _literal [] = "table_catalog";
                using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                template<typename T>
                struct _member_t {
                    T table_catalog;
                    T& operator()(){ return table_catalog; }
                    const T& operator()() const { return table_catalog;}
                };
            };
            using _traits = sqlpp::make_traits<sqlpp::varchar>;
        };

        struct table_schema {
            struct _alias_t {
                static constexpr const char _literal [] = "table_schema";
                using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                template<typename T>
                struct _member_t {
                    T table_schema;
                    T& operator()(){ return table_schema; }
                    const T& operator()() const { return table_schema; }
                };

            };
            using _traits = sqlpp::make_traits<sqlpp::varchar>;
        };

        struct table_name {
            struct _alias_t {
                static constexpr const char _literal [] = "table_name";
                using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                template<typename T>
                struct _member_t {
                    T table_name;
                    T& operator()(){ return table_name; }
                    const T& operator()() const { return table_name; }
                };

            };
            using _traits = sqlpp::make_traits<sqlpp::varchar>;
        };

        namespace views_ {

            struct ViewTable : public sqlpp::table_t<ViewTable,table_catalog,table_schema,table_name> {
                struct _alias_t {
                    static constexpr const char _literal [] = "information_schema.views";
                    using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                    template<typename T>
                    struct _member_t {
                        T viewTable;
                        T& operator()(){ return viewTable; }
                        const T& operator()() const { return viewTable; }
                    };
                };

            };

            
        }
        extern views_::ViewTable views;

        namespace columns_ {
            

            

            struct column_name {

            };

            struct is_nullable {

            };

            struct data_type {

            };


        }



    }
}