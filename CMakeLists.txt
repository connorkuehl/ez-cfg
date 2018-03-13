cmake_minimum_required(VERSION 3.0)

project(cfg)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    main.cpp
    lexer.cpp
    grammar.cpp
    symbol.cpp
)

set(HEADERS
    lexer.h
    grammar.h
    symbol.h
)

add_executable(gencfg ${SOURCES} ${HEADERS})
