#pragma once
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/table.h>

namespace pg {
    namespace information_schema {

        struct catalog_name {
            struct _alias_t {
                static constexpr const char _literal [] = "catalog_name";
                using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                template<typename T>
                struct _member_t {
                    T catalog_name;
                    T& operator()(){ return catalog_name; }
                    const T& operator()() const { return catalog_name;}
                };
            };
            using _traits = sqlpp::make_traits<sqlpp::varchar>;
        };

        struct schema_name {
            struct _alias_t {
                static constexpr const char _literal [] = "schema_name";
                using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                template<typename T>
                struct _member_t {
                    T schema_name;
                    T& operator()(){ return schema_name; }
                    const T& operator()() const { return schema_name;}
                };
            };
            using _traits = sqlpp::make_traits<sqlpp::varchar>;
        };

        struct schema_owner {
            struct _alias_t {
                static constexpr const char _literal [] = "schema_owner";
                using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                template<typename T>
                struct _member_t {
                    T schema_owner;
                    T& operator()(){ return schema_owner; }
                    const T& operator()() const { return schema_owner;}
                };
            };
            using _traits = sqlpp::make_traits<sqlpp::varchar>;
        };

        namespace schemata_ {
            struct SchemataTable : public sqlpp::table_t<SchemataTable,catalog_name,schema_name,schema_owner> {
                struct _alias_t {
                    static constexpr const char _literal [] = "information_schema.schemata";
                    using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                    template<typename T>
                    struct _member_t {
                        T schemataTable;
                        T& operator()(){ return schemataTable; }
                        const T& operator()() const { return schemataTable; }
                    };
                };

            };

            
        }
        extern schemata_::SchemataTable schemata;

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
                struct _alias_t {
                    static constexpr const char _literal [] = "column_name";
                    using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                    template<typename T>
                    struct _member_t {
                        T column_name;
                        T& operator()(){ return column_name; }
                        const T& operator()() const { return column_name; }
                    };

                };
            using _traits = sqlpp::make_traits<sqlpp::varchar>;
            };

            struct is_nullable {
                struct _alias_t {
                    static constexpr const char _literal [] = "is_nullable";
                    using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                    template<typename T>
                    struct _member_t {
                        T is_nullable;
                        T& operator()(){ return is_nullable; }
                        const T& operator()() const { return is_nullable; }
                        
                    };
                };
                using _traits = sqlpp::make_traits<sqlpp::boolean>;
            };

            struct data_type {
                struct _alias_t {
                    static constexpr const char _literal [] = "data_type";
                    using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                    template<typename T>
                    struct _member_t {
                        T data_type;
                        T& operator()(){ return data_type; }
                        const T& operator()() const { return data_type; }
                    };
                };
                using _traits = sqlpp::make_traits<sqlpp::varchar>;
            };

            struct ColumnTable : public sqlpp::table_t<ColumnTable,table_catalog,table_schema,table_name,column_name,is_nullable,data_type> {
                struct _alias_t {
                    static constexpr const char _literal [] = "information_schema.columns";
                    using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                    template<typename T>
                    struct _member_t {
                        T columnTable;
                        T& operator()(){ return columnTable; }
                        const T& operator()() const { return columnTable; }
                    };
                };

            };

        }
        extern columns_::ColumnTable columns;

        struct table_type {
                struct _alias_t {
                    static constexpr const char _literal [] = "table_type";
                    using _name_t = sqlpp::make_char_sequence<sizeof(_literal),_literal>;
                    template<typename T>
                    struct _member_t {
                        T table_type;
                        T& operator()(){ return table_type; }
                        const T& operator()() const { return table_type; }
                    };
                };
                using _traits = sqlpp::make_traits<sqlpp::varchar>;
            };

        namespace tables_ {

            struct TableTable : public sqlpp::table_t<TableTable,table_catalog,table_schema,table_name,table_type> {
                struct _alias_t {
                    static constexpr const char _literal [] = "information_schema.tables";
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
        extern tables_::TableTable tables;


    }
}