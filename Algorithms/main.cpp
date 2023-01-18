#pragma once
#include "Application.h"


// ------- Random Number ----------- //
#include "ctime"
#include "cstdlib"
// --------------------------------- //






extern Application* CreateApplication();

void main()
{
	// Seed srand with std::time
	std::srand(std::time(nullptr));


	auto app = CreateApplication();
	app->Run();


}



