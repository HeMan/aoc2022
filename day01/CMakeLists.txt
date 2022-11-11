cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(day01)
target_add_binary_data(${PROJECT_NAME}.elf "input.txt" TEXT)
