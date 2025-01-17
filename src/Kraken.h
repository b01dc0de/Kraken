#ifndef KRAKEN_H
#define KRAKEN_H

// C++ Std Lib
#include <cstdio>
#include <vector>
// Win32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
// DX11
#include <d3d11.h>
#include <d3dcompiler.h>
#include <dxgi.h>

// Globals
extern bool bRunning;
extern HWND hWindow;
extern UINT WinResX;
extern UINT WinResY;

// Common Kraken headers
#include "Math.h"
#include "Utils.h"

#endif // KRAKEN_H