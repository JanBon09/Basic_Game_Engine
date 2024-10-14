#pragma once

namespace BGE {
	class BGE_ShaderProgram {
	public:
		BGE_ShaderProgram();
		~BGE_ShaderProgram();

		void BGE_readShaders();
		void BGE_createShaderProgram(int);
	private:
		unsigned int shaderProgramID;
	};
}