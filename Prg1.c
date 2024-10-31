#include <stdio.h>

void sortProcesses(int n, int burst_time[], int process_id[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst_time[i] > burst_time[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst_time[n], process_id[n], wait_time[n], turn_around_time[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        process_id[i] = i + 1;
    }

    // Sort processes by burst time
    sortProcesses(n, burst_time, process_id);

    wait_time[0] = 0;
    turn_around_time[0] = burst_time[0];

    for (i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
        turn_around_time[i] = wait_time[i] + burst_time[i];
    }

    // Display results
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", process_id[i], burst_time[i], wait_time[i], turn_around_time[i]);
    }

    return 0;
}

