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
 * @file stat.h
 * @brief Contains 7 functions for analyzing the data set in the array.  
 *
 * These functions are: print_statistics(), print_array(), find_median(), find_mean() , find_maximum(), find_minimum() and sort_array(). 
 *
 *
 * @author Hesham Abobakr
 * @date 21 Jan, 2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

extern void print_statistics(unsigned char *array, unsigned int size);

/**
 * @brief  A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * Description: This function calls other functions to calculate the value of the statistics.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 */

extern void print_array(const unsigned char *array, unsigned int size);

/**
 * @brief This function prints an array to the screen.
 *
 * Description: It loops over array elements and print them.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 */

extern unsigned char find_median(unsigned char *array, unsigned int size);

/**
 * @brief This function returns the median value of the data in the array.
 *
 * Calculates the middle value of the data set then returns it rounded down to the nearest integer.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 * @return unsigned char: The median of the data set.
 */

extern unsigned char find_mean(const unsigned char *array, unsigned int size);

/**
 * @brief This function returns the mean value of the data in the array.
 *
 * Calculates the average value of the data set then returns it rounded down to the nearest integer.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 * @return unsigned char: The meanof the data set.
 */

extern unsigned char find_maximum(const unsigned char *array, unsigned int size);

/**
 * @brief This function returns the maximum value of the data in the array.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 * @return unsigned char: The maximum of the data set.
 */

extern unsigned char find_minimum(const unsigned char *array, unsigned int size);

/**
 * @brief This function returns the minimum value of the data in the array.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 * @return unsigned char: The minimum of the data set.
 */

extern void sort_array(unsigned char *array, unsigned int size);

/**
 * @brief This function returns the data in the array sorted descendingly.
 *
 * Uses selection sort algorithm.
 *
 * @param unsigned char * array: pointer to the data set.
 * @param unsigned int size: size of the array.
 */

extern void swap(unsigned char* a, unsigned char*b);

/**
 * @brief This function swaps the contents of two variable.
 *
 * Uses a temp variable in the operation of swapping.
 *
 * @param unsigned char * a: pointer to the first number.
 * @param unsigned char * b: pointer to the second number.
 */
#endif /* __STATS_H__ */
