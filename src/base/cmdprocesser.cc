#include "cmdprocesser.h"
#include "cmddata.h"
int CmdProcesser::process_command(int argc, char **argv,CmdData * res){
	
	CmdData * tmp=new CmdData();
	if (tmp == null)
		return 0;
	tmp->init_data();
	for (int i=1; i<argc; i++) 
	{
		if (strcmp(argv[i-1], "-url") == 0) 
			tmp->set_url_string(argv[i]);
		if (strcmp(argv[i-1], "-out") == 0)
		{
			if (strcmp(argv[i], "txt") == 0)
				tmp->set_output_type=1;
			else if (strcmp(argv[i], "html") == 0)
				tmp->set_output_type=0;
			else
				tmp->set_output_type=0;
		}	
		if (strcmp(argv[i-1], "-o") == 0)
			tmp->set_output_filename(argv[i]);
		if (strcmp(argv[i-1], "-dict") == 0)
			tmp->set_dict_string(argv[i]);
	}
	res=tmp;
	return 1;
}
