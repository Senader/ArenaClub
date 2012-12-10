/*
** fight.c for day14 in /home/plassa_b//afs/folder/PersonnalProject/Fight
** 
** Made by clery1 plassat
** Login   <plassa_b@epitech.net>
** 
** Started on  Thu Oct 25 15:14:37 2012 clery1 plassat
** Last update Mon Dec 10 15:41:00 2012 clery1 plassat
*/

#include "project.h"
#include <unistd.h>

void	attack(t_all *all, t_char *first_char, t_char *second_char)
{
  srandom(time(0) * getpid());
  second_char->hp -= (random() % 20 + 41);
  if (second_char->hp > 0)
    {
      my_putstr(second_char->name);
      if (second_char->name[0] == 'Y')
	my_putstr(" have ");
      else
	my_putstr(" has ");
      my_put_nbr(second_char->hp);
      my_putstr(" life points left.\n");
    }
  put_ui_to_window(all);
  usleep(1000000);
  return ;
}

void	magic(t_all *all, t_char *first_char, t_char *second_char)
{
  srandom(time(0) * getpid());
  first_char->energy = first_char->energy - 40;
  second_char->hp = second_char->hp - (random() % 40 + 81);
  if (second_char->hp > 0)
    {
      my_putstr(second_char->name);
      if (second_char->name[0] == 'Y')
	my_putstr(" have ");
      else
	my_putstr(" has ");
      my_put_nbr(second_char->hp);
      my_putstr(" life points left.\n");
    }
  put_ui_to_window(all);
  usleep(1000000);
  return ;
}

void	potion(t_all *all, t_char *my_char)
{
  if (my_char->hp < my_char->hp_max - 80)
    my_char->hp = my_char->hp + (random() % 40 + 81);
  else if (my_char->hp < my_char->hp_max && my_char->hp > my_char->hp_max - 80)
    my_char->hp = my_char->hp_max;
  my_char->energy = my_char->energy - 40;
  my_putstr(my_char->name);
  my_putstr(" has ");
  my_put_nbr(my_char->hp);
  my_putstr(" life points left now.\n");
  put_ui_to_window(all);
  usleep(1000000);
  return ;
}


void	enemy_phase(t_all *all, t_char *first_char, t_char *second_char)
{
  int	option;
  int	ok;
  
  ok = 0;
  if (all->system.phase == 1)
    {
      put_ui_to_window(all);
      my_putchar('\n');
      my_putstr(first_char->name);
      my_putstr("'s turn !\n");

      /* Manage of meditation and regen_energyeration */

      if (first_char->meditate_last == 0)
	{
	  first_char->regen_energy = 10;
	  my_putstr("Meditation has now end\n");
	}
      if (first_char->meditate_last >= 0)
	--(first_char->meditate_last);
      if (first_char->energy >= 100 - first_char->regen_energy)
	first_char->energy == 100;
      else
	first_char->energy += first_char->regen_energy;
      put_ui_to_window(all);
      usleep(1000000);
      put_ui_to_window(all);

      /* Use of random to choose the bot command */

      srandom(time(0) * getpid());
      if (second_char->hp < 120 && first_char->energy >= 40)
	option = 2;
      else if (second_char->hp < 60 && first_char->energy < 40)
	option = 1;
      else if (first_char->hp >= first_char->hp_max / 3 * 2 && first_char->energy == 100)
	option = 2;
      else if (first_char->hp < first_char->hp_max / 3 * 2 && first_char->energy >= 40 
	       && first_char->meditate_last > 0)
	option = random() % 2 + 2;
      else if (first_char->hp >= first_char->hp_max / 3 * 2 && first_char->energy >= 40)
	{
	  option = random() % 3 + 2;
	  if (option == 3)
	    option = 2;
	}
      else if (first_char->hp < first_char->hp_max / 3 * 2 && first_char->energy >= 40)
	option = random() % 3 + 2;
      else if (first_char->energy >= 40 && first_char->meditate_last > 0)
	option = 2;
      else if (first_char->energy < 40)
	{
	  option = random() % 2 + 1;
	  if (option == 2)
	    option = 4;
	}

      /* Use of option variable to select the correct action */

      if (option == 1)
	{
	  my_putstr(first_char->name);
	  my_putstr(" attacks !\n");
	  put_ui_to_window(all);
	  usleep(1000000);
	  attack(all, first_char, second_char);
	  put_ui_to_window(all);
	  return ;
	}
      else if (option == 2 && first_char->energy >= 40)
	{
	  my_putstr(first_char->name);
	  my_putstr(" uses a special attack !\n");
	  put_ui_to_window(all);
	  usleep(1000000);
	  magic(all, first_char, second_char);
	  put_ui_to_window(all);
	  return ;
	}
      else if (option == 3 && first_char->hp < first_char->hp_max)
	{
	  my_putstr(first_char->name);
	  my_putstr(" heals himself !\n");
	  put_ui_to_window(all);
	  usleep(1000000);
	  potion(all, first_char);
	  put_ui_to_window(all);
	  return ;
	}
      else if (option == 4)
	{
	  my_putstr(first_char->name);
	  my_putstr(" uses meditation !\n");
	  first_char->regen_energy = 20;
	  first_char->meditate_last = 3;
	  put_ui_to_window(all);
	  usleep(1000000);
	  put_ui_to_window(all);
	  return ;
	}
    }
}
