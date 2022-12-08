#include <stdio.h>
#include <stdlib.h>

#include "input.h"

int main(int argc, char *argv[]) {
  unsigned char *ptr = input_txt;
  unsigned char *endptr;
  long x1, x2, y1, y2;

  unsigned long contain_count = 0;
  unsigned long overlap_count = 0;

  while (ptr - input_txt < input_txt_len) {
    x1 = strtol((char *)ptr, (char **)&endptr, 10);
    ptr = endptr + 1;
    x2 = strtol((char *)ptr, (char **)&endptr, 10);
    ptr = endptr + 1;
    y1 = strtol((char *)ptr, (char **)&endptr, 10);
    ptr = endptr + 1;
    y2 = strtol((char *)ptr, (char **)&endptr, 10);
    ptr = endptr + 1;

    if (x1 <= y1 && x2 >= y2) {
      ++contain_count;
    } else if (y1 <= x1 && y2 >= x2) {
      ++contain_count;
    }

    if ((x1 < y1 ? y1 : x1) <= (x2 < y2 ? x2 : y2)) {
      ++overlap_count;
    }
  }
  printf("%ld\n", contain_count);
  printf("%ld\n", overlap_count);

  return 0;
}
