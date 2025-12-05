/*
 * F2.c
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

void sort_even_odd(int n, int a[]) {
    int even_pos = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            int temp = a[i];
            for (int j = i; j > even_pos; j--) {
                a[j] = a[j-1];
            }
            a[even_pos] = temp;
            even_pos++;
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


