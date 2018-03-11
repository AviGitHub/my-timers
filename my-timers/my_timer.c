#pragma once
#include "my_timer.h"
#include "my_clock.h"

Timer_node* timers_list = NULL;


TIMER_HANLDE create_timer_impl(TIMER_HANLDE timer)
{
	// compute actual timeout

	ULONG current_time = get_current_time();
	ULONG computed_timeout = current_time + timer->timout;

	// first timer
	if (NULL == timers_list)
	{
		timers_list = malloc(sizeof(Timer_node));
		timers_list->timer = timer;
		timers_list->next = NULL;
			
		set_comperator(computed_timeout, timer->callback);
	}
}


TIMER_HANLDE create_timer(ULONG timeout, void(*callback)(void))
{
	if (NULL == callback)
	{
		return NULL;
	}

	TIMER_HANLDE timer = malloc(sizeof(MyTimer));
	
	if (NULL == timer)
	{
		return NULL;
	}

	timer->timout = timeout;
	timer->callback = callback;
	
	printf("Timer was created %x\n", timer);

	return create_timer_impl(timer);
}
