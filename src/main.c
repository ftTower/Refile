#include "../include/refile.h"

// 		struct stat file_stat;
//     if (stat("example.txt", &file_stat) == 0) {
//         time_t creation_time = file_stat.st_ctime;
//         printf("Creation time: %s", ctime(&creation_time));
//     } else {
//         perror("stat");
//     }
//     return 0;

int	main(void)
{
	t_file *file;

	file = get_file("db test", "/home/tower/Refile/test.txt", O_RDONLY);

	display_file(*file, DISPLAY_LIGHT);

	free_vector_content(file->content);
	free(file);
	return (0);
}