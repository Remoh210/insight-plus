#pragma once

#include "glfwDraw.h"

// Third party headers 
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace insight_plus
{
    void GlfwDrawStrategy::Setup()
    {
        const char* glsl_version = "#version 130";

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
    }

    void GlfwDrawStrategy::Draw()
    {
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
    }
    void GlfwDrawStrategy::Render()
    {
        // Platform specific rendering
    }
    GlfwDrawStrategy::~GlfwDrawStrategy()
    {
        //Cleanup
        //ImGui_ImplOpenGL3_Shutdown();
        //ImGui_ImplGlfw_Shutdown();
        //ImGui::DestroyContext();
    }
}