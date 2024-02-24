#pragma once
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <alloca.h>

#include "vk_init.h"


GLFWwindow* initWindow();

void mainLoop(GLFWwindow* win);

void cleanup(GLFWwindow* win);


void run(GLFWwindow* win)
{
    initVulkan();
    mainLoop(win);
    cleanup(win);
}

