/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 15:56:46 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 16:12:56 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 4
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
/* Not technically required, but needed on some UNIX distributions */
# include <sys/types.h>
# include <sys/stat.h>

int		get_next_line(int fd, char **line);
char	*remove_line_from_buff(char *buffer, char **line);
size_t	contain_line(char *str);
size_t	line_len(char *line);

#endif
