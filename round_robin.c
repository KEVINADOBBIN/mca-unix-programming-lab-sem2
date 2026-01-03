#include <stdio.h>

int main() {
    int processes[] = {1, 2, 3};
    int n = 3;  // Number of processes
    int bt[] = {6, 3, 9}; // Burst times
    int qt = 3;  // Time quantum

    int wt[n], tat[n], total_wt = 0, total_tat = 0, t = 0;
    int rem_bt[n];

    // Initialize remaining burst times
    for(int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    // Round Robin algorithm
    while(1) {
        int done = 1;
        for(int i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                done = 0;
                if(rem_bt[i] > qt) {
                    t += qt;
                    rem_bt[i] -= qt;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if(done)
            break;
    }

    // Calculate turnaround times
    for(int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    // Print results
    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        printf("Process[%d]\t%d\t\t%d\t\t%d\n", processes[i], bt[i], tat[i], wt[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);

    return 0;
}
