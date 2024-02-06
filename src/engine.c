#include "engine.h"


GLFWwindow* initWindow(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    return glfwCreateWindow(800,600, "SC3D", NULL, NULL);
}




int main(void)
{
    GLFWwindow* window;

    window = initWindow();

    // Main loop
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();
    // const char* layers[] = {"VK_LAYER_KHRONOS_validation", "VK_LAYER_KHRONOS_profiles"};
    //
    // VkApplicationInfo app_info;
    // app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    // app_info.pNext = 0; // 0 is the same as nullptr right?
    //
    //
    // VkInstanceCreateInfo inst_create_info;
    // inst_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    //
    //
    // printf("Test 123 \n");
}

