all: run

configure:
	cmake -S . -B build/

build: configure
	cmake --build build
	ln -sf build/compile_commands.json .

run: build
	clear
	@./build/morse

clean:
	rm build docs/html docs/rtf docs/man docs/latex -rf


documentation: configure
	cmake --build build -t generate_documentation


format:
	cmake --build build -t format

.PHONY: all configure build run clean
