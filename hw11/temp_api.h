#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>

typedef struct {
    int minute;
    int year;
    int month;
    int day;
    int hour; 
    int temperature;
} TempData;

void print_month_stats(TempData data[], int count, int month);
float calc_month_avg(TempData data[], int count, int month);
int find_month_min(TempData data[], int count, int month);
int find_month_max(TempData data[], int count, int month);

void print_year_stats(TempData data[], int count);
float calc_year_avg(TempData data[], int count);
int find_year_min(TempData data[], int count);
int find_year_max(TempData data[], int count);

#endif // TEMP_API_H
