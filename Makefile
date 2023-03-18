.PHONY: all day01 zig-day01

all:
	@echo You good?

day01:
	g++ -o day-1.out ./day-1.cpp && ./day-1.out && rm -rf ./day-1.out

zig-day01:
	zig c++ -o day-1.out ./day-1.cpp && ./day-1.out && rm -rf ./day-1.out
