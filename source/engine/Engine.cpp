#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/mat2x2.hpp>
#include "Engine.hpp"
#include <iostream>
#include <spdlog/spdlog.h>
#include <stb_image.h>

namespace Hex {



void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void HelloEngine()
{
    spdlog::info("Hello {}!", "HexEngine");
    spdlog::warn("Hello {}!", "HexEngine");
    spdlog::error("Hello {}!", "HexEngine");
    spdlog::critical("Hello {}!", "HexEngine");
}

Application::Application()
{
    spdlog::info("Creating Engine Application");
}
Application::~Application()
{
   spdlog::info("Destroying Engine Application");
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


    int width, height, nrChannels;
    unsigned char *data = stbi_load("image.png", &width, &height, &nrChannels, 0);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);



    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else{
            spdlog::error("image not found!");
        }


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
