all: program

program: main.o RestaurantQueue.o Group.o PersonalInfo.o Stack.o myUtil.o
	g++ -g -Wall -std=c++17 main.o RestaurantQueue.o Group.o PersonalInfo.o Stack.o myUtil.o -o program

main.o: main.cpp
	g++ -g -c -std=c++17 -Wall main.cpp -o main.o

RestaurantQueue.o: RestaurantQueue.cpp
	g++ -g -c -std=c++17 -Wall RestaurantQueue.cpp -o RestaurantQueue.o

Group.o: Group.cpp
	g++ -g -c -std=c++17 -Wall Group.cpp -o Group.o

PersonalInfo.o: PersonalInfo.cpp
	g++ -g -c -std=c++17 -Wall PersonalInfo.cpp -o PersonalInfo.o

Stack.o: Stack.cpp
	g++ -g -c -std=c++17 -Wall Stack.cpp -o Stack.o

myUtil.o: myUtil.cpp
	g++ -g -c -std=c++17 -Wall myUtil.cpp -o myUtil.o

clean:
	rm -f *.o
	rm -f ./program
