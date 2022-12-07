import fileinput
from heapq import nlargest
from itertools import groupby


def main():
    with fileinput.input() as file:
        three_elves = nlargest(
            3,
            (sum(map(int, g)) for k, g in groupby((line.strip() for line in file), key=bool) if k),
        )
    print(three_elves[0], sum(three_elves))


if __name__ == "__main__":
    main()
