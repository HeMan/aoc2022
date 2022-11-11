idf_component_register(SRCS "getinput.cpp"
                       EMBED_TXTFILES "input.txt"
                       INCLUDE_DIRS ".")
idf_component_set_property(${COMPONENT_NAME} PROPERTY CXX_STANDARD 20)
target_add_binary_data(${COMPONENT_TARGET} "input.txt" TEXT)
