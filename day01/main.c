#include <stdio.h>
#include <stdlib.h>

#include "input.h"

#define TOP_N 3

int main(int argc, char *argv[]) {
  unsigned char *ptr = input_txt;
  unsigned char *endptr;
  long max_cal = 0;
  long top_cal[TOP_N] = {0};
  long elf_cal = 0;
  long cal;

  unsigned int i, j;
  long prev, next;

  while (ptr - input_txt < input_txt_len) {
    if (*ptr == '\n') {
      for (i = 0; i < TOP_N; ++i) {
        if (elf_cal > top_cal[i]) {
          next = elf_cal;
          for (j = i; j < TOP_N; ++j) {
            prev = top_cal[j];
            top_cal[j] = next;
            next = prev;
          }
          break;
        }
      }
      if (elf_cal > max_cal)
        max_cal = elf_cal;
      elf_cal = 0;
      ++ptr;
      continue;
    }
    cal = strtol((char *)ptr, (char **)&endptr, 10);
    elf_cal += cal;
    ptr = endptr + 1;
  }
  printf("%ld\n", max_cal);

  long total_cal = 0;
  for (i = 0; i < TOP_N; ++i)
    total_cal += top_cal[i];
  printf("%ld\n", total_cal);

  return 0;
}
