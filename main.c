/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "includes/my.h"

void checkdev(char *path_str, DIR *dir)
{
    if (dir == NULL) {
        if (my_strstr(path_str, "/dev") != NULL) {
            write(1, path_str, my_strlen(path_str));
            write(1, "\n", 1);
        } else {
            write(1, "cannot open directory\n", 23);
        }
        exit(1);
    }
}

void bouclecheckflag(char **av , int ac)
{
    for (int j = 0; j < ac; j++) {
        if (av[j][0] == '-') {
            checksecondlfag(av, j);
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 1) {
        my_ls(".");
    }
    if (ac == 2) {
        for (int i = 1; i < ac; i++) {
            checkflag(av, i);
        }
    }
    if (ac >= 3) {
        bouclecheckflag(av, ac);
    }
    return 0;
}
