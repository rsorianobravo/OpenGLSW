#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

/*
//Vertex Shader Source Code
const char* vertexShaderSource = "version 330 core\n"
	"layout (location=0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

//Fragment Shader Source Code
const char* fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"	FragColor = vec4(0.8f,0.3f,0.02f,1.0f);\n"
	"}\n\0";
*/

/*
//Create Vertices of an triangle
GLfloat vertices1[] =
{
	-0.5f,-0.5f * float(sqrt(3)) / 3, 0.0f, //Left 0
	0.5f,-0.5f * float(sqrt(3)) / 3, 0.0f,	//Right 1
	0.0f,0.5f * float(sqrt(3)) * 2 / 3,0.0f	//Up 2
};

//Create Vertices of an triangle
GLfloat vertices[] =
{ //               COORDINATES                  /     COLORS           //
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
};

*/

/*
// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,	 0.0f,0.0f,// Lower left corner
	-0.5f,  0.5f, 0.0f,     0.0f, 1.0f, 0.0f,	 0.0f,1.0f,// Upper left corner
	 0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f,	 1.0f,1.0f,// Upper right corner
	 0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	 1.0f,0.0f// Lower right corner
};
*/

/*
//Create Vertices of an triangle without indivisual color (color defined in the fragment Shader
GLfloat vertices[] =
{ //               COORDINATES                  / 
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,  
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,  
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,  
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,  
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,  
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f  
};
*/

//Create Vertices of an triangle
GLfloat vertices[] =
{ //               COORDINATES                  /     COLORS           //
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
};


GLuint indices[] =
{
	0,3,5,
	3,2,4,
	5,4,1
};


/*
// Indices for vertices order
GLuint indices[] =
{
	0, 2, 1, // Upper triangle
	0, 3, 2 // Lower triangle
};
*/




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

	/*OLD
	
	//Create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//Compile the Vertex Shader into machine code
	glad_glCompileShader(vertexShader);

	//Create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//Attach Fragment Shader sourceeeeee to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);

	//Create Shader Program Object amd get its reference
	GLuint shaderProgram = glCreateProgram();
	//Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	//Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(shaderProgram);

	//Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	//Create reference containers for the Vertex Array Object and the Vertex Buffer Object
	GLuint VBO;
	GLuint VAO;

	GLuint EBO;

	//Generate the VAO and VBO with only 1 object each
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);


	glGenBuffers(1, &EBO);

	//Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(VAO);

	//Bind the VBO specifying it's a GL_Array_Buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Configure the Vertex Attribute so that OpenGL knows how to read the VBO
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);

	//Enable the Vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(0);

	
	//Bind both the VBO and the VAO so that we don't accidentally modify the VAO and the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	//Clean the BackBuffer and assing the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	//Swap the BackBuffer with the FrontBuffer
	glfwSwapBuffers(window);

	//Execute meanwhile the user don't close the window
	while (!glfwWindowShouldClose(window)) 
	{
		
		//Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		//Clean the BackBuffer and assing the new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		//Tell OpenGL wich Shader Program we want to use
		glUseProgram(shaderProgram);
		
		//Bind the VAO so OpenGL knows to use it
		glBindVertexArray(VAO);

		//Draw the triangle using the GL_TRIANGLES primitive
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);


		//Detect all GLFW events en the window
		glfwPollEvents();
	}

	//Delete all the objects created
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);

	//Release the objects before close.
	glfwDestroyWindow(window);
	glfwTerminate();
	
	return 0;

	*/

	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");




	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO to VAO
	
	// Link VBO directly without layout
	//VAO1.LinkVBO(VBO1, 0);

	
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	//	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	

	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// ------ Uniforms
	
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	// ------
	// ------ Main Loop
	// ------ Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// ------ Check update input 
		//glfwSetWindowShouldClose(window, true);
		
		// ------ Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// ------ Clean the BackBuffer and assing the new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		glUniform1f(uniID, 0.3f);

		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		
		// Draw Primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);





		// ------ Swap the BackBuffer with the FrontBuffer
		glfwSwapBuffers(window);



		// ------ Check all the GLFW events
		glfwPollEvents();
	}

	// ------ End Program
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();



	// ------ Delete window before closing
	glfwDestroyWindow(window);
	
	// ------ Terminate GLFW before closing
	glfwTerminate();

	// ------ Delete Program

	return 0;

}