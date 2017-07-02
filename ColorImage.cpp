// ColorImage.cpp: implementation of the CColorImage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "ColorImage.h"
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

CColorImage::CColorImage(CBaseColorInfo *img,int width,int height)
{
	int i,j,k;
	int size = width * height;
	_img = new CBaseColorInfo[size];
	_oldimg = new CBaseColorInfo[size];
	for(i = 0 ; i < size;i++){
		_oldimg[i] = img[i];
	}
	_width = width;
	_height = height;
}

CColorImage::~CColorImage()
{
}

void CColorImage::RGBtoCMY(){
	int i,j,k;

	int size = _width * _height;

	for(i = 0 ; i < size ; i ++){
		_img[i].SetRed(255- _oldimg[i].GetRed());
		_img[i].SetGreen(255- _oldimg[i].GetGreen());
		_img[i].SetBlue(255- _oldimg[i].GetBlue());
	}
}

void CColorImage::RGBtoYUV(){
	int i,j,k;

	int size = _width * _height;
	double y,u,v;
	for(i = 0 ; i < size ; i ++){

		y = 0.299 * _oldimg[i].GetRed() + 0.587 * _oldimg[i].GetGreen() 
			+ 0.144 * _oldimg[i].GetBlue();
		u = _oldimg[i].GetBlue() - y;
		v = _oldimg[i].GetRed() - y;
		_img[i].SetRed(y);
		_img[i].SetGreen(u);
		_img[i].SetBlue(v);
	}
}
void CColorImage::RGBtoYCBCR(){
	int i,j,k;

	int size = _width * _height;
	double y,u,v;
	for(i = 0 ; i < size ; i ++){

		y = 0.299 * _oldimg[i].GetRed() + 0.587 * _oldimg[i].GetGreen() 
			+ 0.144 * _oldimg[i].GetBlue();
		u = (_oldimg[i].GetBlue() - y) * (1.0 - 0.114) * 2.0;
		v = (_oldimg[i].GetRed() - y) * (1.0 - 0.299) * 2.0 ;
		_img[i].SetRed(y);
		_img[i].SetGreen(u);
		_img[i].SetBlue(v);
	}
}

double getmin(double a,double b,double c){
	double t = a>b?b:a; 
	return t>c?c:t;
}

void CColorImage::RGBtoHSItoRGB(){

	double PI = 3.1415926;
	int i,j,k;
	int size = _width * _height;
	double ii,ss,hh;
	double r,g,b;
	double Rt;
	for(i = 0 ; i < size ; i ++){
		r = _oldimg[i].GetRed()/255.0;
		g = _oldimg[i].GetGreen()/255.0;
		b = _oldimg[i].GetBlue()/255.0;
	
		ii = 1.0/3.0*(r+g+b);
		ii = ii *255;
		if (r==g && g == b && r == 0)
		{
			ss = 0;
		}else{
		ss = 1 - 3*(getmin(r,g,b))/(r+g+b);
		ss = ss * 255;
		}
		Rt = acos(1.0/2.0*(r-g+r-b)/ sqrt(  (r-g)*(r-g) + (r-b)*(g-b)  ));
		if (b>g)
		{
			Rt = 255 - Rt;
		}
		hh = Rt*255.0/255.0;
		
		hh = hh/255.0;
		ss = ss/255.0;
		ii = ii/255.0;
		hh = hh * 360;

		if (hh  < 120)
		{
			b = ii * (1 - ss);
			r = ii*(1+ss*cos(hh/180*PI)/cos((60-hh)/180*PI));
			g = 3*ii - r -b;
		}else if(hh < 240){
			hh = hh - 120;
			r = ii * (1-ss);
			g = ii*(1+ss*cos(hh/180*PI)/cos((60-hh)/180*PI));
			b = 3*ii - (r+b);
		}else{
			hh = hh - 240;
			
			g = ii*(1-ss);
			b = ii * (1 + ss*cos(hh/180*PI)/cos((60 - hh)/180*PI));
			r = 3*ii - (r+b);
		}
	
		
		_img[i].SetRed(r*255);
		_img[i].SetGreen(g*255);
		_img[i].SetBlue(b*255);
	}
}
void CColorImage::RGBtoHSI(){
	int i,j,k;
	int size = _width * _height;
	double ii,ss,hh;
	double r,g,b;
	double Rt;
	for(i = 0 ; i < size ; i ++){
		r = _oldimg[i].GetRed()/255.0;
		g = _oldimg[i].GetGreen()/255.0;
		b = _oldimg[i].GetBlue()/255.0;
	
		ii = 1.0/3.0*(r+g+b);
		ii = ii *255;
		if (r==g && g == b && r == 0)
		{
			ss = 0;
		}else{
		ss = 1 - 3*(getmin(r,g,b))/(r+g+b);
		ss = ss * 255;
		}
		Rt = acos(1.0/2.0*(r-g+r-b)/ sqrt((r-g)*(r-g)+(r-b)*(g-b)));
		if (b>g)
		{
			Rt = 360 - Rt;
		}

		hh = Rt;
	
		_img[i].SetRed(hh);
		_img[i].SetGreen(ss);
		_img[i].SetBlue(ii);
	}
}

void CColorImage::GraytoColor(int *img){
	
	int i,j,k;

	int size = _width * _height;
	double y,u,v,tmp2;

	CBaseColorInfo * color = new CBaseColorInfo[216];

	for(i = 0 ; i < size ; i ++){
		tmp2 = img[i];
		if (tmp2 <= 51)  
         {  
            v = 255;  
            u = tmp2*5;  
            y = 0;  
         }  
         else if (tmp2 <= 102)  
         {  
            tmp2-=51;  
            v = 255-tmp2*5;  
            u = 255;  
            y = 0;  
         }  
         else if (tmp2 <= 153)  
         {  
            tmp2-=102;  
            v = 0;  
            u = 255;  
            y = tmp2*5;  
         }  
         else if (tmp2 <= 204)  
         {  
            tmp2-=153;  
            v = 0;  
            u = 255-(128.0*tmp2/51.0+0.5);  
            y = 255;  
         }  
         else  
         {  
            tmp2-=204;  
            v = 0;  
            u = 127-(127.0*tmp2/51.0+0.5);  
            y = 255;  
         }  



		_img[i].SetRed(y);
		_img[i].SetGreen(u);
		_img[i].SetBlue(v);
	}
}


void CColorImage::P287_15(){
	int i,j,k;

	int size = _width * _height;
	double h,s,iu;
	double r,g,b;
	for(i = 0 ; i < size ; i ++){
		r = _oldimg[i].GetRed();
		g = _oldimg[i].GetGreen();
		b = _oldimg[i].GetBlue();

		h = 255.0 * acos( (2 * r - g - b)/(2 * sqrt((r-g)*(r-g) + (r-b)*(g-b))));
		if(b>g){
			h = 255 - h;
		}
		iu = (r+b+g)/3.0;
		s = 255 - 3*min3x(r,g,b)/(r+g+b);
		
		_img[i].SetRed(h);
		_img[i].SetGreen(s);
		_img[i].SetBlue(i);
	}
	
}