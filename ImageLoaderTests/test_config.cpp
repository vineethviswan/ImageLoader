#include "pch.h"
#include "config.h"

namespace ImageLoaderTests
{
    TEST (ConfigTest, ReturnsFilenameIfEnvNotSet) {
        // Unset the environment variable for this test
#ifdef _WIN32
        _putenv_s ("IMAGE_LOADER_ASSETS", "");
#else
        unsetenv ("IMAGE_LOADER_ASSETS");
#endif

        std::string result = config::GetConfigPath ("test.png");
        EXPECT_EQ (result, "test.png");
    }

    TEST (ConfigTest, ReturnsPathWithEnvSet) {
        // Set the environment variable
#ifdef _WIN32
        _putenv_s ("IMAGE_LOADER_ASSETS", "C:/assets");
#else
        setenv ("IMAGE_LOADER_ASSETS", "/assets", 1);
#endif

        std::string result = config::GetConfigPath ("test.png");
#ifdef _WIN32
        EXPECT_EQ (result, "C:/assets/test.png");
#else
        EXPECT_EQ (result, "/assets/test.png");
#endif
    }
}