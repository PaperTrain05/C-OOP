cmake_minimum_required(VERSION 3.28)
project(Testing)

set(CMAKE_CXX_STANDARD 26)

add_executable(Testing it/mameli_alemanno/calendario/main.cpp
        it/mameli_alemanno/calendario/api/Evento.cpp
        it/mameli_alemanno/calendario/libs/Evento.h
        it/mameli_alemanno/calendario/api/Giorno.cpp
        it/mameli_alemanno/calendario/libs/Giorno.h
        it/mameli_alemanno/calendario/libs/Giorno.h
        it/mameli_alemanno/calendario/manager/Calendario.cpp
        it/mameli_alemanno/calendario/libs/Calendario.h
        it/mameli_alemanno/calendario/libs/Calendario.h)
