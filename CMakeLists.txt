cmake_minimum_required(VERSION "3.12.1")

project(Antra_uzduotis)

add_executable(Antra_uzduotis main.cpp Asmuo.cpp Studentas.cpp pagalb_funkcijos.cpp vart_ived.cpp Asmuo.h Studentas.h pagalb_funkcijos.h vart_ivedimas.h)

install(TARGETS Antra_uzduotis DESTINATION bin)