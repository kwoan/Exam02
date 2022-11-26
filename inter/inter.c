#include <unistd.h>

void    inter(char *s1, char *s2, int *ascii)
{
    int i = 0;
    while (s2[i])
    {
        if (ascii[(int)s2[i]] == 0)
            ascii[(int)s2[i]] = 1;
        i++;
    }
    i = 0;
    while (s1[i])
    {
        if (ascii[(int)s1[i]] == 1)
        {
            ascii[(int)s1[i]] = 2;
            write(1, &s1[i], 1);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    int ascii[255];

    if (ac == 3)
    {
        int i = 0;
        while (i < 255)
            ascii[i++] = 0;
        inter(av[1], av[2], ascii);
    }
    write(1, "\n", 1);
    return (0);
}