/*
 * A11.c
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
	int a, b, c, d, e, min, max;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	
	min = a < b ? a : b;
	min = min< c ? min: c;
	min = min< d ? min: d;
	min = min< e ? min: e;
	
	max = a > b ? a : b;
	max = max> c ? max: c;
	max = max> d ? max: d;
	max = max> e ? max: e;
	printf("%d", max + min);
	return 0;
}


