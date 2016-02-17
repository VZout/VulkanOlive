#ifndef VULKAN_H
#define VULKAN_H

#include <vulkan/vulkan.h>
#include <vector>
#include <iostream>

class VkHelper {
public:
    static VkInstance CreateVkInstance(const char* extensionNames[]);
    static void LogVkPhysicalDeviceInfo(VkPhysicalDevice physDevice);
    static VkDevice CreateVkDevice(VkPhysicalDevice physDevice, const char* extensionNames[]);
};

#endif
