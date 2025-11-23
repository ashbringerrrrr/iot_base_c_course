/*
 * E10.c
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
    int arr[12];
    int temp[4];
    
    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }
    
     for (int i = 0; i < 4; i++) {
        temp[i] = arr[8 + i];
    }
    
	for (int i = 11; i >= 4; i--) {
        arr[i] = arr[i - 4];
    }
    
    for (int i = 0; i < 4; i++) {
        arr[i] = temp[i];
    }
    
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}


