#include "../include/refile.h"

// ╔══════╗
// ║      ║
// ╠══════╣
// ║      ║
// ╚══════╝

const char *colors[] = {
    "\033[30m", // Noir
    "\033[31m", // Rouge
    "\033[32m", // Vert
    "\033[33m", // Jaune
    "\033[34m", // Bleu
    "\033[35m", // Magenta
    "\033[36m", // Cyan
    "\033[37m", // Blanc
    "\033[90m", // Gris
    "\033[91m", // Rouge clair
    "\033[92m", // Vert clair
    "\033[93m", // Jaune clair
    "\033[94m", // Bleu clair
    "\033[95m", // Magenta clair
    "\033[96m", // Cyan clair
    "\033[97m", // Blanc clair
    "\033[40m", // Arrière-plan noir
    "\033[41m", // Arrière-plan rouge
    "\033[42m", // Arrière-plan vert
    "\033[43m", // Arrière-plan jaune
    "\033[44m", // Arrière-plan bleu
    "\033[45m", // Arrière-plan magenta
    "\033[46m", // Arrière-plan cyan
    "\033[47m", // Arrière-plan blanc
    "\033[100m", // Arrière-plan gris
    "\033[101m", // Arrière-plan rouge clair
    "\033[102m", // Arrière-plan vert clair
    "\033[103m", // Arrière-plan jaune clair
    "\033[104m", // Arrière-plan bleu clair
    "\033[105m", // Arrière-plan magenta clair
    "\033[106m", // Arrière-plan cyan clair
    "\033[107m", // Arrière-plan blanc clair
    "\033[0m"   // Reset
};

void    print_format(char *line, size_t size, int color)
{
    if (color < 0 || color > 32)
        return ;
    size_t size_cmp = strlen(line);
    if (size_cmp <= size)
        printf("%s %s %s", colors[color],line, colors[32]);
    else
        printf("%s %s %s",colors[color], line + (size_cmp - size + 2), colors[32]);
}

void	file_print_name(t_file file)
{
	printf("%s📄%s", colors[27], colors[32]);
    print_format(file.name, 10, 27);
}

void	put_load_bar(size_t size, size_t v1, size_t v2)
{
    if (v2 == 0) {
        printf("Error: Division by zero\n");
        return;
    }
    double ratio = (double)v1 / (double)v2 * size;

    for (size_t i = 0; i < (size_t)ratio; i++)
        printf("%s%s%s", colors[17], " |", colors[32]);
    for(size_t i = ratio; i < size; i++)
        printf("%s%s%s", colors[18], " |", colors[32]);
}

void	file_print_content(t_file file, ssize_t size)
{
    if (file.content == NULL) {
        return (printf("%s 📁 %s", colors[28], colors[32]), put_load_bar(8, 0, 10), printf(" %s0    %s/%s0%s", colors[9], colors[32], colors[6],colors[32]),(void)NULL);
    }
	printf("%s 📁 %s", colors[28], colors[32]);
	put_load_bar(8, file.content->size, file.content->capacity);
       
    printf(" %s%-5zu%s/%s%-5zu%s", colors[9], file.content->size,colors[32], colors[6], file.content->capacity,colors[32]);
    if (size < 0)
        return (printf("\n"), (void)NULL);
    if (file.content->lines == NULL) {
        return (printf(" %s lines is NULL%s\n", colors[27], colors[32]), (void)NULL);
    }
}

void	file_print_path(t_file file, size_t size)
{
    if (!file.path || size <= 0)
        return ;
    size_t size_cmp = strlen(file.path);
    if (size_cmp <= size)
        printf("%s %s %s", colors[27],file.path, colors[32]);
    else
        printf("%s %s %s",colors[27], file.path + (size_cmp - size), colors[32]);
}

void	file_print_permissions()
{

}

void	file_print_fd()
{

}

void	file_print_is_open()
{

}

void	file_print_creation_time()
{

}

void	file_print_modification_time()
{

}

void	file_print_size()
{

}