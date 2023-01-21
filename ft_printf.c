#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// cspdiuxX flags mandatory
// %c - char
// %s - string 
// %p - memory address (The void * pointer argument has to be printed in hexadecimal format.)
// %d - decimal
// %i - integer
// %u - unsigned decimal
// %x - hexadecimal in lowercase
// %X - hexadecimal in uppercase
// %% - percent

// Bonus part flags
// {-} - left-justify (ex. %-10d) 
// {0} - used to zero-pad numeric output (ex. %010d)
// {#} - #x - hexadecimal and #o octal conversation (ex. %#x or %#o)
// { } - used to add a space before the output for positive numerical value (ex. % d)
// {+} - used to always include a sign for numerical output, 
//       whether positive or negative or right-justify (ex. %+d or %+10d)

char    check_flags()
{
    return (-1);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int     length;
    size_t  i;

    if(!str)
        return (0);
    va_start(args, str);
    while(str[i])
    {
        // if()
        write(1, &str[i], 1);
        i++;
    }
    va_end(args);
    return (length);
}

int main()
{
    // ft_printf("Hello");
    printf("%010000000000d\n", 1213123);
    return (0);
}