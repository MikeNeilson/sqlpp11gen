#include "data_dictionary.h"

namespace pg {
    namespace information_schema {
        schemata_::SchemataTable schemata;
        views_::ViewTable views;
        columns_::ColumnTable columns;
        tables_::TableTable tables;
    }
}