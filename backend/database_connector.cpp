#include <iostream>
#include <fstream>
#include <unordered_map>
#include "database_connector.h"

database_connector::database_connector() : database_connector("db.conf"){}

database_connector::database_connector(std::filesystem::path config_file_path){
    std::ifstream ifs;
    ifs.open(config_file_path); 
    if (!ifs.is_open()) {
       throw std::runtime_error{std::string{"Failed to open "} + config_file_path.c_str()};
    }

    std::unordered_map<std::string, std::string> map;
    for (std::string line; std::getline(ifs, line); ) {
        size_t pos = line.find('=');
        map.emplace(line.substr(0, pos), line.substr(pos + 1));
    }

    ifs.close();
 
    std::cout << map["database"] << std::endl ;
}
