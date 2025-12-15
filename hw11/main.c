#include <stdio.h>
#include <stdlib.h>
#include "temp_api.h"

#define MAX_DATA 100

int main() {
    TempData temp_data[MAX_DATA];
    
    int count = 0;

    print_month_stats(temp_data, count, 1); 
    print_month_stats(temp_data, count, 2);
    print_month_stats(temp_data, count, 3);
    printf("\n");
    
    print_year_stats(temp_data, count);
       
    return 0;
}
