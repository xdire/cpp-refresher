
output: main.o twisters.o
	g++ main.o first_unique_char_string.o -o runprog

main.o: main.cpp
	g++ -c main.cpp

twisters.o: twisters/first_unique_char_string.h twisters/first_unique_char_string.cpp
	g++ -c twisters/first_unique_char_string.cpp

clean:
	rm *.o runprog twisters/*.o
