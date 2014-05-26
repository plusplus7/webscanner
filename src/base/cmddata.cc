#include "cmddata.h"
void CmdData::init_data()
{
	string_set.clear();
	url_index=-1;
	dict_index=-1;
	output_index=-1;
	output_type=-1;
}
void CmdData::set_url_string(char *url)
{
	string_set.push_back(string(url));
	url_index=string_set.size()-1;
}
void CmdData::set_dict_string(char *dict)
{
	string_set.push_back(string(dict));
	dict_index=string_set.size()-1;
}
void CmdData::set_output_filename(char *filename)
{
	string_set.push_back(string(filename));
	output_index=string_set.size()-1;
}
void CmdData::set_output_type(int type)
{
	output_type=type;
}
void CmdData::clear_data()
{
	string_set.clear();
}

string CmdData::get_url_string()
{
	if (url_index == -1)
		return string("");
	return string_set[url_index];
}


string CmdData::get_dict_string()
{
	if (dict_index == -1)
		return string("dict/webscanner_dict.list");
	return string_set[dict_index];
}

string CmdData::get_output_filename()
{
	if (output_index == -1)
		return string("webscanner.out");
	return string_set[output_index];
}
int CmdData::get_output_type()
{
	return output_type;
}
