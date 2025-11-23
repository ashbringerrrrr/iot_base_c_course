/*
 * E3.c
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

int main(int argc, char **argv)
{
    int arr[10], n_max, n_min;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min = arr[0];
    int max = arr[0];
    n_max = 0;
    n_min = 0;
    for (int i = 1; i < 10; i++) {
        if (arr[i] < min) {
            min = arr[i];
            n_min = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            n_max = i;
        }
    }
    
    printf("%d %d %d %d\n", n_max + 1, max, n_min + 1, min);
    
    return 0;
}


