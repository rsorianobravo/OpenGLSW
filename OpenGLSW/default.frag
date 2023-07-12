#version 440 core

// Outputs colors in RGBA
out vec4 FragColor;

in vec3 color;

void main()
{
	// Frament when the vertices doesn't have color defined on each vertex
	// FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);

	// Use the color vector defined in the Vertex that define the positions 4 to 6 in the Vertices. [x,y,z][r,g,b] 
	FragColor = vec4(color, 1.0f);

}