/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include <stddef.h>
#include <stdbool.h>

bool detect_separator(char const ch, char const * const separators)
{
    for (int i = 0; separators[i]; i++)
        if (separators[i] == ch)
            return true;
    return false;
}

bool find_word(int *i, char const * const str, char const * const separators)
{
    if (detect_separator(str[*i], separators))
        return false;
    while (detect_separator(str[*i], separators) == false) {
        (*i)++;
    }
    return true;
}

unsigned int count_words(char const * const str, char const * const separators)
{
    int nb_words = 0;

    for (int i = 0;str[i]; i++) {
        nb_words += find_word(&i, str, separators);
    }
    return nb_words;
}

char *extract_word(unsigned int *i, char const * const str, char const * const separators)
{
    int dup_len = 0;
    int dup_i = 0;
    char *dup = NULL;
    
    for (int tmp = *i; detect_separator(str[tmp], separators) == false; tmp++, dup_len++);
    dup = malloc(sizeof(char) * (dup_len + 1));
    if (dup == NULL)
        return NULL;
    for (; dup_i < dup_len; (*i)++, dup_i++)
        dup[dup_i] = str[*i];
    dup[dup_i] = '\0';
    return dup;

}

char **extract_words(char **words, char const * const str, char const * const separators)
{
    unsigned int word_i = 0;

    for (unsigned int i = 0; str[i]; i++) {
        if (detect_separator(str[i], separators) == true) 
            continue;
        words[word_i] = extract_word(&i, str, separators);
        if (words[word_i] == NULL)
            return NULL;
        word_i++;
    }
    words[word_i] = NULL;
    return words;
}

char **str_to_word_array(char const * const str, char const * const separators)
{
    unsigned int nb_words = count_words(str, separators);
    char **words = NULL;

    if (nb_words == 0)
        return NULL;
    words = malloc(sizeof(char *) * (nb_words + 1));
    if (words == NULL)
        return NULL;
    return extract_words(words, str, separators);
}