/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: romainlaforgue <romainlaforgue@student.    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 15:56:46 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 16:16:34 by romainlafor ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 25
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
/* Not technically required, but needed on some UNIX distributions */
# include <sys/types.h>
# include <sys/stat.h>

int		get_next_line(int fd, char **line);
void	add_to_tmp(char **tmp, char *str, int readCnt);
size_t	ft_linelen(char *str);
size_t	ft_strlen(char *str);
void	ft_extract(char **line, char **tmp);
char	*extract_last_lines(char *str);
char	*extract_first_line(char *str);
void	*ft_memchr(const void *s, int c, size_t n);

#endif
