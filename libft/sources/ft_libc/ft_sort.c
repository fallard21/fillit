/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:20:14 by fallard           #+#    #+#             */
/*   Updated: 2020/11/13 16:24:07 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_quick_sort(int *arr, int first, int last)
{
	int left;
	int right;
	int middle;
	int tmp;

	left = first;
	right = last;
	middle = arr[(left + right) / 2];
	while (left <= right)
	{
		while (arr[left] < middle)
			left++;
		while (arr[right] > middle)
			right--;
		if (left <= right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
		ft_quick_sort(arr, first, right);
		ft_quick_sort(arr, left, last);
	}
}

void	ft_bubble_sort(int *arr, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j + 1] < arr[j])
				ft_swap(&arr[j + 1], &arr[j]);
			j++;
		}
		i++;
	}
}

void	ft_insert_sort(int *arr, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 1;
	while (i < size)
	{
		tmp = arr[i];
		j = i;
		while (j > 0 && arr[j - 1] > tmp)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = tmp;
		i++;
	}
}
