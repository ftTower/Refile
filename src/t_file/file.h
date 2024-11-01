#ifndef FILE_H
# define FILE_H

t_file 				*create_file(void);
t_file 				*get_file(char *name, char *path, int permissions);

void				file_print_name(t_file file);
void				file_print_content(t_file file, ssize_t size);

void				display_file(t_file file, t_display_lvl level);


#endif