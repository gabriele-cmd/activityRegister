cmake_minimum_required(VERSION 3.25)
project(activityRegister)

#modifications to make
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.5.1\\mingw_64\\lib\\cmake\\Qt6")
set(Qt6_DIR "C:\\Qt\\6.5.1\\mingw_64\\lib\\cmake\\Qt6")
set(GTEST_DIR "C:\\Users\\chirl\\Documents\\CLion_Projects\\google-googletest\\googletest")#.
include_directories(${GTEST_DIR}/include ${GTEST_DIR})
set(TEST_SOURCE_FILES test/runAllTests.cpp test/TestActivity.cpp test/TestRegister.cpp)
link_directories(${GTEST_DIR}/src)

set(CMAKE_WIN32_EXECUTABLE ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(activityRegister
        main.cpp
        Activity.cpp Activity.h
        Register.cpp Register.h
        MainWindow.cpp MainWindow.h
        NewActivityWindow.cpp NewActivityWindow.h
        ListActivityWindow.cpp ListActivityWindow.h
        ${TEST_SOURCE_FILES}
        )

target_link_libraries(activityRegister PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        gtest
        gtest_main
        core
        )

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
            if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
                set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
            endif()
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "C:\\Qt\\6.5.1\\mingw_64\\bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()