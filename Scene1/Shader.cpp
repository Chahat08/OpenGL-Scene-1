#include "Shader.h"

void Shader::checkErrors(unsigned int shaderID, char type) {
	int success;
	char infoLog[512];
	
	if (type == 'c') // type is compile errors
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	else if (type == 'l') // check for linking errors
		glGetShaderiv(shaderID, GL_LINK_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
		std::cerr << "ERROR: failed to " << (type=='c'?"compile":"link") << " shader\n" << infoLog << std::endl;
	}
}

unsigned int Shader::createShader(const std::string& shaderSource, char type) {
	unsigned int shaderID = 0;

	if (type == 'v') // vertex shader
		shaderID = glCreateShader(GL_VERTEX_SHADER);
	else if (type == 'f') // fragment shader
		shaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* shaderSourceString = shaderSource.c_str();
	glShaderSource(shaderID, 1, &shaderSourceString, NULL);
	glCompileShader(shaderID);

	return shaderID;
}

Shader::Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource, bool pathProvided=true) {
	unsigned int vertexShader, fragmentShader;

	std::string vertexShaderSourceStr = vertexShaderSource;
	std::string fragmentShaderSourceStr = fragmentShaderSource;

	if (pathProvided) {
		std::fstream vFileStream(vertexShaderSource, std::ios::in);
		if (vFileStream.is_open()) {
			std::string vertShaderSrcStr(
				(std::istreambuf_iterator<char>(vFileStream)),
				std::istreambuf_iterator<char>()
			);
			vertexShaderSourceStr = vertShaderSrcStr;
			vFileStream.close();
		}
		else std::cerr << "ERROR: in openging vertex shader " << vertexShaderSource << std::endl;

		std::fstream fFileStream(fragmentShaderSource, std::ios::in);

		if (fFileStream.is_open()) {
			std::string fragShaderSrcStr(
				(std::istreambuf_iterator<char>(fFileStream)),
				std::istreambuf_iterator<char>()
			);
			fragmentShaderSourceStr = fragShaderSrcStr;
			fFileStream.close();
		}
		else std::cerr << "ERROR: in openging fragment shader " << fragmentShaderSource << std::endl;
	}

	vertexShader = createShader(vertexShaderSourceStr, 'v');
	checkErrors(vertexShader, 'c');
	fragmentShader = createShader(fragmentShaderSourceStr, 'f');
	checkErrors(vertexShader, 'c');

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	checkErrors(vertexShader, 'l');

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

unsigned int Shader::getID() {
	return ID;
}

void Shader::use() {
	glUseProgram(ID);
}

void Shader::del() {
	glDeleteProgram(ID);
}

void Shader::setUniformInt(std::string& name, int value) {
	unsigned int uniformLocation = glGetUniformLocation(ID, name.c_str());
	if (uniformLocation == -1)
		std::cerr << "ERROR: Int uniform " << name << " not found. " << std::endl;
	glUniform1i(uniformLocation, value);
}

void Shader::setUniformBool(std::string& name, bool value) {
	unsigned int uniformLocation = glGetUniformLocation(ID, name.c_str());
	if (uniformLocation == -1)
		std::cerr << "ERROR: Bool uniform " << name << " not found." << std::endl;
	glUniform1i(uniformLocation, (int)value);
}

void Shader::setUniformFloat(std::string& name, float value) {
	unsigned int uniformLocation = glGetUniformLocation(ID, name.c_str());
	if (uniformLocation == -1)
		std::cerr << "ERROR: Float uniform " << name << " not found. " << std::endl;
	glUniform1f(uniformLocation, value);
}

void Shader::setUniform4fMatrix(std::string& name, glm::mat4 matrix) {
	unsigned int uniformLocation = glGetUniformLocation(ID, name.c_str());
	if (uniformLocation == -1)
		std::cerr << "ERROR: 4 Float Matrix uniform " << name << " not found. " << std::endl;
	glUniform4fv(uniformLocation, 1, glm::value_ptr(matrix));
}