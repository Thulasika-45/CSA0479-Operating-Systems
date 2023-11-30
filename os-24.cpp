//24.. Develop a C program to simulate C-SCAN disk scheduling algorithm.

#include<stdio.h>
#include<stdlib.h>

void sortRequests(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void cscan(int requests[], int n, int start, int size) {
    sortRequests(requests, n);

    int seek_sequence[n + 3];
    int distance, cur_track = start;
    int total_count = 0;
    int head_movement = 0;
    int prev_track = -1;
    int direction = 1;

    seek_sequence[total_count++] = start;

    if (start > 0) {
        head_movement += start;
        cur_track = 0;
    }

    for (int i = 0; i < n; i++) {
        distance = abs(requests[i] - cur_track);
        head_movement += distance;
        seek_sequence[total_count++] = requests[i];
        cur_track = requests[i];
    }

    if (direction == 1 && cur_track < size - 1) {
        head_movement += size - 1 - cur_track;
        cur_track = size - 1;
    }

    direction = 0;
    head_movement += cur_track;

    for (int i = n - 1; i >= 0; i--) {
        distance = abs(requests[i] - cur_track);
        head_movement += distance;
        seek_sequence[total_count++] = requests[i];
        cur_track = requests[i];
    }

    printf("Seek Sequence: ");
    for (int i = 0; i < total_count; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\nTotal Head Movement: %d\n", head_movement);
}

int main() {
    int size, n, start;

    printf("Enter the size of the disk: ");
    scanf("%d", &size);

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter the starting position of the head: ");
    scanf("%d", &start);

    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    cscan(requests, n, start, size);

    return 0;
}

