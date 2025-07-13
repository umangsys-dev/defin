#include "curate_missing.hpp"

std::vector<std::string> get_missing_OR_present(std::vector<std::string> detected_libs, std::unordered_map<std::string, std::unordered_map<std::string, std::string>>json_map, std::string distro_name, std::string flag){

	std::vector<std::string> missing_list;

	std::vector<std::string> present_list;

	std::string lib_found_cmd = json_map[distro_name]["find"];

	const std::regex regex_missing("not");

	const std::regex expr("\\{pkg\\}");

	for(const auto& pkg : detected_libs){

		std::string buff = "";

		std::string distro_specific_cmd = std::regex_replace(lib_found_cmd, expr, pkg);

		std::vector<std::string> cmd_storage = {distro_specific_cmd};

		tiny::Process check(distro_specific_cmd, "", [&buff](const char* bytes, size_t n){

			buff.append(bytes, n);

		}, [&buff](const char* bytes, size_t n) {

			buff.append(bytes, n);
		});

		if(regex_search(buff, regex_missing)) missing_list.push_back(pkg);

		else present_list.push_back(pkg);
	}

	if(flag == "-p"){

		std::cout << "packages found:" << std::endl;
		for(auto& m : present_list) std::cout << std::setw(15) << "" << m << std::endl;
		return present_list;
	}


	if(flag == "-m"){

		std::cout << "missing packages:" << std::endl;
		for(auto& m : missing_list) std::cout << std::setw(15) << "" << m << std::endl;
		return missing_list;
	}
}