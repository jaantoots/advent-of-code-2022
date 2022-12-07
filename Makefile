.PHONY: all clean
.PRECIOUS: %/input.h

all: $(addprefix bin/,$(wildcard day*))

clean:
	rm -vf bin/* */input.h

%/input.h: %/input.txt
	xxd -i -n input_txt $< >$@

bin/%: %/main.c %/input.h
	clang -O3 -o $@ $<
