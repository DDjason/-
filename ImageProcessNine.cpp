// ImageProcessNine.cpp: implementation of the CImageProcessNine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "ImageProcessNine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImageProcessNine::CImageProcessNine(int *img, int width, int height)
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

CImageProcessNine::~CImageProcessNine()
{
		if(_img != NULL)
		delete []_img;
	if(_oldimg != NULL)
		delete []_oldimg;

}

void CImageProcessNine::jisuan_fushi(int level)
{
	int size = _width * _height;
	int pp = level / 2;
	int i, j;
	for(i = pp; i < _width - pp; ++ i )
	{
		for(j = pp; j <_height - pp; ++ j)
		{
			int index = j * _width + i;
			if(_oldimg[index] == 0)
				continue;
			for(int x = i - pp; x <= i + pp; ++ x)
			{
				for(int y = j - pp; y <= j + pp; ++ y)
				{
					int temp = y * _width + x;
					if(_oldimg[temp] == 0){
						_img[index] = 0;
						break;
					}
				}
			}
		}
	}
}

void CImageProcessNine::jisuan_pengzhang(int level)
{
	int size = _width * _height;
	int pp = level / 2;
	int i, j;
	for(i = pp; i < _width - pp; ++ i )
	{
		for(j = pp; j <_height - pp; ++ j)
		{
			int index = j * _width + i;
			if(_oldimg[index] == 255)
				continue;
			for(int x = i - pp; x <= i + pp; ++ x)
			{
				for(int y = j - pp; y <= j + pp; ++ y)
				{
					int temp = y * _width + x;
					if(_oldimg[temp] == 255){
						_img[index] = 255;
						break;
					}
				}
			}
		}
	}
}
