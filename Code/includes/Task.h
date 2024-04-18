#pragma once
#include <string>
#include <vector>

struct Task
{

	std::string Descrip;
	bool done;

};

void save(const std::vector<Task>& task,const std::string& filename);

std::vector<Task> load(const std::string& filename);

