#ifndef TEMP_API_H
#define TEMP_API_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TempData;

typedef struct {
    TempData* data;
    size_t count;
    size_t capacity;
} DynamicTempData;

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

DynamicTempData* create_dynamic_data(size_t init_cap);
void free_dynamic_data(DynamicTempData* array);
int add_to_dynamic_data(DynamicTempData* array, TempData data);
int remove_from_dynamic_data(DynamicTempData* array, size_t index);
int load_from_csv(DynamicTempData* array, const char* filename);

void sort_by_date(TempData data[], size_t count);
void print_data(TempData data[], size_t count);

void print_month_stats(TempData data[], size_t count, int month);
float calc_month_avg(TempData data[], size_t count, int month);
int find_month_min(TempData data[], size_t count, int month);
int find_month_max(TempData data[], size_t count, int month);

void print_year_stats(TempData data[], size_t count);
float calc_year_avg(TempData data[], size_t count);
int find_year_min(TempData data[], size_t count);
int find_year_max(TempData data[], size_t count);

void print_help();

#endif // TEMP_API_H
