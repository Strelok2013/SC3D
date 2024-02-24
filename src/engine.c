#include "engine.h"


GLFWwindow* initWindow(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    return glfwCreateWindow(800,600, "SC3D", NULL, NULL);
}

void checkExtensionSupport()
{
    uint32_t extCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extCount, NULL);
    VkExtensionProperties* available_exts = calloc(extCount, sizeof(VkExtensionProperties));

}

void mainLoop(GLFWwindow* win)
{
    while(!glfwWindowShouldClose(win))
    {
        glfwPollEvents();
    }
}

void cleanup(GLFWwindow* win)
{
    vkDestroyInstance(instance, NULL);

    glfwDestroyWindow(win);
    glfwTerminate();
}

int main(void)
{
    GLFWwindow* window;

    window = initWindow();

    run(window);

    return 0;
}

