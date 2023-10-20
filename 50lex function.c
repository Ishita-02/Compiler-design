#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// ARITHMETIC FUNCTIONS

// Function to add two numbers a and b
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers a and b
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers a and b
int multiply(int a, int b) {
    return a * b;
}

// Function to divide number a by b
double divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0.0;
    }
    return (double)a / b;
}

// Function to calculate base raised to the power of exponent
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    }
    double result = 1.0;
    for (int i = 0; i < abs(exponent); i++) {
        result *= base;
    }
    return (exponent > 0) ? result : 1.0 / result;
}

// Function to calculate the absolute value of a number
int absoluteValue(int number) {
    return (number < 0) ? -number : number;
}

// Function to calculate the floor a number
double floor(double x) {
    return floor(x);
}

// Function to calculate the modulo of a number
int modulo(int dividend, int divisor) {
    if (divisor == 0) {
        // Handle division by zero
        return 0;
    }
    return dividend % divisor;
}

// Function to negate (change the sign of) a number
int negate(int number) {
    return -number;
}

// Function to check if a number is positive
int isPositive(int number) {
    return (number > 0) ? 1 : 0;
}

// Function to check if a number is negative
int isNegative(int number) {
    return (number < 0) ? 1 : 0;
}

// Function to check if a number is zero
int isZero(int number) {
    return (number == 0) ? 1 : 0;
}

// Function to check if a number is even
int isEven(int number) {
    return (number % 2 == 0) ? 1 : 0;
}

// Function to check if a number is odd
int isOdd(int number) {
    return (number % 2 != 0) ? 1 : 0;
}

// Function to find the maximum of two numbers a and b
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the minimum of two numbers a and b
int minimum(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the average of two numbers a and b
double average(int a, int b) {
    return (double)(a + b) / 2.0;
}

// Function to calculate the absolute difference between a and b
int absoluteDifference(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

// Function to calculate the square root of a number
double squareRoot(double number) {
    if (number < 0) {
        printf("Error: Cannot calculate square root of a negative number.\n");
        return 0.0;
    }
    return sqrt(number);
}

// Function to calculate the logarithm of number with a specified base
double logarithm(double base, double number) {
    if (base <= 0 || base == 1 || number <= 0) {
        printf("Error: Invalid base or number for logarithm calculation.\n");
        return 0.0;
    }
    return log(number) / log(base);
}

// Function to calculate the factorial of a number
unsigned long long factorial(int number) {
    if (number < 0) {
        printf("Error: Cannot calculate factorial of a negative number.\n");
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

// Function to check if a number is prime
int isPrime(int number) {
    if (number <= 1) {
        return 0;
    }
    if (number <= 3) {
        return 1;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return 0;
    }
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a text or string is a palindrome
int isPalindrome(const char* text) {
    int length = strlen(text);
    for (int i = 0; i < length / 2; i++) {
        if (text[i] != text[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // It's a palindrome
}

// Calculates the greatest common divisor (GCD) of two numbers.
int gcd(int a, int b) {
    while (b) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

// Computes the least common multiple (LCM) of two numbers.
int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

// DATE AND TIME FUNCTIONS 

// Function to calculate the number of days in a specific month of a given year
int daysInMonth(int month, int year) {
    if (month < 1 || month > 12) {
        return -1; // Invalid month
    }
    if (year < 1) {
        return -1; // Invalid year
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year (February has 29 days)
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        daysInMonth[2] = 29;
    }

    return daysInMonth[month];
}

// Retrieves the current date in the format "YYYY-MM-DD".
char* getCurrentDate() {
    time_t now;
    struct tm *tm_info;
    static char date[12];
    time(&now);
    tm_info = localtime(&now);
    strftime(date, 12, "%Y-%m-%d", tm_info);
    return date;
}

// RANDOM NUMBER FUNCTIONS

// Generates a random number within a specified range.
int generateRandomNumber(int min_value, int max_value) {
    return rand() % (max_value - min_value + 1) + min_value;
}

// Generates a random true or false value (0 or 1).
int randomBoolean() {
    return rand() % 2;
}

// ARRAY FUNCTIONS 

// Finds the maximum value in an array.
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Finds the minimum value in an array.
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Computes the sum of all elements in an array.
int arraySum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Computes the average of elements in an array.
double arrayAverage(int arr[], int size) {
    if (size == 0) return 0;
    return (double)arraySum(arr, size) / size;
}

// Sorts the elements in an array in ascending order.
void arraySort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Reverses the order of elements in an array.
void arrayReverse(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Checks if an element exists in an array.
int arrayContains(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1;  // Element found
        }
    }
    return 0;  // Element not found
}

// Retrieves the index of an element in an array.
int arrayIndex(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;  // Element found at index i
        }
    }
    return -1;  // Element not found
}

// Removes an element from an array.
void arrayRemove(int arr[], int* size, int element) {
    for (int i = 0; i < *size; i++) {
        if (arr[i] == element) {
            // Shift elements to fill the gap
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            return;  // Element removed
        }
    }
}

// STRING FUNCTIONS

// Function to concatenate two strings.
char* concatenateStrings(const char* str1, const char* str2) {
    char* result = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

// Function to calculate the length of a string.
size_t stringLength(const char* str) {
    return strlen(str);
}

// Function to check if a string contains a substring.
int stringContains(const char* str, const char* substring) {
    return strstr(str, substring) != NULL;
}

// Function to convert a string to uppercase.
char* stringToUpper(const char* str) {
    char* result = (char*)malloc(strlen(str) + 1);
    for (size_t i = 0; i < strlen(str); i++) {
        result[i] = toupper(str[i]);
    }
    result[strlen(str)] = '\0';
    return result;
}

// Function to convert a string to lowercase.
char* stringToLower(const char* str) {
    char* result = (char*)malloc(strlen(str) + 1);
    for (size_t i = 0; i < strlen(str); i++) {
        result[i] = tolower(str[i]);
    }
    result[strlen(str)] = '\0';
    return result;
}

// Function to check whether the string is null or empty.
bool isNullOrEmpty(const char* str) {
    return str == NULL || str[0] == '\0';
}

// Function to split a string into an array based on a delimiter.
char** stringSplit(const char* str, const char* delimiter, int* count) {
    char* copy = strdup(str);
    char* token = strtok(copy, delimiter);
    char** result = NULL;
    *count = 0;

    while (token) {
        result = (char**)realloc(result, (*count + 1) * sizeof(char*));
        result[(*count)++] = strdup(token);
        token = strtok(NULL, delimiter);
    }

    free(copy);
    return result;
}

// Function to reverse the characters in a string
void reverseString(char* text) {
    int length = strlen(text);
    for (int i = 0; i < length / 2; i++) {
        char temp = text[i];
        text[i] = text[length - i - 1];
        text[length - i - 1] = temp;
    }
}

// Function to findastring that ends with suffix string
bool endsWith(const char* str, const char* suffix) {
    int strLength = strlen(str);
    int suffixLength = strlen(suffix);

    // If the suffix is longer than the string, it cannot be a suffix
    if (strLength < suffixLength) {
        return false;
    }

    // Compare the characters at the end of the string with the suffix
    for (int i = 0; i < suffixLength; i++) {
        if (str[strLength - suffixLength + i] != suffix[i]) {
            return false; // Mismatch found
        }
    }

    return true; // All characters in the suffix match the end of the string
}

// File Operations

// Function to write in the file
void writeFile(const char* filename, const char* data) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s", data);
    fclose(file);
}

// Function to check whether the file exist or not
int fileExists(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}