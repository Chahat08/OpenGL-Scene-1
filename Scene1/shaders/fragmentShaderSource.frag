#version 330 core
in vec3 fragColor;
out vec4 fragmentColor;
in vec2 texCoord;
//uniform sampler2D purpleStars;
//uniform sampler2D greenLines;

uniform sampler2D texture_diffuse1;

void main(){
	//fragmentColor=vec4(fragColor, 1.0f);
	//fragmentColor = texture(purpleStars, texCoord);//*vec4(fragColor, 0.5f);
	//fragmentColor = mix(texture(purpleStars, texCoord), texture(greenLines, texCoord), 0.5);
	fragmentColor = texture(texture_diffuse1, texCoord);
}