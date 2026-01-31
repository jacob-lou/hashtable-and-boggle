cmake_minimum_required(VERSION 3.16)
project(cpp_hashtable_boggle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- demos ----
add_executable(boggle_demo boggle-driver.cpp boggle.cpp)
target_include_directories(boggle_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# ---- GoogleTest ----
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_hw6
  tests/test_ht.cpp
  tests/test_boggle.cpp
  boggle.cpp
)
target_include_directories(test_hw6 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_hw6 PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_hw6)
