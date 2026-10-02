cmake_minimum_required(VERSION 3.15)
project(hwy_thread_pool_test CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(hwy REQUIRED)
find_package(Threads REQUIRED)

add_executable(thread_pool_test thread_pool_test.cc)
target_link_libraries(thread_pool_test PRIVATE hwy::hwy_contrib hwy::hwy Threads::Threads)
