#pragma once

namespace BGE {
	static class BGE_Init {
	public:
		static void BGE_Initialization(int, int);	//OpenGL Initialization
		static void BGE_LoadGLAD();					//Loading GLAD
	};
}