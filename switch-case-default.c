
#include <stdio.h>

// ask user to type number 1-7 to find out day of week;

int main()
{
	int number;
	printf("Type number 1 to 7: \n");
	scanf("%d", &number);

	switch(number)
{
	case 1:
	printf("Sunday");
	break;

	case 2:
	printf("Monday");
	break;

	case 3:
	printf("Tuesday");
	break;

	case 4:
	printf("Wednesday");
	break;

	case 5:
	printf("Thursday");
	break;

	case 6:
	printf("Friday");
	break;

	case 7:
	printf("Saturday");
	break;

	default:
	printf("Invalid number");
	break;
}
return 0;
}
