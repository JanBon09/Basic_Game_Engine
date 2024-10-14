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

	void BGE_Window::BGE_windowCreation() {
		window = glfwCreateWindow(this->WIDTH, this->HEIGHT, this->title, NULL, NULL);
		if (window == NULL) {
			std::cerr << "Failed to create GLFW window" << std::endl;
			system("pause");
			exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(window);
		BGE_viewport();
	}

	void BGE_Window::BGE_viewport() {
		glViewport(0, 0, this->WIDTH, this->HEIGHT);
	}

	void BGE_Window::BGE_inputController() {
		BGE_Input::BGE_processInput(this->window);
	}

	int BGE_Window::GET_WINDOW_WIDTH() {
		return this->WIDTH;
	}

	int BGE_Window::GET_WINDOW_HEIGHT() {
		return this->HEIGHT;
	}
}