cmake_minimum_required(VERSION 3.20)
project(math_bench)

set(CMAKE_CXX_STANDARD 20)

add_executable(math_bench main.cpp)

Include(FetchContent)
FetchContent_Declare(
        nanobench
        GIT_REPOSITORY https://github.com/martinus/nanobench.git
        GIT_TAG v4.3.11 # or a later release
)
FetchContent_MakeAvailable(nanobench)
target_link_libraries(math_bench PRIVATE nanobench)
target_include_directories(math_bench PRIVATE gcem/include)