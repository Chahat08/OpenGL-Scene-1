#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <cstddef>

#include "Texture.h"
#include "Shader.h"
#include "Material.h"

class Vertex {
public:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	//glm::vec3 color;
};

class Mesh {
private:
	unsigned int VAO, VBO, EBO;
	void setupMesh();

public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;
	Material material;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures, Material material);
	void draw(Shader& shader);
	void deallocateBuffers();
};