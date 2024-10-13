#pragma once

#include <GLFW/glfw3.h>

namespace BGE {
	static class BGE_Input {
	public:
		static void BGE_ProcessInput(GLFWwindow*);	//Mapping inputs to certain functions
	};
}