/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:37:58 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/26 12:07:08 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

t_philo	*philos_init(t_info *info)
{
	t_philo	*philos;
	int		i;
	int		size;

	size = info->size;
	philos = (t_philo *)malloc(sizeof(t_philo) * size);
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		philos[i].name = i + 1;
		philos[i].dish = 0;
		philos[i].left = &(info->fork_array[i]);
		if (i + 1 == size)
			philos[i].right = &(info->fork_array[0]);
		else
			philos[i].right = &(info->fork_array[i + 1]);
		philos[i].iseaten = &(info->iseaten_array[i]);
		philos[i].eaten_time = &(info->eaten_time_array[i]);
		philos[i].info = info;
		i++;
	}
	return (philos);
}
