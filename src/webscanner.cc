#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "webscanner.h"
#include "base/cmddata.h"
#include "base/cmdprocesser.h"
int WebScanner::work(int argc,  char **argv)
{
	CmdProcesser * processer=new CmdProcesser();
	CmdData * result=NULL;
	if ( processer->process_command(argc, argv, &result) != 0 )
		return -1;          // command not legal
	if ( result->get_url_string()  ==  "" )
		return -2;          // url is needed
	string url=result->get_url_string();
	FILE *dict_pointer=fopen(result->get_dict_string().c_str(),"r");
	FILE *output_pointer=fopen(result->get_output_filename().c_str(), "w");
	if ( dict_pointer == NULL )
		return -3;	        // dict file not existed
 	if ( output_pointer == NULL )
		return -4;          // Fail to create the output file 	
	printf("Starting to scan!\n");
	
	sockaddr_in serv_addr=get_serv_addr(url);
	in_addr in;
	memcpy(&in.s_addr,&(serv_addr.sin_addr), sizeof(in));
	printf("The IP address of the server: %s\n",inet_ntoa(in));
	printf("Start to scan...\n\n");
	g_webscanner_interupted=false;
	signal(SIGINT,work_interupt);
	while (!feof(dict_pointer) && !g_webscanner_interupted)
	{
		string url_add=dict_readline(dict_pointer);
		printf("\33[1A");
		printf("\33[K");
		printf("Checking: %s%s\n",url.c_str(),url_add.c_str());
		int response=send_request(url, url_add,serv_addr);
		if ( response == 200 || response == 403 )
			output_writeline(output_pointer,url+url_add,response);
	}
	delete result;
	delete processer;
	fclose(dict_pointer);
	fclose(output_pointer);
}
void work_interupt(int signo)
{
	printf("Stop scanning?Y/N ");
	string s;
	std::cin>>s;
	if (s[0] == 'y' || s[0] == 'Y')
		g_webscanner_interupted=true;	
}
sockaddr_in WebScanner::get_serv_addr(string url)
{
	hostent * host=gethostbyname(url.c_str());
	sockaddr_in tmp;
	bzero(&tmp,sizeof(tmp));
	tmp.sin_family=AF_INET;
	tmp.sin_port=htons(80);
	tmp.sin_addr=*((in_addr *)host->h_addr);
	return tmp;
}
int WebScanner::send_request(string url,string url_add, sockaddr_in serv_addr)
{
	char request[2048];
	sprintf(request,"GET %s HTTP/1.1\r\n",url_add.c_str());	
	strcat(request,"Accept: */*\r\n");  
    strcat(request,"Accept-Language: zh-cn\r\n");  
    strcat(request,"User-Agent: Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1;\r\n");  
    strcat(request,"Host: ");  
    strcat(request,url.c_str());  
    strcat(request,"\r\nConnection: close\r\n\r\n");  
	int sockfd;
	int res;
	char buff[16];
	do{

		sockfd=socket(AF_INET,SOCK_STREAM,0);
		if (sockfd < 0)
			return -1;
		if (connect(sockfd, (sockaddr *)&serv_addr,sizeof(sockaddr)) == -1)
			return -1;
		memset(buff,0,sizeof(buff));
		send(sockfd, request,2014,0);
		res=recv(sockfd,buff,sizeof(buff)-1,0);
	}while ( res == -1);
	sscanf(buff,"%*s %d %*s %*d",&res);
	close(sockfd);
	return res;
}
string WebScanner::dict_readline(FILE *fp)
{	
	char line[URL_LENGTH];
	fgets(line, URL_LENGTH-1, fp);
	int ll=strlen(line);
	line[ll-1]='\0';
	return string(line);
}
void WebScanner::output_writeline(FILE *fp, string url, int response)
{
	fprintf(fp,"%s %d\n",url.c_str(),response);
}
