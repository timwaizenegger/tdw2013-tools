#include <iostream>
#include <fstream>
#include <vector>
#include "bmp.h"
#include <cmath>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int fillBpmBuffer() {
	FILE *file;
	BITMAPFILEHEADER header;
	BITMAPINFOHEADER info;
	RGBQUAD *palette;
	int i = 0;
	
	file = fopen("/home/miller/test.bmp", "rb");
	if( !file ) {
		cout << "Error opening file." << endl;
		return -1;
	}

	if( fread(&header, 1, sizeof(BITMAPFILEHEADER), file) != sizeof(BITMAPFILEHEADER) ) {
		cout << "Error reading bmp header." << endl;
	    return -1;
	}

	if( fread(&info, 1, sizeof(BITMAPINFOHEADER), file) != sizeof(BITMAPINFOHEADER) ) {
		cout << "Error reading image info" << endl;
	    return -1;
	}

	if( info.numColors > 0 ) {
		cout << "Reading palette." << endl;
	   	palette = (RGBQUAD*)malloc(sizeof(RGBQUAD) * info.numColors);
	   	if( fread(palette, sizeof(RGBQUAD), info.numColors, file) != (info.numColors * sizeof(RGBQUAD)) ) {
			cout << "Error reading palette" << endl;
	      	return -1;
		}
	}
	
	RGBQUAD *pixel = (RGBQUAD*) malloc( sizeof(RGBQUAD));
	int read, j;
	for( j=0; j<info.height; j++ ) {
		cout << "ROW NUMBER: " << j+1 << endl;
		read = 0;
		for( i=0; i<info.width; i++ ) {
			if( fread(pixel, 1, sizeof(RGBQUAD), file) != sizeof(RGBQUAD) ) {
				cout << "Error reading pixel!" << endl;
				return -1;
			}
			read += sizeof(RGBQUAD);
			cout << "Pixel " << i+1 << ": " << (int)pixel->red << " " << (int)pixel->green <<" " <<  (int)pixel->blue << endl;
		}
		//if( read % 4 != 0 ) {
			//read = 4 - (read%4);
			//cout << "Padding: " <<  read  << " bytes" << endl;
			//fread( pixel, read, 1, file );
		//}
	}

	fclose(file);
}

int main() {
	int z = fillBpmBuffer();

	return 0;

}
