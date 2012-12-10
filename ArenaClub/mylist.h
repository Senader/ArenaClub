/*
** list.h for day12 in /home/plassa_b/
** 
** Made by clery1 plassat
** Login   <plassa_b@epitech.net>
** 
** Started on  Tue Oct 23 09:04:54 2012 clery1 plassat
** Last update Wed Oct 24 15:50:11 2012 clery1 plassat
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
} t_list;

int		my_put_in_list(struct s_list **link, void *data);
void		my_show_list(struct s_list *list);
struct s_list	*my_params_in_list(int ac, char **av);
	
#endif
