#include <iostream>
using namespace std;
int ph[5];
int ch[5];

void signal(int w) {
    int r = (w + 1) % 5;
    ch[w] = 0;
    ch[r] = 0;
    ph[w] = 0;
}

void wait(int s) {
    int r = (s + 1) % 5;
    if (ph[s] == 0 && ph[r] == 0) {
        ph[s] = 1;
        ch[s] = 1;
        ch[r] = 1;
    } else if (ph[s] == 1) {
        cout << "Do you want philosopher " << s << " to stop eating? (Enter philosopher number): ";
        int w;
        cin >> w;
        signal(w);
    } else {
        cout << "Chopstick " << s << " & " << r << " are busy!" << endl;
        cout << "Philosopher " << s << " has to wait!" << endl;
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        ph[i] = 0;
        ch[i] = 0;
    }
    int u = 1; // Initialize u to 1 to enter the loop
    do {
        for (int i = 0; i < 5; i++) {
            if (ph[i] == 0) cout << "Philosopher " << i << " is Thinking" << endl;
            else cout << "Philosopher " << i << " is Eating" << endl;
        }

        int s;
        cout << "Who wants to eat: ";
        cin >> s;
        wait(s);

        cout << "Press 1 to continue: ";
        cin >> u;
    } while (u == 1);
    return 0;
}
