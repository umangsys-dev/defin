#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

bool is_supported_filetype(auto file);

bool is_blacklisted_dir(auto file);

std::vector<std::string> find_headers(std::string);