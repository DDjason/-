// ImageProcessRGB.cpp: implementation of the CImageProcessRGB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "ImageProcessRGB.h"
#include "BaseColorInfo.h"
#include <cmath>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImageProcessRGB::CImageProcessRGB(CBaseColorInfo *img, int width, int height)
{
	int size = width * height;
	_img = new CBaseColorInfo [size];
	_oldimg = new CBaseColorInfo [size];
	for(int i = 0; i < size; ++ i){
		_img[i] = img[i];
		_oldimg[i] = img[i];
	}
	_width = width;
	_height = height;
}

CImageProcessRGB::~CImageProcessRGB()
{
	if(_img != NULL)
		delete []_img;
	if(_oldimg != NULL)
		delete []_oldimg;
}

void CImageProcessRGB::jisuan_RGB_CMY()
{
	int i;
	int size = _width * _height;
	for(i = 0; i < size; ++ i){
		int r = 255 - _oldimg[i].GetRed() ;
		int g = 255 - _oldimg[i].GetGreen();
		int b = 255 - _oldimg[i].GetBlue();
		_img[i] =  CBaseColorInfo(r, g, b);
	}
}

void CImageProcessRGB::jisuan_RGB_YUV()
{
	int i;
	int size = _width * _height;
	for(i = 0; i < size; ++ i){
		double r = _oldimg[i].GetRed() / 255.0 ;
		double g = _oldimg[i].GetGreen() / 255.0;
		double b = _oldimg[i].GetBlue() / 255.0;
		double y = 0.299 * r + 0.587 * g + 0.114 * b;
		double u = b - y;
		double v = r - y;
		_img[i] =  CBaseColorInfo(y * 255, u * 255, v * 255);
	}
}

void CImageProcessRGB::jisuan_RGB_YCbCr()
{
	int i;
	int size = _width * _height;
	for(i = 0; i < size; ++ i){
		double r = _oldimg[i].GetRed() / 255.0 ;
		double g = _oldimg[i].GetGreen() / 255.0;
		double b = _oldimg[i].GetBlue() / 255.0;
		double y = 0.299 * r + 0.587 * g + 0.114 * b;
		double cb = 2 * (1 - 0.114) * (b - y);
		double cr = 2 * (1 - 0.299) * (r - y);
		_img[i] =  CBaseColorInfo(y * 255, cb * 255, cr * 255);
		
	}
}

void CImageProcessRGB::jisuan_RGB_HSI()
{
	int i;
	int size = _width * _height;
	for(i = 0; i < size; ++ i){
		double r = _oldimg[i].GetRed() / 255.0 ;
		double g = _oldimg[i].GetGreen() / 255.0;
		double b = _oldimg[i].GetBlue() / 255.0;
		double I = (r + g + b) / 3 * 255;
		double S;
		double d = r;
		if(d > g)
			d = g;
		if(d > b)
			d = b;
		if(r == b && b == g && r == 0)
			S = 0;
		else
			S = (1 - 3 * d / (r + g + b)) * 255;
		double H;
		double fenzi = ((r - g) + (r - b)) / 2.0;
		double fenmu = sqrt((r - g) * (r - g) + (r - b) * (g - b));
		if(b > g){
			H = 2 * acos(-1.0) - acos(fenzi / fenmu);
		}
		else if(r != g ||r != b){
			H = acos( fenzi / fenmu);
		}
		H = H /  (2 * acos(-1.0)) * 255;
		_img[i] =  CBaseColorInfo(H, S, I);
		_oldimg[i] = _img[i];
	}
}

void CImageProcessRGB::jisuan_HSI_RGB(){
	
	CImageProcessRGB::jisuan_RGB_HSI();
	double H, S, I;
	int size = _width * _height;
	for(int i = 0; i < size; ++ i){
		double H = _oldimg[i].GetRed() / 255.0 ;
		double S = _oldimg[i].GetGreen() / 255.0;
		double I = _oldimg[i].GetBlue() / 255.0;
		double x =  acos(-1.0);
		H *= 2 * x;
		H += x / 3.0;

	//	S *= 0.5;
		double h = H / x * 180;
		double r, g, b;
		if(h >= 0 && h <= 120){
			r = I * (1 + S * cos(H) / cos(x / 3.0 - H));
			b = I * (1 - S);
			g = 3 * I - (b + r);
		}
		else if(h > 120 && h <= 240){
			r = I * (1 - S);
			g = I * (1 + S * cos(H - x * 120.0 / 180.0) / cos(x - H));
			b = 3 * I - (r + g);
		}
		else if(h > 240 && h <= 360){
			g = I * (1 - S);
			b = I * (1 + S * cos(H - 240.0 / 180.0 * x) / cos(300.0 / 180.0 * x - H));
			r = 3 * I - (g + b);
		}
		_img[i] = CBaseColorInfo(r * 255, g * 255, b * 255);
	}
}

void CImageProcessRGB::jisuan_15_a()
{
	int size = _width * _height;
	double r, g, b, p;

	for(int i = 0; i < size; ++ i)
	{
		 r = _oldimg[i].GetRed() / 255.0;
		 g = _oldimg[i].GetGreen() /255.0;
		 b = _oldimg[i].GetBlue() /255.0;
		 if(r == g && g == b)
			 p = 0;
		 else
		 {
			double fenzi = 0.5 * ((r - g) + (r - b));
			double fenmu = (r - g) * (r - g) + sqrt((r - b) * (g - b));
			 p = acos(fenzi / fenmu);
			if(b > g)
				p = 2 * acos(-1.0) - p;
			p = p / (2 * acos(-1.0)) * 255;

		 }
		_img[i] = CBaseColorInfo(p, p, p);

	}
}

void CImageProcessRGB::jisuan_15_b()
{
	int size = _width * _height;
	double r, g, b;

	for(int i = 0; i < size; ++ i)
	{
		 r = _oldimg[i].GetRed() / 255.0;
		 g = _oldimg[i].GetGreen() /255.0;
		 b = _oldimg[i].GetBlue() /255.0;
		double d = r;
		if(d > g)
			d = g;
		if(d > b)
			d = b;
		double p =(1 - 3 * d / (r + g + b)) * 255;
		_img[i] = CBaseColorInfo(p, p, p);

	}
}

void CImageProcessRGB::jisuan_15_c()
{
	int size = _width * _height;
	double r, g, b;

	for(int i = 0; i < size; ++ i)
	{
		 r = _oldimg[i].GetRed() / 255.0;
		 g = _oldimg[i].GetGreen() /255.0;
		 b = _oldimg[i].GetBlue() /255.0;
		
		double p =((r + g + b) / 3) * 255;
		_img[i] = CBaseColorInfo(p, p, p);

	}
}