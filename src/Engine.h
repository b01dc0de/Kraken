#ifndef ENGINE_H
#define ENGINE_H

#include "Kraken.h"

namespace Kraken
{
    // Globals
    extern bool bRunning;
    extern HWND hWindow;
    extern UINT WinResX;
    extern UINT WinResY;

    struct Engine
    {
        static void Init(HINSTANCE hInst, int WndShow);
        static void MainLoop();
        static void Term();
    };
}

#endif // ENGINE_H