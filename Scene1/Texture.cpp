#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(std::string path, std::string imgType, bool flip = false) {

	glGenTextures(1, &this->ID);
	glBindTexture(GL_TEXTURE_2D, this->ID);

	int width, height, nrChannels;

	stbi_set_flip_vertically_on_load(flip);
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, (imgType == "jpg" ? GL_RGB : GL_RGBA), GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else std::cerr << "Failed to load texture " << path << std::endl;
	stbi_image_free(data);
}

void Texture::setTextureParams(int wrap_s, int wrap_t, int minFilter, int magFilter){
	glBindTexture(GL_TEXTURE_2D, this->ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
}

void Texture::setTextureUnit(int unitNumber) {
	if (unitNumber == 0) {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, ID);
	}
	else if (unitNumber == 1) {
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, ID);
	}
	else if (unitNumber == 2) {
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, ID);
	}
	else if (unitNumber == 3) {
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, ID);
	}
	else {
		glActiveTexture(GL_TEXTURE4);
		glBindTexture(GL_TEXTURE_2D, ID);
	}
}

unsigned int Texture::getID() {
	return ID;
}