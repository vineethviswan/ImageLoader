#pragma once

#include <string>
#include <cstdlib>

namespace config
{
	inline std::string GetConfigPath(const char* filename)
	{
		if(const char* env = std::getenv("IMAGE_LOADER_ASSETS")) {
			return std::string(env) + "/" + filename;
		}
		return filename;
	}
}