#include <glad/glad.h>
#include <vector>

#include "BGE_ShaderProgram.hpp"
#include "BGE_Shader.hpp"

namespace BGE {
	BGE_ShaderProgram::BGE_ShaderProgram() {

	}

	BGE_ShaderProgram::~BGE_ShaderProgram() {
		glDeleteProgram(shaderProgramID);
	}

	void BGE_ShaderProgram::BGE_readShaders() {

	}

	void BGE_ShaderProgram::BGE_createShaderProgram(int numberOfShaders) {
		std::vector<BGE_Shader> shadersArray;

		for (int i{ 0 }; i < numberOfShaders; i++) {

		}
	}
}