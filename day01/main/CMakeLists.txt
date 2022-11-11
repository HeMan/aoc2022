idf_component_register(SRCS "day01.cpp"
                       INCLUDE_DIRS "."
										   REQUIRES "getinput")
idf_component_set_property(${COMPONENT_NAME} PROPERTY CXX_STANDARD 20)
