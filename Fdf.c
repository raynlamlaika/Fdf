#include "fdf.h"

char* takemap(int map)
{
	char	*oprt;
	char	*next;
	char	*tmpp;

	oprt = ft_strdup("");
	if (!oprt)
		return (free(oprt), NULL);
	next = get_next_line(map);
	while (next)
	{
		tmpp = oprt;
		oprt = ft_strjoin(oprt, next);
		if (!oprt)
			return (free(oprt), free(next), free(tmpp), NULL);
		free(tmpp);
		free(next);
		next = get_next_line(map);
	}
	return (oprt);
}

void intoarray(char** buffer)
{
	int	i;
	int	*array;

	i = 0;

	while (buffer[i])
	{
		printf("buffer :%s\n", buffer[i]);
		buffer[i] = ft_split(buffer[i], ' ');
		i++;
	}


}

int main(int ac, char**av, char**ev)
{
	int		*arraymap;
	char	*buffer;
	int		file;
	char	**mmap;

	file = open("map", O_RDONLY);
	buffer = takemap(file);
	if (!buffer)
		return(write(2,"error in the map string\n", 24), 0);
	mmap = ft_split(buffer, '\n');
	intoarray(mmap);
	return (0);
}