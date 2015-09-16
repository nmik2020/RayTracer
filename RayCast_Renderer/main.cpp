#include <stdio.h>
#include <stdlib.h>
#include "viewport.h"
#include "xmlload.h"
int main()
{
	printf("Starting");
	int success = LoadScene("scene2.xml");
	if (success == 1)
	{
		showDefault();
	}
	return 1;
	
}
