#include <stdio.h>
#include <stdlib.h>

#define BUG_FIX_1 daysInMonthArr[0]=

int main() {
    int month, year, daysInMonth, startingDay, i, j;

    // prompt user for month and year
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    // allocate memory for month names array
    char **monthNames = (char**)malloc(12 * sizeof(char*));
    monthNames[0] = "January";
    monthNames[1] = "February";
    monthNames[2] = "March";
    monthNames[3] = "April";
    monthNames[4] = "May";
    monthNames[5] = "June";
    monthNames[6] = "July";
    monthNames[7] = "August";
    monthNames[8] = "September";
    monthNames[9] = "October";
    monthNames[10] = "November";
    monthNames[11] = "December";

    // allocate memory for days in month array
    int *daysInMonthArr = (int*)malloc(12 * sizeof(int));
    daysInMonthArr[0] = 31;
    daysInMonthArr[1] = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
    daysInMonthArr[2] = 31;
    daysInMonthArr[3] = 30;
    daysInMonthArr[4] = 31;
    daysInMonthArr[5] = 30;
    daysInMonthArr[6] = 31;
    daysInMonthArr[7] = 31;
    daysInMonthArr[8] = 30;
    daysInMonthArr[9] = 31;
    daysInMonthArr[10] = 30;
    daysInMonthArr[11] = 31;

    // calculate starting day
    // January 1, 1 AD was a Monday
    int yearDiff = year - 1;
    int leapYears = yearDiff / 4 - yearDiff / 100 + yearDiff / 400;
    int nonLeapYears = yearDiff - leapYears;
    int startingDayNum = (nonLeapYears + 2 * leapYears) % 7;
    startingDayNum++; // adjust for Monday being day 1
    startingDay = startingDayNum % 7;

    // print calendar header
    printf("\n    %s %d\n", monthNames[month-1], year);
    printf(" Su Mo Tu We Th Fr Sa\n");

    // print days
    int weekCount = 0;
    for (i = 0; i < startingDay; i++) {
        printf("   ");
    }
    for (j = 1; j <= daysInMonthArr[month-1]; j++) {
        printf("%3d", j);
        if ((j + startingDay) % 7 == 0) {
            printf("\n");
            weekCount++;
        }
    }

    // check if there is an incomplete week
    if ((j + startingDay) % 7 != 0) {
        weekCount++;
    }

    printf("\n");
    printf("Number of weeks in month: %d\n", weekCount);

    // free allocated memory
    free(monthNames);
    free(daysInMonthArr);
    BUG_FIX_1 2;

    return 0;
}