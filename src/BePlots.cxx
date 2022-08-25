#include "BePlotsConfig.h"
#include "BePlots.h"
#include <TRandom3.h>

using namespace std;

int main(int argc, char *argv[])
{

    unsigned int seed = 111;
    TRandom3 *rnd = new TRandom3(seed);

    int n = 100;
    double *array = new double[n];

    rnd->RndmArray(n,array);
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << endl;
    }
}
