#include <fstream>
#include <unordered_map>
#include "database_connector.h"
#include "logger.h"

database_connector::database_connector() : database_connector("db.conf"){}

database_connector::database_connector(std::filesystem::path config_file_path){
    std::ifstream ifs;
    ifs.open(config_file_path); 
    if (!ifs.is_open()) {
        logger::error("Could not open database config file");
        throw std::runtime_error{std::string{"Failed to open "} + config_file_path.c_str()};
    }

    std::unordered_map<std::string, std::string> map;
    for (std::string line; std::getline(ifs, line); ) {
        size_t pos = line.find('=');
        map.emplace(line.substr(0, pos), line.substr(pos + 1));
    }

    ifs.close();
 
    db_connection_ = std::make_unique<pqxx::connection>(fmt::format("postgresql://{}:{}@{}:{}/{}", 
                                                        map["dbuser"], 
                                                        map["dbpassword"], 
                                                        map["host"], 
                                                        map["port"], 
                                                        map["database"]));

    pqxx::work txn(*db_connection_);
    
}

