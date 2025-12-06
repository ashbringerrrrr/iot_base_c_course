/*
 * G3.c
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
    
    char str[1001];
    fgets(str, 1001, input_file);
    
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
    
    if (len == 0) {
        fclose(input_file);
        fclose(output_file);
        return 0;
    }
    
    char last_char = str[len - 1];
    int first_match = 1;
    
    for (size_t i = 0; i < len - 1; i++) {
        if (str[i] == last_char) {
            if (first_match) {
                fprintf(output_file, "%zu", i);
                first_match = 0;
            } else {
                fprintf(output_file, " %zu", i);
            }
        }
    }
    
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}

