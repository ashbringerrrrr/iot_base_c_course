#include "temp_api.h"
#include <stdio.h>
#include <limits.h>

void print_month_stats(TempData data[], int count, int month) {
    printf("Данные за месяц %02d \n", month);
    printf("Среднемесячная температура: %.1f°C\n", calc_month_avg(data, count, month));
    printf("Минимальная температура: %d°C\n", find_month_min(data, count, month));
    printf("Максимальная температура: %d°C\n", find_month_max(data, count, month));
}

float calc_month_avg(TempData data[], int count, int month) {
    return 15.5f;
}

int find_month_min(TempData data[], int count, int month) {
    return -5;
}

int find_month_max(TempData data[], int count, int month) {
    return 30;
}

void print_year_stats(TempData data[], int count) {
    printf("Годовая статистика\n");
    printf("Среднегодовая температура: %.1f°C\n", calc_year_avg(data, count));
    printf("Минимальная температура за год: %d°C\n", find_year_min(data, count));
    printf("Максимальная температура за год: %d°C\n", find_year_max(data, count));
}

float calc_year_avg(TempData data[], int count) {
    return 12.3f;
}

int find_year_min(TempData data[], int count) {
    return -15;
}

int find_year_max(TempData data[], int count) {
    return 35;
}
