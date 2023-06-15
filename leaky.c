#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/logging.h>

Test(leaky, leaky_test)
{
    int vector[3] = {1,2,3};
    int expected[3] = {1, 2, 3};

    cr_assert(eq(int[3], vector, expected));
}
