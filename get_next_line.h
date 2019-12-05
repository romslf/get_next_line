/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 15:56:46 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 19:15:53 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
/* Not technically required, but needed on some UNIX distributions */
# include <sys/types.h>
# include <sys/stat.h>

int		get_next_line(int fd, char **line);
size_t	line_is_complete(char **line);
size_t  count_lines(char *text);

#endif
