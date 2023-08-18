#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FIX_BUG *guessed=

int main() {
    int max_guesses, max_words, max_len = 0;
    printf("Set your max guess number: \n");
    scanf(" %d", &max_guesses);
    printf("Set your max word number: \n");
    scanf(" %d", &max_words);
    printf("Set your max word length: \n");
    scanf(" %d", &max_len);

    char** words = (char**) malloc(max_words * sizeof(char*));
    for (int i = 0; i < max_words; i++) {
        words[i] = (char*) malloc(max_len * sizeof(char));
    }
    char* word = (char*) malloc(max_len * sizeof(char));
    char* guessed = (char*) malloc(max_len * sizeof(char));
    int num_words = 0;
    int i, len, guesses = 0;
    char guess;
    int correct = 0;
    
    FILE* fp = fopen("../real_world_case/hangman.txt", "r");
    while (fgets(words[num_words], max_len, fp)) {
        len = strlen(words[num_words]);
        if (len > 0 && words[num_words][len-1] == '\n') {
            words[num_words][len-1] = '\0';
            num_words++;
        }
    }
    fclose(fp);
    srand(time(NULL));
    strcpy(word, words[rand() % num_words]);
    for (i = 0; i < strlen(word); i++) {
        guessed[i] = '_';
    }
    guessed[i] = '\0';
    printf("The word has %d letters. You have %d guesses. (To test, the word is %s)\n", strlen(word), max_guesses, word);

    while (guesses < max_guesses && correct < strlen(word)) {
        printf("Guessed word: %s\n", guessed);

        printf("Enter a letter: ");
        scanf(" %c", &guess);
        int found = 0;
        for (i = 0; i < strlen(word); i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correct++;
                found = 1;
            }
        }
        if (!found) {
            guesses++;
            printf("Incorrect guess. You have %d guesses remaining.\n", max_guesses - guesses);
        }
    }
    if (correct == strlen(word)) {
        printf("You won!\n");
    } else {
        printf("You lost. The word was %s.\n", word);
    }
    for (i = 0; i < max_words; i++) {
        free(words[i]);
    }
    free(words);
    free(word);
    free(guessed);
    FIX_BUG "fixbug";

    return 0;
}