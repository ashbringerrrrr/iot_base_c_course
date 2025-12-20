#include <stdio.h>
#include <stdlib.h>
#include "temp_api.h"
#include <unistd.h>

#define MAX_DATA 100

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

    TempData data[MAX_DATA];
    TempData test_data[] = {
        {2025, 1, 15, 10, 30, -2},
        {2025, 1, 15, 14, 45, 3},
        {2025, 2, 1, 8, 0, -8},
        {2025, 12, 31, 23, 59, -15},
        {2025, 2, 15, 12, 30, 5},
        {2025, 3, 10, 15, 45, 12},
        {2025, 3, 20, 18, 30, 18},
        {2025, 1, 16, 9, 15, 1},
        {2025, 12, 25, 16, 45, -10},
        {2025, 12, 24, 12, 0, -5}
    };
    size_t count = ARRAY_SIZE(test_data);

    printf("\nВсе записи:\n");
    print_data(test_data, count);
    TempData new_data = {2025, 6, 11, 12, 30, 21};
    add_data(test_data, MAX_DATA, &count, new_data);

    sort_by_date(test_data, count);
    print_data(test_data, count);

    remove_data(test_data, &count, 7);
    print_data(test_data, count);

    printf("\n");

    if (chosen_month > 0) {
        int is_found = 0;
        for (size_t i = 0; i < count; i++) {
            if (test_data[i].month == chosen_month) {
                is_found = 1;
                break;
            }
        }
        if (is_found) {
            print_month_stats(test_data, count, chosen_month);
        } else {
            printf("Нет данных за %d месяц\n", chosen_month);
        }
    }
    else{
        print_year_stats(test_data, count);
    }
    return 0;
}
