/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:29:08 by iragusa           #+#    #+#             */
/*   Updated: 2023/06/28 20:29:15 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	ft_freexit(t_program *p)
{
	int	i;

	i = -1;
	while (++i < p->n_phil)
		pthread_join(p->thread[i], NULL);
	i = -1;
	while (++i < p->n_phil)
		pthread_mutex_destroy(&p->fork[i]);
	pthread_mutex_destroy(&p->n_eat);
	pthread_mutex_destroy(&p->dead);
	pthread_mutex_destroy(&p->print);
	pthread_mutex_destroy(&p->last_m);
	i = -1;
	free(p->philo);
	free(p->fork);
	free(p->thread);
	free(p);
}

void	ft_init_prog(int argc, char **argv, t_program *p)
{
	struct timeval	time;
	int				i;

	i = -1;
	p->n_phil = ft_atoi(argv[1]);
	p->t_die = ft_atoi(argv[2]);
	p->t_eat = ft_atoi(argv[3]);
	p->t_sleep = ft_atoi(argv[4]);
	p->num_eat = -1;
	if (argc == 6)
		p->num_eat = ft_atoi(argv[5]);
	p->thread = (pthread_t *)malloc(sizeof(pthread_t) * p->n_phil);
	p->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p->n_phil);
	while (++i < p->n_phil)
		pthread_mutex_init(&p->fork[i], NULL);
	pthread_mutex_init(&p->print, NULL); 
	pthread_mutex_init(&p->dead, NULL);
	pthread_mutex_init(&p->n_eat, NULL);
	pthread_mutex_init(&p->last_m, NULL);
	p->philo = (t_philo *)malloc(sizeof(t_philo) * p->n_phil);
	gettimeofday(&time, NULL);
	p->t_start = time.tv_sec;
	p->ut_start = time.tv_usec;
	p->muert = 0;
	p->all_eat = 0;
}

void	ft_init_fork(t_program *p, t_philo *philo)
{
	if (philo->id == philo->n_phil)
	{
		philo->my_fork = &p->fork[0];
		philo->fork_next = &p->fork[philo->id - 1];
	}
	else
	{
		philo->my_fork = &p->fork[philo->id - 1];
		philo->fork_next = &p->fork[philo->id];
	}
}

void	ft_init_philo(t_program *p)
{
	int	i;

	i = -1;
	while (++i < p->n_phil)
	{
		p->philo[i].n_phil = p->n_phil;
		p->philo[i].t_die = p->t_die;
		p->philo[i].t_eat = p->t_eat;
		p->philo[i].t_sleep = p->t_sleep;
		p->philo[i].num_eat = p->num_eat;
		p->philo[i].print = &p->print;
		p->philo[i].dead = &p->dead;
		p->philo[i].n_eat = &p->n_eat;
		p->philo[i].id = i + 1;
		p->philo[i].t_start = p->t_start;
		p->philo[i].ut_start = p->ut_start;
		p->philo[i].muert = &p->muert;
		p->philo[i].all_eat = &p->all_eat;
		p->philo[i].last = get_time(&p->philo[i]);
		p->philo[i].last_m = &p->last_m;
		ft_init_fork(p, &p->philo[i]);
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_program	*p;

	if (ft_check_args(argc, argv))
		return (1);
	i = -1;
	p = (t_program *)malloc(sizeof(t_program));
	ft_init_prog(argc, argv, p);
	ft_init_philo(p);
	while (++i < p->n_phil)
		pthread_create(&p->thread[i], NULL, &ft_routine, &p->philo[i]);
	if (ft_death_check(p))
		ft_freexit(p);
	return (0);
}
