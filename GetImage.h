// GetImage.h: interface for the CGetImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GETIMAGE_H__FE883772_880C_4670_AC7F_6A420541AF71__INCLUDED_)
#define AFX_GETIMAGE_H__FE883772_880C_4670_AC7F_6A420541AF71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BaseColorInfo.h"
class CGetImage  
{
public:
	CGetImage(int *img, int width, int height);
	virtual ~CGetImage();
	void jisuan_lapulasi();
	void jisuan_Robert();
	void jisuan_Sobel();
	//实验八
	void jisuan_216_RGB();
	void jisuan_number_15();
	void jisuan_number_25();

	//实验九
	void jisuan_fushi(int level);
	void jisuan_pengzhang(int level);

	//实验十
	void jisuan_fushi2(int *model, int level, bool white);
	bool XiangDeng(int *first, int *second);
	void JiaoJi(int *first, int *second, int *result);
	void jisuan_quyutianchong(int x, int y, int *model, int level, bool white);

	void dfs_liantong(int x, int y, int index, int top);
	void jisuan_liantong();
	void jisuan_xihua();

	//实验十一
	void jisuan_hafuman();
	void dfs(int root);
	
public:
	int *getImg(){
		return _img;
	}
	CBaseColorInfo *getImg_RGB(){
		return rgb_img;
	}
	int *getliantong(){
		return flag_liantong;
	}
	CString *getHafuman(){
		return _hafuman;
	}
private:
	int *_oldimg;
	int *_img;
	int *_fanxiangimg;
	int *flag_liantong;
	int _width;
	int _height;
	CString *_hafuman;
	CBaseColorInfo *rgb_img;
};


#endif // !defined(AFX_GETIMAGE_H__FE883772_880C_4670_AC7F_6A420541AF71__INCLUDED_)
