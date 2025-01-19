#ifndef INPUT_H
#define INPUT_H

#include "Kraken.h"

namespace Kraken
{
    struct KeyState
    {
        int VKCode = 0;
    };
    struct KeyboardState
    {
        static constexpr int KeyCount = 16;
        static int KeysPressed;
        static KeyState Keys[KeyCount];

        static bool GetKeyState(int VKCode);
        static void SetKeyDown(WPARAM wParam);
        static void SetKeyUp(WPARAM wParam);
    };

    struct MouseState
    {
    };
}

#endif // INPUT_H