#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

int main(int argc, char *argv[]) {
  unsigned char *ptr = input_txt;
  unsigned char *endptr = ptr;
  unsigned char *cur;

  long error_sum = 0;
  long badge_sum = 0;
  long row_idx = 0;
  unsigned char common[UCHAR_MAX] = {0};

  while (ptr - input_txt < input_txt_len) {
    while (*endptr != '\n')
      ++endptr;
    unsigned char items[UCHAR_MAX] = {0};
    for (cur = ptr; cur - ptr < endptr - cur; ++cur)
      items[*cur] = 1;
    for (; cur < endptr; ++cur) {
      if (items[*cur]) {
        error_sum += *cur - (*cur < 'a' ? 'A' - 27 : 'a' - 1);
        break;
      }
    }

    for (cur = ptr; cur < endptr; ++cur)
      common[*cur] |= 1 << (row_idx % 3);
    if (row_idx % 3 == 2) {
      for (unsigned char i = 0; i < UCHAR_MAX; ++i) {
        if (common[i] == 7) {
          badge_sum += i - (i < 'a' ? 'A' - 27 : 'a' - 1);
        }
        common[i] = 0;
      }
    }

    ++endptr;
    ptr = endptr;
    ++row_idx;
  }
  printf("%ld\n", error_sum);
  printf("%ld\n", badge_sum);

  return 0;
}
