//////////////////////////////////////////////////////////////////////////
// ImageStuDlg.h : header file
// 图像处理实验学生平台
// 创建人: 邓飞
// 创建时间: 2008-8-31
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGESTUDLG_H__8B975AD1_2A07_4F7F_B0EC_1B03621056BF__INCLUDED_)
#define AFX_IMAGESTUDLG_H__8B975AD1_2A07_4F7F_B0EC_1B03621056BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "BaseColorInfo.h"

class CImageStuDlg : public CDialog
{
// Construction
public:
	CImageStuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CImageStuDlg)
	enum { IDD = IDD_IMAGESTU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageStuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CImageStuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileOpen();
	afx_msg void OnDestroy();
	afx_msg void OnFileShowArray();
	afx_msg void OnTest();
	afx_msg void OnFileSave();
	afx_msg void OnAllRed();
	afx_msg void OnRedBlue();
	afx_msg void Oncaisehuidu();
	afx_msg void Onhuiduheibai();
	afx_msg void Onhuidufenbianlv();
	afx_msg void OnErciChazhi();
	afx_msg void Onshuipin();
	afx_msg void Onchuizhi();
	afx_msg void OnMenuitem32834();
	afx_msg void OnMenuitem32836();
	afx_msg void OnMenuitem32837();
	afx_msg void OnMenuitem32838();
	afx_msg void OnMenuitem32839();
	afx_msg void OnLinYu();
	afx_msg void OnLinYuQuick();
	afx_msg void OnYuZhi();
	afx_msg void OnMsk();
	afx_msg void OnPlusQ();
	afx_msg void OnLpls();
	afx_msg void OnRobert();
	afx_msg void OnSobel();
	afx_msg void OnSobeluse();
	afx_msg void OnZongZhi();
	afx_msg void OnRgbCmy();
	afx_msg void OnRgbyuv();
	afx_msg void OnRgbycbcr();
	afx_msg void OnGrayTColor();
	afx_msg void OnP28825();
	afx_msg void OnP28715();
	afx_msg void OnFuhua();
	afx_msg void OnRgbHsi();
	afx_msg void OnRgbHsiRgb();
	afx_msg void OnPengZhang();
	afx_msg void OnKaiDo();
	afx_msg void OnBiDo();
	afx_msg void OnGetBian();
	afx_msg void OnQytcUse();
	afx_msg void Onliantongqy();
	afx_msg void OnXiHua();
	afx_msg void OnWCs();
	afx_msg void OnPhdFl();
	afx_msg void OnHfmTs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
		// 读取文件头
	BOOL ReadFileHeader( CFile & file );
	// 读取文件信息头
	BOOL ReadInfoHeader( CFile & file );
	// 释放数据
	void FreeData();
	// 计算调色板颜色数量
	int CalcQuadNum();
	// 读取调色板数据
	void ReadQuad( CFile &file );
	// 判断是否为256色灰度图
	BOOL Is256Gray();
	// 读入图像数据
	void ReadImageData( CFile &file );
	// 判断图像类型
	IMAGE_TYPE CalcImageType();
	// 将24位彩色BMP数据转换成24位颜色数据
	void BMPConvertColor24();
	// 将8位彩色BMP数据转成24位颜色数据
	void BMPConvertColor8();
	// 将8位灰度BMP数据转成8位灰度数据
	void BMPConvertGray8();
	// 将8位灰度数据转成用24位颜色
	void Gray8ConvertColor24( BYTE * grayData, CBaseColorInfo * colorData, int width, int height );
	// 将8位灰度数据转成用24位颜色
	void Gray8ConvertColor24( int * grayData, CBaseColorInfo * colorData, int width, int height );


	// 显示图像(通过图像数组, 彩色图像)
	void ShowPicByArray( CBaseColorInfo * colorData, int width, int height );
	// 显示图像(通过图像数组, 灰度图像)
	void ShowPicByArray( int * grayData, int width, int height );

	// 保存BMP图片
	bool SaveAsBmp( char * bmpName, unsigned char * imgBuf, int width, int height, int biBitCount, RGBQUAD * pColorTable );
	
public:
	// 文件头
	BITMAPFILEHEADER _fileHeader;
	
	// 调色板
	RGBQUAD * _quad;
	// 调色板数目
	int _numQuad;
	// 图像数据
	BYTE * _lpBuf;
	BITMAPINFO * _bitmapInfo;
	// 处理后的图像数据
	BYTE * _processBuf;
	// 是否打开了bmp文件
	bool _flag;
	
	// 信息头
	BITMAPINFOHEADER _infoHeader;

	// 图像类型
	IMAGE_TYPE _imageType;
	// 灰度(256灰度数据, 按从上到下, 从左到右的顺序排列,一维矩阵排列)
	int * _grayData;
	// 彩色数据(按从上到下, 从左到右的顺序排列,一维矩阵排列)
	CBaseColorInfo * _colorData;




};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGESTUDLG_H__8B975AD1_2A07_4F7F_B0EC_1B03621056BF__INCLUDED_)
