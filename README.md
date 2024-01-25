# Printf

This project is an implementation of the C `printf` function in C. The `printf` function in C is used to print formatted output to the standard output (stdout). This implementation aims to mimic the functionality and behavior of the standard `printf` function while providing insights into how it works under the hood.

## Features
- Format specifiers: `%d`, `%s`, `%c`, `%i`, `%x`, `%X`, `%u`, `%p`, `%%`
- Width and precision specifiers
- Variable argument list handling (`va_list`, `va_start`, `va_arg`, `va_end`)

## Usage
To use this `printf` implementation in your C projects, simply include the `ft_printf.h` header file and link with the `ft_printf.c`, `ft_printf_helpers.c` source files.

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "world");
    ft_printf("The answer is %d\n", 42);
    return (0);
}
```

## Contributors
- [Arsen Badalyan](https://github.com/arsenbadalyan)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
