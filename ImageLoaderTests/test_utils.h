#pragma once

#pragma once

#include <cstdlib>

namespace ImageLoaderTests
{
    inline void SetAssetsEnv (const char* value) {
#ifdef _WIN32
        _putenv_s ("IMAGE_LOADER_ASSETS", value ? value : "");
#else
        if (value)
            setenv ("IMAGE_LOADER_ASSETS", value, 1);
        else
            unsetenv ("IMAGE_LOADER_ASSETS");
#endif
    }
}