project(opengl_example)

# Add header files
file(GLOB_RECURSE HEADER_FILES 
  ${CMAKE_SOURCE_DIR}/*.h)
  
# Add source files
file(GLOB_RECURSE GL_EXAMPLE_SOURCE_FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Define the executable
add_executable(${PROJECT_NAME} ${GL_EXAMPLE_SOURCE_FILES})

# Make sure opengl_example depends on insight_plus
add_dependencies(opengl_example insight_plus)

target_link_libraries(opengl_example PRIVATE insight_plus)
target_link_libraries(opengl_example PRIVATE glfw)
target_link_libraries(opengl_example PRIVATE glad)
