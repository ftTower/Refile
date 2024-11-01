#include "../include/refile.h"

void	print_file(t_file file)
{
	file_print_name(file);
	printf("\n");
	file_print_content(file);
}