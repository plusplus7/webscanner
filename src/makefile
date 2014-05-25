webscanner: main.o cmddata.o cmdprocesser.o webscanner.o
	g++ -o webscanner main.o cmddata.o cmdprocesser.o webscanner.o
main.o: main.cc
	g++ -c main.cc

cmddata.o: base/cmddata.cc base/cmddata.h
	g++ -c base/cmddata.cc

cmdprocesser.o: base/cmdprocesser.cc base/cmdprocesser.h
	g++ -c base/cmdprocesser.cc

webscanner.o: webscanner.cc webscanner.h
	g++ -c webscanner.cc
clean:
	rm *.o
