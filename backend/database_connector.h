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

        template <typename... Ts>
        auto query(std::string_view query_str) {
            logger::info("query: " + query_str);
            pqxx::work w{*db_connection_};
            logger::info("worker time");
            return w.stream<Ts...>(query_str);
        }

        //for (const auto& val : db.query<int, std::string>("SELECT blabal")) {
            //do things
        //}
};