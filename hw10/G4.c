/*
 * G4.c
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
#include <ctype.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    
    char input[202];
    fgets(input, sizeof(input), input_file);
    
    size_t len = strlen(input);
    while (len > 0 && (input[len - 1] == '\n' || input[len - 1] == '\r')) {
        input[len - 1] = '\0';
        len--;
    }
    
    char *space_pos = strchr(input, ' ');
    if (space_pos == NULL) {
        fclose(input_file);
        fclose(output_file);
        return 0;
    }
    
    char word1[101], word2[101];
    strncpy(word1, input, space_pos - input);
    word1[space_pos - input] = '\0';
    strcpy(word2, space_pos + 1);
    
    int freq1[26] = {0};
    int freq2[26] = {0};
    
    for (int i = 0; word1[i]; i++) {
        if (islower(word1[i])) {
            freq1[word1[i] - 'a']++;
        }
    }
    
    for (int i = 0; word2[i]; i++) {
        if (islower(word2[i])) {
            freq2[word2[i] - 'a']++;
        }
    }
    
    char result[27];
    int count = 0;
    
    for (int i = 0; i < 26; i++) {
        if (freq1[i] == 1 && freq2[i] == 1) {
            result[count++] = 'a' + i;
        }
    }
    
    result[count] = '\0';
    
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            if (i > 0) {
                fprintf(output_file, " ");
            }
            fprintf(output_file, "%c", result[i]);
        }
    }
    
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}
