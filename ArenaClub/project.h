/*
** project.h for project in /home/bourco_v//folder/projets/pkmn
** 
** Made by vincent bourcois
** Login   <bourco_v@epitech.net>
** 
** Started on  Thu Nov 22 20:48:52 2012 vincent bourcois
** Last update Tue Dec 11 10:15:49 2012 clery1 plassat
*/

#ifndef PROJECT_H_
# define PROJECT_H_

typedef struct	s_character
{
  char	*name;
  int	energy;
  int	energy_max;
  int	hp;
  int	hp_max;
  int	regen_base;
  int	regen_energy;
  int	damages;
  int	healing;
  int	meditate_last;
  int	xp;
  int	lvl;
}t_char;

typedef struct	s_system
{
  void	*mlx_p;
  void	*mlx_w;
  int	error_msg;
  int	phase;
}t_sys;

typedef struct	s_all
{
  t_sys		system;
  t_char	p1;
  t_char	p2;
}t_all;


void	swap(char *, char *);
int	my_strlength(char *);
char	*int_to_char(int);
int	expose(t_all *all);
int	end_phase(t_all *all);
int	gere_key(int key, t_all *all);
char	*getfile(int fd);
int	put_ui_to_window(t_all *all);
int	init_game(t_all *all);
int	put_enemy_ui(t_all *all);
void	mlx_pixel_put_to_image(void *mlx_i, int x, int y, unsigned long color);

#endif
