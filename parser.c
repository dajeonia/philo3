#include "philo.h"
#include "lib.h"

int	ft_check_ispos(char *nptr);
int	**info_list_new(t_info *info, int size);

int	parser(t_info *info, int argc, char **argv)
{
	int	i;
	int	**info_list;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd("philo: parse error: argument number", 2);
		return (-1);
	}
	info_list = info_list_new(info, argc - 1);
	i = 1;
	while (i < 6)
	{
		if (ft_check_ispos(argv[i]) == 0)
		{
			free(info_list);
			ft_putendl_fd("philo: parse error: argument should be positive integer", 2);
			return (-1);
		}
		if (i == argc)
			*(info_list[i - 1]) = -1;
		else
			*(info_list[i - 1]) = ft_atoi(argv[i]);
		i++;
	}
	free(info_list);
	return (0);
}

int	**info_list_new(t_info *info, int size)
{
	int	**list;
	int	i;

	list = (int **)malloc(sizeof(int) * size);
	if (list == NULL)
		return (NULL);
	i = 0;
	list[i++] = &(info->number_of_philos);
	list[i++] = &(info->time_to_die);
	list[i++] = &(info->time_to_eat);
	list[i++] = &(info->time_to_sleep);
	list[i] = &(info->number_of_times);
	return (list);
}

int	ft_check_ispos(char *nptr)
{
	if (ft_isspace(*nptr))
		nptr += ft_duplen(nptr, " ");
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-')
		return (0);
	if (ft_isin(*nptr, "0123456789"))
	{
		nptr += ft_duplen(nptr, "0123456789");
		if (*nptr)
			return (0);
	}
	else
		return (0);
	return (1);
}