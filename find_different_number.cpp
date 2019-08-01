#include "find_different_number.h"

int find_different_number(int number_table[], int number_table_size, int min_number, int max_number) {
    for (int present_number = min_number; present_number <= max_number; present_number++) {
        int i;
        for (i = 0; i < number_table_size; i++) {
            if(number_table[i] == present_number) break;
        }
        if (i == number_table_size) return present_number;
    }
    return max_number + 1;
}