#ifndef WEBSCANNER_WEBSCANNER_H
#define WEBSCANNER_WEBSCANNER_H
#define URL_LENGTH 5000
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
using std::string;
void work_interupt(int signo);
class WebScanner
{
public:
	int work(int argc, char **argv);
protected:
private:
	char *get_ip(const char *host);
	int send_request(string url, string url_add, sockaddr_in serv_addr);
	string dict_readline(FILE *fp);
	void output_writeline(FILE *fp, string url, int response);
	sockaddr_in get_serv_addr(string url);
	void construct_http_header(string url, string url_add, char *request);	
};
#endif // end of  WEBSCANNER_WEBSCANNER_H

