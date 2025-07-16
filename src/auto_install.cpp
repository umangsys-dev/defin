#include "auto_install.hpp"

std::vector<std::string> install(std::vector<std::string> missing_list, std::unordered_map<std::string, std::unordered_map<std::string, std::string>> manager_map, std::string pacman){

	std::vector<std::string> install_status;

	std::vector<std::string> failed_installs;

	std::string install_cmd = manager_map[pacman]["install"];

	std::regex exp("\\{pkg\\}");

	std::regex error_exp("([Ee]rror)*(E:)*");

	std::cout << "fetching the following packages: " << std::endl;

	for(auto& m : missing_list) std::cout << std::setw(6) << m << std::endl;

	std::cout << "---------------------------------" << std::endl;

	std::cout << "Total to be installed : " << missing_list.size() << std::endl;

	for(auto& lib : missing_list){

		std::string lib_specific_install_cmd = std::regex_replace(install_cmd, exp, lib);

		std::string buff = "";

		tiny::Process check(lib_specific_install_cmd, "", [&buff, &install_status, &error_exp](const char* bytes, size_t n){

			buff.append(bytes, n);

		}, [&buff, &install_status, &error_exp](const char* bytes, size_t n){

			buff.append(bytes, n);
		});

		int exit_code = check.get_exit_status();

		if(std::regex_search(buff, error_exp) || exit_code != 0){
			std::cerr << "Error: failed to install the package: " << lib << std::endl;
			continue;
		}
	}

	return install_status;
}