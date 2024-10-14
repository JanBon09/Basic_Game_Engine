#include <glad/glad.h>
#include <iostream>
#include <fstream>

#include "BGE_Shader.hpp"

namespace BGE {
	BGE_Shader::BGE_Shader()
	{
	}

	BGE_Shader::~BGE_Shader() {
		glDeleteShader(this->shaderID);
	}

	const char* BGE_Shader::BGE_readShaderFile(const char* shaderPath) {
		std::ifstream fin{ shaderPath };
		std::string temp = "";
		std::string shaderFile = "";

		if (!fin) {
			std::cerr << "Failed to open file" << std::endl;
			fin.close();
			system("pause");
			exit(EXIT_FAILURE);
		}

		while (std::getline(fin, temp, '\n')) {
			shaderFile.append(temp + '\n');
		}

		return shaderFile.c_str();
	}

	void BGE_Shader::BGE_createShader(int mode, const char* shaderPath) {
		const char* shaderFile = BGE_readShaderFile(shaderPath);
		switch (mode) {
		case 0:
			this->shaderID = glCreateShader(GL_VERTEX_SHADER);
			break;
		case 1:
			this->shaderID = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		}
		{
			int success;
			char infoLog[512];

			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
			if (!success) {
				glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
				std::cerr << "Failed to create shader" << std::endl;
				system("pause");
				exit(EXIT_FAILURE);
			}
		}
	}
}