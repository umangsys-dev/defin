#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "fetch_dbmap.hpp"

std::vector<std::string> resolve_llibs(std::unordered_map<std::string, std::string> map, std::vector<std::string> headers);

std::vector<std::string> resolve_pkg_per_pm(std::vector<std::string>, std::string);