// ImageProcessNine.h: interface for the CImageProcessNine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEPROCESSNINE_H__2B506560_1949_4593_92A3_927DA6B5EC86__INCLUDED_)
#define AFX_IMAGEPROCESSNINE_H__2B506560_1949_4593_92A3_927DA6B5EC86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseColorInfo.h"
class CImageProcessNine  
{
public:
	CImageProcessNine(int *img, int width, int height);
	virtual ~CImageProcessNine();


	void jisuan_fushi(int level);
	void jisuan_pengzhang(int level);
	
public:
	int *getImg(){
		return _img;
	}
	CBaseColorInfo *getImg_RGB(){
		return rgb_img;
	}
private:
	int *_oldimg;
	int *_img;
	int _width;
	int _height;
	CBaseColorInfo *rgb_img;
};


#endif // !defined(AFX_IMAGEPROCESSNINE_H__2B506560_1949_4593_92A3_927DA6B5EC86__INCLUDED_)
