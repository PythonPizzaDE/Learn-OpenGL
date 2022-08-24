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
#include "shader_s.hpp"

struct vertex {
    float x;
    float y;
    float z;
    float red;
    float green;
    float blue;
};

const vertex vertices[] = {
    vertex { -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f },
    vertex {  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f },
    vertex {  0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f },
};

// const vertex vertices[] = {
//     vertex { 0.75f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f },
//     vertex { 0.25f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f },
//     vertex { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f },

//     vertex { -0.75f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f },
//     vertex { -0.25f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f },
//     vertex { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f },
    
// };

const unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3,
};

int main(int argc, char** argv)
{

    GLFWwindow* window = setup();

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    Shader shader ("./vertex.glsl", "./fragment.glsl");
    shader.use();

    while (!glfwWindowShouldClose(window))
    {
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
    }

    terminate();
}
