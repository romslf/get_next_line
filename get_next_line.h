/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 15:56:46 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 15:38:14 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_substrdup(char *s, unsigned long start, size_t len);
char	*ft_substr(char *s, unsigned long start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_memchr(char *s, long c, size_t n);
size_t	ft_strlen(char *str);
size_t	ft_linelen(char *str);

#endif
