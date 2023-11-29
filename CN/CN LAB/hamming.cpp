#include <iostream>
using namespace std;

// Function to generate the Hamming code

void generateHammingCode(int dataBits[], int m)
{
    int r = 0; // Number of redundant bits needed

    // Calculate the number of redundant bits needed (r)
    while ((1 << r) < (m + r + 1))
    {
        r++;
    }

    int hammingCode[m + r] = {0};

    // Copy data bits to their positions in the Hamming code
    int j = 0;
    for (int i = 1; i <= m + r; i++)
    {
        if ((i & (i - 1)) == 0)
        {
            // Skip redundant bit positions
            hammingCode[i - 1] = 0;
        }
        else
        {

            hammingCode[i - 1] = dataBits[j++];
        }
    }

    // Calculate parity bits
    for (int i = 0; i < r; i++)
    {
        int parityPos = (1 << i);
        int parityBit = 0;
        for (int j = parityPos; j <= m + r; j++)
        {
            if ((j & parityPos) != 0)
            {
                parityBit ^= hammingCode[j - 1];
            }
        }

        hammingCode[parityPos - 1] = parityBit;
    }

    std::cout << "Data Bits: ";
    for (int i = m - 1; i >= 0; i--)
    {
        std::cout << dataBits[i] << " ";
    }

    std::cout << "\nHamming Code: ";
    for (int i = m + r - 1; i >= 0; i--)
    {
        std::cout << hammingCode[i] << " ";
    }
}

int main()
{

    int n;

    cout << "enter the length of data";
    cin >> n;
    int dataBits[n];

    cout << "enter the data bits";
    for (int i = n - 1; i >= 0; i--)
    {

        cin >> dataBits[i];
    }

    // Replace with your data bits

    int m = sizeof(dataBits) / sizeof(dataBits[0]);
    generateHammingCode(dataBits, m);

    return 0;
}

/*
enter the length of data6
enter the data bits1
2
3
1
1
1
Data Bits: 1 2 3 1 1 1
Hamming Code: 1 2 3 3 1 1 3 1 2 1
--------------------------------
Process exited after 9.105 seconds with return value 0
Press any key to continue . . .
/*
