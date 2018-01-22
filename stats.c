/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stat.c
 * @brief This file contains the implementation of the functions in the stat.h
 *        file with the main module.
 *
 * All the functions are tested in the main module.
 *
 * @author Hesham Abobakr
 * @date 21 Jan, 2018
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  print_statistics(test, SIZE);
  print_array(test, SIZE);
}

/**
 * @brief  A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * Description: This function calls other functions to calculate the value of the statistics.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 */
void print_statistics(unsigned char *array, unsigned int size) {  

  unsigned char mean = 0, median = 0, min = 0, max = 0;
  mean = find_mean(array, SIZE);
  min = find_minimum(array, SIZE);
  max = find_maximum(array, SIZE);
  median = find_median(array, SIZE);
  printf("Mean = %u\nMedian = %u\nMinimum = %u\nMaximum = %u\n", mean, median, min, max);
}

/**
 * @brief This function prints an array to the screen.
 *
 * Description: It loops over array elements and print them.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 */
void print_array(const unsigned char *array, unsigned int size) {

  for(int i = 0; i<size; i++) {
    printf("%u ", array[i]);
  }
  printf("\n");
}

/**
 * @brief This function returns the median value of the data in the array.
 *
 * Calculates the middle value of the data set then returns it rounded down to the nearest integer.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 * @return unsigned char: The median of the data set.
 */
unsigned char find_median(unsigned char *array, unsigned int size) {
  
  sort_array(array, size);
  if(size % 2 != 0) {
    return (unsigned char)array[(size-1)/2];
  }
  else {
    unsigned char median1 = 0, median2 = 0; 
    float averageMedian = 0;
    median1 = array[(size-1)/2];
    median2 = array[size/2];
    averageMedian = (median1+median2)/2;
    return (unsigned char)averageMedian;
  } 
}

/**
 * @brief This function returns the maximum value of the data in the array.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 * @return unsigned char: The maximum of the data set.
 */
unsigned char find_maximum(const unsigned char *array, unsigned int size) {

  unsigned char max = array[0];
  for(unsigned int i = 0; i<size; i++) {
		if(array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

/**
 * @brief This function returns the minimum value of the data in the array.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 * @return unsigned char: The minimum of the data set.
 */
unsigned char find_minimum(const unsigned char *array, unsigned int size) {

  unsigned char min = array[0];
  for(unsigned int i = 0; i<size; i++) {
		if(array[i] < min) {
			min = array[i];
		}
	}
	return min;
}

/**
 * @brief This function returns the mean value of the data in the array.
 *
 * Calculates the average value of the data set then returns it rounded down to the nearest integer.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 * @return unsigned char: The meanof the data set.
 */
unsigned char find_mean(const unsigned char *array, unsigned int size) {

	unsigned int sum = 0;
	for(int i = 0; i<size; i++) {
		sum += array[i];
	}

	return (unsigned char)((float)sum/size);
}
/**
 * @brief This function returns the data in the array sorted descendingly.
 *
 * Uses selection sort algorithm.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 */
void sort_array(unsigned char *array, unsigned int size) {

	unsigned int maxIndex = 0, i = 0, j = 0;
	for(i = 0; i<size-1; i++) {
		maxIndex = i;
		for(j = i+1; j<size; j++) {
			if(array[j] > array[maxIndex]) {
				maxIndex = j;
			}
		}
		swap(&array[i], &array[maxIndex]);
	}
}

/**
 * @brief This function swaps the contents of two variable.
 *
 * Uses a temp variable in the operation of swapping.
 *
 * @param unsigned char * a: pointer to the first number.
 * @param unsigned char * b: pointer to the second number.
 */
void swap(unsigned char* a, unsigned char*b) {

	unsigned char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
