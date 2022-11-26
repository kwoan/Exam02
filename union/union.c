#include <unistd.h>

int main(int ac, char **av)
{
    int ascii[255];
    int i;
    int j;

    if (ac == 3)
    {
        i = 0;
        while (i < 255)
            ascii[i++] = 0;
        i = 1;
        while (i < ac)
        {
            j = 0;
            while (av[i][j])
            {
                if (ascii[av[i][j]] == 0)
                {
                    ascii[av[i][j]] = 1;
                    write(1, &av[i][j], 1);
                }
                j++;
            }
            i++;
        }      
    }
    write(1, "\n", 1);
    return (0);
}