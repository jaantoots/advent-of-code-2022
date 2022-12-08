#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

#define N 9

typedef struct {
  unsigned char crates[UCHAR_MAX];
  unsigned char n;
} stack;

unsigned char pop(stack *s) { return s->crates[--s->n]; }

void append(stack *s, unsigned char crate) { s->crates[s->n++] = crate; }

int main(int argc, char *argv[]) {
  unsigned char *ptr = input_txt;
  unsigned char *endptr;
  unsigned char id;

  stack stacks[N] = {};
  for (size_t j = 0;; ++j) {
    if (*ptr == '\n') {
      ++ptr;
      break;
    }
    for (size_t i = 0; i < N; ++i) {
      id = *(ptr + 1 + 4 * i);
      if (id != ' ') {
        stacks[i].crates[UCHAR_MAX - 1 - stacks[i].n] = id;
        ++stacks[i].n;
      }
    }
    while (*ptr != '\n')
      ++ptr;
    ++ptr;
  }

  for (size_t i = 0; i < N; ++i) {
    size_t offset = UCHAR_MAX - stacks[i].n;
    if (offset == 0)
      continue;
    for (size_t j = 0; j < stacks[i].n; ++j) {
      stacks[i].crates[j] = stacks[i].crates[offset + j];
      stacks[i].crates[offset + j] = 0;
    }
  }

  unsigned char n, from, to;

  while (ptr - input_txt < input_txt_len) {
    ptr += 5;
    n = (unsigned char)strtol((char *)ptr, (char **)&endptr, 10);
    ptr = endptr + 6;
    from = (unsigned char)strtol((char *)ptr, (char **)&endptr, 10) - 1;
    ptr = endptr + 4;
    to = (unsigned char)strtol((char *)ptr, (char **)&endptr, 10) - 1;
    ptr = endptr + 1;

    for (unsigned char i = 0; i < n; ++i) {
      append(&stacks[to], pop(&stacks[from]));
    }
  }

  for (size_t i = 0; i < N; ++i) {
    printf("%c", stacks[i].crates[stacks[i].n - 1]);
  }
  printf("\n");

  return 0;
}
