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

	file = get_file("/home/tower/Refile/test_files/test.txt", O_RDONLY);
	file2 = get_file("/home/tower/Refile/test_files/essai.txt", O_RDONLY);

	display_file(file, DISPLAY_LIGHT);
	display_file(file2, DISPLAY_LIGHT);

	free_file(file), free_file(file2);
	return (0);
}