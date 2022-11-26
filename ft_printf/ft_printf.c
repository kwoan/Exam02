#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

int    s(char *str)
{
    int ret;

    ret = 0;
    if (!str)
        ret += write(1, "(null)", 6);
    else
        while (str[ret])
            write(1, &str[ret++], 1);
    return (ret);
}

int     d(int nbr, char *base)
{
    int ret = 0;

    if (nbr >= 10)
        ret += d(nbr / 10, base);
    ret += write(1, &base[nbr % 10], 1);
    return (ret);
}

int     x(int nbr, char *base)
{
    int ret = 0;

    if (nbr >= 16)
        ret += x(nbr / 16, base);
    ret += write(1, &base[nbr % 16], 1);
    return (ret);
}

int ft_printf(const char *format, ...)
{
    va_list arg;
    int     len;
    int     i;

    va_start(arg, format);
    len = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 's')
                len += s(va_arg(arg, char *));
            else if (format[i] == 'd')
                len += d(va_arg(arg, int), "0123456789");
            else if (format[i] == 'x')
                len += x(va_arg(arg, unsigned), "0123456789abcdef");
        }
        else
            len += write(1, &format[i], 1);
        i++;
    }
    va_end(arg);
    return (len);
}

int main()
{
    int a = printf("%x\n", 255);
    int b = ft_printf("%x\n", 255);
    printf("%d, %d", a, b);
}