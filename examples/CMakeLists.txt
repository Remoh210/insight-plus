add_subdirectory(external)
add_subdirectory(opengl)

#Grouping
set_target_properties(opengl_example PROPERTIES FOLDER examples/opengl)