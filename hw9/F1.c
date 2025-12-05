/*
 * F1.c
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

void sort_array(int size, int a[]) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
        }
    }
}

int main(int argc, char **argv)
{
    int size;
    if (scanf("%d", &size) != 1 || size <= 0) {
        return 1;
    }
    
    int a[size];
    
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    
    sort_array(size, a);
    
    for (int i = 0; i < size; i++) {
        printf("%d", a[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}


