// Jiaquan.h: interface for the CJiaquan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JIAQUAN_H__021C134A_9EEE_46CB_BE0B_95D264D5663B__INCLUDED_)
#define AFX_JIAQUAN_H__021C134A_9EEE_46CB_BE0B_95D264D5663B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CJiaquan  
{
public:
	CJiaquan(int *img, int width, int height);
	virtual ~CJiaquan();
	
	void jisuan_normal(int level);
	void jisuan_middle(int level);
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

#endif // !defined(AFX_JIAQUAN_H__021C134A_9EEE_46CB_BE0B_95D264D5663B__INCLUDED_)
