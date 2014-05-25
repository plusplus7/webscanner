#ifndef WEBSCANNER_BASE_CMDDATA_H
#define WEBSCANNER_BASE_CMDDATA_H

#include <string>
#include <vector>
using std::string;
using std::vector;
class CmdData
{
public:
	void init_data();
	void set_url_string(char *url);
	void set_dict_string(char *dict);
	void set_output_type(int type);
	void set_output_filename(char *filename);
	void clear_data();
	string get_url_string();
	string get_dict_string();
	string get_output_filename();
	int get_output_type();
protected:
private:
	vector<string> string_set;
	int url_index;
	int dict_index;
	int output_index;
	int output_type;
};
#endif // end of  WEBSCANNER_BASE_CMDDATA_H

