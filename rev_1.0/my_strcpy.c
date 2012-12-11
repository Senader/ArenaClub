/*
** my_strcpy.c for my_strcpy in /home/plassa_b//afs/folder/day06
** 
** Made by clery1 plassat
** Login   <plassa_b@epitech.net>
** 
** Started on  Mon Oct  8 09:18:37 2012 clery1 plassat
** Last update Fri Oct 12 11:58:10 2012 clery1 plassat
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
