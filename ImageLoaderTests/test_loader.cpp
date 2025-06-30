#include "gtest/gtest.h"
#include "test_utils.h"
#include "loader.h"

namespace ImageLoaderTests
{
    TEST (LoaderTest, LoadJPGImage) {
        SetAssetsEnv ("D:/Git/ImageLoader/testfiles"); // Update this path to your test assets directory
        ImageLoader loader;
        int result = loader.LoadImage ("test_jpg_image.jpg");
        EXPECT_EQ (result, 0); // Ensure the image loads successfully
        EXPECT_EQ (loader.GetWidth (), 3840);
        EXPECT_EQ (loader.GetHeight (), 2160);
        EXPECT_EQ (loader.GetChannels (), 3);
    }

    TEST (LoaderTest, LoadBMPImage) {
        SetAssetsEnv ("D:/Git/ImageLoader/testfiles"); // Update this path to your test assets directory
        ImageLoader loader;
        int result = loader.LoadImage ("test_bmp_image.bmp");
        EXPECT_EQ (result, 0); // Ensure the image loads successfully
        EXPECT_EQ (loader.GetWidth (), 647);
        EXPECT_EQ (loader.GetHeight (), 432);
        EXPECT_EQ (loader.GetChannels (), 3);
    }

    TEST (LoaderTest, LoadGIFImage) {
        SetAssetsEnv ("D:/Git/ImageLoader/testfiles"); // Update this path to your test assets directory
        ImageLoader loader;
        int result = loader.LoadImage ("test_gif_image.gif");
        EXPECT_EQ (result, 0); // Ensure the image loads successfully
        EXPECT_EQ (loader.GetWidth (), 1000);
        EXPECT_EQ (loader.GetHeight (), 1000);
        EXPECT_EQ (loader.GetChannels (), 4);
    }

    TEST (LoaderTest, LoadPNGImage) {
        SetAssetsEnv ("D:/Git/ImageLoader/testfiles"); // Update this path to your test assets directory
        ImageLoader loader;
        int result = loader.LoadImage ("test_png_image.png");
        EXPECT_EQ (result, 0); // Ensure the image loads successfully
        EXPECT_EQ (loader.GetWidth (), 2560);
        EXPECT_EQ (loader.GetHeight (), 1080);
        EXPECT_EQ (loader.GetChannels (), 3);
    }

    TEST (LoaderTest, LoadNonExistentImage) {
        SetAssetsEnv ("D:/Git/ImageLoader/testfiles");
        ImageLoader loader;
        int result = loader.LoadImage ("nonexistent_image.png");
        EXPECT_NE (result, 0); // Ensure the image fails to load
    }

}