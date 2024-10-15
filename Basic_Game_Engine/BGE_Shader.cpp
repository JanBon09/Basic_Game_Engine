#include <glad/glad.h>
#include <iostream>
#include <fstream>

#include "BGE_Shader.hpp"

namespace BGE {
	BGE_Shader::BGE_Shader() {

	}
	BGE_Shader::BGE_Shader(int mode, const std::string& shaderContentString)
	{
		BGE_createShader(mode, shaderContentString);
	}

	BGE_Shader::~BGE_Shader() {
		glDeleteShader(this->shaderID);
	}

	void BGE_Shader::BGE_createShader(int mode, const std::string& shaderContentString) {
		const char* shaderContent = shaderContentString.c_str();
		switch (mode) {
		case 0:
			this->shaderID = glCreateShader(GL_VERTEX_SHADER);
			break;
		case 1:
			this->shaderID = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		}

		glShaderSource(shaderID, 1, &shaderContent, NULL);
		glCompileShader(shaderID);

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

	unsigned int BGE_Shader::ShaderID() {
		return this->shaderID;
	}
}