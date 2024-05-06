#include "cpp-code.h"

#include <stdio.h>

#include <map>
#include <string>

#include "stm32f1xx_hal.h"


extern int sbrk_call_counter;
extern int malloc_count;
extern int free_count;

void function_to_investigate()
{
    std::map<std::string, int> m;
    for (int i = 1; i <= 10; ++i)
    {
        m[std::to_string(i)] = i;
    }
}

void print_stat()
{
    // Some code here should print statistic of _sbrk, malloc, free usage
    printf("Calls => _sbrk: %d, malloc: %d, free: %d\r\n", sbrk_call_counter, malloc_count, free_count);
}

void cpp_code_entry_point()
{
    function_to_investigate();
    print_stat();
}
