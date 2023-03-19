.PHONY: all day01 zig-day01 format

all:
	@echo You good?
	$(MAKE) format

day01:
	g++ -o day-1.out ./day-1.cpp && ./day-1.out && rm -rf ./day-1.out

zig-day01:
	zig c++ -o day-1.out ./day-1.cpp && ./day-1.out && rm -rf ./day-1.out

format:
	# Use clang-format from macports
	clang-format-mp-15 -i *.cpp
