cmake_minimum_required(VERSION 3.29)
project(upparsing)

set(CMAKE_CXX_STANDARD 20)

add_executable(upparsing main.cpp
        cmd.cpp
        cmd.h
        cible.cpp
        cible.h
        Parser.cpp
        Parser.h
        Help.h
        Help.cpp
        Prout.h
        Prout.cpp
)
