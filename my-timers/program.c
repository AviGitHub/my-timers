#include <stdio.h>
#include <stdlib.h>
#include "my_timer.h"
#include "my_clock.h"
#include "functions.h"


void main() 
{
	start_my_clock();

	//foo();
	//bar();

	
	create_timer(2 * SEC, &foo);
	printf("crate timer for 2 sec for foo");
	Sleep(10 * SEC);
	
	//
	//create_timer(1 * SEC, bar);
	//
	//create_timer(3 * SEC, foobar);

	

	end_my_clock();

	getchar();
}