// ImageProcessRGB.h: interface for the CImageProcessRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEPROCESSRGB_H__8158AD39_38ED_4A77_A2F5_CB1014D46ECD__INCLUDED_)
#define AFX_IMAGEPROCESSRGB_H__8158AD39_38ED_4A77_A2F5_CB1014D46ECD__INCLUDED_
#include "BaseColorInfo.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CImageProcessRGB  
{
public:
	CImageProcessRGB(CBaseColorInfo *img, int width, int height);
	virtual ~CImageProcessRGB();

	//实验七
	void jisuan_RGB_CMY();
	void jisuan_RGB_YUV();
	void jisuan_RGB_YCbCr();
	void jisuan_RGB_HSI();
	void jisuan_HSI_RGB();
	//实验八
	void jisuan_15_a();
	void jisuan_15_b();
	void jisuan_15_c();


public:
	CBaseColorInfo *getImg(){
		return _img;
	}
	private:
		CBaseColorInfo *_oldimg;
		CBaseColorInfo *_img;
		int _width;
		int _height;
};

#endif // !defined(AFX_IMAGEPROCESSRGB_H__8158AD39_38ED_4A77_A2F5_CB1014D46ECD__INCLUDED_)
