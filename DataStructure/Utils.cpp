#include "Utils.h"
#include "stack.h"
#include <iostream>
#define REVERSE_ARR_SIZE 10

void reverse(int* nums, unsigned int size)
{
	Stack* s = new Stack;
	initStack(s);

	for (size_t i = 0; i < size; i++)
	{
		push(s, nums[i]);
	}

	for (size_t i = 0; i < size; i++)
	{
		nums[i] = pop(s);
		std::cout << nums[i];
	}
	delete(s);
}

int* reverse10()
{
    int* reversed_arr = new int[REVERSE_ARR_SIZE];
	for (size_t i = 0; i < REVERSE_ARR_SIZE; i++)
	{
		std::cin >> reversed_arr[i];
	}
	reverse(reversed_arr, REVERSE_ARR_SIZE);
    return reversed_arr;
}
