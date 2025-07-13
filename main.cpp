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

	std::vector<std::string> m_OR_p_list;

	std::vector<std::string> installation;


	if(static_cast<std::string>(argv[1]) == "fix"){

		headers_list = find_headers(static_cast<std::string>(argv[2]));
		
		llibs_list = resolve_llibs(llib_map, headers_list);
	
		pkgs_list = resolve_pkg_per_pm(llibs_list, pm_here);

		m_OR_p_list = get_missing_OR_present(pkgs_list, pm_map, pm_here, flag_missing);

		installation = install(m_OR_p_list, pm_map, pm_here);

	}


	if(static_cast<std::string>(argv[1]) == "enlist"){

		if(static_cast<std::string>(argv[2]) == flag_missing || static_cast<std::string>(argv[2]) == flag_present){

			headers_list = find_headers(static_cast<std::string>(argv[3]));
   
			llibs_list = resolve_llibs(llib_map, headers_list);
	
			pkgs_list = resolve_pkg_per_pm(llibs_list, pm_here);

			m_OR_p_list = get_missing_OR_present(pkgs_list, pm_map, pm_here, argv[2]);
		}

		else std::cerr << "Error: expected flags '-m' or '-p' after \"enlist\"" << "\n";
	}

	return 0;
}