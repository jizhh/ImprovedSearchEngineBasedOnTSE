#include <signal.h>
#include <stdio.h>

static void int_handler(int iSignal)
{
	printf("Catch a signal\r\n");
}

int main()
{
}