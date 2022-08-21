#include <fstream>
#include <iostream>
//
// use (modern) OpenGL
#define GLEW_STATIC
#include <GL/glew.h>

// windowing and input
#include <GLFW/glfw3.h>

// utilities for creating windows etc.
#include "util.h"


// [x, y, z, r, g, b]
const float vertecies[] = {
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
     0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
};

const char* vertexSource = R"glsl(
#version 330 core

layout (location = 0) in vec3 aPos;
layout(location = 1) in vec3 color;

out vec3 Color;

void main()
{
    Color = color;
    gl_Position = vec4(aPos, 1.0);
}
)glsl";

const char* fragmentSource =  R"glsl(
#version 330 core

out vec4 FragColor;

in vec3 Color;

void main()
{
    FragColor = vec4(Color, 1.0f);
}
)glsl";

int main(int argc, char** argv)
{

    GLFWwindow* window = setup();

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    GLuint shaderProgram = getShaderProgram(vertexSource, fragmentSource);
    glUseProgram(shaderProgram);

    while (!glfwWindowShouldClose(window))
    {
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
    }

    terminate();
}
