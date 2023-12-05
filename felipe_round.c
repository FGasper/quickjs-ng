#include <stdio.h>
#include <fenv.h>
#include <math.h>

int main()
{
    double d = 25;

    fesetround(FE_UPWARD);

    printf("round %f up w printf: %+.*e\n", d, 0, d);

    return 0;
}
