#include <windows.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void daleN();
void daleP();
int main ()
{
    HDC dng = GetDC(NULL);
    RegisterHotKey(NULL, 1,0, 0x39); //9 pistola
    RegisterHotKey(NULL, 2,0, 0x43); //c escopeta
    RegisterHotKey(NULL, 3,0, 0x56); //v sniper
    RegisterHotKey(NULL, 4,0x0004, 0x2E); //shift + del deregistrar y cerrar
    MSG msg;
    while(1)
    {
        if (GetMessage(&msg, NULL, 0,0) > 0)
        {
            if (msg.message == WM_HOTKEY)
            {
                switch(msg.wParam)
                {
                    case 1:
                        //macro content
                        break;
                    case 2:
                        //macro content
                        break;
                    case 3:
                        //macro content
                        break;
                    case 4: //close app and unregister hotkeys
                        ReleaseDC(NULL, dng);
                        for (int i = 1; i <=3; i++)UnregisterHotKey(NULL,i);
                        exit(0);
                }
            }
        }
    }

}
