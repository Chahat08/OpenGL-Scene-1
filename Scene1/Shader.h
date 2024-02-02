#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <iostream>

class Shader {
	unsigned int ID = 0;
	
	unsigned int createShader(const std::string& shaderSource, char type);
	void checkErrors(unsigned int shaderID, char type);
public:
	Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource, bool pathProvided);

	unsigned int getID();
	
	void use();
	void del();

	void setUniformInt(std::string& name, int value);
	void setUniformBool(std::string& name, bool value);
	void setUniformFloat(std::string& name, float value);

	void setUniform4fMatrix(std::string& name, glm::mat4 matrix);
	
};