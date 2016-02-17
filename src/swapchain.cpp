#include "swapchain.h"

void SwapChain::SetupSwapChain(VkDevice& device) {
    VkSwapchainCreateInfoKHR swapCreateInfo = {
      // surf goes in here
    };
    
    VkSwapchainKHR swap;
    vkCreateSwapchainKHR(device, &swapCreateInfo, NULL, &swap);
}
