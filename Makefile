all: main.cpp
	g++ -std=c++17 -O2 $^ -o main

clean:
	rm main -f
