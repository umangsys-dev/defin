#include "fetch_dbmap.hpp"
#include "fetch_headers.hpp"
#include "resolver.hpp"
#include "fetch_pm.hpp"
#include "curate_missing.hpp"
#include "auto_install.hpp"

int main(int argc, char**argv){

	// fix cmd: sudo defin fix usr/local/project
	// enlist cmd flags -p | -m: sudo defin enlist -m usr/local/project

	std::string flag_missing = "-m";
	std::string flag_present = "-p";

	std::unordered_map<std::string, std::unordered_map<std::string, std::string>> pm_map = get_pm_map("/usr/local/share/defin/pm-cmd.json");

	std::unordered_map<std::string, std::string> llib_map = get_llib_OR_pkg_map("/usr/local/share/defin/header-llib.json");

	std::string pm_here = get_pm(pm_map);

	std::vector<std::string> headers_list;

	std::vector<std::string> llibs_list;

	std::vector<std::string> pkgs_list;

	std::vector<std::string> missing_list;

	std::vector<std::string> present_list;

	std::vector<std::string> installation;


	if(static_cast<std::string>(argv[1]) == "fix"){

		headers_list = find_headers(static_cast<std::string>(argv[2]));

		if(headers_list.size() == 0){
			std::cout << "No listed c++ packages implemented." << std::endl;
			return 0;
		}
		
		llibs_list = resolve_llibs(llib_map, headers_list);
	
		pkgs_list = resolve_pkg_per_pm(llibs_list, pm_here);

		missing_list = get_missing_OR_present(pkgs_list, pm_map, pm_here, flag_missing);

		if(missing_list.size() == 0){
			std::cout << "No packages to fix." << std::endl;
			return 0;
		}

		installation = install(present_list, pm_map, pm_here);

	}


	if(static_cast<std::string>(argv[1]) == "enlist"){

		std::string given_flag = static_cast<std::string>(argv[2]);

		if(static_cast<std::string>(argv[2]) == flag_missing || static_cast<std::string>(argv[2]) == flag_present){

			headers_list = find_headers(static_cast<std::string>(argv[3]));

			if(headers_list.size() == 0){
				std::cout << "No listed c++ packages implemented." << std::endl;
				return 0;
			}
   
			llibs_list = resolve_llibs(llib_map, headers_list);
	
			pkgs_list = resolve_pkg_per_pm(llibs_list, pm_here);

			if(given_flag == flag_missing){

				missing_list = get_missing_OR_present(pkgs_list, pm_map, pm_here, flag_missing);

				if(missing_list.size() == 0){
					std::cout << "No missing packages." << std::endl;
					return 0;
				}else{
					std::cout << "Following packages missing:" << std::endl;
					for(auto& m : missing_list) std::cout << std::setw(15) << "" << m << std::endl;
				}
			}

			else{

				present_list = get_missing_OR_present(pkgs_list, pm_map, pm_here, flag_present);

				if(present_list.size() == 0){
					std::cout << "No packages present, meaning required packages are missing." << std::endl;
					std::cout << "Use \"sudo defin fix dir/\" to resolve missing packages." << std::endl;
					return 0;
				}else{
					std::cout << "Following packages found:" << std::endl;
					for(auto& m : present_list) std::cout << std::setw(25) << "" << m << std::endl;
				}
			}
		}

		else std::cerr << "Error: expected flags '-m' or '-p' after \"enlist\"" << "\n";
	}

	return 0;
}