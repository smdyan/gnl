#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char	*str;
	int		n;
	int		fd1;
	int		fd2;
	char	path1[] = "/Users/lily/gnl/gnl_src/file1.txt";
	char	path2[] = "/Users/lily/gnl/gnl_src/file2.txt";

	fd1 = open(path1, O_RDONLY);
	if (fd1 == -1)
		printf("file not found");
	fd2 = open(path2, O_RDONLY);
	if (fd2 == -1)
		printf("file not found");
	printf("fd1=%d, fd2=%d\n", fd1, fd2);
	n = 1;
	while (n <= 6)
	{
		str = get_next_line(fd1);
		printf("%d. %s", n, str);
		free(str);
		n++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
