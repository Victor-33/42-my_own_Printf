# 42 Cursus - Project: Printf
<img src="https://game.42sp.org.br/static/assets/achievements/ft_printfe.png" alt="Printf">
This project is originally from 42 École and the development was created following their rules. Recreates the original 'Printf' function.

* **The mandatory part requires the use of the following formats specifiers** - `cspdiuxX%`

-character (%c) type input variable;

-string (%s) type input variable;

-**pointer** (`%p`) type input variable.

-**int** (`%i` and `%d`) and **unsigned int** (`%u`)type input variables;

-**lower** (`%x`) and **upper hexadecimal** (`%X`) type input variables;

-percent (%%) character.

### Instructions

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

**Usage**

Include its header:

```C
#include "ft_printf.h"
```

and, when compiling your code, add the required flags:

```shell
-lftprintf -L path/to/libftprintf.a -I path/to/ft_printf.h
```

This project will only be validated if its behavior is the same as the original Printf. It's all right here. :)
