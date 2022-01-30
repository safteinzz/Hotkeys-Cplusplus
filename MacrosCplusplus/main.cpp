#include <windows.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void daleN();
void daleP();
int main ()
{
    HDC dng = GetDC(NULL);
    const int posX = 1282;
    const int posY = 1291;
    const int pistolaBHigh = 40;
    const int escopetaBLow = 180;
    const int sniperGHigh = 60;
    int g;
    int b;
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
                COLORREF c;
                c = GetPixel(dng,posX,posY);
                g = (int)GetGValue(c);
                b = (int)GetBValue(c);
                switch(msg.wParam)
                {
                    case 1: //CAMBIO A PISTOLA
                        if(b < pistolaBHigh)break;
                        else if(b > escopetaBLow)daleN();
                        else if(g < sniperGHigh)daleP();
                        else break;
                        break;
                    case 2: //CAMBIO A ESCOPETA
                        if(b > escopetaBLow)break;
                        else if(b < pistolaBHigh)daleP();
                        else if(g < sniperGHigh)daleN();
                        else break;
                        break;
                    case 3: //CAMBIO A SNIPER
                        if(g < sniperGHigh)break;
                        else if(b > escopetaBLow)daleP();
                        else if(b < pistolaBHigh)daleN();
                        else break;
                        break;
                    case 4: //cerrar aplicacion
                        ReleaseDC(NULL, dng);
                        for (int i = 1; i <=3; i++)UnregisterHotKey(NULL,i);
                        exit(0);
                }
            }
        }
    }

}
void daleN(){
    keybd_event(0x4E, 0, KEYEVENTF_EXTENDEDKEY,0);
    Sleep(10);
    keybd_event(0x4E, 0, KEYEVENTF_KEYUP,0);
    return;
}
void daleP(){
    keybd_event(0x50, 0, KEYEVENTF_EXTENDEDKEY,0);
    Sleep(10);
    keybd_event(0x50, 0, KEYEVENTF_KEYUP,0);
    return;
}
