#include <stdio.h>
#include <stdlib.h>

#include "input.h"

int main(int argc, char *argv[]) {
  unsigned char *ptr = input_txt;

  unsigned char opp;
  unsigned char me;
  long score = 0;

  while (ptr - input_txt < input_txt_len) {
    opp = *ptr - 'A';
    ++ptr;
    if (*ptr != ' ') {
      printf("unexpected character: '%c'\n", *ptr);
      return 1;
    }
    ++ptr;
    me = *ptr - 'X';
    ++ptr;
    if (*ptr != '\n') {
      printf("unexpected character: '%c'\n", *ptr);
      return 1;
    }
    ++ptr;
    score += (3 + me - opp + 1) % 3 * 3 + me + 1;
  }
  printf("%ld\n", score);

  return 0;
}
