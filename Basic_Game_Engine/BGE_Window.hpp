#pragma once

#include <GLFW/glfw3.h>

namespace BGE {
	class BGE_Window {
	public:
		BGE_Window(int, int, const char*);
		~BGE_Window();

		void BGE_WindowCreation();	//Creation of GLFW window
		bool BGE_WindowClose();		//Checking if window is closed, used in main render loop
		void BGE_Viewport();		//Viewport creation, used everytime window is resized
		void BGE_InputController();		//Mapping keys to certain functionality

		//Access functions
		int GET_WINDOW_WIDTH();		
		int GET_WINDOW_HEIGHT();
	
	private:
		GLFWwindow* window;
		int WIDTH, HEIGHT;
		const char* title;
	};
}