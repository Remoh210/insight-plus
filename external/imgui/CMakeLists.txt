cmake_minimum_required(VERSION 3.1)
project(imgui)

# Core ImGui files
set(IMGUI_SRC
    imgui.cpp
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
)

# Always define IMGUI_BACKENDS as an empty list first
set(IMGUI_BACKENDS)

if (INS_BUILD_EXAMPLES)
    list(APPEND IMGUI_BACKENDS
        backends/imgui_impl_glfw.cpp
        backends/imgui_impl_opengl3.cpp
    )
endif()

set(IMGUI_BACKENDS
    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_opengl3.cpp
)

add_library(imgui STATIC
    ${IMGUI_SRC}
    ${IMGUI_BACKENDS}
)

if (INS_BUILD_EXAMPLES)
    target_link_libraries(imgui PRIVATE glad)
    target_link_libraries(imgui PRIVATE glfw)
endif()

target_include_directories(imgui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/backends
)