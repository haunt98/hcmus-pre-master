.PHONY: all day01 zig-day01 format

all:
	@echo You good?
	$(MAKE) format

day01:
	g++ -Wall -Wextra -o day-01.out ./day-01.cpp && ./day-01.out && rm -rf ./day-01.out

zig-day01:
	zig c++ -o day-01.out ./day-01.cpp && ./day-01.out && rm -rf ./day-01.out

day02:
	g++ -Wall -Wextra -o day-02.out ./day-02.cpp && ./day-02.out && rm -rf ./day-02.out

zig-day02:
	zig c++ -o day-02.out ./day-02.cpp && ./day-02.out && rm -rf ./day-02.out

day03:
	g++ -Wall -Wextra -o day-03.out ./day-03.cpp && ./day-03.out && rm -rf ./day-03.out

zig-day03:
	zig c++ -o day-03.out ./day-03.cpp && ./day-03.out && rm -rf ./day-03.out

day04:
	g++ -Wall -Wextra -o day-04.out ./day-04.cpp && ./day-04.out && rm -rf ./day-04.out

zig-day04:
	zig c++ -o day-04.out ./day-04.cpp && ./day-04.out && rm -rf ./day-04.out

day05:
	g++ -Wall -Wextra -o day-05.out ./day-05.cpp && ./day-05.out && rm -rf ./day-05.out

zig-day05:
	zig c++ -o day-05.out ./day-05.cpp && ./day-05.out && rm -rf ./day-05.out

202202:
	g++ -Wall -Wextra -o 202202.out ./202202.cpp && ./202202.out && rm -rf ./202202.out

zig-202202:
	zig c++ -o 202202.out ./202202.cpp && ./202202.out && rm -rf ./202202.out

format:
	# Use clang-format from macports
	clang-format-mp-15 -i *.cpp
