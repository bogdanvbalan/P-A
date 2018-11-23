int day_of_year (int year, int month, int day) {
	int i, leap;

	if (0 >= year || year > 2018) {
		printf("Incorrect year.\n");
		return 0;
	}

	if (0 >= day || day > 31) {
		printf("Incorrect day.\n");
		return 0;
	}

	if (0 >= month || month > 12) {
		printf("Incorrect month\n");
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
} 

void month_day(int year, int yearday, int *pmonth, int *pday)    {        
	
	int i, leap; 


	if (0 >= year || year > 2018) {
		printf("Incorrect year.\n");
		return 0;
	}

	if (0 >= day || day > 31) {
		printf("Incorrect day.\n");
		return 0;
	}

	if (0 >= month || month > 12) {
		printf("Incorrect month\n");
	}


	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;        
	for (i = 1; yearday > daytab[leap][i]; i++)            
		yearday -= daytab[leap][i];        
	*pmonth = i;        
	*pday = yearday;    
} 