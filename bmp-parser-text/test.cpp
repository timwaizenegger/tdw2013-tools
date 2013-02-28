#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"

using namespace std;


vector<char> bmp_file_buffer;
PBITMAPFILEHEADER bmp_file_header;
PBITMAPINFOHEADER bmp_info_header;
int bmp_data_offset;


void fillBpmBuffer() {
    std::ifstream file("/home/miller/test.bmp");

    if (file) {
        file.seekg(0,std::ios::end);
        std::streampos length = file.tellg();
        file.seekg(0,std::ios::beg);

        bmp_file_buffer.resize(length);
        file.read(&bmp_file_buffer[0],length);

        bmp_file_header = (PBITMAPFILEHEADER)(&bmp_file_buffer[0]);
        bmp_info_header = (PBITMAPINFOHEADER)(&bmp_file_buffer[0] + sizeof(BITMAPFILEHEADER));
        bmp_data_offset = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
        
    }

}
int main() {
fillBpmBuffer();

// get the pointer to the first element in the array, add 10 (10 byte offset) re-cast to int* (pointer to int), dereference to get the value
int bmpOffset = *(int*) ( &bmp_file_buffer[0] + 10);
cout << bmpOffset << endl;
cout << sizeof(unsigned int) << endl;
cout << sizeof(char) << endl;
cout << "bmp_data_offset: "<< bmp_data_offset << endl;
cout << (int) bmp_file_buffer[bmp_data_offset] << endl;
cout <<  sizeof(bmp_file_buffer) << endl;


//transverses the array of pixels
for(int i=bmp_data_offset; i < bmp_file_buffer.size(); i++){
	cout << (int) bmp_file_buffer[i] << endl;
	
	//comparison: acceps if it has a color
	if((int) bmp_file_buffer[bmp_data_offset]){
		return 0;
	}
}

return 0;

}

