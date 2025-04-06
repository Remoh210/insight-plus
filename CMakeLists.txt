cmake_minimum_required(VERSION 3.4)
project(insight_plus)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#--------------------------------------------------------------------
# Compiler settings
#--------------------------------------------------------------------
if(APPLE)
set(CMAKE_CXX_FLAGS "-std=c++14 -stdlib=libc++")
endif()

#--------------------------------------------------------------------
# Add options
#--------------------------------------------------------------------
option(INS_BUILD_EXAMPLES "Build shared libraries" ON)

# Add header files
file(GLOB_RECURSE HEADER_FILES 
  ${CMAKE_SOURCE_DIR}/src/*.h
  ${CMAKE_SOURCE_DIR}/src/*.hpp)
  
# Add source files
file(GLOB_RECURSE SOURCE_FILES 
  ${CMAKE_SOURCE_DIR}/src/*.c
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.fs
  ${CMAKE_SOURCE_DIR}/src/*.gs
  ${CMAKE_SOURCE_DIR}/src/*.vs)

#--------------------------------------------------------------------
# Add subdirectories
#--------------------------------------------------------------------
add_subdirectory(external)

if (INS_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

#--------------------------------------------------------------------
# Define the executables
#--------------------------------------------------------------------
add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})

#--------------------------------------------------------------------
# Link libraries and includes
#--------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/headers)

#--------------------------------------------------------------------
# Set the INTERFACE_INCLUDE_DIRECTORIES to virtualize the include path
#--------------------------------------------------------------------
set_target_properties(${PROJECT_NAME} PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/src/headers"
)

#--------------------------------------------------------------------
# Macro to preserve source files hierarchy in the IDE
#--------------------------------------------------------------------
macro(GroupSources curdir)
	file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)
	foreach(child ${children})
		if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
			GroupSources(${curdir}/${child})
		else()
			string(REPLACE "/" "\\" groupname ${curdir})
			string(REPLACE "src" "Sources" groupname ${groupname})
			source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
		endif()
	endforeach()
endmacro()

# Run macro
GroupSources(src)
