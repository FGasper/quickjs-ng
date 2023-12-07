#include <stdio.h>
#include <fenv.h>
#include <math.h>

int main()
{
    double d[] = {26, 25, 24};

    fesetround(FE_UPWARD);

    for (int i=0; i<sizeof(d) / sizeof(double); i++) {
            printf("round %f up w printf: %+.*e\n", d[i], 0, d[i]);
    }

    fesetround(FE_DOWNWARD);

    for (int i=0; i<sizeof(d) / sizeof(double); i++) {
            printf("round %f down w printf: %+.*e\n", d[i], 0, d[i]);
    }

    fesetround(FE_TONEAREST);

    for (int i=0; i<sizeof(d) / sizeof(double); i++) {
            printf("round %f to nearest w printf: %+.*e\n", d[i], 0, d[i]);
    }

    return 0;
}
