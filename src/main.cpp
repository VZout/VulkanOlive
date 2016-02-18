#define GLFW_INCLUDE_VULKAN

#include <vulkan/vulkan.h>

#include "vkhelper.h"
#include "window.h"

int main() {

	// Init GLFW
	WindowHelper::InitGLFW();

	int count;
	const char** extensions = glfwGetRequiredInstanceExtensions(&count); // Use GLFW to get extensions.

	PFN_vkCreateInstance pfnCreateInstance = (PFN_vkCreateInstance) // <-- not sure what this does
    glfwGetInstanceProcAddress(NULL, "vkCreateInstance"); // <-- not sure what this does

	VkInstance inst = VkHelper::CreateVkInstance(extensions); 	// Create VkInstance.

	PFN_vkCreateDevice pfnCreateDevice = (PFN_vkCreateDevice) // <-- not sure what this does
    glfwGetInstanceProcAddress(inst, "vkCreateDevice"); // <-- not sure what this does

	PFN_vkGetDeviceProcAddr pfnGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)// <-- not sure what this does
    glfwGetInstanceProcAddress(inst, "vkGetDeviceProcAddr"); // <-- not sure what this does

	VkPhysicalDevice phys[4]; uint32_t physCount = 4;
	vkEnumeratePhysicalDevices(inst, &physCount, phys); // Get physical devices.
	VkHelper::LogVkPhysicalDeviceInfo(phys[0]); // print physical device details.

	// Create VkDevice
	VkDevice dev = VkHelper::CreateVkDevice(phys[0], extensions);

	//Create GLFW window
	GLFWwindow* window = WindowHelper::CreateGLFWWindow(400, 320, "Vulkan Learning");

	//Create Vulkan Surface with GLFW
	VkSurfaceKHR surf = WindowHelper::CreateSurface(inst, window);

	// Start a basic while/game loop.
	WindowHelper::StartLoop(window);

	return 0;
}
