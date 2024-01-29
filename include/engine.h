#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <optional>

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;

    bool isComplete()
    {
        return graphicsFamily.has_value();
    }
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
    VkDebugUtilsMessengerEXT debugMessenger;

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

    //Device stuff?
    void pickPhysicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);

    //Queue stuff

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    // Non-Vulkan stuff
    void initWindow();
    void mainLoop();
    void cleanup();

    bool checkValidationLayerSupport();

};
