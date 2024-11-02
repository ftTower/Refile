#include "../include/refile.h"

	// 	struct stat file_stat;
    // if (stat("example.txt", &file_stat) == 0) {
    //     time_t creation_time = file_stat.st_ctime;
    //     printf("Creation time: %s", ctime(&creation_time));
    // } else {
    //     perror("stat");
    // }
    // return 0;

int	main(void)
{
	t_file *file, *file2;

	file = get_file("test.txt", "/home/tower/Refile/test.txt", O_RDONLY);
	file2 = get_file("test copy.txt", "/home/tower/Refile/test copy.txt", O_RDONLY);

	display_file(file, DISPLAY_LIGHT);
	display_file(file2, DISPLAY_LIGHT);

	free_file(file), free_file(file2);
	return (0);
}