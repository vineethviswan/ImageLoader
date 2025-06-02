
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "config.h"

#include <iostream>

int main()
{
	std::cout << "STB_IMAGE...\n";

    int width, height, channels;
	std::string image_path = config::GetConfigPath("blue-aesthetic-2560x1080-17495.png");    
    unsigned char* img = stbi_load(image_path.c_str(), &width, &height, &channels, 0);    
    if (img == NULL) {
        printf("Failed to load image\n");
        return 1;
    }

    printf("Loaded image with width: %d, height: %d, channels: %d\n", width, height, channels);
    stbi_image_free(img);
	
}
