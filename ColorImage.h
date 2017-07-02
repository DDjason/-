// ColorImage.h: interface for the CColorImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORIMAGE_H__515E0870_EFE8_46EF_BFBF_71C4C1E7134B__INCLUDED_)
#define AFX_COLORIMAGE_H__515E0870_EFE8_46EF_BFBF_71C4C1E7134B__INCLUDED_
#include "BaseColorInfo.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CColorImage  
{
public:
	CColorImage(CBaseColorInfo *img,int width,int height);
	virtual ~CColorImage();
public:
	CBaseColorInfo *getImg(){
		return _img;
	}
	void RGBtoCMY();
	void RGBtoYUV();
	void RGBtoYCBCR();
	void RGBtoHSI();
	void RGBtoHSItoRGB();
	void GraytoColor(int *img);
	void P287_15();
	void P288_25();
	double min3x(double x11,double y11,double z11){
		double t =  x11>y11?x11:y11;
		return t > z11?t:z11; 
	}
private:
	CBaseColorInfo *_oldimg;
	CBaseColorInfo *_img;
	int _width;
	int _height;

};

#endif // !defined(AFX_COLORIMAGE_H__515E0870_EFE8_46EF_BFBF_71C4C1E7134B__INCLUDED_)
