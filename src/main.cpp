#define GLFW_INCLUDE_VULKAN

#include <vulkan/vulkan.h>

#include "vkhelper.h"
#include "window.h"

int main() {

	WindowHelper::InitGLFW();

	int count;
	const char** extensions = glfwGetRequiredInstanceExtensions(&count);

	PFN_vkCreateInstance pfnCreateInstance = (PFN_vkCreateInstance)
    glfwGetInstanceProcAddress(NULL, "vkCreateInstance");

	VkInstance inst = VkHelper::CreateVkInstance(extensions);

	PFN_vkCreateDevice pfnCreateDevice = (PFN_vkCreateDevice)
    glfwGetInstanceProcAddress(inst, "vkCreateDevice");

	PFN_vkGetDeviceProcAddr pfnGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)
    glfwGetInstanceProcAddress(inst, "vkGetDeviceProcAddr");

	VkPhysicalDevice phys[4]; uint32_t physCount = 4;
	vkEnumeratePhysicalDevices(inst, &physCount, phys);
	VkHelper::LogVkPhysicalDeviceInfo(phys[0]);

	VkDevice dev = VkHelper::CreateVkDevice(phys[0], extensions);

	GLFWwindow* window = WindowHelper::CreateGLFWWindow(400, 320, "Vulkan Learning");
	VkSurfaceKHR surf = WindowHelper::CreateSurface(inst, window);


	WindowHelper::StartLoop(window);

	return 0;
}
