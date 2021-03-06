/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-korc <ael-korc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 07:34:00 by ael-korc          #+#    #+#             */
/*   Updated: 2022/04/17 21:30:57 by ael-korc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# define ERROR -1
# define IS_NOT_DIGIT -1
# define SUCCESS 0
# define INFINITE_LOOP -1
# define EVERY_ONE_HAS_EAT_ENOUGHT 5
# define THINKING 2
# define HUNGRY 1
# define EATING 0
# define NAP 3
# define REACHED_NUMBER_OF_MEALS_LIMIT -2
# define DIE 4

typedef struct s_philosopher
{
	long			time_last_meal;
	int				id;
	int				nb_meal;
	long			t_start;
	long			t_now;
	int				state;
	int				left;
	int				right;
	pthread_t		thread;
}					t_philosopher;

typedef struct s_info
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_philosopher	*philosopher;
	int				limit_nb_meal;
	long			time_actuel;
	int				philo_dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat;
	pthread_t		*ptr_thread_id;
	int				current_number_of_meals;

}					t_info;

t_info	g_info;

int					print_error(char *msg);
int					ft_atoi(const char *nptr);
int					str_is_digit(char *str);
int					parsing(int nb_arg, char **arg);
long				get_actuel_time(void);
void				*cycle_philosopher(void *ptr);
void				init_philosopher(t_philosopher philo[], int nb_philo);
int					check_is_alive(t_philosopher philosopher[]);
void				clear_semaphor(t_info *info);
int					init_mutex(pthread_mutex_t fork[]);
int					clear_mutex(void);
#endif
