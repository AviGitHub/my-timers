#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "my_clock.h"
#include "my_types.h"

#define SEC (1000)
typedef struct MyTimer MyTimer;
typedef struct Timer_node Timer_node;
#define TIMER_HANLDE  MyTimer*

struct MyTimer
{
	ULONG timout;
	void(*callback)(void);
};

struct Timer_node
{
	TIMER_HANLDE timer;
	Timer_node * next;
};


TIMER_HANLDE create_timer(size_t timeout, void(*callback)(void));
