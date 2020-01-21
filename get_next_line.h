/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 15:56:46 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:47:48 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*extract_last_lines(char *str);
char	*extract_first_line(char *str);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_extract(char **line, char **tmp);
void	add_to_tmp(char **tmp, char *str);
size_t	ft_linelen(char *str);
size_t	ft_strlen(char *str);

#endif
