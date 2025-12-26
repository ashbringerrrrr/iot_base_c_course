#include <stdio.h>
#include <stdlib.h>
#include "temp_functions.h"
#include <unistd.h>

int main(int argc, char* argv[])  {
    int chosen_month = 0;
    char* input_file = NULL;
    int opt;

    while ((opt = getopt(argc, argv, "hf:m:y:")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                return 0;
            case 'f':
                input_file = optarg;
                printf("Входной файл с данными: %s\n", input_file);
                break;
            case 'm':
                chosen_month = atoi(optarg);
                if (chosen_month < 1 || chosen_month > 12) {
                    printf("Номер месяца должен быть от 1 до 12\n");
                    return 1;
                }
                break;
            case '?':
                printf("Неверный ввод ключей командной строки\n");
                print_help();
                return 1;
        }
    }

    DynamicTempData* data_array = create_dynamic_data(100);

    if (input_file) {
        int data_loaded = load_from_csv(data_array, input_file);
        if (data_loaded == 0) {
            printf("Error: не удалось загрузить данные из файла %s\n", input_file);
            return 1;
        }
    } else {
        load_test_data(data_array);
    }

    size_t count = ARRAY_SIZE(data_array);

    //printf("\nВсе записи:\n");
    //print_data(data_array->data, data_array->count);

    //printf("\nСортировка:\n");
    sort_by_date(data_array->data, data_array->count);
    //print_data(data_array->data, data_array->count);

    printf("\n");
    if (chosen_month > 0) {
        int is_found = 0;
        for (size_t i = 0; i < data_array->count; i++) {
            if (data_array->data[i].month == chosen_month) {
                is_found = 1;
                break;
            }
        }
        if (is_found)
            print_month_stats(data_array->data, data_array->count, chosen_month);
        else
            printf("Нет данных за %d месяц\n", chosen_month);
    }
    else{
        int months_with_data[12] = {0};
        for (size_t i = 0; i < data_array->count; i++) {
            if (data_array->data[i].month >= 1 && data_array->data[i].month <= 12) {
                months_with_data[data_array->data[i].month - 1] = 1;
            }
        }
        for (int month = 1; month <= 12; month++) {
            if (months_with_data[month - 1]) {
                print_month_stats(data_array->data, data_array->count, month);
            }
        }
        print_year_stats(data_array->data, data_array->count);
    }

    free_dynamic_data(data_array);
    return 0;
}
