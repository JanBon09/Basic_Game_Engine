#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "BGE_Init.hpp"

namespace BGE {
	void BGE_Init::BGE_initialization(int majorVersion, int minorVersion) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void BGE_Init::BGE_loadGLAD() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "Failed to load GLAD" << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}
}