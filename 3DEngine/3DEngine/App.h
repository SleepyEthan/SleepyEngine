#pragma once
#include "Window.h"
#include "FrameTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include "TestPlane.h"
#include "Mesh.h"
#include "ScriptCommander.h"
#include <set>

class App
{
public:
	App( const std::string& commandLine = "" );														
	int Go();													// master frame / message loop
	~App();
private:
	void DoFrame();												// master graphics frame
private:
	std::string commandLine;
	bool cursorEnabled = true;									// used to manipulate cursor
	int x = 0,y = 0;											// mouse x and y
	ImguiManager imgui;											// external tool imgui
	Window wnd;													// self contained win32 window, handles input from user
	ScriptCommander scriptCommander;
	FrameTimer timer;											// world clock
	float speed_factor = 1.0f;									// time manipulation
	Camera cam;													// configurable view matrix
	PointLight light;											// configurable light source
	Model sponza{ wnd.Gfx(),"Models\\sponza\\sponza.obj",1.0f / 20.0f };
	TestPlane bluePlane{ wnd.Gfx(),6.0f,{ 0.3f,0.3f,1.0f,0.0f } };
	TestPlane redPlane{ wnd.Gfx(),6.0f,{ 1.0f,0.3f,0.3f,0.0f } };
	//Model gobber{ wnd.Gfx(),"Models\\gobber\\GoblinX.obj",6.0f };
	//Model wall{ wnd.Gfx(),"Models\\brick_wall\\brick_wall.obj",6.0f };
	//TestPlane tp{ wnd.Gfx(),6.0 };
	//Model nano{ wnd.Gfx(),"Models\\nano_textured\\nanosuit.obj",2.0f };
};
