/// @file   TickerPlant.cpp
/// @brief  Implementation of tick generator
/// @author Eugene Kozlov
/// @date   27-Apr-2016

#define TICKAPI extern "C" __declspec(dllexport)

#include "TickerPlant.h"

#include <Windows.h>

//////////////////////////////////////////////////////////////////////////
namespace
{
   Tick* createTick()
   {
      Tick* tick = new Tick();

      time_t rawtime;
      time(&rawtime);
      localtime_s(&tick->tickTime, &rawtime);
      tick->tickPrice = static_cast<double>(rand()) / RAND_MAX * 500 + 900;

      return tick;
   }

   static HANDLE s_hEvent;
   static HANDLE s_hThread;
   static DWORD s_threadID;

   DWORD WINAPI sendTick(LPVOID)
   {
      DWORD startTickCount = GetTickCount();
      DWORD barTickCount = rand() % 2000;
      while (WaitForSingleObject(s_hEvent, 0) != WAIT_TIMEOUT)
      {
         DWORD tickCount = GetTickCount();
         if (tickCount - startTickCount >= barTickCount)
         {
            Tick* pTick = createTick();
            PostThreadMessage(s_threadID, WM_COMMAND, static_cast<WPARAM>(0), reinterpret_cast<LPARAM>(pTick));
            startTickCount = GetTickCount();
            barTickCount = rand() % 2000;
         }
      }
      return 0;
   }
}

Tick* t = createTick();

//////////////////////////////////////////////////////////////////////////
void StartFeed()
{
   srand(static_cast<unsigned int>(time(NULL)));
   s_hEvent = CreateEvent(NULL, TRUE, TRUE, NULL);
   s_threadID = GetCurrentThreadId();
   s_hThread = CreateThread(NULL, 0, &sendTick, NULL, 0, NULL);
}

//////////////////////////////////////////////////////////////////////////
void StopFeed()
{
   ResetEvent(s_hEvent);
   WaitForSingleObject(s_hThread, INFINITE);
}
