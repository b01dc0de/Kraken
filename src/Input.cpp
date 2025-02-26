#include "Input.h"

namespace Kraken
{
    int KeyboardState::KeysPressed = 0;

    KeyState KeyboardState::Keys[KeyCount];

    bool KeyboardState::GetKeyState(int VKCode)
    {
        bool bResult = false;
        int KeyIdx = 0;
        while (KeyIdx < KeyCount && Keys[KeyIdx].VKCode != 0)
        {
            if (VKCode == Keys[KeyIdx].VKCode)
            {
                bResult = true;
                break;
            }
            KeyIdx++;
        }
        return bResult;
    }

    void KeyboardState::SetKeyDown(WPARAM wParam)
    {
        if (KeysPressed == KeyCount) { return; }

        int KeyIdx = 0;
        bool bKeyFound = false;
        while (KeyIdx < KeysPressed)
        {
            if (Keys[KeyIdx].VKCode == wParam)
            {
                bKeyFound = true;
                break;
            }
            KeyIdx++;
        }
        if (!bKeyFound)
        {
            Keys[KeyIdx].VKCode = wParam;
            KeysPressed++;
        }
    }

    void KeyboardState::SetKeyUp(WPARAM wParam)
    {
        int KeyIdx = 0;
        bool bKeyFound = false;
        while (KeyIdx < KeysPressed)
        {
            if (Keys[KeyIdx].VKCode == wParam)
            {
                bKeyFound = true;
                break;
            }
            KeyIdx++;
        }
        if (bKeyFound)
        {
            while (KeyIdx < (KeysPressed - 1))
            {
                Keys[KeyIdx].VKCode = Keys[KeyIdx + 1].VKCode;
                KeyIdx++;
            }
            Keys[KeyIdx].VKCode = 0;

            KeysPressed--;
        }
    }

    int MouseState::MouseX = MouseState::OffscreenVal;
    int MouseState::MouseY = MouseState::OffscreenVal;

    void MouseState::SetMousePos(int X, int Y)
    {
        bool bOnscreenX = 0 < X && X < WinResX;
        bool bOnscreenY = 0 < Y && Y < WinResY;

        if (bOnscreenX && bOnscreenY)
        {
            MouseX = X;
            MouseY = Y;
        }
        else
        {
            MouseX = OffscreenVal;
            MouseY = OffscreenVal;
        }
    }

    void MouseState::SetMouseClick(UINT MouseMsg)
    {
        bool bOnscreenX = 0 < MouseX && MouseX < WinResX;
        bool bOnscreenY = 0 < MouseY && MouseY < WinResY;

        if (bOnscreenX && bOnscreenY)
        {
            switch (MouseMsg)
            {
                case WM_LBUTTONDOWN:
                case WM_RBUTTONDOWN:
                case WM_MBUTTONDOWN:
                {
                } break;
                case WM_LBUTTONUP:
                case WM_RBUTTONUP:
                case WM_MBUTTONUP:
                {
                } break;
                case WM_LBUTTONDBLCLK:
                case WM_RBUTTONDBLCLK:
                case WM_MBUTTONDBLCLK:
                {
                } break;
                default:
                {

                } break;
            }
        }
    }
}