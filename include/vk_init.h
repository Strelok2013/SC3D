#pragma once
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

extern VkInstance instance;

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const char* validationLayers[] = {"VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

void createInstance();

void initVulkan();

bool checkValidationLayerSupport();
