cmake_minimum_required(VERSION 3.31)
project(SolitarioInglese)

set(CMAKE_CXX_STANDARD 11)

add_executable(SolitarioInglese main.cpp
        scacchiera.h
        scacchiera.cpp
        mosse.h
        mosse.cpp
        partita.h
        partita.cpp
        risultati.h
        risultati.cpp)
