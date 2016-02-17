#define GLFW_INCLUDE_VULKAN

#include <windows.h>
#include <iostream>
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "swapchain.h"

int main() {


	const char* extensionNames[] = { "VK_KHR_surface", "VK_KHR_win32_surface" };

	/*=============================================>>>>>
	= Create Vulkan Instance =
	===============================================>>>>>*/
	VkInstanceCreateInfo instanceCreateInfo = {
	    VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
	    NULL,
	    0,
	    NULL,
	    0,
	    NULL,
	    2,
	    extensionNames,
	};

	VkInstance inst;
	vkCreateInstance(&instanceCreateInfo, NULL, &inst);

	/*=============================================>>>>>
	= Get Physical Devices And Output Properties =
	===============================================>>>>>*/
	VkPhysicalDevice phys[4]; uint32_t physCount = 4;
	vkEnumeratePhysicalDevices(inst, &physCount, phys);

	VkPhysicalDeviceProperties properties;
	vkGetPhysicalDeviceProperties(phys[0], &properties);

	std::cout << "PhysicalDevice Name: " << properties.deviceName << std::endl;
	std::cout << "API Version: " << properties.apiVersion << std::endl;
	std::cout << "Driver Version: " << properties.driverVersion << std::endl;
	std::cout << "VendorID: " << properties.vendorID << std::endl;
	std::cout << "DeviceID: " << properties.deviceID << std::endl;

	/*=============================================>>>>>
	= Create Device AKA Context =
	===============================================>>>>>*/
	VkDeviceCreateInfo deviceCreateInfo = {};
	deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	deviceCreateInfo.pNext = NULL;
	deviceCreateInfo.queueCreateInfoCount = 0;
	deviceCreateInfo.pQueueCreateInfos = NULL;
	deviceCreateInfo.pEnabledFeatures = NULL;
	deviceCreateInfo.enabledExtensionCount = 2;
	deviceCreateInfo.ppEnabledExtensionNames = extensionNames;

	VkDevice device;
	vkCreateDevice(phys[0], &deviceCreateInfo, nullptr, &device);

	/*=============================================>>>>>
	= GLFW Windowing =
	===============================================>>>>>*/
	if (!glfwInit())
		return -1;

	if (glfwVulkanSupported()) {
		std::cout << "Vulkan Is Supported!" << std::endl;
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(640, 480, "Window Title", NULL, NULL);

	// Create Surface
	VkSurfaceKHR surface;
	VkResult err = glfwCreateWindowSurface(inst, window, NULL, &surface);
	if (err) {
	    std::cout << "Surface Creation Failed" << std::endl;
	}

	while (!glfwWindowShouldClose(window)) {

		glfwSwapBuffers(window);
	    glfwPollEvents();
	}

	SwapChain::SetupSwapChain();

	return 0;
}
