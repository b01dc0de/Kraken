#include "Engine.h"
#include "Graphics.h"
#include "Input.h"

namespace Kraken
{
#if UNICODE
    #define APPNAME() (L"Kraken")
#else
    #define APPNAME() ("Kraken")
#endif

    // Globals
    bool bRunning = false;
    HWND hWindow = nullptr;
    UINT WinResX = 1600U;
    UINT WinResY = 900U;

    // Locals
    HINSTANCE hInst;

    LRESULT CALLBACK Kraken_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    HWND InitWindow(HINSTANCE hInstance, int Width, int Height)
    {
        WNDCLASSEX WndClass = {};
        WndClass.cbSize = sizeof(WNDCLASSEX);
        WndClass.style = CS_GLOBALCLASS | CS_HREDRAW | CS_VREDRAW;
        WndClass.lpfnWndProc = Kraken_WindowProc;
        WndClass.hInstance = hInstance;
        WndClass.lpszClassName = APPNAME();

        RegisterClassEx(&WndClass);

        RECT WndRect = { 0, 0, (LONG)Width, (LONG)Height };
        UINT WndStyle = WS_CAPTION | WS_OVERLAPPEDWINDOW;
        UINT WndExStyle = WS_EX_OVERLAPPEDWINDOW;
        AdjustWindowRectEx(&WndRect, WndStyle, FALSE, WndExStyle);

        HWND NewWindow = CreateWindowEx(
            WndExStyle,
            APPNAME(),
            APPNAME(),
            WndStyle,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            WndRect.right - WndRect.left,
            WndRect.bottom - WndRect.top,
            nullptr,
            nullptr,
            hInstance,
            nullptr
        );

        return NewWindow;
    }

    LRESULT CALLBACK Kraken_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        LRESULT Result = 0;
        switch (uMsg)
        {
            case WM_KEYDOWN:
            {
                KeyboardState::SetKeyDown(wParam);
            } break;
            case WM_KEYUP:
            {
                KeyboardState::SetKeyUp(wParam);
            } break;
            case WM_CLOSE:
            {
                bRunning = false;
            } break;
            case WM_MOUSEMOVE:
            {
                MouseState::SetMousePos(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            } break;
            case WM_LBUTTONDOWN:
            case WM_LBUTTONUP:
            case WM_LBUTTONDBLCLK:
            case WM_RBUTTONDOWN:
            case WM_RBUTTONUP:
            case WM_RBUTTONDBLCLK:
            case WM_MBUTTONDOWN:
            case WM_MBUTTONUP:
            case WM_MBUTTONDBLCLK:
            {
                MouseState::SetMouseClick(uMsg);
            } break;
            default:
            {
                Result = DefWindowProc(hwnd, uMsg, wParam, lParam);
            } break;
        }

        return Result;
    }

    int Kraken_WindowMsgLoop(HWND hWindow)
    {
        MSG Msg = {};
        int MsgCount = 0;
        while (PeekMessage(&Msg, hWindow, 0, 0, PM_REMOVE) > 0)
        {
            TranslateMessage(&Msg);
            DispatchMessage(&Msg);
            MsgCount++;
        }
        return MsgCount;
    }

    void Engine::Init(HINSTANCE InInst, int WndShow)
    {
        hInst = InInst;
        if (HWND hWnd = InitWindow(hInst, WinResX, WinResY))
        {
            hWindow = hWnd;

            HRESULT Result = Kraken::InitGraphics();
            if (Result != S_OK)
            {
                DebugBreak();
            }

            ShowWindow(hWindow, WndShow);
        }
    }

    void Engine::MainLoop()
    {
        bRunning = true;

        while (bRunning)
        {
            Kraken_WindowMsgLoop(hWindow);
            UpdateWindow(hWindow);
            Kraken::Draw();

            if (KeyboardState::GetKeyState(VK_ESCAPE))
            {
                bRunning = false;
            }
        }
    }

    void Engine::Term()
    {
        TermGraphics();
    }
}
