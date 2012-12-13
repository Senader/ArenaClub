/*
** main.c for graph in /home/bourco_v//folder/graph
** 
** Made by vincent bourcois
** Login   <bourco_v@epitech.net>
** 
** Started on  Thu Oct 25 09:45:12 2012 vincent bourcois
** Last update Thu Dec 13 12:21:45 2012 vincent bourcois
*/

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include <mlx_int.h>
#include <stdlib.h>
#include "project.h"

int	expose(t_all *all)
{
  if (all->system.phase == 1)
    put_ui_to_window(all);
  if (all->system.phase == 0)
    {
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 210, 250, 0xFFFFFF, "PRESS SPACE");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 450, 490, 0xFF0000, "rev 1.0"); 
    }
  if (all->system.phase == 2)
    end_phase(all, 1);
  if (all->system.phase == 42)
    {
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 165, 0xFF0000, "      AAAAAA   AAAAAA");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 180, 0xFF0000, "    SSSSSSSSSSSSSSSSSSS");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 195, 0xFF0000, "  TTTTTTTTTTTTTTTTTTTTTTT");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 210, 0xFF0000, " EEEEEEEEEEEEEEEEEEEEEEEEE");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 225, 0xFF0000, "KKKKKKKKKKKKKKKKKKKKKKKKKKK");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 240, 0xFF0000, "###########################");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 255, 0xFF0000, " EEEEEEEEEEEEEEEEEEEEEEEEE");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 270, 0xFF0000, "  NNNNNNNNNNNNNNNNNNNNNNN");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 285, 0xFF0000, "    CCCCCCCCCCCCCCCCCCC");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 300, 0xFF0000, "      UUUUUUUUUUUUUUU");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 315, 0xFF0000, "         LLLLLLLLL");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 165, 330, 0xFF0000, "            EEE");
    }
}

int	end_phase(t_all *all, int once)
{
  all->system.phase = 2;
  mlx_clear_window(all->system.mlx_p, all->system.mlx_w);
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 130, 480, 0xFFFFFF, "Press Escape to return to the menu");
  if (all->p1.hp > 0 && all->p2.hp <= 0)
    mlx_string_put(all->system.mlx_p, all->system.mlx_w, 215, 250, 0xFF00, "YOU WON");
  else
    mlx_string_put(all->system.mlx_p, all->system.mlx_w, 207, 250, 0xFF0000, "YOU LOOSE");
  if (all->p1.hp > 0 && all->p2.hp <= 0 && once == 0)
    {
      all->p1.xp += 100;
      if (all->p1.xp >= 500)
	{
	  all->p1.xp = 0;
	  ++(all->p1.lvl);
	  all->p1.damages += 15;
	  all->p1.healing += 15;
	  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 182, 300, 0xFFFF00, "YOU GAINED A LEVEL");
	}
      save(all);
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 215, 250, 0xFF00, "YOU WON");
    }
  else if (all->p1.hp <= 0 && all->p2.hp > 0 && once == 0)
    {
      all->p1.xp += 20;
      if (all->p1.xp >= 500)
	{
	  all->p1.xp = 0;
	  ++(all->p1.lvl);
	  all->p1.damages += 15;
	  all->p1.healing += 15;
	  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 182, 300, 0xFFFF00, "YOU GAINED A LEVEL");
	}
      save(all);
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 207, 250, 0xFF0000, "YOU LOOSE");
    }
  mlx_string_put(all->system.mlx_p, all->system.mlx_w, 170, 270, 0xFF0000, "Press space to restart");
}

int	gere_key(int key, t_all *all)
{
  int	x = 12;
  int	y;

  menu_cursor(key, all);
  start_cursor(key, all);
  if (key == 32)
    {
      if (all->system.phase == 0)
	{
	  all->system.phase = 3;
	  start(all);
	}
      if (all->system.phase == 4)
	menu(all);
      if (all->system.phase == 2)
	{
	  init_game(all);
	  all->system.phase = 1;
	  mlx_clear_window(all->system.mlx_p, all->system.mlx_w);
	  put_ui_to_window(all);
	}
    }
  if (all->system.phase == 0 && key == 269025053)
    {
      all->system.phase = 42;
      mlx_clear_window(all->system.mlx_p, all->system.mlx_w);
      while (x < 500)
	{
	  y = 0;
	  while (y < 500)
	    {
	      mlx_string_put(all->system.mlx_p, all->system.mlx_w, x, y,
			     0xFF0000, "ASTEK ENCULE !!!");
	      y += 15;
	    }
	  x += 102;
	}
    }
  if (key == 65307 && all->system.phase != 2 && all->system.phase != 4)
    exit(1);
  if (key == 65307 && (all->system.phase == 2 || all->system.phase == 4))
    menu(all);
  if (all->system.phase == 1)
    {
      if (key == 38)
	{
	  attack(all, &(all->p1), &(all->p2));
	  all->p1.energy += all->p1.regen_energy;
	  if (all->p1.meditate_last > 0)
	    all->p1.meditate_last -= 1;
	  if (all->p1.meditate_last == 0)
	    all->p1.regen_energy = all->p1.regen_base;
	  if (all->system.phase == 1)
	    {
	      clear_sides(all);
	      put_ui_to_window(all);
	      enemy_phase(all, &(all->p2), &(all->p1));
	      clear_sides(all);
	      put_ui_to_window(all);
	    }
	}
      if (key == 233)
	{
	  if (all->p1.energy >= 40)
	    {
	      magic(all, &(all->p1), &(all->p2));
	      all->p1.energy += all->p1.regen_energy;
	      if (all->p1.meditate_last > 0)
		all->p1.meditate_last -= 1;
	      if (all->p1.meditate_last == 0)
		all->p1.regen_energy = all->p1.regen_base;
	      if (all->system.phase == 1)
		{
		  clear_sides(all);
		  put_ui_to_window(all);
		  enemy_phase(all, &(all->p2), &(all->p1));
		  clear_sides(all);
		  put_ui_to_window(all);
		}
	    }
	  else
	    {
	      all->system.error_msg = 1;
	      put_ui_to_window(all);
	    }
	}
      if (key == 34)
	{
	  if (all->p1.energy >= 60)
	    {
	      potion(all, &(all->p1), &(all->p2));
	      all->p1.energy += all->p1.regen_energy;
	      if (all->p1.meditate_last > 0)
		all->p1.meditate_last -= 1;
	      if (all->p1.meditate_last == 0)
		all->p1.regen_energy = all->p1.regen_base;
	      if (all->system.phase == 1)
		{
		  clear_sides(all);
		  put_ui_to_window(all);
		  enemy_phase(all, &(all->p2), &(all->p1));
		  clear_sides(all);
		  put_ui_to_window(all);
		}
	    }
	  else
	    {
	      all->system.error_msg = 1;
	      put_ui_to_window(all);
	    }
	}
      if (key == 39)
	{
	  all->p1.energy += all->p1.regen_energy;
	  all->p1.regen_energy = all->p1.regen_base * 2;
	  all->p1.meditate_last = 3;
	  if (all->system.phase == 1)
	    {
	      clear_sides(all);
	      put_ui_to_window(all);
	      enemy_phase(all, &(all->p2), &(all->p1));
	      clear_sides(all);
	      put_ui_to_window(all);
	    }
	}
    }
}

int	clear_sides(t_all *all)
{
  void	*mlx_clear;
  int	x;
  int	y;

  mlx_clear = mlx_new_image(all->system.mlx_p, 500, 318);
  mlx_put_image_to_window(all->system.mlx_p, all->system.mlx_w, mlx_clear, 0, 42);  
}

int	put_ui_to_window(t_all *all)
{
  void	*mlx_i;
  int	x = 0;
  int	y = 0;
  int	i;

  if (all->system.phase == 1)
    {
      if (all->p1.energy > all->p1.energy_max)
	all->p1.energy = all->p1.energy_max;
      if (all->p1.energy < 0)
	all->p1.energy = 0;
      if (all->p2.hp > all->p2.hp_max)
	all->p2.hp = all->p2.hp_max;
      if (all->p2.hp < 0)
	all->p1.energy = 0;
      if (all->p1.hp > all->p1.hp_max)
	all->p1.hp = all->p1.hp_max;
      if (all->p1.hp < 0)
	all->p1.hp = 0;
      if (all->p2.energy > all->p2.energy_max)
	all->p2.energy = all->p2.energy_max;
      if (all->p2.energy < 0)
	all->p2.energy = 0;
      mlx_i = mlx_new_image(all->system.mlx_p, 500, 140);
      while (x < 500)
	{
	  mlx_pixel_put_to_image(mlx_i, x, y, 0xFFFFFF);
	  mlx_pixel_put_to_image(mlx_i, x, y + 20, 0xFFFFFF);
	  mlx_pixel_put_to_image(mlx_i, x, y + 40, 0xFFFFFF);
	  mlx_pixel_put_to_image(mlx_i, x, y + 90, 0xFFFFFF);
	  mlx_pixel_put_to_image(mlx_i, x++, y + 139, 0xFFFFFF);
	}
      x = 0;
      while (y < 140)
	{
	  mlx_pixel_put_to_image(mlx_i, x, y, 0xFFFFFF);
	  if (y > 40)
	    mlx_pixel_put_to_image(mlx_i, x + 250, y, 0xFFFFFF);
	  mlx_pixel_put_to_image(mlx_i, x + 499, y++, 0xFFFFFF);
	}
      y = 0;
      while ((all->p1.energy * 5) > x && x < 501)
	{
	  i = 21;
	  while (i < 40)
	    mlx_pixel_put_to_image(mlx_i, x, y + i++, 0xFFFF00);
	  ++x;
	}
      x = 0;
      while ((all->p1.hp / 2) > x && x < 501)
	{
	  i = 1;
	  while (i < 20)
	    mlx_pixel_put_to_image(mlx_i, x, y + i++, 0xFF0000);
	  ++x;
	}
      put_enemy_ui(all);
      mlx_put_image_to_window(all->system.mlx_p, all->system.mlx_w, mlx_i, 0, 360);
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 230, 52, 0xFF0000, "ENEMY");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 200, 355, 0x00FFFF, "PLAYER (aka you)");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 85, 427, 0xFFFFFF, "Attack  [1]");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 320, 420, 0xFFFFFF, "Special punch  [2]");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 65, 470, 0xFFFFFF, "Use a bandage  [3]");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 83, 485, 0xFFFF00, "60 energy");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 335, 435, 0xFFFF00, "40 energy");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 335, 476, 0xFFFFFF, "Meditation  [4]");
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 240, 395, 0x555555, int_to_char(all->p1.energy));
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 237, 375, 0x555555, int_to_char(all->p1.hp));
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 235, 15, 0x555555, int_to_char(all->p2.energy));
      mlx_string_put(all->system.mlx_p, all->system.mlx_w, 232, 35, 0x555555, int_to_char(all->p2.hp));
      if (all->p1.meditate_last == 3)
	mlx_string_put(all->system.mlx_p, all->system.mlx_w, 350, 350, 0xFFFFFF, "Meditation, 3 turns left");
      if (all->p1.meditate_last == 2)
	mlx_string_put(all->system.mlx_p, all->system.mlx_w, 350, 350, 0xFFFFFF, "Meditation, 2 turns left");
      if (all->p1.meditate_last == 1)
	mlx_string_put(all->system.mlx_p, all->system.mlx_w, 350, 350, 0xFFFFFF, "Meditation, 1 turns left");
      if (all->p2.meditate_last == 3)
	mlx_string_put(all->system.mlx_p, all->system.mlx_w, 20, 70, 0xFFFFFF, "Meditation, 3 turns left");
      if (all->p2.meditate_last == 2)
	mlx_string_put(all->system.mlx_p, all->system.mlx_w, 20, 70, 0xFFFFFF, "Meditation, 2 turns left");
      if (all->p2.meditate_last == 1)
	mlx_string_put(all->system.mlx_p, all->system.mlx_w, 20, 70, 0xFFFFFF, "Meditation, 1 turns left");
      if (all->system.error_msg == 1)
	mlx_string_put(all->system.mlx_p, all->system.mlx_w, 50, 250, 0xFF0000, "Not enough energy");
      all->system.error_msg = 0;
    }
  if (all->p2.hp <= 0 || all->p1.hp <= 0)
    end_phase(all, 0);
}

int	init_game(t_all *all)
{  
  int	fd;
  int	i = 0;
  int	j;
  char	*file;
  char	*value;

  fd = open("save.svg", O_RDONLY);
  if (fd == -1)
    {
      printf("Failed to load the save file.\n");
      return (-1);
    }
  file = getfile(fd);
  all->p1.name = malloc(sizeof(all->p1.name) * 25);
  value = malloc(sizeof(*value) * 6);
  while (file[i] != '\n')
    all->p1.name[i] = file[i++];
  all->p1.name[i++] = '\0';
  j = 0;
  while (file[i] != '\n')
    value[j++] = file[i++];
  value[j] = '\0';
  ++i;
  all->p1.energy = my_getnbr(value);
  all->p1.energy_max = all->p1.energy;
  j = 0;
  while (file[i] != '\n')
    value[j++] = file[i++];
  value[j] = '\0';
  ++i;
  all->p1.hp = my_getnbr(value);
  all->p1.hp_max = all->p1.hp;
  j = 0;
  while (file[i] != '\n')
    value[j++] = file[i++];
  value[j] = '\0';
  ++i;
  all->p1.meditate_last = 0;
  all->p1.regen_energy = my_getnbr(value);
  all->p1.regen_base = all->p1.regen_energy;
  j = 0;
  while (file[i] != '\n')
    value[j++] = file[i++];
  value[j] = '\0';
  ++i;
  all->p1.xp = my_getnbr(value);
  j = 0;
  while (file[i] != '\n')
    value[j++] = file[i++];
  value[j] = '\0';
  ++i;
  all->p1.lvl = my_getnbr(value);
  j = 0;
  while (file[i] != '\n')
    value[j++] = file[i++];
  value[j] = '\0';
  ++i;
  all->p1.damages = my_getnbr(value);
  j = 0;
  while (file[i] != '\n')
    value[j++] = file[i++];
  value[j] = '\0';
  ++i;
  all->p1.healing = my_getnbr(value);
  j = 0;
  while (file[i] != '\n')
    value[j++] = file[i++];
  value[j] = '\0';
  ++i;
  all->p1.crit = my_getnbr(value);
  close(fd);
  if (all->p1.crit == 0)
    all->p1.crit = 7;

  all->p2.name = malloc(sizeof(all->p2.name) * 6);
  all->p2.name = "Enemy";
  all->p2.energy = 100;
  all->p2.energy_max = 100;
  all->p2.hp = 1000;
  all->p2.hp_max = 1000;
  all->p2.damages = 40;
  all->p2.healing = 40;
  all->p2.meditate_last = 0;
  all->p2.regen_energy = 10;  
  all->p2.regen_base = 10;  
  all->p2.xp = 0;
  all->p2.crit = 7;
}

int	put_enemy_ui(t_all *all)
{
  void	*mlx_j;
  int	x = 0;
  int	y = 0;
  int	i;

  mlx_j = mlx_new_image(all->system.mlx_p, 500, 50);
  while (x < 500)
    {
      mlx_pixel_put_to_image(mlx_j, x, y, 0xFFFFFF);
      mlx_pixel_put_to_image(mlx_j, x, y + 20, 0xFFFFFF);
      mlx_pixel_put_to_image(mlx_j, x++, y + 40, 0xFFFFFF);
    }
  x = 0;
  while (y < 40)
    {
      mlx_pixel_put_to_image(mlx_j, x, y, 0xFFFFFF);
      mlx_pixel_put_to_image(mlx_j, x + 499, y++, 0xFFFFFF);
    }
  y = 0;
  while ((all->p2.hp / 2) > x && x < 501)
    {
      i = 21;
      while (i < 40)
	mlx_pixel_put_to_image(mlx_j, x, y + i++, 0xFF0000);
      ++x;
    }
  x = 0;
  while ((all->p2.energy * 5) > x && x < 501)
    {
      i = 1;
      while (i < 20)
	mlx_pixel_put_to_image(mlx_j, x, y + i++, 0xFFFF00);
      ++x;
    }
  mlx_put_image_to_window(all->system.mlx_p, all->system.mlx_w, mlx_j, 0, 0);
}

void	mlx_pixel_put_to_image(void *img, int x, int y, unsigned long color)
{
  char	*data;
  int	bpp;
  int	sizeline;
  int	endian;
  int	i;
 
  data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
  i = x * 4 + y * sizeline;
  data[i] = color % 256;
  color /= 256;
  data[i + 1] = color % 256;
  color /= 256;
  data[i + 2] = color % 256;
  color /= 256;
  data[i + 3] = 0;
  color /= 256;
}

int	save(t_all *all)
{
  int	fd;
  char	x;

  fd = open("save.svg", O_WRONLY);
  if (fd == -1)
    {
      printf("Failed to save char.\n");
      return (-1);
    }
  x = '\n';
  write(fd, all->p1.name, my_strlen(all->p1.name));
  write(fd, &x, 1);
  write(fd, int_to_char(all->p1.energy_max), my_strlen(int_to_char(all->p1.energy_max)));
  write(fd, &x, 1);
  write(fd, int_to_char(all->p1.hp_max), my_strlen(int_to_char(all->p1.hp_max)));
  write(fd, &x, 1);
  write(fd, int_to_char(all->p1.regen_base), my_strlen(int_to_char(all->p1.regen_base)));
  write(fd, &x, 1);
  write(fd, int_to_char(all->p1.xp), my_strlen(int_to_char(all->p1.xp)));
  write(fd, &x, 1);
  write(fd, int_to_char(all->p1.lvl), my_strlen(int_to_char(all->p1.lvl)));
  write(fd, &x, 1);
  write(fd, int_to_char(all->p1.damages), my_strlen(int_to_char(all->p1.damages)));
  write(fd, &x, 1);
  write(fd, int_to_char(all->p1.healing), my_strlen(int_to_char(all->p1.healing)));
  write(fd, &x, 1);
  write(fd, int_to_char(all->p1.crit), my_strlen(int_to_char(all->p1.crit)));
  write(fd, &x, 1);
  close(fd);
  return (0);
}
