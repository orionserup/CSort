cmake_minimum_required(VERSION 3.1)

project(CSort)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

if(MSVC)
    set(CMAKE_C_FLAGS "/W4 /D_CRT_SECURE_NO_DEPRECATE")
    set(CMAKE_C_FLAGS_DEBUG "/DEBUG /Od /DDEBUG /D_DEBUG /DLOG")
    set(CMAKE_C_FLAGS_RELEASE "/Ox /GL /LTCG /DNDEBUG")
else()
    set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Wfloat-equal")
    set(CMAKE_C_FLAGS_DEBUG "-Og -g -DDEBUG -DLOG -DVLA")
    set(CMAKE_C_FLAGS_RELEASE "-Ofast -DNDEBUG -mtune=native -march=native")
    set(CMAKE_LINK_FLAGS_RELEASE "-flto")
endif()

file(GLOB SOURCES ../src/*.c)
file(MAKE_DIRECTORY ../data)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ../include)
set_target_properties(${PROJECT_NAME} PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY ../bin)

# ----------------------------- Documentation Generation ------------------------------ #

find_package(Doxygen REQUIRED dot)
option(BUILD_DOCUMENTATION "Build Documentation in PDF and HTML Format" ${DOXYGEN_FOUND})
if(BUILD_DOCUMENTATION)

    set(DOXYGEN_PROJECT_NAME "CSorts")
    set(DOXYGEN_PROJECT_NUMBER "1.02")
    set(DOXYGEN_PROJECT_BRIEF "Implementations of Popular Searching Algorithms in C")
    
    set(DOXYGEN_GENERATE_HTML True)
    set(DOXYGEN_GENERATE_LATEX True)

    file(MAKE_DIRECTORY ../docs)

    set(DOXYGEN_OUTPUT_DIRECTORY ../docs)
    
    doxygen_add_docs(docs
        ../include ../src
        COMMENT "Generates a Doxygen Generator File Generating Documentation for the source and Include Folders")

endif()

