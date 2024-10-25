// date_calculator.c
#include "date_calculator.h"
#include <time.h>

int calculate_days_since_wedding() {
    struct tm wedding_date = {0};
    wedding_date.tm_year = WEDDING_YEAR - 1900;  // tm_year is years since 1900
    wedding_date.tm_mon = WEDDING_MONTH - 1;     // tm_mon is 0-based
    wedding_date.tm_mday = WEDDING_DAY;

    time_t wedding_time = mktime(&wedding_date);

    time_t current_time = time(NULL);
    double seconds_diff = difftime(current_time, wedding_time);

    // Convert seconds to days
    int days_diff = seconds_diff / (60 * 60 * 24);
    return days_diff;
}

