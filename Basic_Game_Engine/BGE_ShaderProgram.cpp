#include <glad/glad.h>
#include <vector>
#include <iostream>

#include "BGE_ShaderProgram.hpp"
#include "BGE_Shader.hpp"
#include "BGE_FileReader.hpp"

namespace BGE {
	BGE_ShaderProgram::BGE_ShaderProgram() {

	}

	BGE_ShaderProgram::~BGE_ShaderProgram() {
		glDeleteProgram(shaderProgramID);
	}

	void BGE_ShaderProgram::BGE_readShaders(const char* mainPath, std::vector<std::string>& shadersContent) {
		std::string shadersList = BGE_FileReader::showContents(mainPath);
		BGE_FileReader::modeFilteredContent(shadersList, 0);
		BGE_FileReader::extensionFilteredContent(shadersList, std::vector<std::string>{".vert", ".frag"});
		shadersContent = BGE_FileReader::readContent(shadersList);
	}

	void BGE_ShaderProgram::BGE_createShadersVector(const char* mainPath, std::vector<BGE_Shader>& shadersList) {
		std::vector<std::string> shadersContent;
		BGE_readShaders(mainPath, shadersContent);
		int i{ 0 };		//Temporay solution for differentiating vertex and fragment shaders
		for (const std::string& shaderContent : shadersContent) {
			BGE_Shader tempShader{i % 2, shaderContent};
			shadersList.push_back(tempShader);
			i++;
		}
	}

	void BGE_ShaderProgram::BGE_createShaderProgram(int numberOfShaders) {
		shaderProgramID == glCreateProgram();

		std::vector<BGE_Shader> shadersVector;
		const char* mainPath;
		BGE_createShadersVector(mainPath, shadersVector);

		for (int i{ 0 }; i < shadersVector.size(); i++) {
			glAttachShader(shaderProgramID, shadersVector[i].ShaderID());
		}
		glLinkProgram(shaderProgramID);

		int success;
		char infoLog[512];

		glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shaderProgramID, 512, NULL, infoLog);
			std::cerr << "Failed to link shader program\n" << infoLog << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}