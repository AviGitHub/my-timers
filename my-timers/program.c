#include <stdio.h>
#include <stdlib.h>
#include "my_timer.h"
#include "my_clock.h"
#include "functions.h"

void main()
{
	start_my_clock();

	printf("crate timer for 2 sec for foo\n");
	create_timer(2 * SEC, &foo);

	printf("crate timer for 3 sec for bar\n");
	create_timer(3 * SEC, &bar);

	printf("crate timer for 1 sec for foobar\n");
	create_timer(1 * SEC, &foobar);

	printf("crate timer for 2.5 sec for foofoo\n");
	create_timer(2.5 * SEC, &foofoo);

	printf("crate timer for 0.5 sec for foobar\n");
	create_timer(0.5 * SEC, &foobar);

	Sleep(10 * SEC);

	end_my_clock();

	getchar();
}