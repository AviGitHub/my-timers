#include "my_clock.h"

HANDLE threadHandle;
static ULONG running_timer = 0;
static ULONG comperator = 0;
void(*clck_callback)(void);

DWORD WINAPI update_running_timer(void * data)
{
	while (1)
	{
		if (comperator == running_timer && comperator != 0)
		{
			printf("timeout reached at %d, firing callback\n", running_timer);

			if (NULL != clck_callback)
			{
				(*clck_callback)();
			}
		}

		++running_timer;
		Sleep(1);
	}

	return 0;
}

void start_my_clock()
{
	threadHandle = CreateThread(NULL, 0, update_running_timer, NULL, 0, NULL);
	if (threadHandle) {
		printf("timer started\n");
	}
}

void end_my_clock()
{
	if (NULL != threadHandle)
	{
		DWORD exitCode = 0;
		TerminateThread(threadHandle, exitCode);

		printf("timer ended, exit code %d\n", exitCode);
	}
}

void set_comperator(ULONG interval)
{
	comperator = interval;
}

void set_my_clock_timeout_callback(void(*callback)(void))
{
	clck_callback = callback;
}

ULONG get_current_time()
{
	return running_timer;
}