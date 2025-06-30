#pragma once

#include <string>

class ImageLoader
{
public:
    // Constructor
    ImageLoader () = default;

    // Method to load an image
    int LoadImage (const std::string& filename);

    // Getters for image properties
    int GetWidth () const { return width; }
    int GetHeight () const { return height; }
    int GetChannels () const { return channels; }

private:
    int width = 0;
    int height = 0;
    int channels = 0;
};