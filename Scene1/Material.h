#pragma once
#include <glm/glm.hpp>

class Material {
public:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;

	Material():ambient(glm::vec3(0.1)), diffuse(glm::vec3(0.5)), specular(glm::vec3(0.5)), shininess(32.0){}
	Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess) :
		ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess) {}
};