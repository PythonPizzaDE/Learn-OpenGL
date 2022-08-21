#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// reduce boilerplate in main file
GLFWwindow* setup();
GLuint getShaderProgram(char* vertexShaderSource, char* fragmentShaderSource);
void terminate();
