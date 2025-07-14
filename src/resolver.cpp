#include "resolver.hpp"

std::vector<std::string> resolve_llibs(std::unordered_map<std::string, std::string> map, std::vector<std::string> headers){

	std::vector<std::string> resolved;

	for(const auto& each : headers){

		std::string st = map[each];

		if(st.size() > 0){
			resolved.push_back(map[each]);
		}
	}

	return resolved;
}


std::vector<std::string> resolve_pkg_per_pm(std::vector<std::string> llibs_list, std::string pm_here){

	std::string pkg_json_filepath = "/usr/local/share/defin/llib-pkg_{pm}.json";

	std::regex exp("\\{pm\\}");

	std::string pm_specific_json_filepath = std::regex_replace(pkg_json_filepath, exp, pm_here);

	std::unordered_map<std::string, std::string> pkg_map = get_llib_OR_pkg_map(pm_specific_json_filepath);

	std::vector<std::string> pkgs_list;

	for(auto& m : llibs_list){

		pkgs_list.push_back(pkg_map[m]);
	}

	return pkgs_list;
}