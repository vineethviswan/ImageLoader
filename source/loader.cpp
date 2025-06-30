
#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include <iostream>
#include "config.h"
#include "loader.h"

int ImageLoader::LoadImage (const std::string& filename)
{
    std::string image_path = config::GetConfigPath (filename.c_str ());
    unsigned char* img = stbi_load (image_path.c_str (), &width, &height, &channels, 0);
    if (img == nullptr)
    {
        std::cerr << "Failed to load image: " << filename << std::endl;
        return 1; // Error code
    }
    stbi_image_free (img);
    return 0; // Success
}
