#include <stdlib.h>
#include <string.h>

static int count_words(const char *str, const char *charset) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (strchr(charset, *str) != NULL) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++;
    }
    return count;
}

static char *copy_word(const char *start, int length) {
    char *word = (char *)malloc((length + 1) * sizeof(char));
    if (word) {
        strncpy(word, start, length);
        word[length] = '\0';
    }
    return word;
}

char **ft_split(const char *str, const char *charset)
{
    if (!str || !charset) return NULL;

    int word_count = count_words(str, charset);
    char **result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!result) return NULL;

    int index = 0;
    while (*str) {
        if (strchr(charset, *str) != NULL) {
            str++;
        } else {
            const char *start = str;
            int length = 0;
            while (*str && strchr(charset, *str) == NULL) {
                str++;
                length++;
            }
            result[index++] = copy_word(start, length);
        }
    }
    result[index] = NULL;
    return result;
}
