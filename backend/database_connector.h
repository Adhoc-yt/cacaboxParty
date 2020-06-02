#include <filesystem>
#include <memory>
#include <string>
#include <vector>
#include <pqxx/pqxx>

class database_connector {
    private:
        std::unique_ptr<pqxx::connection> db_connection_;

    public:
        std::vector<std::vector<std::string>> db_query(std::string_view query);
        database_connector();
        explicit database_connector(std::filesystem::path config_file);
        bool insert_values(std::string_view table, std::vector<std::string_view> values);
};