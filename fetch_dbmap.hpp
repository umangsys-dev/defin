#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <unordered_map>
#include "json_parser_engine.hpp"
#include <filesystem>

std::unordered_map<std::string, std::string> get_llib_OR_pkg_map(std::string json_filepath);

std::unordered_map<std::string, std::unordered_map<std::string, std::string>> get_pm_map(std::string json_filepath);