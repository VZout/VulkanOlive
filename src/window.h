#ifndef WINDOW_H
#define WINDOW_H

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include <string>

class WindowHelper {
private:
    static void CallWindowHints();
public:
    static void InitGLFW();
    static GLFWwindow* CreateGLFWWindow(int width, int height, const char* title);
    static VkSurfaceKHR CreateSurface(VkInstance inst, GLFWwindow* window);
    static void StartLoop(GLFWwindow* window);
};

#endif
