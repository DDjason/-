// ImageProcess.h: interface for the CImageProcess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEPROCESS_H__77FA3147_4010_4477_A424_C8202398FBA8__INCLUDED_)
#define AFX_IMAGEPROCESS_H__77FA3147_4010_4477_A424_C8202398FBA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CImageProcess  
{
public:
	CImageProcess(int *img, int width, int height);
	virtual ~CImageProcess();
	void jisuan_lapulasi();
	void jisuan_Robert();
	void jisuan_Sobel();
public:
	int *getImg(){
		return _img;
	}
private:
	int *_oldimg;
	int *_img;
	int _width;
	int _height;

};

#endif // !defined(AFX_IMAGEPROCESS_H__77FA3147_4010_4477_A424_C8202398FBA8__INCLUDED_)
