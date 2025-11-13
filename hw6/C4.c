/*
 * C4.c
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

int f(int x) {
    if (x < -2) {
        return 4;
    } else if (x < 2) {
        return x * x;
    } else {
        return x * x + 4 * x + 5;
    }
}

int main(int argc, char **argv)
{
    int x;
    
    int max_value = -2147483647;
    
    
    while (1) {
        scanf("%d", &x);
        if (x == 0) {
            break;
        }
        
        int result = f(x);
        if (result > max_value) {
            max_value = result;
        }
    }
    
	printf("%d", max_value);
    return 0;
}


