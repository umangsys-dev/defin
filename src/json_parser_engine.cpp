#include "json_parser_engine.hpp"

std::unordered_map<std::string, std::string> jpeng::parse(std::unordered_map<std::string, std::string> given_map, std::string key, const std::regex expr){

	std::unordered_map<std::string, std::string> resultant_map;
	
	std::string line = given_map[key];

	std::smatch sm;

	auto begin = std::sregex_iterator(line.begin(), line.end(), expr);
	auto end  = std::sregex_iterator();

	for(; begin != end; begin++){

		std::string st = begin->str();

		if(regex_match(st, sm, expr)) resultant_map.insert({sm[1], sm[2]});
	}

	return resultant_map;
}