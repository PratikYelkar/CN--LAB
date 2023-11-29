#include <iostream>
#include <bitset>
using namespace std;
// Compute parity of a number `x` using the lookup table
int findParity(int x)
{

    // recursively divide the (32–bit) integer into two equal

    // halves and take their XOR until only 1 bit is left
    x = (x & 0x0000FFFF) ^ (x >> 16);
    x = (x & 0x000000FF) ^ (x >> 8);
    x = (x & 0x0000000F) ^ (x >> 4);
    x = (x & 0x00000003) ^ (x >> 2);
    x = (x & 0x00000001) ^ (x >> 1);

    // return 1 if the last bit is set; otherwise, return 0
    return x & 1;
}

int main()
{

    int x = 127;
    cout << x << " in binary is " << bitset<8>(x) << endl;
    if (findParity(x))
    {
        cout << x << " contains odd bits";
    }
    else
    {
        cout << x << " contains even bits";
    }

    return 0;
}
