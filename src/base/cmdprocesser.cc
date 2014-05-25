#include "cmdprocesser.h"
#include "cmddata.h"
#include <iostream>
int CmdProcesser::process_command(int argc, char **argv,CmdData ** res){
	
	*res=new CmdData();
	if ((*res) == NULL)
		return 1;
	(*res)->init_data();
	for (int i=1; i<argc; i++) 
	{
		if (strcmp(argv[i-1], "-url") == 0) 
			(*res)->set_url_string(argv[i]);
		if (strcmp(argv[i-1], "-out") == 0)
		{
			if (strcmp(argv[i], "txt") == 0)
				(*res)->set_output_type(1);
			else if (strcmp(argv[i], "html") == 0)
				(*res)->set_output_type(0);
			else
				(*res)->set_output_type(0);
		}	
		if (strcmp(argv[i-1], "-o") == 0)
			(*res)->set_output_filename(argv[i]);
		if (strcmp(argv[i-1], "-dict") == 0)
			(*res)->set_dict_string(argv[i]);
	}
	return 0;
}
