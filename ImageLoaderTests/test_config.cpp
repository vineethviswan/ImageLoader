
#include "gtest/gtest.h"

#include "config.h"
#include "test_utils.h"

#include <cstdlib>
#include <string>

namespace ImageLoaderTests
{
	TEST (ConfigTest, ReturnsFilenameIfEnvNotSet)
	{
		SetAssetsEnv (nullptr);
		std::string result = config::GetConfigPath ("test.png");
		EXPECT_EQ (result, "test.png");
	}

	TEST (ConfigTest, ReturnsPathWithEnvSet)
	{
		SetAssetsEnv ("C:/assets");
		std::string result = config::GetConfigPath ("test.png");
		EXPECT_EQ (result, "C:/assets/test.png");
	}

	TEST (ConfigTest, HandlesTrailingSlashInEnv)
	{
		SetAssetsEnv ("C:/assets/");
		std::string result = config::GetConfigPath ("test.png");
		EXPECT_EQ (result, "C:/assets/test.png");
	}

	TEST (ConfigTest, HandlesLeadingSlashInFilename)
	{
		SetAssetsEnv ("C:/assets");
		std::string result = config::GetConfigPath ("/test.png");
		EXPECT_EQ (result, "C:/assets/test.png");
	}

	TEST (ConfigTest, HandlesBothSlashes)
	{
		SetAssetsEnv ("C:/assets/");
		std::string result = config::GetConfigPath ("/test.png");
		EXPECT_EQ (result, "C:/assets/test.png");
	}

	TEST (ConfigTest, HandlesEmptyEnv)
	{
		SetAssetsEnv ("");
		std::string result = config::GetConfigPath ("test.png");
		EXPECT_EQ (result, "test.png");
	}

	TEST (ConfigTest, HandlesNullFilename)
	{
		SetAssetsEnv ("C:/assets");
		std::string result = config::GetConfigPath (nullptr);
		EXPECT_EQ (result, "");
	}

} // namespace ImageLoaderTests