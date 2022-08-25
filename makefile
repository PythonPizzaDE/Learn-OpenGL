all:
	mkdir -p build
	g++ main.cpp util.cpp stb_image.cpp -o build/run -lGL -lGLEW -lglfw

run: all
	./build/run
