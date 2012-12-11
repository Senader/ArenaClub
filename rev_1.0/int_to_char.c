/*
** int_to_char.c for inttochar in /home/bourco_v//folder/projets/pkmn
** 
** Made by vincent bourcois
** Login   <bourco_v@epitech.net>
** 
** Started on  Thu Nov 22 20:25:07 2012 vincent bourcois
** Last update Mon Dec 10 15:37:04 2012 clery1 plassat
*/

#include <stdlib.h>

void	swap(char *c, char *d)
{
  char	k;

  k = *d;
  *d = *c;
  *c = k;
}

int	my_strlength(char *str)
{
  int	i;

  while (str[i] != '\0')
    i++;
  return (i);
}

char	*int_to_char(int nb)
{
  char	*result;
  int	i;
  int	j;

  result = malloc(sizeof(result));
  i = 0;
  while (nb / 10 != 0)
    {
      result[i++] = nb % 10 + 48;
      nb /= 10;
    }
  result[i++] = nb % 10 + 48;
  result[i] = '\0';
  i = 0;
  j = my_strlength(result) - 1;
  swap(&result[i++], &result[j--]);
  return (result);
}
