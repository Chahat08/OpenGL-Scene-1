#version 330 core
in vec3 fragColor;
out vec4 fragmentColor;
in vec2 texCoord;

in vec3 fragmentPosition;
in vec3 normal;

//uniform sampler2D purpleStars;
//uniform sampler2D greenLines;

//uniform sampler2D texture_diffuse1;

struct Material{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float shininess;
};

struct Light{
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Material material;
uniform Light light;

uniform vec3 cameraPos;

void main(){
	//fragmentColor=vec4(fragColor, 1.0f);
	//fragmentColor = texture(purpleStars, texCoord);//*vec4(fragColor, 0.5f);
	//fragmentColor = mix(texture(purpleStars, texCoord), texture(greenLines, texCoord), 0.5);

	//fragmentColor = texture(texture_diffuse1, texCoord);

	// ambient
	vec3 ambient = light.ambient*material.ambient;
	
	// diffuse
	vec3 lightDir = normalize(light.position-fragmentPosition);
	vec3 norm = normalize(normal);
	vec3 diffuse = max(dot(lightDir, norm), 0.0)*light.diffuse*material.diffuse;

	// specular
	vec3 viewDir = normalize(cameraPos-fragmentPosition);
	vec3 reflectDir = reflect(-lightDir, norm);
	vec3 specular = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess)*light.specular*material.specular;

	fragmentColor = vec4((ambient+diffuse+specular), 1.0);
}