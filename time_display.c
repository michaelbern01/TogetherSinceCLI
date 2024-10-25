#include "time_display.h"
#include "date_calculator.h"
#include <stdio.h>
#include <time.h>

void display_years_months_days() {
    // Set up wedding date
    struct tm wedding_date = {0};
    wedding_date.tm_year = WEDDING_YEAR - 1900;
    wedding_date.tm_mon = WEDDING_MONTH - 1;
    wedding_date.tm_mday = WEDDING_DAY;
    wedding_date.tm_hour = 0;
    wedding_date.tm_min = 0;
    wedding_date.tm_sec = 0;
    mktime(&wedding_date);

    // Get current date
    time_t current_time;
    time(&current_time);
    struct tm *current_ptr = localtime(&current_time);
    struct tm today = *current_ptr;
    today.tm_hour = 0;
    today.tm_min = 0;
    today.tm_sec = 0;
    mktime(&today);

    // Calculate total days difference
    time_t wedding_time = mktime(&wedding_date);
    double seconds_diff = difftime(current_time, wedding_time);
    int total_days_diff = (int)(seconds_diff / (60 * 60 * 24)) + 1;

    // Calculate initial differences
    int years = today.tm_year - wedding_date.tm_year;
    int months = today.tm_mon - wedding_date.tm_mon;
    int days = today.tm_mday - wedding_date.tm_mday + 1;

    // Adjust for days rollover
    if (days > 31) {  // If days exceed maximum possible days in a month
        months++;
        days = 1;
    }

    // Adjust for month rollover
    if (months >= 12) {
        years++;
        months -= 12;
    }

    // Adjust for negative days
    if (days <= 0) {
        months--;
        // Get days in previous month
        struct tm prev_month = today;
        prev_month.tm_mon--;
        prev_month.tm_mday = 1;
        mktime(&prev_month);
        
        // Get last day of previous month
        struct tm next_month = prev_month;
        next_month.tm_mon++;
        mktime(&next_month);
        time_t next_time = mktime(&next_month);
        time_t prev_time = mktime(&prev_month);
        int days_in_prev_month = (int)(difftime(next_time, prev_time) / (60 * 60 * 24));
        
        days += days_in_prev_month;
    }

    // Adjust for negative months
    if (months < 0) {
        years--;
        months += 12;
    }

    // Display results
    printf("You and your wife have been together for %d days.\n", total_days_diff);
    printf("You and your wife have been together for %d years, %d months, and %d days.\n",
           years, months, days);
}
