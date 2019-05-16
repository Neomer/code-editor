cmake_minimum_required(VERSION 3.10)

set(DEPRECATE_OLDSTYLE_CAST_WARNING -Wno-old-style-cast)

project(code-editor CXX)

set(SOURCES MainWindow.cpp MainWindow.h
            CodeEditor.cpp CodeEditor.h
            cxx_reserved.h
            main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM3 REQUIRED gtkmm-3.0)

INCLUDE_DIRECTORIES(${GTKMM3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM3_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Link the target to the GTKMM libraries
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GTKMM3_LIBRARIES})
