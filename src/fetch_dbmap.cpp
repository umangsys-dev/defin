#include "fetch_dbmap.hpp"

std::unordered_map<std::string, std::string> get_llib_OR_pkg_map(std::string json_filepath){

	std::unordered_map<std::string, std::string> json_map;

	const std::regex expr("\"(.+?)\" *: *\"(.+?)\"");

	std::string line;

	std::cout << line;

	std::ifstream file(json_filepath);

	std::ostringstream oss;

	oss << file.rdbuf();

	line = oss.str();

	file.close();

	std::string key = "hirenkyaku";

	std::unordered_map<std::string, std::string> pass = {{key, line}};

	json_map = jpeng::parse(pass, key, expr);

	return json_map;

}


std::unordered_map<std::string, std::unordered_map<std::string, std::string>> get_pm_map(std::string json_filepath){

	std::unordered_map<std::string, std::unordered_map<std::string, std::string>> final_map;

	std::ostringstream oss;

	const std::regex bigger_expr("\"([a-z]+?)\" *: *(\\{\n+\t+\".+\",\n+\t+\".+\"\n+\t+\\})");

	const std::regex expr("\"(.+?)\" *: *\"(.+?)\"");

	std::string line = "";

	std::ifstream file(json_filepath);

	oss << file.rdbuf();

	line = oss.str();

	std::string key = "xianyang";

	std::unordered_map<std::string, std::string> temp = {{key, line}};

	std::unordered_map<std::string, std::string> intermediate_storage = jpeng::parse(temp, key, bigger_expr);

	for(auto& m : intermediate_storage){

		temp[key] = m.second;

		std::unordered_map<std::string, std::string> cmd_map = jpeng::parse(temp, key, expr);

		final_map.insert({m.first, cmd_map});
	}

	return final_map;
}