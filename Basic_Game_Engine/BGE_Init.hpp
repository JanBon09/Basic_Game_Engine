#pragma once

namespace BGE {
	static class BGE_Init {
	public:
		static void BGE_initialization(int, int);	//OpenGL Initialization
		static void BGE_loadGLAD();					//Loading GLAD
	};
}