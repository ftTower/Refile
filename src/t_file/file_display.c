#include "../include/refile.h"

void	print_file(t_file file)
{
	file_print_name(file);
	printf(" ");
	file_print_content(file, 2);
}

void	display_file(t_file file, t_display_lvl level)
{
	if (level == DISPLAY_LIGHT) {
		file_print_name(file);
		printf(" > ");
		file_print_content(file, 20);
	}
}