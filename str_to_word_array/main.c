/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>

char **str_to_word_array(char const * const, char const * const separators);

void free_2d_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        printf("%s\n", array[i]);
        free(array[i]);
    }
    free(array);
}

int main(void)
{
    char **words = str_to_word_array(" //  Word1 / / Word2 // Word3 // ", " /");
    free_2d_array(words);
    return 0;
}
