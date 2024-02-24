#include "vk_init.h"
VkInstance instance;

_Bool checkValidationLayerSupport()
{
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, NULL);

    VkLayerProperties availableLayers[layerCount];
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers);

    for(int i = 0; i < 1; i++) // No foreach loops, so I gotta keep track of hole many validation layers I have...
    {
        bool layerFound = false;
        for(int j = 0; j < layerCount; j++)
        {
            if(strcmp(validationLayers[i], availableLayers[j].layerName) == 0)
            {
                layerFound = true;
                break;
            }
        }
        if(!layerFound)
        {
            return false;
        }
    }


    return true;
}


void createInstance()
{
    if(enableValidationLayers && !checkValidationLayerSupport())
    {
        printf("Validation layers, requested but not available. \n");
    }


    VkApplicationInfo appInfo;
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "SC3D Engine";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "SC3D";
    appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo;
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionsCount = 0;
    const char **glfwExtensions;

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);

    VkExtensionProperties extensions[extensionCount];
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, extensions);

    printf("Available Extensions:\n");
    for(int i = 0; i < extensionCount; i++)
    {
        printf("\t %s \n", extensions[i].extensionName);
    }

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionsCount);

    createInfo.enabledExtensionCount = glfwExtensionsCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    if(enableValidationLayers)
    {
        createInfo.enabledLayerCount = 1; // No vectors here to pull an int from .size()
        createInfo.ppEnabledLayerNames = validationLayers;
    }
    else
    {
        createInfo.enabledLayerCount = 0;
    }

    createInfo.enabledLayerCount = 0;

    if(vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS)
    {
        printf("Failed to create Instance \n");
    }
}

void initVulkan()
{
    createInstance();
}
