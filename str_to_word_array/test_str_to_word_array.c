/*
** EPITECH PROJECT, 2022
** 
** File description:
** 
*/

#include <criterion/criterion.h>

char **str_to_word_array(char const * const str, char const * const separators);

char const * const basic_words = "   Word1 Word2   Word3  ";

Test(str_to_word_array, null_params)
{
    cr_assert(str_to_word_array("", "") == NULL);
}

Test(str_to_word_array, single_separator)
{
    char **array = str_to_word_array(basic_words, " ");

    cr_assert_str_eq(array[0], "Word1");
    cr_assert_str_eq(array[1], "Word2");
    cr_assert_str_eq(array[2], "Word3");
}

Test(str_to_word_array, muliple_separators)
{
    char const * const only_second_sep = "//Word1//Word2///Word3/";
    char const * const mixed_sep = "/ / Word1 // Word2 Word3 / // ";
    char **array = str_to_word_array(only_second_sep, " /");
    
    cr_assert_str_eq(array[0], "Word1");
    cr_assert_str_eq(array[1], "Word2");
    cr_assert_str_eq(array[2], "Word3");

    array = str_to_word_array(mixed_sep, " /");
    cr_assert_str_eq(array[0], "Word1");
    cr_assert_str_eq(array[1], "Word2");
    cr_assert_str_eq(array[2], "Word3");
}
