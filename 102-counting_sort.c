#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *_calloc - this is a calloc function
 *@nmemb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		p[i] = 0;
	return (p);
}
/**
 * counting_sort - this is a counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int index, maximum = 0, *counter = NULL, *tmp = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;
	/* find maximun number */
	for (i = 0; i < size; i++)
		if (array[i] > maximum)
			maximum = array[i];
	counter = _calloc(maximum + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));
	/* count the array elements */
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	/* get the accumulative values */
	for (index = 1; index <= maximum; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximum + 1);
	/* get the new array sorted */
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	/* replace old array to new array sorted */
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(counter);

}
