#pragma once
#include <Windows.h>
#include <stdio.h>

void start_my_clock();

void end_my_clock();

void set_comperator(ULONG interval);

void set_my_clock_timeout_callback(void(*callback)(void));

ULONG get_current_time();