# Disable unnecessary GLFW options and hide them from CMake GUI
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL " " FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL " " FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL " " FORCE)
set(GLFW_INSTALL OFF CACHE BOOL " " FORCE)
set(GLFW_VULKAN_STATIC OFF CACHE BOOL " " FORCE)

mark_as_advanced(GLFW_BUILD_DOCS GLFW_BUILD_TESTS GLFW_BUILD_EXAMPLES GLFW_INSTALL)

add_subdirectory(imgui)
add_subdirectory(glfw EXCLUDE_FROM_ALL)
add_subdirectory(glad)

#Grouping
set_target_properties(glad PROPERTIES FOLDER external/glad)
set_target_properties(glfw PROPERTIES FOLDER external/glfw)
set_target_properties(imgui PROPERTIES FOLDER external/imgui)




