#include "Kraken.h"

int WINAPI Kraken_WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PSTR CmdLine, int WndShow)
{
	(void)hPrevInst;
	(void)CmdLine;

	using namespace Kraken;
	Engine::Init(hInst, WndShow);
	Engine::MainLoop();
	Engine::Term();

	return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PSTR CmdLine, int WndShow)
{
    return Kraken_WinMain(hInst, hPrevInst, CmdLine, WndShow);
}
