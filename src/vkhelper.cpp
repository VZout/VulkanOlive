#include "vkhelper.h"

VkInstance VkHelper::CreateVkInstance(const char* extensionNames[]) {
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

    VkInstance instance;
    vkCreateInstance(&instanceCreateInfo, NULL, &instance);

    return instance;
}

void VkHelper::LogVkPhysicalDeviceInfo(VkPhysicalDevice physDevice) {
    VkPhysicalDeviceProperties properties;
	vkGetPhysicalDeviceProperties(physDevice, &properties);

	std::cout << "Physical Device Details:"
    "\n\tPhysicalDevice Name: " << properties.deviceName <<
    "\n\tAPI Version: " << properties.apiVersion <<
    "\n\tDriver Version: " << properties.driverVersion <<
    "\n\tVendorID: " << properties.vendorID <<
    "\n\tDeviceID: " << properties.deviceID <<
    std::endl;
}

VkDevice VkHelper::CreateVkDevice(VkPhysicalDevice physDevice, const char* extensionNames[]) {
    VkDeviceCreateInfo deviceCreateInfo = {};
    deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceCreateInfo.pNext = NULL;
    deviceCreateInfo.queueCreateInfoCount = 0;
    deviceCreateInfo.pQueueCreateInfos = NULL;
    deviceCreateInfo.pEnabledFeatures = NULL;
    deviceCreateInfo.enabledExtensionCount = sizeof(extensionNames) / sizeof(extensionNames[0]);
    deviceCreateInfo.ppEnabledExtensionNames = extensionNames;

    VkDevice dev;
    vkCreateDevice(physDevice, &deviceCreateInfo, nullptr, &dev);

    return dev;
}
