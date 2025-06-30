#pragma once

#include <string>
#include <cstdlib>

namespace config
{
	inline std::string GetConfigPath(const char* filename)
	{
		if (!filename)
		{
			return "";
		}

        const char* env = std::getenv ("IMAGE_LOADER_ASSETS");
        if (env && *env)
        {
            std::string base (env);
            // Remove trailing slash from env if present
            if (!base.empty () && (base.back () == '/' || base.back () == '\\'))
            {
                base.pop_back ();
            }
            // Remove leading slash from filename if present
            std::string fname (filename);
            if (!fname.empty () && (fname.front () == '/' || fname.front () == '\\'))
            {
                fname = fname.substr (1);
            }
            return base + "/" + fname;
        }
        return filename;
	}
}