#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int add_data(TempData data[], size_t max_size, size_t* count, TempData new_data) {
    data[(*count)++] = new_data;
    return 1;
}

int remove_data(TempData data[], size_t* count, size_t index) {
    for (size_t i = index; i < *count - 1; i++) {
        data[i] = data[i + 1];
    }
    (*count)--;
    return 1;
}

int compare_by_date(const void* a, const void* b) {
    TempData* dataA = (TempData*)a;
    TempData* dataB = (TempData*)b;

    if (dataA->year != dataB->year) return dataA->year - dataB->year;
    if (dataA->month != dataB->month) return dataA->month - dataB->month;
    if (dataA->day != dataB->day) return dataA->day - dataB->day;
    if (dataA->hour != dataB->hour) return dataA->hour - dataB->hour;
    return dataA->minute - dataB->minute;
}

void sort_by_date(TempData data[], size_t count) {
    qsort(data, count, sizeof(TempData), compare_by_date);
}

void print_data(TempData data[], size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("%04d-%02d-%02d %02d:%02d | %3d°C\n",
                data[i].year, data[i].month, data[i].day,
                data[i].hour, data[i].minute,
                data[i].temperature);
    }
    printf("Всего записей: %zu\n", count);
}

void print_month_stats(TempData data[], size_t count, int month) {
    printf("Данные за месяц %02d \n", month);
    printf("Среднемесячная температура: %.1f°C\n", calc_month_avg(data, count, month));
    printf("Минимальная температура: %d°C\n", find_month_min(data, count, month));
    printf("Максимальная температура: %d°C\n", find_month_max(data, count, month));
}

float calc_month_avg(TempData data[], size_t count, int month) {
    int sum = 0;
    int val_count = 0;
    for (size_t i = 0; i < count; i++) {
        if (data[i].month == month) {
            sum += data[i].temperature;
            val_count++;
        }
    }
    return (val_count > 0) ? (float)sum / val_count : 0.0f;
}

int find_month_min(TempData data[], size_t count, int month) {
    int min_temp = INT_MAX;
    int is_found = 0;
    for (size_t i = 0; i < count; i++) {
        if (data[i].month == month) {
            if (data[i].temperature < min_temp) {
                min_temp = data[i].temperature;
                is_found = 1;
            }
        }
    }
    return is_found ? min_temp : 0;
}

int find_month_max(TempData data[], size_t count, int month) {
    int max_temp = INT_MIN;
    int is_found = 0;
    for (size_t i = 0; i < count; i++) {
        if (data[i].month == month) {
            if (data[i].temperature > max_temp) {
                max_temp = data[i].temperature;
                is_found = 1;
            }
        }
    }
    return is_found ? max_temp : 0;
}

void print_year_stats(TempData data[], size_t count) {
    printf("Годовая статистика\n");
    printf("Среднегодовая температура: %.1f°C\n", calc_year_avg(data, count));
    printf("Минимальная температура за год: %d°C\n", find_year_min(data, count));
    printf("Максимальная температура за год: %d°C\n", find_year_max(data, count));
}

float calc_year_avg(TempData data[], size_t count) {
    int sum = 0;
    int val_count = 0;
    for (size_t i = 0; i < count; i++) {
            sum += data[i].temperature;
            val_count++;
    }
    return (val_count > 0) ? (float)sum / val_count : 0.0f;
}

int find_year_min(TempData data[], size_t count) {
    int min_temp = INT_MAX;
    int is_found = 0;
    for (size_t i = 0; i < count; i++) {
            if (data[i].temperature < min_temp) {
                min_temp = data[i].temperature;
                is_found = 1;
            }
    }
    return is_found ? min_temp : 0;
}

int find_year_max(TempData data[], size_t count) {
    int max_temp = INT_MIN;
    int is_found = 0;
    for (size_t i = 0; i < count; i++) {
            if (data[i].temperature > max_temp) {
                max_temp = data[i].temperature;
                is_found = 1;
            }
    }
    return is_found ? max_temp : 0;
}

void print_help() {
    printf("=======================================\n");
    printf("Ключи командной строки:\n");
    printf("  -h           Показать справку\n");
    printf("  -f <файл>    Входной файл с данными\n");
    printf("  -m <число>   Вывести статистику только за указанный месяц\n");
    printf("\n");
}
