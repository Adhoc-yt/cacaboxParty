cmake_minimum_required(VERSION 3.11)
project(Cacaplash)
link_directories('/usr/local/lib64')
include_directories('/usr/local/include')

file(GLOB All_files
    "*.h"
    "*.cpp"
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(PQXX /usr/local/include/pqxx)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

add_executable(Cacaplash ${All_files})

target_include_directories(Cacaplash PUBLIC modules/spdlog/include)
target_link_libraries(Cacaplash stdc++fs)
target_compile_features(Cacaplash PUBLIC cxx_std_17)
target_link_libraries(Cacaplash ${PQXX_LIB} ${PQ_LIB})
