#include <stdio.h>

int main() {
    // Initial state is 0000 (q0 q1 q2 q3)
    // q0 = first flip-flop, q3 = last flip-flop
    int q0 = 0, q1 = 0, q2 = 0, q3 = 0;

    // Counts how many clock ticks it takes to come back to 0000
    int count = 0;

    printf("Present State -> Next State\n");

    do {
        // Next-state values (all flip-flops change at the same time,
        // so we calculate them from the OLD values first)
        int n0 = !q3;   // D0 = Q3 bar (the feedback wire)
        int n1 = q0;    // D1 = Q0
        int n2 = q1;    // D2 = Q1
        int n3 = q2;    // D3 = Q2

        // Print present state and next state
        printf("    %d%d%d%d      ->    %d%d%d%d\n",
               q0, q1, q2, q3, n0, n1, n2, n3);

        // Clock tick: copy the next-state values into the flip-flops
        q0 = n0;
        q1 = n1;
        q2 = n2;
        q3 = n3;

        // One clock tick done
        count++;

    // Keep going until we are back at the initial state 0000
    } while (!(q0 == 0 && q1 == 0 && q2 == 0 && q3 == 0));

    printf("\nNumber of distinct states = %d\n", count);
    return 0;
}
