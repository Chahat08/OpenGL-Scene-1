#pragma once

#include <glad/glad.h>

#include <iostream>
#include <string>

class Texture {
private:
	unsigned int ID;
	std::string imgType;
public:
	Texture(std::string path, std::string imgType, bool flip);

	void setTextureParams(int wrap_s, int wrap_t, int minFilter, int magFilter);

	void setTextureUnit(int unitNumber);

	unsigned int getID();
};