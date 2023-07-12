#version 440 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 color;

void main()
{
	// Outputs the positions/coordinates of all vertices
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	color = aColor;

} 