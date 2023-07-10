#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>


// ------ FUNCTIONS

// ------ MAIN

int main()
{
	const int WINDOW_WIDTH = 1920;
	const int WINDOW_HEIGHT = 1280;
	int framebufferWidth = 0;
	int framebufferHeight = 0;
	
	// ------ Init the GLFW lib
	glfwInit();

	// ------ Tell GLFW what version of OpenGL we are using
	// ------ OpenGL 4.4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

	// ------ Tell GLFW we are using core profile, only with modern functions (the other is the Compatibility profile)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// ------ GLFW Options
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	// ------ macOS Compatibility
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// ------ Create the Window
	// ------ Create a GLFW Window object of 800/800 pixels with the name. The NULL are for Full Screen , and share window
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "ShowWindowOpenGL", NULL, NULL);

	// ------ Check if the window is not created
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// ------ Important - Introduce the window into the current Context
	glfwMakeContextCurrent(window);

	// ------ Load GLAD so it configures OpenGL
	gladLoadGL();
	
	// ------ Specify the dimensions of the viewport (x,y,x+width, y+height)
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	// ------ Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// ------ Clean the BackBuffer and assing the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// ------ Swap the BackBuffer with the FrontBuffer
	glfwSwapBuffers(window);



	// ------
	// ------
	// ------ Main Loop
	// ------ Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// ------ Check update input 
		//glfwSetWindowShouldClose(window, true);
		glfwPollEvents();
	}

	// ------ End Program
	
	glfwDestroyWindow(window);
	glfwTerminate();

	// ------ Delete Program

	return 0;

}