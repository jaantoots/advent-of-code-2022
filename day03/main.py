import fileinput
import string
from functools import reduce

N = 3


def main():
    with fileinput.input() as file:
        rucksacks = [line.strip() for line in file]
    errors = [set(rucksack[: len(rucksack) // 2]) & set(rucksack[len(rucksack) // 2 :]) for rucksack in rucksacks]
    part1 = sum(string.ascii_letters.index(x.pop()) + 1 for x in errors)

    common = [reduce(lambda x, y: x & y, map(set, group)) for group in zip(*(rucksacks[i::N] for i in range(N)))]
    part2 = sum(string.ascii_letters.index(x.pop()) + 1 for x in common)

    print(part1, part2)


if __name__ == "__main__":
    main()
