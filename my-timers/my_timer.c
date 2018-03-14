#pragma once
#include "my_timer.h"
#include "my_clock.h"

Timer_node* timers_list = NULL;

void launcher(void)
{
	if (timers_list != NULL)
	{
		// fire the callback
		if(timers_list->timer->callback != NULL)
		{
			(*(timers_list->timer->callback))();
		}

		// remove the current node
		Timer_node * tmp = timers_list;
		timers_list = timers_list->next;
		free(tmp->timer);
		free(tmp);

		if (timers_list->timer != NULL)
		{
			set_comperator(timers_list->timer->timout);
		}
	}
}


TIMER_HANLDE instert_timer_to_list(TIMER_HANLDE timer, ULONG timeout)
{
	set_my_clock_timeout_callback(launcher);


	// compute actual timeout
	ULONG current_time = get_current_time();
	ULONG computed_timeout = current_time + timeout;

	// create the timer node
	Timer_node * new_timer_node = malloc(sizeof(Timer_node));
	new_timer_node->timer = timer;	
	new_timer_node->timer->timout = computed_timeout;

	// first timer
	if (NULL == timers_list)
	{
		new_timer_node->next = NULL;
		timers_list = new_timer_node;
		set_comperator(computed_timeout);
		
		return timer;
	}

	// add as new head
	if  ((computed_timeout < timers_list->timer->timout))
	{
		new_timer_node->next = timers_list;
		timers_list = new_timer_node;

		set_comperator(computed_timeout);

		return timer;
	}

	
	Timer_node * current = timers_list; 
	Timer_node * previous = current;
	
	// scan the timers list and insert the timer at the correct place
	while (current != NULL)
	{
		// if need to add at the end of the list
		if ((computed_timeout >= current->timer->timout) && (current->next == NULL))
		{
			new_timer_node->next = NULL;
			current->next = new_timer_node;
			return timer;
		}
		else if ((computed_timeout < current->timer->timout))
		{
			// add in to the list	
			previous->next = new_timer_node;
			new_timer_node->next = current;			
						
			return timer;
		}		
		
		previous = current;
		current = current->next;
	}

	return NULL;
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
	
	timer->callback = callback;
	
	printf("Timer was created: %x\n", timer);

	return instert_timer_to_list(timer, timeout);
}
