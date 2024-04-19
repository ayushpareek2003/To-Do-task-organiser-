#include "Task.h"
#include <vector>
#include <string>
#include <filesystem>
#include <algorithm>
#include <fstream>


void save(const std::vector<Task>& tasks, const std::string& filename)
{
	std::ofstream ostream(filename);
	ostream << tasks.size();

	for (const Task& task : tasks) {
		std::string descrip = task.Descrip;
		std::replace(descrip.begin(), descrip.end(), ' ', '_');

		ostream << '\n' << descrip << ' ' << task.done;


	}
}

std::vector<Task> load(const std::string& filename)
{
	if (!std::filesystem::exists(filename)) {
		return std::vector<Task>();

	}

	std::vector<Task> tasks;
	std::ifstream istream(filename);

	int n;
	istream >> n;

	for (int i = 0; i < n; i++) {
		std::string descrip;
		bool done;
		istream >> descrip >> done;
		std::replace(descrip.begin(), descrip.end(), '_', ' ');

		tasks.push_back(Task{ descrip, done });


	}

	return tasks;
}
