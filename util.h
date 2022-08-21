#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// reduce boilerplate in main file
GLFWwindow* setup();
GLuint getShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
void terminate();
