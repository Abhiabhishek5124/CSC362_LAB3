//Abhishek Shrestha
// CSC 362 Programming Assignment 3
// Date: 11/13/23

/* Description:
 *    This program simulates a two-player version of the Chutes and Ladders game, a classic board game.
 *    Players take turns rolling a 6-sided die, and their game pieces move along the board accordingly.
 *
 *    The game board is represented as an array of characters named 'board', and players' positions are
 *    manipulated using pointers and pointer arithmetic. Direct array access is avoided, and players' movements
 *    are controlled through the manipulation of pointers.
 *
 *    The game board features various elements:
 *    - Chutes ('a' to 'm'): Move backward when landed on.
 *    - Ladders ('o' to 'z'): Move forward when landed on.
 *    - Backward ('B'): Move backward to the nearest preceding haven. Stop at the beginning if no more havens exist.
 *    - Forward ('F'): Move forward to the next haven. Stay if no more havens exist.
 *    - Havens ('H'): Safe squares where players might move when landing on 'B' or 'F'. Removed after being landed on.
 *
 *    The game includes collision rules: If a player lands on a square occupied by the other player, the moving
 *    player must move back one square. Additional moves are ignored if caused by chutes, ladders, 'F', or 'B'.
 *
 *    The program structure is modular, with functions like main, output, move, findHaven, and chuteLadder.
 *    Pointer arithmetic is utilized extensively to traverse the game board without direct array access.
 *
 *    The game's progress is displayed in the console window, showing the outcome of each player's turn.
 *    Additionally, the current state of the board is written to a text file after each player's turn.
 *
 *    The game continues until one player reaches the farthest position on the board, and the winner is determined
 *    by who has gone the farthest.
 */

#include <stdio.h>

// Function to copy elements from source array to destination array
void copy(int *source, int *destination, int size) {
    for (int i = 0; i < size; i++) {
        // Copy each element from the source array to the destination array
        *(destination + i) = *(source + i);
    }
}

// Bubble sort algorithm to sort an array in ascending order
void sort1(int *a, int size) {
    // Flag to determine if the array is sorted
    int sorted = 0;
    // Variable to keep track of the end of the unsorted portion of the array
    int k = size;

    // Continue sorting until the array is sorted
    while (!sorted) {
        // Assume the array is sorted until a swap is performed
        sorted = 1;

        // Iterate through the array and swap adjacent elements if they are in the wrong order
        for (int *p = a; p < a + k - 1; p++) {
            // Check if the current element is greater than the next element
            if (*p > *(p + 1)) {
                // If elements are in the wrong order, set the sorted flag to false
                sorted = 0;
                // Swap elements
                int temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
            }
        }
        // Decrease the end of unsorted portion for the next iteration
        k--;
    }
}

// Insertion sort algorithm to sort an array in ascending order
void sort2(int *a, int size) {
    // Iterate through the array starting from the second element
    for (int *p = a + 1; p < a + size; p++) {
        // Store the current element in a temporary variable
        int temp = *p;
        // Initialize a pointer to the previous element
        int *location = p - 1;

        // Move elements greater than temp to one position ahead of their current position
        while (location >= a && *location > temp) {
            // Shift elements to the right
            *(location + 1) = *location;
            // Move the pointer to the previous position
            location--;
        }

        // Insert temp in its correct position
        *(location + 1) = temp;
    }
}


// Function to print the elements of an array
void output(int *a, int size) {
    for (int *p = a; p < a + size; p++) {
        // Print each element of the array
        printf("%d ", *p);
    }
    printf("\n");
}

// Main function
int main() {
    // Declare and initialize two arrays
    int array1[] = {10, 3, 6, 5, 9, 2, 1, 7, 4, 8};
    int array2[10];

    int size = 10;

    // Copy the elements of array1 to array2
    copy(array1, array2, size);

    // Sort array1 using sort1 function (Bubble sort) and print the result
    sort1(array1, size);
    output(array1, size);

    // Sort array2 using sort2 function (Insertion sort) and print the result
    sort2(array2, size);
    output(array2, size);
    return 0;
}


//Output
//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 7 8 9 10