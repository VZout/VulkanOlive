#define GLFW_INCLUDE_VULKAN

#include <windows.h>
#include <iostream>
#include <vulkan/vulkan.h>

#include "vkhelper.h"
#include "window.h"

int main() {

	const char* extensionNames[] = { "VK_KHR_surface", "VK_KHR_win32_surface" };

	VkInstance inst = VkHelper::CreateVkInstance(extensionNames);

	VkPhysicalDevice phys[4]; uint32_t physCount = 4;
	vkEnumeratePhysicalDevices(inst, &physCount, phys);
	VkHelper::LogVkPhysicalDeviceInfo(phys[0]);

	VkDevice dev = VkHelper::CreateVkDevice(phys[0], extensionNames);

	WindowHelper::InitGLFW();
	GLFWwindow* window = WindowHelper::CreateGLFWWindow(400, 320, "Vulkan Learning");
	VkSurfaceKHR surf = WindowHelper::CreateSurface(inst, window);

	WindowHelper::StartLoop(window);

	return 0;
}
