//Name: Paramveer Singh Bhele
//UNumber: U82076898
//Description : Project 3 - Task2
//first the program requires the user to input the number of people and their arrival times. The arrival times are then stored in an array.
//the total number of active seconds are calculated using the function.
//the arrival times are sorted in ascending order using two for loops and then comparing the values using a temporary variable.
//once in order, the arrival times are compared to the end active time. 
//if the arrival time is less than the end time then 10 seconds are added to ther end time from the current arrival time.
//else the total time is calculated by subtracting the start time from the end time.
//this is done in a loop so that then the code shifts onto the next arrival time if present.

#include <stdio.h>
// Function to calculate the number of active seconds of the escalator.
int active_seconds(int arrival[], int n) {
  // Initialize the total number of active seconds.
  int total_active_time = 0;
  // Sort the arrival times in ascending order.
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arrival[i] > arrival[j]) {
        int temp = arrival[i]; //temperory variable to store the values and then compare.
        arrival[i] = arrival[j];
        arrival[j] = temp; 
      }
    }
  }

  // Calculate the total number of active seconds.
  int start_time = arrival[0];
  int end_time = arrival[0] + 10;
  for (int i = 1; i < n; i++) {
    if (arrival[i] <= end_time) {
      end_time = arrival[i] + 10; // adding 10 seconds to the end time as the arrival time is less than the end time for the last person
    } else {
      total_active_time += end_time - start_time;
      start_time = arrival[i];
      end_time = arrival[i] + 10;
    }
  }
  total_active_time += end_time - start_time;
  return total_active_time;
}

int main() {
  // Get the number of people.
  int n;
  printf("Enter number of people: ");
  scanf("%d", &n);
  // Get the arrival times of each person and then store it in an array
  int arrival[n];
  printf("Enter arrival times: ");
  for (int i = 0; i < n; i++) { //for loop to store the values in an array
    scanf("%d", &arrival[i]);}
  // Calculate the total number of active seconds.
  int total_active_time = active_seconds(arrival, n);
  // Display the result.
  printf("Active seconds: %d\n", total_active_time);
  return 0;
}
