#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <cstddef>

#include "Texture.h"
#include "Shader.h"

class Vertex {
public:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

//class Texture2 {
//public:
//	unsigned int id;
//	std::string type; // specular/diffused etc.
//};

class Mesh {
private:
	unsigned int VAO, VBO, EBO;
	void setupMesh();

public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	void draw(Shader& shader);
};