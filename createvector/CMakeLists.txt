cmake_minimum_required(VERSION 3.16)

project(CreateVector)

add_executable(${PROJECT_NAME}
	main.cpp
)
set_property(TARGET ${PROJECT_NAME}  PROPERTY CXX_STANDARD 20)

