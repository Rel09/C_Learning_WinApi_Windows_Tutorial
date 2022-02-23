#include <stdio.h>
#include <windows.h>

// Trying to make my own C Library
#include "Rellib.h"




LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args,int ncmdshow)
{
   // Trying to implement a way to launch a windows without doing 70 lines of code
   // Doing it step by step, for learning purposes.
   int dev = 0;
   if (dev == 0)
   {
      
      //r_msgBox("Fatal error","Not enough vespene gaz");
      r_print("test");

   }
   else
   {
      
      WNDCLASSW wc = {0};

      //Background colors - Link for info
      //https://i.imgur.com/ZgexXsH.png
      wc.hbrBackground = (HBRUSH)COLOR_HIGHLIGHT;


      //Icon of the cursor, in the window ( Set to CROSS, for fun )
      wc.hCursor = LoadCursor(NULL, IDC_CROSS);
      wc.hInstance = hInst;
      //Window class name, probably to let win32api control it by its name
      wc.lpszClassName = L"MyWindowClass";

      wc.lpfnWndProc = WindowProcedure;

      if(!RegisterClassW(&wc))
      {
         return -1;
      }

      // Actual window
      CreateWindowW(L"MyWindowClass", L"Test Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 300, 300,NULL, NULL, NULL, NULL);

      //Probably some not implemented stuff. Not done with the tutorial
      MSG msg = {0};
      while(GetMessage(&msg, NULL,NULL,NULL))
      {
         TranslateMessage(&msg);
         DispatchMessage(&msg);
      }
      return 0;
   }
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
   switch(msg)
   {
   //If the user close the window, Break.
   case WM_DESTROY:
      PostQuitMessage(0);
      break;
   //Otherwise, we re-display the window (?)   
   default:
      return DefWindowProcW(hWnd, msg, wp, lp);
   }
}
