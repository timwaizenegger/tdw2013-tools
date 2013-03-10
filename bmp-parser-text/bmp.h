
#pragma once

typedef int LONG;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned char BYTE;

#pragma pack(2) //header of the bmp must be 2 byte aligned.

typedef struct tagBITMAPFILEHEADER {
   WORD    bfType;        // must be 'BM' 
   DWORD   bfSize;        // size of the whole .bmp file
   WORD    bfReserved1;   
   WORD    bfReserved2;
   DWORD   bfOffBits;     
} BITMAPFILEHEADER;

#pragma pack() // 

typedef struct tagc {
    DWORD headerSize;
    LONG width;
    LONG height;
    WORD planeCount;
    WORD bitDepth;
    DWORD compression;
    DWORD compressedImageSize;
    LONG horizontalResolution;
    LONG verticalResolution;
    DWORD numColors;
    DWORD importantColors;
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD {
   unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char reserved;
} RGBQUAD;

//typedef struct bmpFILE
//{
    //BITMAPFILEHEADER header;
    //BITMAPINFOHEADER info;
    //RGBQUAD colors[256];
    //unsigned short image[1];
//}BMPFILE;


//class Bitmap {
//public:
    //Bitmap(const char* filename);
    //~Bitmap();
    //RGBQUAD* pixels;
    //BITMAPFILEHEADER fh;
    //BITMAPINFOHEADER ih;

    //private:

//};


