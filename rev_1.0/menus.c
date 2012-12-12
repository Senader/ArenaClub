/*
** menus.c for Arenaclub in /home/bourco_v//folder/projets/ArenaClub/ArenaClub
** 
** Made by vincent bourcois
** Login   <bourco_v@epitech.net>
** 
** Started on  Tue Dec 11 11:46:03 2012 vincent bourcois
** Last update Wed Dec 12 10:29:30 2012 clery1 plassat
*/

#include "project.h"

int	launch_menu(t_all *all)
{
  if (all->system.cursor == 0)
    {
      all->system.phase = 1;
      init_game(all);
      mlx_clear_window(all->system.mlx_p, all->system.mlx_w);
      put_ui_to_window(all);
    }
  if (all->system.cursor == 1)
    {
      
      see_stats(all);
    }
  if (all->system.cursor == 2)
    exit(1);
}

int	see_stats(t_all *all)
{
  all->system.phase = 4;
  mlx_clear_window(all->system.mlx_p, all->system.mlx_w);
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 225, 70, 0xFF1111, all->p1.name);
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 150, 115, 0xFFFFFF, "Energy : ");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 320, 115, 0xFFFFFF, int_to_char(all->p1.energy_max));
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 150, 150, 0xFFFFFF, "Healt points : ");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 320, 150, 0xFFFFFF, int_to_char(all->p1.hp_max));
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 150, 190, 0xFFFFFF, "Energy regen per turn : ");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 320, 190, 0xFFFFFF, int_to_char(all->p1.regen_base));
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 150, 230, 0xFFFFFF, "Damages : ");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 320, 230, 0xFFFFFF, int_to_char(all->p1.damages));
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 150, 270, 0xFFFFFF, "Healing : ");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 320, 270, 0xFFFFFF, int_to_char(all->p1.healing));
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 150, 310, 0xFFFFFF, "Level : ");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 320, 310, 0xFFFFFF, int_to_char(all->p1.lvl));
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 150, 350, 0xFFFFFF, "Experience : ");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 320, 350, 0xFFFFFF, int_to_char(all->p1.xp));
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 190, 475, 0xFFFFFF, "Press Space to quit");
}

int	menu(t_all *all)
{
  all->system.phase = 3;
  mlx_clear_window(all->system.mlx_p, all->system.mlx_w);
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 210, 200, 0xFFFFFF, "Fight a bot !");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 217, 475, 0xFFFFFF, "Press Enter");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 200, 250, 0xFFFFFF, "Go to the armory !");
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 210, 300, 0xFFFFFF, "Flee (coward)");
  if (all->system.cursor == 0)
    mlx_string_put(all->system.mlx_p, all->system.mlx_w, 210, 200, 0xFFFF00, "Fight a bot !");
  if (all->system.cursor == 1)
    mlx_string_put(all->system.mlx_p, all->system.mlx_w, 200, 250, 0xFFFF00, "Go to the armory !");
  if (all->system.cursor == 2)
    mlx_string_put(all->system.mlx_p, all->system.mlx_w, 210, 300, 0xFFFF00, "Flee (coward)");
}

int	menu_cursor(int key, t_all *all)
{
  if (all->system.phase == 3)
    {
      if (key == 32 || key == 65293)
	{
	  key = 0;
	  launch_menu(all);
	}
      if (key == 65362) // upper
	{
	  if (all->system.cursor == 0)
	    {
	      all->system.cursor = 2;
	      menu(all);
	    }
	  else
	    {
	      all->system.cursor -= 1;
	      menu(all);
	    }
	}
      if (key == 65364) // down
	{
	  if (all->system.cursor == 2)
	    {
	      all->system.cursor = 0;
	      menu(all);
	    }
	  else
	    {
	      all->system.cursor += 1;
	      menu(all);
	    }
	}
    }
}