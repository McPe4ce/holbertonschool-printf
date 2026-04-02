# Printf Implementation

A simplified recreation of the standard C `printf()` function as part of the Holbertonschool curriculum.

## Table of Contents

- [Description](#description)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Supported Specifiers](#supported-specifiers)
- [Project Structure](#project-structure)
- [Examples](#examples)
- [Limitations](#limitations)
- [Compilation](#compilation)
- [Authors](#authors)

## Description

This project implements a custom `_printf()` function that mimics the behavior of the standard C library's `printf()` function. It provides a foundational understanding of variadic functions, format string parsing, and character output in C.

The implementation uses a modular approach with function pointers in a structure array to handle different format specifiers, making it extensible and maintainable.

## Requirements

- **Language**: C
- **Compiler**: GCC or compatible C compiler
- **OS**: Unix/Linux based systems
- **Standard**: C89/C90

## Installation

Clone the repository:

```bash
git clone https://github.com/McPe4ce/holbertonschool-printf.git
cd holbertonschool-printf
```

## Usage

### Compilation

To compile the project:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o printf_test
```

### Basic Usage

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("Character: %c\n", 'A');
    _printf("Percentage: %%\n");
    return (0);
}
```

## Supported Specifiers

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Character | `_printf("%c", 'A')` → `A` |
| `%s` | String | `_printf("%s", "Hello")` → `Hello` |
| `%%` | Percent sign | `_printf("%%")` → `%` |

## Project Structure

```
holbertonschool-printf/
├── main.h          # Header file with function prototypes and struct definition
├── printf.c        # Main implementation of _printf and format specifiers
├── _putchar.c      # Character output function using write()
└── README.md       # This file
```

### Key Components

- **`_printf()`**: Main function that processes the format string and variadic arguments
- **`_putchar()`**: Low-level function that writes a single character to stdout
- **`handle_specifier()`**: Routes format specifiers to appropriate handler functions
- **Handler functions**: `print_char()`, `longueprint2string()`, `print_pour2cent()`

## Examples

```c
#include "main.h"

int main(void)
{
    int count;
    
    count = _printf("String: %s\n", "Holbertonschool");
    _printf("Number of characters printed: %d\n", count);
    
    _printf("Char: %c, String: %s, Percent: %%\n", 'X', "test");
    
    return (0);
}
```

**Output:**
```
String: Holbertonschool
Number of characters printed: 26
Char: X, String: test, Percent: %
```

## Limitations

- Only supports `%c`, `%s`, and `%%` format specifiers
- Does not support width, precision, or flag modifiers
- Does not support integer conversion specifiers (`%d`, `%i`, `%x`, etc.)
- Does not support floating-point specifiers
- Null format strings return -1
- Trailing `%` without specifier returns -1

## Implementation Details

The implementation uses a structure-based dispatcher pattern:

```c
typedef struct type
{
    char specifier;
    int (*fn)(va_list *);
} typeuh;
```

This approach allows for:
- Easy addition of new format specifiers
- Clean separation of concerns
- Efficient specifier lookup and handling

## Return Value

The `_printf()` function returns:
- The total number of characters printed on success
- -1 on error (null format string or trailing %)

## Compilation Flags

Recommended compilation with strict flags for C89:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o program
```

## Authors

- **McPe4ce** - Primary developer
- **Giosue** - Collaborator

## License

This project is part of the Holbertonschool curriculum. Usage and distribution are subject to school guidelines.

---

**Last Updated**: 2026-04-02 14:32:48