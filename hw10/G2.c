/*
 * G2.c
 * 
 * Copyright 2025 ashbringer <ashbringer@WIN-MAIN>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if no t, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    
    int N;
    fscanf(input_file, "%d", &N);
    char result[27];
    int letter_index = 0;
    int digit_cycle = 0;
    
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1) {
            result[i-1] = 'A' + letter_index;
            letter_index++;
        } else {
            int digit = 2 + (digit_cycle % 4) * 2;
            result[i-1] = '0' + digit;
            digit_cycle++;
        }
    }
    
    result[N] = '\0';
    
    fprintf(output_file, "%s", result);
    
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}


