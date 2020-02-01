/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 15:56:46 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 16:17:16 by rolaforg    ###    #+. /#+    ###.fr     */
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
char	*extract_first_line(char const *s, unsigned int start, size_t len);
char	*ft_memchr(char *s, int c, size_t n);
int 	ft_extract(char **line, char **tmp, int index);
void	add_to_tmp(char **tmp, char *str);
size_t	ft_linelen(char *str);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);
char    *ft_substr(char *s, unsigned int start, size_t len);

#endif
