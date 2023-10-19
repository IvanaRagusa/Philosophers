/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:29:08 by iragusa           #+#    #+#             */
/*   Updated: 2023/06/28 20:29:15 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

/*ritorno diff tra now e start in millisecondi (sec * 1000) e (microsec /1000)*/
long int	get_time(t_philo *philo)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	return (((t1.tv_sec - philo->t_start) * 1000
			+ (t1.tv_usec - philo->ut_start) / 1000));
}

int	ft_check_args(int argc, char **argv)
{
	int	j;
	int	i;

	i = 1;
	if (!(argc == 5 || argc == 6))
	{
		printf("we tremon, metti 4 o 5 argomenti (solo numeri!)");
		return (1);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				printf("we tremon, solo numeri!");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_help(t_program *p, t_philo *philo, int t_last)
{
	pthread_mutex_lock(&p->dead);
	if (get_time(philo) - t_last > p->t_die)
	{
		p->muert = 1;
		ft_print_status(philo, 'd');
		pthread_mutex_unlock(&p->dead);
		return (1);
	}
	pthread_mutex_unlock(&p->dead);
	return (0);
}

int	ft_death_check(t_program *p)
{
	int	i;
	int	t_last;

	while (1)
	{
		i = -1;
		while (++i < p->n_phil)
		{
			pthread_mutex_lock(&p->n_eat);
			if (p->all_eat == 1)
			{
				pthread_mutex_unlock(&p->n_eat);
				return (1);
			}
			pthread_mutex_unlock(&p->n_eat);
			pthread_mutex_lock(&p->last_m);
			t_last = p->philo[i].last;
			pthread_mutex_unlock(&p->last_m);
			if (ft_check_help(p, &p->philo[i], t_last))
				return (1);
			usleep(5);
		}
	}
	return (0);
}
