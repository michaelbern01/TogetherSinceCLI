// time_display.c
#include "time_display.h"
#include "date_calculator.h"
#include <stdio.h>
#include <time.h>

void display_relationship_and_wedding_dates() {
    // Set up "together since" date
    struct tm together_date = {0};
    together_date.tm_year = TOGETHER_YEAR - 1900;
    together_date.tm_mon = TOGETHER_MONTH - 1;
    together_date.tm_mday = TOGETHER_DAY;

    // Display "together since" days and breakdown
    int together_days = calculate_days_since(together_date);
    printf("\n\nTogether for %d days.\n", together_days);
    calculate_years_months_days_since(together_date);

    // Set up "married since" date
    struct tm wedding_date = {0};
    wedding_date.tm_year = WEDDING_YEAR - 1900;
    wedding_date.tm_mon = WEDDING_MONTH - 1;
    wedding_date.tm_mday = WEDDING_DAY;

    // Display "married since" days and breakdown
    int married_days = calculate_days_since(wedding_date);
    printf("Married for %d days.\n", married_days);
    calculate_years_months_days_since(wedding_date);
}
