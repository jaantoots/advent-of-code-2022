#include <stdio.h>
#include <stdlib.h>

#include "input.h"

int main(int argc, char *argv[]) {
  unsigned char *ptr = input_txt;

  unsigned char opp;
  unsigned char res;
  long score = 0;

  while (ptr - input_txt < input_txt_len) {
    opp = *ptr - 'A';
    ++ptr;
    if (*ptr != ' ') {
      printf("unexpected character: '%c'\n", *ptr);
      return 1;
    }
    ++ptr;
    res = *ptr - 'X';
    ++ptr;
    if (*ptr != '\n') {
      printf("unexpected character: '%c'\n", *ptr);
      return 1;
    }
    ++ptr;
    score += res * 3 + (3 + opp + res - 1) % 3 + 1;
  }
  printf("%ld\n", score);

  return 0;
}
