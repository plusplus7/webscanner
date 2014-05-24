#include "webscanner.h"
int main(int argc, char **argv)
{
	WebScanner * ws=new WebScanner();
	ws->work(argc,argv);
	delete ws;
	return 0;
}
