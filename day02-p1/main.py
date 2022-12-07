import fileinput

A = ord("A")
X = ord("X")


def score(a, b):
    a -= A
    b -= X
    return (b - a + 1) % 3 * 3 + b + 1


def score2(a, b):
    a -= A
    b -= X
    return b * 3 + (a + b - 1) % 3 + 1


def main():
    with fileinput.input() as file:
        rounds = [list(map(ord, line.strip().split())) for line in file]
    print(sum(score(*x) for x in rounds), sum(score2(*x) for x in rounds))


if __name__ == "__main__":
    main()
