.PHONY: all clean
.PRECIOUS: %/input.h

all: bin/day01

clean:
	rm -vf bin/* */input.h

%/input.h: %/input.txt
	xxd -i -n input_txt $< >$@

bin/%: %/main.c %/input.h bin
	clang -O3 -o $@ $<

bin:
	mkdir $@
