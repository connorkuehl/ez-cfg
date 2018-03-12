cmake_minimum_required(VERSION 3.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cfg)
set(CMAKE_CXX_STANDARD 14)

set(SOURCES
    main.cpp
)

set(HEADERS

)

add_executable(gencfg ${SOURCES} ${HEADERS})
