/*
** fdf.c for fdf in /home/plassa_b//afs/folder/piscine/functions/Igraph/FDF
** 
** Made by clery1 plassat
** Login   <plassa_b@epitech.net>
** 
** Started on  Wed Dec  5 12:00:33 2012 clery1 plassat
** Last update Mon Dec 10 15:51:10 2012 clery1 plassat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char	*getfile(int fd)
{
  int	i;
  int	ret;
  char	str[2];
  char	*buffer;
  char	*temp;

  i = 0;
  while ((ret = read(fd, str, 1)) > 0)
    {
      temp = malloc(sizeof(*temp) * (5 + i));
      if (temp == NULL)
	exit(0);
      if (i > 0)
	my_strcpy(temp, buffer);
      buffer = malloc(sizeof(*buffer) * (5 + i));
      if (buffer == NULL)
	exit(0);
      my_strcpy(buffer, temp);
      buffer[i] = str[0];
      ++i;
    }
  if (ret == -1)
    return (NULL);
  buffer[i] = '\0';
  return (buffer);
}
