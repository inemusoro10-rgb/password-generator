#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 256

// check how strong a password is based on length + character variety
int checkStrength(char *password, int length) {
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    int i;

    for (i = 0; i < length; i++) {
        char c = password[i];
        if (c >= 'a' && c <= 'z') hasLower = 1;
        else if (c >= 'A' && c <= 'Z') hasUpper = 1;
        else if (c >= '0' && c <= '9') hasDigit = 1;
        else hasSpecial = 1;
    }

    int score = hasLower + hasUpper + hasDigit + hasSpecial;

    if (length < 8 || score <= 2) return 1;  // weak
    if (length < 12 || score == 3) return 2; // medium
    return 3;                                 // strong
}

void printStrength(int level) {
    if (level == 1) printf("  Strength: WEAK\n");
    else if (level == 2) printf("  Strength: MEDIUM\n");
    else printf("  Strength: STRONG\n");
}

// build character set based on user preferences
int buildCharset(char *charset, int useLower, int useUpper, int useDigits, int useSpecial) {
    int size = 0;

    if (useLower) {
        char lower[] = "abcdefghijklmnopqrstuvwxyz";
        int i;
        for (i = 0; lower[i] != '\0'; i++) charset[size++] = lower[i];
    }
    if (useUpper) {
        char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int i;
        for (i = 0; upper[i] != '\0'; i++) charset[size++] = upper[i];
    }
    if (useDigits) {
        char digits[] = "0123456789";
        int i;
        for (i = 0; digits[i] != '\0'; i++) charset[size++] = digits[i];
    }
    if (useSpecial) {
        char special[] = "!@#$%^&*()-_=+[]{};:,.<>?";
        int i;
        for (i = 0; special[i] != '\0'; i++) charset[size++] = special[i];
    }

    charset[size] = '\0';
    return size;
}

char getChoice(char *prompt) {
    char choice;
    printf("%s (y/n): ", prompt);
    scanf(" %c", &choice);
    return choice;
}

int main() {
    srand((unsigned int)time(NULL));

    printf("=== Password Generator ===\n\n");

    // user picks what to include
    int useLower  = (getChoice("Include lowercase letters") == 'y') ? 1 : 0;
    int useUpper  = (getChoice("Include uppercase letters") == 'y') ? 1 : 0;
    int useDigits = (getChoice("Include numbers")           == 'y') ? 1 : 0;
    int useSpecial= (getChoice("Include special characters") == 'y') ? 1 : 0;

    // need at least one character type
    if (!useLower && !useUpper && !useDigits && !useSpecial) {
        printf("\nError: select at least one character type.\n");
        return 1;
    }

    char charset[MAX_LENGTH];
    int charsetSize = buildCharset(charset, useLower, useUpper, useDigits, useSpecial);

    int passwordLength;
    printf("\nEnter desired password length (1-255): ");
    scanf("%d", &passwordLength);

    if (passwordLength <= 0 || passwordLength >= MAX_LENGTH) {
        printf("Error: length must be between 1 and 255.\n");
        return 1;
    }

    int count;
    printf("How many passwords do you want to generate? ");
    scanf("%d", &count);

    if (count <= 0 || count > 20) {
        printf("Error: please enter a number between 1 and 20.\n");
        return 1;
    }

    printf("\n--- Generated Passwords ---\n\n");

    char password[MAX_LENGTH];
    int p, i;

    for (p = 0; p < count; p++) {
        // pick random characters from the charset
        for (i = 0; i < passwordLength; i++) {
            int randomIndex = rand() % charsetSize;
            password[i] = charset[randomIndex];
        }
        password[passwordLength] = '\0';

        int strength = checkStrength(password, passwordLength);

        printf("  Password %d: %s\n", p + 1, password);
        printStrength(strength);
        printf("\n");
    }

    printf("Charset size: %d characters\n", charsetSize);

    return 0;
}