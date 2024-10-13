#include <iostream>

#include "BGE_Window.hpp"
#include "BGE_Input.hpp"

namespace BGE {
	BGE_Window::BGE_Window(int w, int h, const char* t) 
		: WIDTH {w}, HEIGHT {h}, title{t}
	{

	}

	BGE_Window::~BGE_Window() {
		glfwDestroyWindow(window);
	}

	void BGE_Window::BGE_WindowCreation() {
		window = glfwCreateWindow(this->WIDTH, this->HEIGHT, this->title, NULL, NULL);
		if (window == NULL) {
			std::cerr << "Failed to create GLFW window" << std::endl;
			exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(window);
		BGE_Viewport();
	}

	void BGE_Window::BGE_Viewport() {
		glViewport(0, 0, this->WIDTH, this->HEIGHT);
	}

	void BGE_Window::BGE_InputController() {
		BGE_Input::BGE_ProcessInput(this->window);
	}
}