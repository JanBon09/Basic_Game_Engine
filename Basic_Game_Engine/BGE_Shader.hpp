#pragma once

#include <string>

namespace BGE {
	class BGE_Shader {
	public:
		BGE_Shader();
		~BGE_Shader();

		const char* BGE_readShaderFile(const char*);
		void BGE_createShader(int, const char*);
	private:
		unsigned int shaderID;
	};
}