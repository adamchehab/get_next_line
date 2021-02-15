#include <fcntl.h>
#include <stdio.h>
#include "../gnl_files/get_next_line.h"

int main()
{
	int i;
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);

	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("RETURN: %d | LINE: %s\n", i, line);
		free(line);
	}
	if (i == 0)
	{
		printf("RETURN: %d | LINE: %s\n", i, line);
		free(line);
	}

	close(fd);
	return (0);
}