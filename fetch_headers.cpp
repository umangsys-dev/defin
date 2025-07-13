#include "fetch_headers.hpp"

bool is_supported_filetype(auto file){

	std::vector<std::string> filetypes = {".cpp", ".hpp", ".h", ".c"};

	for(auto ext : filetypes){

		if(file.path().extension().string() == ext) return 1;

		else return 0;
	}
}

bool is_blacklisted_dir(auto dir){

	std::vector<std::string> blacklist = {"build"};

	for(auto m : blacklist){

		if(dir.path().filename().string() == m) return 1;

		else return 0;
	}
}

std::vector<std::string> find_headers(std::string filepath){

	std::vector<std::string>libs_used;

	std::string line = "";

	const std::regex expr("#include[ *]<(.+?)>");

	std::smatch sm;

	std::ostringstream oss;

	for(auto it = fs::recursive_directory_iterator(filepath); it!=fs::recursive_directory_iterator(); it++){

		auto entry = *it;

		if(entry.is_directory() && is_blacklisted_dir(entry)){
			it.disable_recursion_pending();
			continue;
		}

		if(!is_supported_filetype(entry)) {continue;}

		std::ifstream file(entry.path());

		oss << file.rdbuf();

		line = oss.str();

		auto begin = std::sregex_iterator(line.begin(), line.end(), expr);
		auto end = std::sregex_iterator();

		for(; begin != end; begin++){

			std::string st = begin->str();

			if(regex_match(st, sm, expr)) libs_used.push_back(sm[1]);
		}

		file.close();

	}

	std::sort(libs_used.begin(), libs_used.end());
	auto temp = std::unique(libs_used.begin(), libs_used.end());
	libs_used.erase(temp, libs_used.end());

	return libs_used;
}
