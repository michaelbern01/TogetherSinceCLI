// date_calculator.h
#ifndef DATE_CALCULATOR_H
#define DATE_CALCULATOR_H

#include <time.h>  // Include time.h for struct tm

// Define the starting date of the relationship and wedding date
#define TOGETHER_YEAR 2018
#define TOGETHER_MONTH 7
#define TOGETHER_DAY 22

#define WEDDING_YEAR 2022
#define WEDDING_MONTH 10
#define WEDDING_DAY 17

// Function prototypes
int calculate_days_since(struct tm start_date);
void calculate_years_months_days_since(struct tm start_date);

#endif
