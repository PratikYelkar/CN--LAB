#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Define the maximum window size and the total number of frames
const int MAX_WINDOW_SIZE = 4;
const int TOTAL_FRAMES = 10;
int main()
{
    int windowSize;
    int totalFramesSent = 0;
    cout << "\n\n\n\t\t ========== SELECTIVE REPEAT ARQ ============\n\n\n";
    cout << "--> Enter window size: ";
    cin >> windowSize;
    vector<bool> acknowledged(TOTAL_FRAMES, false);
    srand(time(0)); // Seed the random number generator
    cout << "\n-->Simulating Selective Repeat ARQ:\n\n";
    while (totalFramesSent < TOTAL_FRAMES)
    {
        cout << "Sender's Window: ";
        // Send frames within the current window
        for (int i = totalFramesSent; i < min(totalFramesSent + windowSize, TOTAL_FRAMES); i++)
        {
            if (!acknowledged[i])
            {
                cout << i << " ";
                // Simulate frame transmission and random acknowledgment
                if (rand() % 2 == 0)
                {
                    acknowledged[i] = true;
                    cout << "(Sent) ";
                }
            }
        }
        cout << "\nReceiver's Window: ";
        // Simulate receiver's acknowledgment
        for (int i = totalFramesSent; i < min(totalFramesSent + windowSize, TOTAL_FRAMES); i++)
        {
            if (acknowledged[i])
            {
                cout << i << " ";
            }
        }
        cout << "\n\n";
        // Move the window
        totalFramesSent += windowSize;
    }
    cout << "\n\n\t\t!!! All frames have been sent and acknowledged. !!!\n\n\n";
    return 0;
}
