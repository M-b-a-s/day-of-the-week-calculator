#include <stdio.h>

// function to calculate the day of the week (Zeller's Formula)
int dayOfTheWeek(int day, int month, int year){
    if(month < 3){
        month += 12;
        year--;
    }

    int K = year % 100; // the year of the century
    int J = year / 100; // the zero-based century

    int h = (day + ((13*(month + 1)/5) + K + (K/4) + (J/4) - 2*J) % 7); // the day of the week

    if(h < 0){
        h += 7;
    }

    return h;
}

void displayResult(int day, int month, int year){
    // month names
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // day names
    char *days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    // total number of days in each month
    int numDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // calculate the day of the week for the first day of the month
    int dayOfWeek = dayOfTheWeek(1, month, year);

    // calculate the number of days in the given month and year
    int totalDays = numDays[month - 1];
    
    // check for leap year
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
        totalDays++;
    }
    
    // printing the result
    printf("The day of the week for %d %s %d is: %s\n", day, months[month - 1], year, days[(dayOfWeek + (day - 1)) % 7]);
}

int main() {
    int day, month, year;

    printf("Enter day (0 - 31): ");
    scanf("%d", &day);

    printf("Enter month (1 - 12): ");
    scanf("%d", &month);    

    printf("Enter year: ");
    scanf("%d",&year);

    displayResult(day, month, year);

    return 0;
}
