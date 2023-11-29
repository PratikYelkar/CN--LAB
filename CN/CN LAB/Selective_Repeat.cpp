#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
    int nf, N;
    int no_tr = 0;
    srand(time(NULL));
    
    cout << "Enter the number of frames: ";
    cin >> nf;
    cout << "Enter the Window Size: ";
    cin >> N;
    
    int i = 1;
    while (i <= nf)
    {
        bool windowCorrupted = false; // Flag to track if any acknowledgment is corrupted in the window
        for (int j = i; j < i + N && j <= nf; j++)
        {
            cout << "Sent Frame " << j << endl;
            no_tr++;
        }
        for (int j = i; j < i + N && j <= nf; j++)
        {
            int flag = rand() % 2; // Simulate the ACK (0 for success, 1 for failure)
            if (!flag)
            {
                cout << "Acknowledgment for Frame " << j << " (Sent Frame " << j + N << ")" << endl;
            }
            else
            {
                cout << "Acknowledgment for Frame " << j << " is corrupted. Retransmitting Frame " << j << endl;
                windowCorrupted = true; // Set the flag to indicate acknowledgment corruption
            }
        }
        cout << endl;
        if (windowCorrupted)
        {
            cout << "Retransmitting Window" << endl;
        }
        i += N; // Move the window by the window size N
    }
    cout << "Total number of transmissions: " << no_tr << endl;
    return 0;
}


/*
Enter the number of frames: 10
Enter the Window Size: 4
Sent Frame 1
Sent Frame 2
Sent Frame 3
Sent Frame 4
Acknowledgment for Frame 1 is corrupted. Retransmitting Frame 1
Acknowledgment for Frame 2 is corrupted. Retransmitting Frame 2
Acknowledgment for Frame 3 is corrupted. Retransmitting Frame 3
Acknowledgment for Frame 4 (Sent Frame 8)

Retransmitting Window
Sent Frame 5
Sent Frame 6
Sent Frame 7
Sent Frame 8
Acknowledgment for Frame 5 (Sent Frame 9)
Acknowledgment for Frame 6 is corrupted. Retransmitting Frame 6
Acknowledgment for Frame 7 is corrupted. Retransmitting Frame 7
Acknowledgment for Frame 8 is corrupted. Retransmitting Frame 8

Retransmitting Window
Sent Frame 9
Sent Frame 10
Acknowledgment for Frame 9 is corrupted. Retransmitting Frame 9
Acknowledgment for Frame 10 (Sent Frame 14)

Retransmitting Window
Total number of transmissions: 10
--------------------------------
*/
