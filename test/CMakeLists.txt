cmake_minimum_required(VERSION 3.25)
project(test)

#modifications to make
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.5.1\\mingw_64\\lib\\cmake\\Qt6")

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp TestActivity.cpp TestRegister.cpp)

add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests Qt6::Core Qt6::Gui Qt6::Widgets)
target_link_libraries(runAllTests gtest gtest_main core)