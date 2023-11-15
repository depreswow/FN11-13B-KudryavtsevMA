#include <iostream>

const int N=41;
static char current_word[N], vowels[10]={'e', 'u', 'i', 'o', 'a', 'E', 'U', 'I', 'O', 'A'};
static char words[N][N];
bool is_vowel(char c);

int main() {
    int current_i=0, word_i=0, vowel_counter=0;
    puts("Enter your string (<=40 symbols):");
    scanf("%c", &current_word[current_i]);
    while (current_word[current_i]!='\n') {
        if ((current_word[current_i]==' ') or (current_word[current_i]=='.')) {
            if (vowel_counter>=2) {for (int i=0; i<=current_i-1; i++) words[word_i][i]=current_word[i]; word_i++;}
            current_i=0; vowel_counter=0;
        } else {if (is_vowel(current_word[current_i])) vowel_counter++; current_i++;};
        scanf("%c", &current_word[current_i]);
    }
    puts("\nNew string:");
    for (int i=0; i<=word_i-1; i++) {
        current_i=0;
        if (i>0) printf(" ");
        while (words[i][current_i]!='\0') {printf("%c", words[i][current_i]); current_i++;}
    }
    puts(".");
}

bool is_vowel(char c) {
    for (int i=0; i<11; i++) {
        if (c==vowels[i]) return true;
    }
    return false;
}

