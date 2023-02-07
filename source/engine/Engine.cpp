#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/mat2x2.hpp>
#include "engine.hpp"
#include "logger/logger.hpp"
#include <iostream>
namespace Hex {
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void HelloEngine()
{
    std::cout << "Hello Engine!\n";
    HelloLogger();
}

Application::Application()
{
    std::cout << "Create EngineApp\n";
}
Application::~Application()
{
   std::cout << "Destroy EngineApp\n";
}
int Application::Run()
{
    Hex::HelloEngine();
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_E){
        std::cout << "E pressed\n";
    }
    if (key == GLFW_KEY_A && action == GLFW_PRESS){
        std::cout << "A pressed\n";
    }
}
}
