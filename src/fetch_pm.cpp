#include "fetch_pm.hpp"

std::string get_pm(std::unordered_map<std::string, std::unordered_map<std::string, std::string>> json_map){

	std::vector<std::string> pkgmngr_list;

	for(auto& m : json_map) pkgmngr_list.push_back(m.first);

	std::regex exp("\\{pm\\}");

	std::string cmd = "which {pm}";

	for(auto& pm : pkgmngr_list){

		std::string specific_cmd = std::regex_replace(cmd, exp, pm);

		std::string buff = "";

		tiny::Process check(specific_cmd, "", [&buff, &pm](const char* bytes, size_t n){

			buff.append(bytes, n);

		}, [](const char* bytes, size_t n){});

		int exit_code = check.get_exit_status();

		if(exit_code != 0) std::cerr << "Error: failed to fetch package manager exited with code: " << exit_code << std::endl;

		if(buff.size() > 0) return pm;
	}
}