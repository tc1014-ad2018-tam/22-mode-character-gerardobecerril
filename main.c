/* This program shows the mode (most repeated) character in a string that's entered by the user. It first discards
 * from the string.
 *
 * Author: Gerardo González Becerril.
 * Date: October 16th, 2018.
 * E-mail: a01411981@itesm.mx
 */

#include <stdio.h>

int main() {

    char string[100]; // Variable that stores the string.
    int counter = 0; // Counts the amount of characters in the array.
    int n = 0; // Counts the amount of values entered into the new array.
    char newString[100]; // New array that will store the string without spaces.
    char asciiCounter[128]; // Array that stores amount of times any ASCII value is repeated in the string.
    int modeValue = 0; // Amount of times the mode has been repeated.
    int mode; // Most repeated value.

    printf("Give me a string:\n"); // Asks the user for input.
    fgets(string, sizeof(string), stdin); // Stores the input in the string.

    // While loop that goes through all the string.
    while (string[counter] != '\0') {
        // If statement that saves characters that are not whitespaces into the new array.
        if (string[counter] != 32) {
            newString[n] = string[counter]; // Sends the current character to the new array.
            n++; // Keeps the count of characters in the new array.
        }
        counter++;
    }

    // For loop that goes through all the characters in the new array.
    for (int i = 0; newString[i] != '\0'; i++) {
        asciiCounter[newString[i]]++; // Adds one to the value stored in the ASCII number of any given character.
    }

    // For loop that goes through all the numbers in the ASCII counter.
    for (int i = 0; i < 128; i++) {
        // If statement that checks if a character in the ASCII counter has a bigger value than the current mode's.
        if (asciiCounter[i] > modeValue) {
            modeValue = asciiCounter[i]; // Changes the mode value to the now bigger value.
            mode = i; // Changes the old mode to the new one.
        }
    }

    printf("The mode is: %c.", mode); // Prints the mode.

    return 0;

}