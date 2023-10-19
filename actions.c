/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:37:12 by iragusa           #+#    #+#             */
/*   Updated: 2023/07/09 18:37:24 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	ft_time_toaction(t_philo *philo, int t_type)
{
	long int	time_now;

	time_now = get_time(philo);
	while (get_time(philo) - time_now < (long int)t_type)
		usleep(50);
}

void	ft_print_status(t_philo *philo, char c)
{
	static int	check = 0;

	pthread_mutex_lock(philo->print);
	if (check == 0)
	{
		if (c == 'd')
		{
			check = 1;
			printf("%ld Mcfratm %d ha muert\n", get_time(philo), philo->id);
		}
		else if (c == 'f')
			printf("%ld Mcfratm %d ha pigghiat a forcin\n",
				get_time(philo), philo->id);
		else if (c == 'e')
			printf("%ld Mcfratm %d sta mmangj\n",
				get_time(philo), philo->id);
		else if (c == 's')
			printf("%ld Mcfratm %d sta ddorm\n",
				get_time(philo), philo->id);
		else if (c == 't')
			printf("%ld Mcfratm %d sta tutt fissat'\n",
				get_time(philo), philo->id);
	}
	pthread_mutex_unlock(philo->print);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->my_fork);
	ft_print_status(philo, 'f');
	pthread_mutex_lock(philo->fork_next);
	ft_print_status(philo, 'f');
	ft_print_status(philo, 'e');
	pthread_mutex_lock(philo->last_m);
	philo->last = get_time(philo);
	pthread_mutex_unlock(philo->last_m);
	ft_time_toaction(philo, philo->t_eat);
	pthread_mutex_unlock(philo->fork_next);
	pthread_mutex_unlock(philo->my_fork);
}

void	ft_routine_help(t_philo *philo, int i)
{
	while (i != 0)
	{
		ft_eat(philo);
		ft_print_status(philo, 's');
		ft_time_toaction(philo, philo->t_sleep);
		ft_print_status(philo, 't');
		pthread_mutex_lock(philo->dead);
		if (*(philo->muert) != 0)
		{
			pthread_mutex_unlock(philo->dead);
			break ;
		}
		pthread_mutex_unlock(philo->dead);
		if (i > 0)
			i--;
		if (i == 0)
		{
			pthread_mutex_lock(philo->n_eat);
			*philo->all_eat = 1;
			pthread_mutex_unlock(philo->n_eat);
			break ;
		}
	}
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = philo->num_eat;
	if (philo->id % 2 == 0)
		usleep(5000);
	if (philo->n_phil == 1)
	{
		ft_print_status(philo, 'f');
		ft_time_toaction(philo, philo->t_die);
		ft_print_status(philo, 'd');
		return (NULL);
	}
	ft_routine_help(philo, i);
	return (NULL);
}
//valgrind --tool=helgrind etc
