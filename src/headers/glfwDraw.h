#pragma once

#include "drawStrategy.h"

// Forward declarations
struct GLFWwindow;

namespace insight_plus
{
    class GlfwDrawStrategy : public iDrawStrategy
    {
    public:
        GlfwDrawStrategy(GLFWwindow* WindowIn)
            :window(WindowIn){}

        void Setup();
        void Draw();
        void Render();

        ~GlfwDrawStrategy();

    private:
        GLFWwindow* window;
    };
}