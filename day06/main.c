#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

// #define N 4
#define N 14

int main(int argc, char *argv[]) {
  unsigned char *ptr = input_txt;
  unsigned char buf[N] = {0};

  while (ptr - input_txt < input_txt_len) {
    buf[(ptr - input_txt) % N] = *ptr;
    ++ptr;
    if ((ptr - input_txt) <= N)
      continue;

    unsigned char chars[UCHAR_MAX] = {0};
    for (size_t i = 0; i < N; ++i) {
      if (chars[buf[i]]++)
        goto next;
    }
    break;
  next:
    continue;
  }
  printf("%ld\n", ptr - input_txt);

  return 0;
}
