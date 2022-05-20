# Purpose 

My database uses a lot of writable views and function to perform actions.
The generator provided by sqlpp11 only processed a text file and only tables at that.

I created this to save myself a rather large amount of typing.

It works by connecting to a running database with your schema and goes through the
postgres information tables to extract the columns and types for each object.

Currently only handles Postgres as that is the database I use

It of course depends on https://github.com/rbock/sqlpp11.
As well as https://github.com/kainjow/Mustache

Both of which should download automatically during the cmake build process.

# To build

```
git clone https://github.com/MikeNeilson/sqlpp11gen.git
cd sqlpp11gen
mkdir build
cd build
cmake ..
```

|option|default|description|
|------|--------|-----------|
|-h,--host=&lt;hostname&gt;|localhost|hostname of the postgres server|
|p,port=&lt;port&lt;|5432|port of the postgres server|
|-u,--user=&lt;username&gt;|*MUST* provide|User name to connect as. Should have same permission as clients that will connect|
|-a,--password=&lt;password&gt;|*MUST* provide|Password for the above user|
|-d,--database=&lt;database&gt;|*MUST* provide|Postgres Database name to connect to|
|-n,--namespace=&lt;namespace&gt;|defaults to lower case of database name|C++ namespace to output has. NOTE: nest with `:` instead of `::`|
|-o,--output=&lt;filename&gt;|&lt;defaults to lower case of database name&gt;.h|a file name. Location must be writable by user.|
    