cmake_minimum_required(VERSION 3.11)
project(Cacaplash)

file(GLOB ALL_FILES
    "*.h"
    "*.cpp"
)

add_executable(Cacaplash ${ALL_FILES})

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq PATHS /usr/local/pgsql/lib)

target_include_directories(Cacaplash PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/modules/spdlog/include)
target_link_libraries(Cacaplash stdc++fs ${PQXX_LIB} ${PQ_LIB})

target_compile_features(Cacaplash PRIVATE cxx_std_17)
