# required libraries are:
# GLEW
# GLFW
# stb_image (included)
# glm (header only, so no linking in the makefile)

all:
	mkdir -p build
	g++ main.cpp util.cpp stb_image.cpp -o build/run -lGL -lGLEW -lglfw

run: all
	./build/run
