/// @file   TickerPlant.h
/// @brief  Interface of tick generator
/// @author Eugene Kozlov
/// @date   27-Apr-2016

#pragma once

#include <ctime>

#ifndef TICKAPI
#define TICKAPI extern "C" __declspec(dllimport)
#endif

/// @brief Starts sending ticks to caller thread
TICKAPI void StartFeed();
/// @brief Stops sending ticks
TICKAPI void StopFeed();

/// @brief Tick description
struct Tick
{
   tm tickTime;     ///< Tick time
   double tickPrice;///< Tick price
};
