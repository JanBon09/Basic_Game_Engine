#pragma once

#include "BGE_Shader.hpp"

namespace BGE {
	class BGE_ShaderProgram {
	public:
		BGE_ShaderProgram();
		~BGE_ShaderProgram();

		static void BGE_readShaders(const char*, std::vector<std::string>&);
		void BGE_createShadersVector(const char*, std::vector<BGE_Shader>&);
		void BGE_createShaderProgram(int);
	private:
		unsigned int shaderProgramID;
	};
}