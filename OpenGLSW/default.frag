#version 440 core

// Outputs colors in RGBA
out vec4 FragColor;

in vec3 color;

void main()
{
	//FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);

	FragColor = vec4(color, 1.0f);

}