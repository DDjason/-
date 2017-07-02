// ImageProcess.cpp: implementation of the CImageProcess class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <math.h>
#include "imagestu.h"
#include "ImageProcess.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImageProcess::CImageProcess(int *img, int width, int height)
{
	int size = width * height;
	_img = new int[size];
	_oldimg = new int[size];
	for(int i = 0; i < size; ++ i){
		_img[i] = img[i];
		_oldimg[i] = img[i];
	}
	_width = width;
	_height = height;
}

CImageProcess::~CImageProcess()
{
	if(_img != NULL)
		delete []_img;
	if(_oldimg != NULL)
		delete []_oldimg;
}

void CImageProcess::jisuan_lapulasi(){
	int size = _width * _height;
	int i, j;
	for(i = 1; i < _width - 1; ++ i){
	
		for(j = 1; j <_height - 1; ++ j)
		{
			int index = j * _width + i;
			int s = 0;
			s += _oldimg[index - 1];
			s += _oldimg[index + 1];
			s += _oldimg[index - _width];
			s += _oldimg[index + _width];
			s += _oldimg[index - _width - 1];
			s += _oldimg[index - _width + 1];
			s += _oldimg[index + _width - 1];
			s += _oldimg[index + _width + 1];
			s -= 8 * _oldimg[index];
			_img[index] = abs(s);
		}
	}
}

void CImageProcess::jisuan_Robert(){
	int size = _width * _height;
	int i, j;
	for(i = 0; i < _width - 1; ++ i){
		for(j = 0; j < _height - 1; ++ j){
			int index = j * _width + i;
			_img[index] = abs(_oldimg[index + _width + 1] - _oldimg[index]) 
				+ abs(_oldimg[index + _width] -_oldimg[index + 1]);
		}
	}
}

void CImageProcess::jisuan_Sobel(){
	int i, j;
	for(i = 1; i <_width - 1; ++ i){
		for(j = 1; j < _height - 1; ++ j){
			int index = j * _width + i;
			int z1= _oldimg[index - _width - 1];
			int z2= _oldimg[index - _width];
			int z3= _oldimg[index - _width + 1];
			int z4= _oldimg[index  - 1];
			int z5= _oldimg[index];
			int z6= _oldimg[index + 1];
			int z7= _oldimg[index + _width - 1];
			int z8= _oldimg[index + _width];
			int z9= _oldimg[index + _width + 1];
			_img[index] = abs((z7 + 2 * z8 + z9) -(z1 + 2 * z2 + z3))
				+ abs((z3 + 2 * z6 + z9) - (z1 + 2 * z4 + z7));
		}
	}
}