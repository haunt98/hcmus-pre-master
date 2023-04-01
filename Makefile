.PHONY: all day01 zig-day01 format

all:
	@echo You good?
	$(MAKE) format

day01:
	g++ -o day-01.out ./day-01.cpp && ./day-01.out && rm -rf ./day-01.out

zig-day01:
	zig c++ -o day-01.out ./day-01.cpp && ./day-01.out && rm -rf ./day-01.out

day02:
	g++ -o day-02.out ./day-02.cpp && ./day-02.out && rm -rf ./day-02.out

zig-day02:
	zig c++ -o day-02.out ./day-02.cpp && ./day-02.out && rm -rf ./day-02.out

day03:
	g++ -o day-03.out ./day-03.cpp && ./day-03.out && rm -rf ./day-03.out

zig-day03:
	zig c++ -o day-03.out ./day-03.cpp && ./day-03.out && rm -rf ./day-03.out

format:
	# Use clang-format from macports
	clang-format-mp-15 -i *.cpp
