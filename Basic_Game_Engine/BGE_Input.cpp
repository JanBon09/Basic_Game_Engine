#include <glad/glad.h>
#include "BGE_Input.hpp"

namespace BGE {
	void BGE_Input::BGE_processInput(GLFWwindow* window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}
}