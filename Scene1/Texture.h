#pragma once

#include <glad/glad.h>

#include <iostream>
#include <string>

class Texture {
private:
	unsigned int ID = 0;
public:
	Texture() {};
	Texture(std::string path, bool gamma = false, bool flip = true);

	void setTextureParams(int wrap_s = GL_REPEAT, int wrap_t = GL_REPEAT, int minFilter = GL_LINEAR_MIPMAP_LINEAR, int magFilter = GL_LINEAR);

	void setTextureUnit(int unitNumber);

	unsigned int getID();

	std::string type; // img type: specular/diffuse
	std::string path; // img type: jpg or png, or specular/diffuse
};