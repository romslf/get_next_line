/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: romainlaforgue <romainlaforgue@student.    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 13:36:14 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 16:21:19 by romainlafor ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
    char		*buffer;
	static char	*tmp;
	int			readCnt;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
	if ((readCnt = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		add_to_tmp(&tmp, buffer, readCnt);
		if (!ft_linelen(tmp))
			return(get_next_line(fd, line));
		else
		{
			ft_extract(line, &tmp);
			return (1);
		}
	}
	else if (readCnt < BUFFER_SIZE)
	{
		ft_extract(line, &tmp);
		if (!tmp || !ft_strlen(tmp))
			return (0);
		return (1);
	}
	return (-1);
}

void	ft_extract(char **line, char **tmp)
{
	*line = extract_first_line(*tmp);
	*tmp = extract_last_lines(*tmp);
}

int main()
{
    const int fd = open("file.txt", O_RDONLY);
    char *st;
	char **str = &st;
	unsigned long i = 1;
    while (get_next_line(fd, str) == 1)
		printf("N°%zu: >%s< \n", i++, st);
	printf("N°%zu: >%s< \n", i++, st);
}