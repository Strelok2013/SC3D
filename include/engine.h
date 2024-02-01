#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <optional>
#include <set>
#include <cstdint>
#include <limits>
#include <algorithm>

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete()
    {
        return graphicsFamily.has_value() && presentFamily.has_value();

    }
};

const std::vector<const char*> deviceExtensions =
{
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

struct SwapChainSupportDetails
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class Engine
{
public:
    void run()
    {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
private:
    GLFWwindow* window;

    VkInstance instance;
    //Debug
    VkDebugUtilsMessengerEXT debugMessenger;
    // Device
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    //Queue
    VkQueue graphicsQueue;
    // Vulkan stuff
    void initVulkan();
    void createInstance();
    std::vector<const char*> getRequiredExtensions();

    // Debug stuff
     static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
     VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
     VkDebugUtilsMessageTypeFlagsEXT messageType,
     const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
     void* pUserData);
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void setupDebugMessenger();

    //Surface stuff
    VkSurfaceKHR surface;
    void createSurface();

    //Device stuff?
    void pickPhysicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    void createLogicalDevice();

    //Queue stuff
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    VkQueue presentQueue;

    //Swap chain stuff
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    void createSwapChain();
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

    // Non-Vulkan stuff
    void initWindow();
    void mainLoop();
    void cleanup();

    bool checkValidationLayerSupport();

};
