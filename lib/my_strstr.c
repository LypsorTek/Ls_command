/*
** EPITECH PROJECT, 2023
** strstr
** File description:
** strstr
*/

int my_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[j]) {
            j++;
        } else {
            j = 0;
        }
        if (to_find[j] == '\0') {
            return 1;
        }
        i++;
    }
    return 0;
}