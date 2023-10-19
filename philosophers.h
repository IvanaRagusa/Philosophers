/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:29:26 by iragusa           #+#    #+#             */
/*   Updated: 2023/06/28 20:29:27 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stddef.h>

typedef struct s_philo
{
	int				n_phil;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_eat;
	int				id;
	int				*muert;
	int				*all_eat;
	long int		last;
	pthread_mutex_t	*my_fork;
	pthread_mutex_t	*fork_next;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*n_eat;
	pthread_mutex_t	*last_m;
	time_t			t_start;
	suseconds_t		ut_start;
}	t_philo;

typedef struct s_program
{
	int				n_phil;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_eat;
	int				muert;
	int				all_eat;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_mutex_t	n_eat;
	pthread_mutex_t	last_m;
	t_philo			*philo;
	time_t			t_start;
	suseconds_t		ut_start;
}	t_program;

/*file: utils.c*/
void		ft_print_status(t_philo *philo, char c);
int			ft_atoi(const char *str);
int			ft_check_args(int argc, char **argv);
long int	get_time(t_philo *philo);
int			ft_death_check(t_program *p);

/*file: actions.c*/
void		*ft_routine(void *arg);
void		ft_eat(t_philo *philo);
void		ft_time_toaction(t_philo *philo, int t_type);

/*file: philosophers.c*/
void		ft_init_fork(t_program *p, t_philo *philo);
void		ft_init_philo(t_program *p);
void		ft_init_prog(int argc, char **argv, t_program *p);
#endif