#include <filesystem>
#include <string>
#include <vector>
#include <pqxx/pqxx>

class database_connector {
    private:
        int a;
        //pqxx::connection C;

    public:
        database_connector();
        explicit database_connector(std::filesystem::path config_file);
        bool insert_values(std::string_view table, std::vector<std::string_view> values);
};