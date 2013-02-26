#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"


std::vector<char> bmp_file_buffer;
PBITMAPFILEHEADER bmp_file_header;
PBITMAPINFOHEADER bmp_info_header;
int bmp_data_offset;


void fillBpmBuffer() {
    std::ifstream file("/home/tim/Desktop/test.bmp");

    if (file) {
        file.seekg(0,std::ios::end);
        std::streampos length = file.tellg();
        file.seekg(0,std::ios::beg);

        bmp_file_buffer.resize(length);
        file.read(&bmp_file_buffer[0],length);

        bmp_file_header = (PBITMAPFILEHEADER)(&bmp_file_buffer[0]);
        bmp_info_header = (PBITMAPINFOHEADER)(&bmp_file_buffer[0] + sizeof(BITMAPFILEHEADER));
        bmp_data_offset = sizeof(BITMAPFILEHEADER) + sizeof(PBITMAPINFOHEADER);
        
    }

}
int main() {
fillBpmBuffer();

// get the pointer to the first element in the array, add 10 (10 byte offset) re-cast to int* (pointer to int), dereference to get the value
int bmpOffset = *(int*) ( &bmp_file_buffer[0] + 10);


std::cout << bmpOffset << std::endl;


std::cout << sizeof(unsigned int) << std::endl;
std::cout << sizeof(char) << std::endl;


std::cout << bmp_data_offset << std::endl;

std::cout << (int) bmp_file_buffer[bmp_data_offset] << std::endl;

return 0;

}

