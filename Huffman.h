#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <vector>
#include <ctime>
#include <direct.h>
#include "dirent.h"
using namespace std;


struct NODE {
	unsigned char c;	// ky tu
	int freq;			// so lan xuat hien
	bool used;			// danh dau node da xu ly chua
	int nLeft;			// chi so nut con nam ben trai
	int nRight;			// chi so nut con nam ben phai
};

struct MABIT {
	char* bits;
	int soBit;
};

const int MAX_NODE = 256 * 9;
const int MAX_BIT_LEN = 10000;

/********************************NEN TAP TIN********************************/
//ham khoi tao 1 node
void KhoiTao();
//tao bang thong ke tan so xuat hien cua cac ky tu
void ThongKeTanSoXuatHien(char* tenFile);
//xuat bang tan so thong ke
void XuatBangThongKe();
//ham tim 2 phan tu co tan suat thap nhat
bool Tim2PhanTuMin(int& i, int& j, int nNode);
//xay dung cay Huffman
int TaoCayHuffman();
//duyet cay Huffman
void DuyetCayHuffman(int node, char maBit[], int nMaBit);
//phat sinh bang ma bit
void PhatSinhMaBit(int nRoot);
//xuat bang ma bit
void XuatBangMaBit();
//ghi bang thong ke
void GhiBangThongKe(FILE*& fpwrite);
//ma hoa 1 ky tu
void MaHoa1KyTu(FILE*& fpwrite, unsigned char c, unsigned char& out, unsigned char& viTriBit);
//nen Huffman
void NenHuffman(char* inputFile, char* outputFile, bool type);

/********************************GIAI NEN TAP TIN********************************/
//reset va load lai cay Huffman
void LoadHuffmanTree(FILE*& fpread);
//dem so ky tu
int DemSoKiTu();
//ham lay bit
int getbit(unsigned char out, int i);
//ham bat bit
void onbit(char unsigned& out, int i);
//giai nen file
void DeCompress(char* outputpath, char* decodepath);

/********************************NEN VA GIAI NEN THU MUC********************************/
//chuyen doi string sang char*
char* convertString_CharArr(string str);
//nen folder
void NenFolder(string inputFolder, string outputFolder);
//giai nen folder
void GiaiNenFolder(string inputFolder, string outputFolder);
