/*
 * C10.c
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
void find_simple(int num) {
    int first = 1;
    
    while (num % 2 == 0) {
        if (first) {
            printf("%d", 2);
            first = 0;
        } else {
            printf(" %d", 2);
        }
        num /= 2;
    }
    
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            if (first) {
                printf("%d", i);
                first = 0;
            } else {
                printf(" %d", i);
            }
            num /= i;
        }
    }
    
    if (num > 1) {
        if (first) {
            printf("%d", num);
        } else {
            printf(" %d", num);
        }
    }
}


int main(int argc, char **argv)
{
    int num;
    scanf("%d", &num);
    find_simple(num);
    return 0;
}


