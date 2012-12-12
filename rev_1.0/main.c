/*
** main.c for graph in /home/bourco_v//folder/graph
** 
** Made by vincent bourcois
** Login   <bourco_v@epitech.net>
** 
** Started on  Thu Oct 25 09:45:12 2012 vincent bourcois
** Last update Wed Dec 12 11:07:22 2012 clery1 plassat
*/

#include <unistd.h>
#include <mlx.h>
#include <mlx_int.h>
#include <stdlib.h>
#include "project.h"

int	main()
{
  t_all	*all;
  int	(*expose_ptr)(t_all *);
  int	(*gere_key_ptr)(int, t_all *);
  
  expose_ptr = expose;
  gere_key_ptr = gere_key;
  all = malloc(sizeof(*all));
  all->system.mlx_p = malloc(sizeof(all->system.mlx_p));
  all->system.mlx_w = malloc(sizeof(all->system.mlx_w));
  all->system.mlx_p = mlx_init();
  all->system.mlx_w = mlx_new_window(all->system.mlx_p, 500, 500, "Window");
  all->system.phase = 0;
  all->system.cursor = 0;
  init_game(all);
  mlx_expose_hook(all->system.mlx_w, expose_ptr, all);
  mlx_key_hook(all->system.mlx_w, gere_key_ptr, all);
  mlx_loop(all->system.mlx_p);
}
