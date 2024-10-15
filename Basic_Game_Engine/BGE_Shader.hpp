#pragma once

#include <string>

namespace BGE {
	class BGE_Shader {
	public:
		BGE_Shader();
		BGE_Shader(int, const std::string&);
		~BGE_Shader();

		void BGE_createShader(int, const std::string&);
		unsigned int ShaderID();
	private:
		unsigned int shaderID;
	};
}