#include "window.h"
#include <sstream>
#include <math.h>

void WindowHelper::InitGLFW() {
    if (!glfwInit()) {
        std::cerr << "Error Initializing GLFW" << std::endl;
        std::exit(0);
    }

    if (!glfwVulkanSupported()) {
        std::cerr << "Vulkan Is Not Supported" << std::endl;
        std::exit(0);
    }
}

void WindowHelper::CallWindowHints() {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // IMPORTANT
}

GLFWwindow* WindowHelper::CreateGLFWWindow(int width, int height, const char* title) {

    CallWindowHints();

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

    return window;
}

VkSurfaceKHR WindowHelper::CreateSurface(VkInstance inst, GLFWwindow* window) {
    VkSurfaceKHR surf;
    VkResult err = glfwCreateWindowSurface(inst, window, NULL, &surf);
    if (err) {
        std::cerr << "Surface Creation Failed" << std::endl;
    }

    return surf;
}

void WindowHelper::StartLoop(GLFWwindow* window) {

    float lastTime = 0;
    int frames = 0;

    while (!glfwWindowShouldClose(window)) {

        frames++;

        if (lastTime < (float)glfwGetTime() - 1.0f) {
            int value = frames;
            std::stringstream fps_str;
            fps_str << (value);

            std::string string = "Vulkan FPS: ";
            string += fps_str.str();

            glfwSetWindowTitle(window, string.c_str());

            std::cout << frames << std::endl;
            frames = 0;
            lastTime = glfwGetTime();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
