// date_calculator.c
#include "date_calculator.h"
#include <time.h>
#include <stdio.h>

int calculate_days_since(struct tm start_date) {
    time_t start_time = mktime(&start_date);
    time_t current_time = time(NULL);
    double seconds_diff = difftime(current_time, start_time);
    return (int)(seconds_diff / (60 * 60 * 24)) + 1;  // Include today
}

void calculate_years_months_days_since(struct tm start_date) {
    // Get the current date
    time_t current_time = time(NULL);
    struct tm *current_ptr = localtime(&current_time);
    struct tm today = *current_ptr;
    today.tm_hour = 0;
    today.tm_min = 0;
    today.tm_sec = 0;
    mktime(&today);

    // Calculate initial differences
    int years = today.tm_year - start_date.tm_year;
    int months = today.tm_mon - start_date.tm_mon;
    int days = today.tm_mday - start_date.tm_mday;

    // Adjust for negative days
    if (days < 0) {
        months--;
        struct tm prev_month = today;
        prev_month.tm_mon--;
        prev_month.tm_mday = 1;
        mktime(&prev_month);

        // Calculate days in the previous month
        struct tm next_month = prev_month;
        next_month.tm_mon++;
        mktime(&next_month);
        int days_in_prev_month = (int)(difftime(mktime(&next_month), mktime(&prev_month)) / (60 * 60 * 24));
        
        days += days_in_prev_month;
    }

    // Adjust for negative months
    if (months < 0) {
        years--;
        months += 12;
    }

    // Include today by adding 1 day to days count if all are positive
    if (days < 29) {
        days += 1;
    }

    // Display result
    printf("that is  %d years, %d months, and %d days.\n\n\n", years, months, days);
}
