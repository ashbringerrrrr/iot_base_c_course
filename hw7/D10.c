/*
 * D10.c
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
 
int is_prime(int n, int del) {
    if (n < 2) {
        return 0;
    }
    if (del * del > n) {
        return 1;
    }
    if (n % del == 0) {
        return 0;
    }
    return is_prime(n, del + 1);
}


int main(int argc, char **argv)
{
    int num;
    scanf("%d", &num);   
    if (is_prime(num, 2)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}


