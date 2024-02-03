#version 330 core
layout(location=0) in vec3 vertexPositions;
layout(location=1) in vec3 colorPositions;
layout(location=2) in vec2 textureCoords;
out vec3 fragColor;
out vec2 texCoord;
uniform mat4 projection, view, model;
void main(){
	gl_Position=projection*view*model*vec4(vertexPositions, 1.0f);
	fragColor = colorPositions;
	texCoord=textureCoords;
}