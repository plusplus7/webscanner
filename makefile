webscanner: main.o cmddata.o cmdprocesser.o webscanner.o
	g++ -o webscanner main.o cmddata.o cmdprocesser.o webscanner.o
main.o: src/main.cc
	g++ -c src/main.cc

cmddata.o: src/base/cmddata.cc src/base/cmddata.h
	g++ -c src/base/cmddata.cc

cmdprocesser.o: src/base/cmdprocesser.cc src/base/cmdprocesser.h
	g++ -c src/base/cmdprocesser.cc

webscanner.o: src/webscanner.cc src/webscanner.h
	g++ -c src/webscanner.cc
clean:
	rm *.o
