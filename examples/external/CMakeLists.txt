add_subdirectory(glfw)
add_subdirectory(glad)

#Grouping
set_target_properties(glad PROPERTIES FOLDER external/glad)
set_target_properties(glfw PROPERTIES FOLDER external/glfw)




