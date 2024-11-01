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

	file = malloc(sizeof(t_file));
	file->name = "test file";

	file->content = create_vector_content(2);
	add_line_to_vector(file->content, "coucou");
	add_line_to_vector(file->content, "kakou");
	add_line_to_vector(file->content, "salut");
	add_line_to_vector(file->content, "salut");
	add_line_to_vector(file->content, "salut");
	add_line_to_vector(file->content, "salut");
	add_line_to_vector(file->content, "salut");
	add_line_to_vector(file->content, "salut");


	print_file(*file);

	free_vector_content(file->content);
	free(file);
	return (0);
}