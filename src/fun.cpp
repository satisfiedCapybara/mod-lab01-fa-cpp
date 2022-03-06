// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    bool withDigit = false;
    bool inWord = false;
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (inWord == true && withDigit == false && str[i] == ' ') {
            inWord = false;
        } else if (inWord == true && withDigit == false && isdigit(str[i])) {
            withDigit = true;
            count--;
        } else if (inWord == false && withDigit == false && isalpha(str[i])) {
            inWord = true;
            count++;
        } else if (inWord == false && withDigit == false && isdigit(str[i])) {
            inWord = true;
            withDigit = true;
        } else if (inWord == true && withDigit == true && str[i] == ' ') {
            inWord = false;
            withDigit = false;
        }
        i++;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    bool uncorrectlyWord = false;
    bool inWord = false;
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (inWord == true && uncorrectlyWord == false && str[i] == ' ') {
            inWord = false;
        } else if (inWord == true && uncorrectlyWord == false 
        && isdigit(str[i])) {
            uncorrectlyWord = true;
            count--;
        } else if (inWord == true && uncorrectlyWord == false
        && isalpha(str[i]) && isupper(str[i])) {
            uncorrectlyWord = true;
            count--;
        } else if (inWord == false && uncorrectlyWord == false
        && !isalpha(str[i]) &&!isdigit(str[i])) {
            inWord = true;
            uncorrectlyWord = true;
        } else if (inWord == false && uncorrectlyWord == false
        && isalpha(str[i]) && islower(str[i])) {
            inWord = true;
            uncorrectlyWord = true;
        } else if (inWord == false && uncorrectlyWord == false
        && isalpha(str[i]) && isupper(str[i])) {
            inWord = true;
            count++;
        } else if (inWord == false && uncorrectlyWord == false
        && !isalpha(str[i]) && !isdigit(str[i])) {
            inWord = true;
            uncorrectlyWord == true;
        } else if (inWord == true && uncorrectlyWord == false
        && !isalpha(str[i]) & !isdigit(str[i])) {
            uncorrectlyWord = true;
            count--;
        } else if (inWord == false && uncorrectlyWord == false
        && isdigit(str[i])) {
            inWord = true;
            uncorrectlyWord = true;
        } else if (inWord == true && uncorrectlyWord == true
        && str[i] == ' ') {
            inWord = false;
            uncorrectlyWord = false;
        }
        i++;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    std::vector<int> letters_count;
    bool inWord = false;
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (inWord == true && str[i] == ' ') {
            inWord = false;
        } else if (inWord == false && str[i] != ' ') {
            inWord = true;
            count++;
            letters_count.push_back(1);
        } else if (inWord == true && str[i] != ' ') {
            letters_count.back()++;
        }
        i++;
    }

    return round(static_cast<double>(std::accumulate(begin(letters_count),
        end(letters_count), 0, std::plus<int>())) / letters_count.size());
}
