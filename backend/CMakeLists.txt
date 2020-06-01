cmake_minimum_required(VERSION 3.11)
project(Cacaplash)

file(GLOB All_files
    "*.h"
    "*.cpp"
)
add_executable(Cacaplash ${All_files})
target_include_directories(Cacaplash PUBLIC modules/spdlog/include)
target_link_libraries(Cacaplash stdc++fs)
target_compile_features(Cacaplash PUBLIC cxx_std_17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")
set(PQXX /usr/include/pqxx)
find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)