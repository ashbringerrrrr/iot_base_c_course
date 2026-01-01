#include "temp_functions.h"
#include <ctype.h>

DynamicTempData* create_dynamic_data(size_t init_cap){
    DynamicTempData* array = (DynamicTempData*)malloc(sizeof(DynamicTempData));
    array->data = (TempData*)malloc(init_cap * sizeof(TempData));
    array->count = 0;
    array->capacity = init_cap;

    return array;
}
void free_dynamic_data(DynamicTempData* array){
    free(array->data);
    free(array);
}

int add_to_dynamic_data(DynamicTempData* array, TempData data){

    if (data.year < 1900 || data.year > 2100 ||
        data.month < 1 || data.month > 12 ||
        data.day < 1 || data.day > 31 ||
        data.hour < 0 || data.hour > 23 ||
        data.minute < 0 || data.minute > 59 ||
        data.temperature < -99 || data.temperature > 99) {
        return 0;
    }

    if (array->count >= array->capacity) {
        size_t new_cap = array->capacity * 2;
        TempData* new_data = (TempData*)realloc(array->data, new_cap * sizeof(TempData));
        array->data = new_data;
        array->capacity = new_cap;
    }
    array->data[array->count++] = data;
    return 1;
}

int remove_from_dynamic_data(DynamicTempData* array, size_t index){
    if (!array || index >= array->count) {
        return 0;
    }

    for (size_t i = index; i < array->count - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->count--;
    return 1;
}

int load_from_csv(DynamicTempData* array, const char* filename){
    if (!filename) return 0;

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: opening file was unsuccessful: %s\n", filename);
        return 0;
    }

    char line[256];
    int line_number = 1;
    int data_added = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        if (strlen(line) == 0) {
            line_number++;
            continue;
        }

        TempData data;
        int year, month, day, hour, minute, temperature;
        int parsed_fields = sscanf(line, "%d,%d,%d,%d,%d,%d", &year, &month, &day, &hour, &minute, &temperature);

        if (parsed_fields != 6) {
            parsed_fields = sscanf(line, "%d;%d;%d;%d;%d;%d", &year, &month, &day, &hour, &minute, &temperature);
            if (parsed_fields != 6) {
                parsed_fields = sscanf(line, "%d\t%d\t%d\t%d\t%d\t%d", &year, &month, &day, &hour, &minute, &temperature);
            }
        }

        if (parsed_fields != 6) {
            printf("Error: line №%d: wrong data format. Data: %s\n", line_number, line);
            line_number++;
            continue;
        }

        data.year = year;
        data.month = month;
        data.day = day;
        data.hour = hour;
        data.minute = minute;
        data.temperature = temperature;

        if (add_to_dynamic_data(array, data)) {
            data_added++;
        } else {
            printf("Error: line №%d: wrong data format. Data: %s\n", line_number, line);
        }

        line_number++;
    }
    fclose(file);
    return data_added;
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
    printf("Total records: %zu\n", count);
}

void print_month_stat_header() {
    printf("%-5s %-8s %-8s %-8s\n", "Month", "MonthAvg", "MonthMax", "MonthMin");
    printf("%-5s %-8s %-8s %-8s\n", "─────", "────────", "────────", "────────");
}

void print_month_stats(TempData data[], size_t count, int month) {

    float avg = calc_month_avg(data, count, month);
    int max = find_month_min(data, count, month);
    int min = find_month_max(data, count, month);

    printf("%-5d %-8.1f %-8d %-8d\n", month, avg, max, min);
    /*
    printf("Data for month %02d \n", month);
    printf("Month's average temperature: %.1f°C\n", calc_month_avg(data, count, month));
    printf("Month's minimal temperature: %d°C\n", find_month_min(data, count, month));
    printf("Month's maximal temperature: %d°C\n", find_month_max(data, count, month));
    printf("=======================================\n");
    */
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
    int curr_year = data->year;
    printf("=======================================\n");
    printf("Statistic for %d year\n", curr_year);
    printf("Year's average temperature: %.1f°C\n", calc_year_avg(data, count));
    printf("Year's minimal temperature: %d°C\n", find_year_min(data, count));
    printf("Year's maximal temperature: %d°C\n", find_year_max(data, count));
    printf("=======================================\n");
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
    printf("Temperature statistic app. Please enter cmd's key:\n");
    printf("  -h                for help.\n");
    printf("  -f <filename>     for load data from this file.\n");
    printf("  -m <xx>           statistic for xx month.\n");
    printf("\n");
}