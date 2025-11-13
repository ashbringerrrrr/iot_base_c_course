/*
 * C7.c
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

int convert(int N, int P) {
    if (N == 0) {
        return 0;
    }
    
    int res = 0;
    int mult = 1;
    
    while (N > 0) {
        int digit = N % P;
        res = res + digit * mult;
        mult *= 10;
        N /= P;
    }
    
    return res;
}


int main(int argc, char **argv)
{
    int N, P;
    scanf("%d %d", &N, &P);
    printf("%d\n", convert(N, P));
    return 0;
}


