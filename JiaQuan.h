// JiaQuan.h: interface for the JiaQuan class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JIAQUAN_H__A67FCAE8_0197_4219_984F_A747C72F51DC__INCLUDED_)
#define AFX_JIAQUAN_H__A67FCAE8_0197_4219_984F_A747C72F51DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class JiaQuan  
{
private :
	//原始图像
	int *_oldImg;
	int _width;
	int _height;
	//获得图像
	int *_result;
public:
	JiaQuan(int *img ,int width,int height);
	virtual ~JiaQuan();

public:
		int * getImg(){
		return _result;
	}
		void jisuan(int level);

		void Lapulasi();


};

#endif // !defined(AFX_JIAQUAN_H__A67FCAE8_0197_4219_984F_A747C72F51DC__INCLUDED_)
