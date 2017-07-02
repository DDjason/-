// ImageStuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageStu.h"
#include "ImageStuDlg.h"
#include "DlgShowArray.h"
#include "ImageProcess.h"
#include "ImageProcessRGB.h"
#include "ImageProcessNine.h"
#include "DlgTask.h"
#include "math.h"
#include "JiaQuan.h"
#include "JiaQuan1.h"
#include "ColorImage.h"
#include "GetImage.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageStuDlg dialog

CImageStuDlg::CImageStuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageStuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImageStuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// 图像已打开标记
	_flag = false;

}

void CImageStuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageStuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CImageStuDlg, CDialog)
	//{{AFX_MSG_MAP(CImageStuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_FILE_OPEN, OnFileOpen)
	ON_WM_DESTROY()
	ON_COMMAND(IDC_FILE_SHOW_ARRAY, OnFileShowArray)
	ON_COMMAND(IDC_TEST, OnTest)
	ON_COMMAND(IDC_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_ALL_RED, OnAllRed)
	ON_COMMAND(ID_RED_BLUE, OnRedBlue)
	ON_COMMAND(ID_caise_huidu, Oncaisehuidu)
	ON_COMMAND(ID_huidu_heibai, Onhuiduheibai)
	ON_COMMAND(ID_huidu_fenbianlv, Onhuidufenbianlv)
	ON_COMMAND(ID_ERCI_CHAZHI, OnErciChazhi)
	ON_COMMAND(ID_shuipin, Onshuipin)
	ON_COMMAND(ID_chuizhi, Onchuizhi)
	ON_COMMAND(ID_MENUITEM32834, OnMenuitem32834)
	ON_COMMAND(ID_MENUITEM32836, OnMenuitem32836)
	ON_COMMAND(ID_MENUITEM32837, OnMenuitem32837)
	ON_COMMAND(ID_MENUITEM32838, OnMenuitem32838)
	ON_COMMAND(ID_MENUITEM32839, OnMenuitem32839)
	ON_COMMAND(IDC_LinYu, OnLinYu)
	ON_COMMAND(IDC_LinYuQuick, OnLinYuQuick)
	ON_COMMAND(IDC_YuZhi, OnYuZhi)
	ON_COMMAND(IDC_MSK, OnMsk)
	ON_COMMAND(IDC_PlusQ, OnPlusQ)
	ON_COMMAND(IDC_LPLS, OnLpls)
	ON_COMMAND(IDC_Robert, OnRobert)
	ON_COMMAND(IDC_Sobel, OnSobel)
	ON_COMMAND(IDC_So_bel, OnSobeluse)
	ON_COMMAND(ID_ZongZhi, OnZongZhi)
	ON_COMMAND(IDC_RGB_CMY, OnRgbCmy)
	ON_COMMAND(ID_RGBYUV, OnRgbyuv)
	ON_COMMAND(ID_RGBYCBCR, OnRgbycbcr)
	ON_COMMAND(IDC_GrayTColor, OnGrayTColor)
	ON_COMMAND(IDC_P288_25, OnP28825)
	ON_COMMAND(IDC_P287_15, OnP28715)
	ON_COMMAND(IDC_FUHUA, OnFuhua)
	ON_COMMAND(IDC_RGB_HSI, OnRgbHsi)
	ON_COMMAND(IDC_RGB_HSI_RGB, OnRgbHsiRgb)
	ON_COMMAND(IDC_PENG_ZHANG, OnPengZhang)
	ON_COMMAND(IDC_KAI_DO, OnKaiDo)
	ON_COMMAND(IDC_BI_DO, OnBiDo)
	ON_COMMAND(IDC_GET_BIAN, OnGetBian)
	ON_COMMAND(IDC_QYTC_USE, OnQytcUse)
	ON_COMMAND(IDC_liantong_qy, Onliantongqy)
	ON_COMMAND(IDC_XI_HUA, OnXiHua)
	ON_COMMAND(IDC_W_CS, OnWCs)
	ON_COMMAND(IDC_PHD_FL, OnPhdFl)
	ON_COMMAND(IDC_HFM_TS, OnHfmTs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageStuDlg message handlers

BOOL CImageStuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CImageStuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CImageStuDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}

	// 绘图
	CDC * pDC = GetDC();
	if( _flag == true ){
		
		// 已经打开文件
		SetDIBitsToDevice(
			  pDC->m_hDC  // 设备描述表
			, 0 // 设备描述表位图输出的起始逻辑x坐标
			, 0 // 设备描述表位图输出的起始逻辑y坐标
			, _infoHeader.biWidth // DIB的宽度
			, _infoHeader.biHeight // DIB的高度
			, 0 // DIB开始读取输出的像素数据的x位置
			, 0 // DIB开始读取输出的像素数据的y位置
			, 0 // DIB中像素的水平行号, 对应lpBits内存缓冲区的第一行数据
			, _infoHeader.biHeight  // DIB的行数
			, _lpBuf  // 像素数据
			, _bitmapInfo //BITMAPINFO数据
			, DIB_RGB_COLORS // 显示的颜色
		);

	}
	ReleaseDC( pDC );

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CImageStuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//////////////////////////////////////////////////////////////////////////
// 销毁对话框, 映射WM_DESTORY消息
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here

	if( _flag == true ){
		FreeData();
	}

	
}

/************************************************************************/
/*                           菜单                                       */
/************************************************************************/

//////////////////////////////////////////////////////////////////////////
// "文件"-->"打开"(IDC_FILE_OPEN)
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnFileOpen() 
{
	// TODO: Add your command handler code here
	
	LPCTSTR lpszFilter = "BMP Files(*.bmp)|*.bmp|任何文件|*.*|";
	CFileDialog dlg( TRUE, lpszFilter, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		lpszFilter, NULL );
	// 文件名
	CString fileName;
	CFile file;
	// 打开文件
	if( dlg.DoModal() == IDOK ){

		// 文件名
		fileName = dlg.GetPathName();
		if( file.Open( fileName, CFile::modeRead | CFile::shareDenyNone, NULL ) == 0 ){
			// 读取文件失败
			AfxMessageBox( "无法打开文件", MB_OK, MB_ICONERROR );
			return;
		}

		// 读取文件头
		if( !ReadFileHeader( file ) ){
			return;
		}

		// 读取信息头 
		if( !ReadInfoHeader( file ) ){
			return;
		}

		// 若前面已有文件打开，则释放相应的数据
		if( _flag == true ){
			FreeData();
			_flag = false;
		}

		// 计算调色板颜色数量
		_numQuad = CalcQuadNum();
		// 读取调色板数据
		ReadQuad( file );

		// 判断图像类型
		_imageType = CalcImageType();

		// 读入图像数据
		ReadImageData( file );
		

		

		// 分配处理后的数据
		_processBuf = ( BYTE * )HeapAlloc( GetProcessHeap(), 0, _infoHeader.biSizeImage );
	
		// 宽度不是4的倍数则补齐
		DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
		if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
			dwBytes++;
		}
		dwBytes *= 4;

		
		
		Invalidate( );

		int width = _infoHeader.biWidth;
        int height = _infoHeader.biHeight;

		// 分配空间
		_colorData = new CBaseColorInfo[ width * height ];
		_grayData = new int[ width * height ];

		// 根据图像类型，将其转换成相应的图像数据
		if( _imageType == COLOR_24_BIT ){
			// 24位颜色图像
			BMPConvertColor24();
			
		}
		else if( _imageType == COLOR_8_BIT ){
			// 256彩色图像
			BMPConvertColor8();
		}
		else if( _imageType == GRAY_8_BIT ){
			// 256灰度图像
			BMPConvertGray8();
			// 将8位灰度数据转成用24位颜色
			Gray8ConvertColor24( _grayData, _colorData, width, height );
		}
		else{
			MessageBox( "暂不支持该图像类型" );
			// 关闭图像
			file.Close();
			FreeData();
			return;
		}

		// 图像读取完毕
		file.Close();
		_flag = true;

	}

}


//////////////////////////////////////////////////////////////////////////
// "文件"-->"显示数组图像"
// 将转换后的24位彩色数据在对话框中显示
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnFileShowArray() 
{
	// TODO: Add your command handler code here

	if(_flag == FALSE){
		MessageBox("没有打开图像");
		return;
	}

	CDlgShowArray dlg;
	dlg.SetColorData( _colorData );
	dlg.SetWidth( _infoHeader.biWidth );
	dlg.SetHeight( _infoHeader.biHeight );
	dlg.DoModal();

}


//////////////////////////////////////////////////////////////////////////
// "文件"-->"保存"菜单
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnFileSave() 
{
	// TODO: Add your command handler code here
	if( ! _flag  ){
		MessageBox( "没有图片，无法保存" );
		return;
	}
	
	CFileDialog dlg(false,"*.bmp",NULL,NULL,"*.bmp|*.bmp||");
	if (dlg.DoModal()==IDOK)
	{
		SaveAsBmp( (LPTSTR)(LPCTSTR)dlg.GetPathName(), _lpBuf, _infoHeader.biWidth, _infoHeader.biHeight, _infoHeader.biBitCount,
			_quad );
	}
	
}


/************************************************************************/
/*                         私有函数                                     */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////
// 读取文件头
// 参数:
//   file: CFile &, BMP文件
// 返回值:
//   BOOL, TRUE: 成功; FALSE: 失败
//////////////////////////////////////////////////////////////////////////
BOOL CImageStuDlg::ReadFileHeader( CFile &file ){

	// 读取文件头
	file.Read( &_fileHeader, sizeof( _fileHeader ) );
	// 判断是否为BMP文件
	if( _fileHeader.bfType != 0x4d42 ){
		// "BM"
		AfxMessageBox( "不是BMP文件", MB_OK, MB_ICONERROR );
		return FALSE;
	}

	// 判断文件是否损坏(文件大小是否与文件头的信息一致)
	if( file.GetLength() != _fileHeader.bfSize ){
		AfxMessageBox( "文件已损坏", MB_OK, MB_ICONERROR );
		return FALSE;
	}

	return TRUE;
	
}


//////////////////////////////////////////////////////////////////////////
// 读取文件信息头
// 参数:
//   file: CFile &, 已经打开的BMP文件
// 返回值:
//   BOOL, TRUE成功; 其它失败
//////////////////////////////////////////////////////////////////////////
BOOL CImageStuDlg::ReadInfoHeader( CFile &file ){

	// 读取文件信息头
	file.Read( &_infoHeader, sizeof( _infoHeader ) );

	// 将图片格式限定在8位图像
// 	if( _infoHeader.biBitCount != 8 ){
// 		AfxMessageBox( "必须为8位灰度图", MB_OK, MB_ICONERROR );
// 		return FALSE;
// 	}

	return TRUE;

}


//////////////////////////////////////////////////////////////////////////
// 释放数据
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::FreeData(){

	HeapFree( GetProcessHeap(), 0, _bitmapInfo );
	HeapFree( GetProcessHeap(), 0, _lpBuf );
	// 处理后的数据
	HeapFree( GetProcessHeap(), 0, _processBuf );
	// 灰度颜色数据
	delete [] _grayData;
	// 彩色颜色数据
	delete [] _colorData;



}

//////////////////////////////////////////////////////////////////////////
// 计算调色板颜色数量
// 参数: 无
// 返回值:
//   int, 调色板颜色数量
//////////////////////////////////////////////////////////////////////////
int CImageStuDlg::CalcQuadNum(){

	// 计算调色板数据
	int numQuad = 0;
	if( _infoHeader.biBitCount < 24){
		// 相当于2的biBitCount次方
		numQuad = ( 1 << _infoHeader.biBitCount );
	}

	return numQuad;

}

//////////////////////////////////////////////////////////////////////////
// 读取调色板数据
// 参数:
//   file: CFile &, BMP文件
// 返回值: 无
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ReadQuad( CFile &file ){

	// 为图像信息pbi申请空间
	_bitmapInfo = ( BITMAPINFO * )HeapAlloc( 
		GetProcessHeap(), 
		0, 
		sizeof( BITMAPINFOHEADER ) + _numQuad * sizeof( RGBQUAD ) 
	);
	memcpy( _bitmapInfo, &_infoHeader, sizeof( _infoHeader ) );
	_quad = ( RGBQUAD * )( ( BYTE *)_bitmapInfo + sizeof( BITMAPINFOHEADER ) );

	// 读取调色板
	if( _numQuad != 0 ){
		file.Read( _quad, sizeof( RGBQUAD ) * _numQuad );
	}

}

//////////////////////////////////////////////////////////////////////////
// 判断是否为256色灰度图
// 判断依据，调色板中所有颜色的的RGB三个分量应该相等
// BOOL: TRUE为256色灰度图
//////////////////////////////////////////////////////////////////////////
BOOL CImageStuDlg::Is256Gray(){

	BOOL result = TRUE;
	for( int i = 0; i <= _numQuad - 1; i++ ){
		RGBQUAD color = *( _quad + i );
		//TRACE( "%d: %d, %d, %d\n", i, color.rgbRed,  color.rgbGreen, color.rgbBlue );
		if( !( color.rgbRed == color.rgbGreen && color.rgbRed == color.rgbBlue ) ){
			result = FALSE;
			break;
		}
	}
	
	return result;

}

//////////////////////////////////////////////////////////////////////////
// 读入图像数据
// 参数:
//   file: CFile &, BMP图像
// 返回值: 无
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ReadImageData( CFile &file ){

	// 为图像数据申请空间
	_infoHeader.biSizeImage = _fileHeader.bfSize - _fileHeader.bfOffBits;
	_lpBuf = ( BYTE *)HeapAlloc( GetProcessHeap(), 0, _infoHeader.biSizeImage );
	// 读取图像数据
	file.Read( _lpBuf, _infoHeader.biSizeImage );

}

//////////////////////////////////////////////////////////////////////////
// 判断图像类型
// 参数: 无
// 返回值: IMAGE_TYPE, 图像类型, 参数枚举IMAGE_TYPE的定义
//////////////////////////////////////////////////////////////////////////
IMAGE_TYPE CImageStuDlg::CalcImageType(){

	IMAGE_TYPE type = COLOR_24_BIT;
	if( _infoHeader.biBitCount == IMAGE_TYPE_BIT_24 ){
		// 24彩色图像
		type = COLOR_24_BIT;
		//MessageBox( "24位图像" );
	}
	else if( _infoHeader.biBitCount == IMAGE_TYPE_BIT_1 ){
		// 二值图像　
		type = GRAY_1_BIT;
		//MessageBox( "1位图像" );
	}
	else if( _infoHeader.biBitCount == IMAGE_TYPE_BIT_8 ){
		// 8位
		if( Is256Gray() ){
			// 8位灰度图像
			type = GRAY_8_BIT;
			//MessageBox( "8位灰度图像" );
		}
		else{
			// 8位彩色图像
			type = COLOR_8_BIT;
			//MessageBox( "8位彩色图像" );
		}
	}

	return type;

}

//////////////////////////////////////////////////////////////////////////
// 将BMP数据转换成24位颜色数据
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::BMPConvertColor24(){

	// 宽度不是4的倍数则补齐
	DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
	if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
		dwBytes++;
	}
	dwBytes *= 4;

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	// 分配彩色数据

	int i,j;

	for( i = 0; i <= height - 1; i++ ){
		for( j = 0; j <= width - 1; j++ ){
			
			// BMP图片数据中的坐标
			DWORD index = i * 3 * width + 3 * j;
			if( dwBytes % 3 != 0 ){
				index = i * dwBytes + 3 * j ;
			}
			// 颜色数组中的坐标
			DWORD resultIndex = ( height - 1 - i ) * width + j;
			_colorData[ resultIndex ].SetRed( _lpBuf[ index  + 2 ] );
			_colorData[ resultIndex ].SetGreen( _lpBuf[ index  + 1 ] );
			_colorData[ resultIndex ].SetBlue( _lpBuf[ index ] );

		}// for j
	}// for i 

}

//////////////////////////////////////////////////////////////////////////
// 将8位彩色BMP数据转成24位颜色数据
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::BMPConvertColor8(){

	// 宽度不是4的倍数则补齐
	DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
	if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
		dwBytes++;
	}
	dwBytes *= 4;

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	// 分配彩色数据
// 	if( _colorFlag == true ){
// 		delete [] _colorData;
// 	}
// 	_colorData = new CBaseColorInfo[ width * height ];
// 	_colorFlag = true;


	int i,j;
// 	for( i = 0; i <= 100; i++ ){
// 		TRACE( "%d->%d,", i, _lpBuf[ i ] );
// 	}
// 	TRACE( "\n" );
	for( i = 0; i <= height - 1; i++ ){
		for( j = 0; j <= width - 1; j++ ){
			
			// BMP图片数据中的坐标
			DWORD index = i * dwBytes + j ;

			// 颜色数组中的坐标
			DWORD resultIndex = ( height - 1 - i ) * width + j;
// 			if( index >= _infoHeader.biSizeImage || resultIndex >= _infoHeader.biSizeImage ){
// 				TRACE( "*** i = %d, j = %d, index = %d, resultIndex = %d, widht = %d, height = %d \n", 
// 					i, j, index, resultIndex, width, height );
// 			}

// 			int red = _lpBuf[ index ] + 2;
// 			int green = _lpBuf[ index ] + 1;
// 			int blue = _lpBuf[ index ] + 0;
// 
// 			if( resultIndex <= width * height - 1 ){
// 			_colorData[ resultIndex ].SetRed( red );
// 			_colorData[ resultIndex ].SetGreen( green );
// 			_colorData[ resultIndex ].SetBlue( blue );
// 			}

			_colorData[ resultIndex ].SetRed( _quad[ _lpBuf[ index ] ].rgbRed );
			_colorData[ resultIndex ].SetGreen( _quad[ _lpBuf[ index ] ].rgbGreen );
			_colorData[ resultIndex ].SetBlue( _quad[ _lpBuf[ index ] ].rgbBlue );

// 			TRACE( "%d,%d,%d\t", _colorData[ resultIndex ].GetRed(),
// 				_colorData[ resultIndex ].GetGreen(), 
// 				_colorData[ resultIndex ].GetBlue() );

// 			if( i <= 10 && j <= 10 ){
// 			  TRACE( "(%d,%d,%d)->(%d,%d,%d) ", i,j,index, _colorData[ resultIndex ].GetRed(),
// 				_colorData[ resultIndex ].GetGreen(), 
// 				_colorData[ resultIndex ].GetBlue() );
/*			}*/

		}// for j
	}// for i 

}

//////////////////////////////////////////////////////////////////////////
// 将8位灰度BMP数据转成8位灰度数据
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::BMPConvertGray8(){

	// 宽度不是4的倍数则补齐
	DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
	if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
		dwBytes++;
	}
	dwBytes *= 4;

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	// 分配彩色数据
// 	if( _colorFlag == true ){
// 		delete [] _colorData;
// 	}
// 	_grayData = new BYTE[ width * height ];
// 	_grayFlag = true;


	int i,j;
// 	for( i = 0; i <= 100; i++ ){
// 		TRACE( "%d->%d,", i, _lpBuf[ i ] );
// 	}
// 	TRACE( "\n" );
	for( i = 0; i <= height - 1; i++ ){
		for( j = 0; j <= width - 1; j++ ){
			
			// BMP图片数据中的坐标
			DWORD index = i * dwBytes + j ;

			// 颜色数组中的坐标
			DWORD resultIndex = ( height - 1 - i ) * width + j;
// 			if( index >= _infoHeader.biSizeImage || resultIndex >= _infoHeader.biSizeImage ){
// 				TRACE( "*** i = %d, j = %d, index = %d, resultIndex = %d, widht = %d, height = %d \n", 
// 					i, j, index, resultIndex, width, height );
// 			}

// 			int red = _lpBuf[ index ] + 2;
// 			int green = _lpBuf[ index ] + 1;
// 			int blue = _lpBuf[ index ] + 0;
// 
// 			if( resultIndex <= width * height - 1 ){
// 			_colorData[ resultIndex ].SetRed( red );
// 			_colorData[ resultIndex ].SetGreen( green );
// 			_colorData[ resultIndex ].SetBlue( blue );
// 			}

			_grayData[ resultIndex ] = _lpBuf[ index ];


// 			TRACE( "%d,%d,%d\t", _colorData[ resultIndex ].GetRed(),
// 				_colorData[ resultIndex ].GetGreen(), 
// 				_colorData[ resultIndex ].GetBlue() );

// 			if( i <= 10 && j <= 10 ){
// 			  TRACE( "(%d,%d,%d)->(%d,%d,%d) ", i,j,index, _colorData[ resultIndex ].GetRed(),
// 				_colorData[ resultIndex ].GetGreen(), 
// 				_colorData[ resultIndex ].GetBlue() );
/*			}*/

		}// for j
	}// for i 

}

//////////////////////////////////////////////////////////////////////////
// 将8位灰度数据转成用24位颜色
// 灰度图的RGB值均相同
// 参数:
//   grayData: BYTE *, 灰度数据
//   colorData: CBaseColorInfo *, 24位颜色数据
//   width: 图片宽度
//   height: 图片高度
//  返回值: 无
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::Gray8ConvertColor24( BYTE * grayData, 
										    CBaseColorInfo * colorData, 
											int width, 
											int height ){


	int length = width * height;
	for( int i = 0; i <= length - 1; i++ ){
		colorData[ i ].SetRed( grayData[ i ] );
		colorData[ i ].SetGreen( grayData[ i ] );
		colorData[ i ].SetBlue( grayData[ i ] );
	}

}

// 将8位灰度数据转成用24位颜色
void CImageStuDlg::Gray8ConvertColor24( int * grayData, CBaseColorInfo * colorData, int width, int height ){

	int length = width * height;
	for( int i = 0; i <= length - 1; i++ ){
		colorData[ i ].SetRed( grayData[ i ] );
		colorData[ i ].SetGreen( grayData[ i ] );
		colorData[ i ].SetBlue( grayData[ i ] );
	}

}

//////////////////////////////////////////////////////////////////////////
// 显示图像(通过图像数组,彩色图像)
// 参数:
//   colorData: CBaseColorInfo, 颜色数据
//   width: int, 图像宽度
//   height: int, 图像高度
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ShowPicByArray( CBaseColorInfo * colorData, 
								   int width, 
								   int height ){

	CDlgShowArray dlg;
	// 图像数据(24位彩色图像)
	dlg.SetColorData( colorData );
	// 图像宽度
	dlg.SetWidth( width );
	// 图像高度
	dlg.SetHeight( height );
	// 显示对话框
	dlg.DoModal();

}




//////////////////////////////////////////////////////////////////////////
// 显示图像(通过图像数组, 灰度图像)
// 参数:
//   colorData: CBaseColorInfo, 灰度图像数据
//   width: int, 图像宽度
//   height: int, 图像高度
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ShowPicByArray( int * grayData, 
								   int width, 
								   int height ){

	// 将灰度图像转成彩色图像
	CBaseColorInfo * colorData = new CBaseColorInfo[ width * height ];
	Gray8ConvertColor24( grayData, colorData, width, height );

	CDlgShowArray dlg;
	// 图像数据(24位彩色图像)
	dlg.SetColorData( colorData );
	// 图像宽度
	dlg.SetWidth( width );
	// 图像高度
	dlg.SetHeight( height );
	// 显示对话框
	dlg.DoModal();

	// 释放彩色图像
	delete [] colorData;

}











void CImageStuDlg::OnTest() 
{
	// TODO: Add your command handler code here
	int x, y;
	int width = 800;
	int height = 600;
	CBaseColorInfo * img = new CBaseColorInfo[ width * height ];
	for( x = 0; x < width; ++x ){
		for( y = 0; y < height; ++y ){
			int index = y * width + x;
			if( x % 10 == 0 ){
				img[ index ] = CBaseColorInfo( 255, 0, 0 );
			}
			else{
				img[ index ] = CBaseColorInfo( 0, 255, 0 );
			}
			
		}
	}

	// 显示图像
	ShowPicByArray( img, width, height );

	delete []img;
}


//////////////////////////////////////////////////////////////////////////
// 功能：保存BMP图片
// 参数：
//   bmpName: char *, 文件名(含路径、文件后缀)
//   imgBuf: unsigned char *, 图像数据
//   width: int, 图像宽度
//   height: int, 图像高度
//   biBitCount: int, 像素深度
//   pColorTable: RGBAUAD *, 颜色表
//////////////////////////////////////////////////////////////////////////
bool CImageStuDlg::SaveAsBmp( char * bmpName, 
							  unsigned char * imgBuf, 
							  int width, 
							  int height,
							  int biBitCount, 
							  RGBQUAD * pColorTable 
							 ){
	
	// 如果位图数据为空，则没有数据传入
	if( !imgBuf ){
		return false;
	}
	
	// 颜色表大小，以字节为单位，灰度图像颜色表为1024，彩色图像颜色表大小为0
	int colorTableSize = 0;
	if( biBitCount == 8 ){
		colorTableSize = 1024; // 感觉不一定正确
	} 
	
	// 将带存储图像数据每行字节数转为4的倍数
	int lineByte = ( width * biBitCount / 8 + 3 ) / 4 * 4;
	// 以二进制的写的方式打开文件
	FILE *fp = fopen( bmpName, "wb" );
	if( !fp ){
		return false;
	}
	
	// 申请位图文件头结构变量，填写文件头信息
	BITMAPFILEHEADER fileHead;
	fileHead.bfType = 0x4D42;// bmp类型
	// bfSize是图像文件4个组成部分之和
	fileHead.bfSize = sizeof( BITMAPFILEHEADER ) 
		+ sizeof( BITMAPINFOHEADER )
		+ colorTableSize 
		+ lineByte * height; // 图像数据字节数
	fileHead.bfReserved1 = 0;
	fileHead.bfReserved2 = 0;
	
	// bfOffBits是图像文件前三部分所需空间之和
	fileHead.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)  + colorTableSize;
	// 文件头写入文件
	fwrite( &fileHead, sizeof( BITMAPFILEHEADER ) , 1, fp );
	
	// 申请位图信息头结构变量，填写信息头信息
	BITMAPINFOHEADER head;
	head.biSize = sizeof(BITMAPINFOHEADER); // 位图信息头结构的大小(40个字节)
	head.biWidth = width;// 图像宽度，以像素为单位
	head.biHeight = height;// 图像高度，以像素为单位
	head.biPlanes = 1;// 必须为1
	head.biBitCount = biBitCount; // 像素深度，每个像素的为数(bit数)
	head.biCompression = BI_RGB; // 图像是否压缩，一般是未压缩的
	head.biSizeImage = lineByte * height; // 实际的位图数据占据的字节数
	head.biXPelsPerMeter = 0; // 目标设备的水平分辨率
	head.biYPelsPerMeter = 0; // 目标设备的垂直分辨率
	head.biClrUsed = 0; // 本图像实际用到的颜色数
	head.biClrImportant = 0; // 本图像重要的颜色，如果为0，则所有的颜色均重要 
	
	// 写位图信息头进内存
	fwrite( &head, sizeof( BITMAPINFOHEADER ), 1, fp );
	
	// 如果图像时灰度图像，有颜色表，写入文件
	if( biBitCount == 8 ){
		fwrite( pColorTable, sizeof( RGBQUAD ), 256, fp );
	}
	
	// 写位图数据进文件
	fwrite( imgBuf, height * lineByte, 1, fp );
	
	// 关闭文件
	fclose( fp );
	
	return true;
	
}



void CImageStuDlg::OnAllRed() 
{
	// TODO: Add your command handler code here
	int width = 800;
	int height = 600;
	int size = width * height;
	CBaseColorInfo *newColor = new CBaseColorInfo [size];

	for(int i = 0; i < size; ++ i){
		
		newColor[i].SetRed(255);
		newColor[i].SetGreen(0);
		newColor[i].SetBlue(0);
	}
	ShowPicByArray(newColor, width, height);
	delete [] newColor;
	
}

void CImageStuDlg::OnRedBlue() 
{
	// TODO: Add your command handler code here
		int width = 800;
	int height = 600;
	int size = width * height;
	CBaseColorInfo *newColor = new CBaseColorInfo [size];
	int i = 0;
	for(int x = 0; x < 600; ++ x)
	{
		for(int y = 0; y < 800; ++ y)
		{
			if((x / 30) % 2 == 0){
				if((y / 40) & 1){
					newColor[i].SetRed(0);
					newColor[i].SetGreen(0);
					newColor[i].SetBlue(255);
				}
				else{
					newColor[i].SetRed(255);
					newColor[i].SetGreen(0);
					newColor[i].SetBlue(0);
				}
			}
			else{
				if((y / 40) & 1){
					newColor[i].SetRed(255);
					newColor[i].SetGreen(0);
					newColor[i].SetBlue(0);
				}
				else{
					newColor[i].SetRed(0);
					newColor[i].SetGreen(0);
					newColor[i].SetBlue(255);
				}
			}
			 i ++;
		}
	}
	ShowPicByArray(newColor, width, height);
	delete [] newColor;
	
}

void CImageStuDlg::Oncaisehuidu() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	CBaseColorInfo *newColor = new CBaseColorInfo [width * height];
	for(int i = 0; i < width; ++ i){
		for(int j = 0; j < height; ++ j){
			int index = j * width + i;
			CBaseColorInfo info = _colorData[index];
			int y = 0.299 * info.GetRed()
				+ 0.587 * info.GetGreen()
				+ 0.114 * info.GetBlue();
		//	newColor[index].SetRed(y);
			//newColor[index].SetGreen(y);
		//	newColor[index].SetBlue(y);
			newColor[index] = CBaseColorInfo (y, y, y);
		}
	}
	ShowPicByArray(newColor, width, height);
	delete [] newColor;
	
}

void CImageStuDlg::Onhuiduheibai() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	CBaseColorInfo *newColor = new CBaseColorInfo [width * height];
	for(int i = 0; i < width; ++ i){
		for(int j = 0; j < height; ++ j){
			int index = j * width + i;
			CBaseColorInfo info = _colorData[index];
			int y = 0.299 * info.GetRed()
				+ 0.587 * info.GetGreen()
				+ 0.114 * info.GetBlue();
			if(y < 100){
				newColor[index].SetRed(0);
				newColor[index].SetGreen(0);
				newColor[index].SetBlue(0);
			}
			else{
				newColor[index].SetRed(255);
				newColor[index].SetGreen(255);
				newColor[index].SetBlue(255);
			}
		}
	}
	ShowPicByArray(newColor, width, height);
	delete [] newColor;
	
}

void CImageStuDlg::Onhuidufenbianlv() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int level =  8;
	//CBaseColorInfo *newcolor = new CBaseColorInfo [size];
	int *pic = new int [size];
	for(int i = 0; i < size; ++ i){
		int oldGray = _grayData[i];
		int newGray = oldGray / level * level;
		pic[i] = newGray;
	}
	ShowPicByArray(pic, width, height);
	delete [] pic;
	
	
}

void CImageStuDlg::OnErciChazhi() 
{
	// TODO: Add your command handler code here
	int oldwidth = _infoHeader.biWidth;
	int oldheight = _infoHeader.biHeight;
	double scale = 1.5;
	int newwidth = oldwidth * scale;
	int newheight = oldheight * scale;
	int *pic = new int[newwidth * newheight];
	for(int i = 0;i < newwidth; ++ i)
	{
		for(int j = 0; j < newheight; ++ j)
		{
			double oldx = i * 1.0 / scale;
			double oldy = j * 1.0 / scale;
			int ax = oldx;
			int ay = oldy;
			int ga = _grayData[(int)ay * oldwidth + ax];

			int bx = min(oldx + 1, oldwidth - 1);
			int by = oldy;
			int gb = _grayData[(int)by * oldwidth + bx];

			int cx = oldx;
			int cy = min(oldy + 1, oldheight - 1);
			int gc = _grayData[cy * oldwidth + cx];

			int dx = min(oldx + 1, oldwidth - 1);
			int dy = min(oldy + 1, oldheight - 1);
			int gd = _grayData[dy * oldwidth + dx];

			double ge = (gb - ga) * (oldx - ax) + ga;
			double gf = (gd - gc) * (oldx - ax) + gc;

			int gg = (gf - ge) * (oldy - ay) + ge;
			pic[j * newwidth + i] = gg;
		}
	}
	ShowPicByArray(pic, newwidth, newheight);
	delete []pic;
	
}

void CImageStuDlg::Onshuipin() 
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
/*	CONST int level = 128;
	int *pic = new int[size];
	for(int i = 0; i < size; ++i){
		int oldgray = _grayData[i];
		int gray = oldgray / level * level;
		pic[i] = gray;

	}

	ShowPicByArray(pic, width, height);
	delete[] pic;
	*/
	int midwidth = width / 2;
	int midheight = height / 2;
	int *pic = new int[size];
	for(int x = 0; x < width - 1; ++x)
	{
		for(int y = 0; y < height - 1; ++y)
		{
			int a = y*width + x;
			int index = 2 * (y * width + midwidth) - (y * width + x) ;
				pic[a] = _grayData[index];
			
		}
	}
	ShowPicByArray(pic, width, height);
	delete[] pic;

	
}

void CImageStuDlg::Onchuizhi() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;

	int midwidth = (int)width / 2;
	int midheight = (int)height / 2;
	int *pic = new int[size];
for(int x = 0; x < width - 1; ++x)
	{
		for(int y = 0; y < height - 1; ++y)
		{
			int a = y*width + x;
			int index = 2 * ((midheight-1) * width + x) - (y * width + x) ;
				pic[a] = _grayData[index];
			
		}
	}
	ShowPicByArray(pic, width, height);
	delete[] pic;

	
	
}

void CImageStuDlg::OnMenuitem32834() 
{
	// TODO: Add your command handler code here
	int i, j;
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *pic = new int [size];
	//计算直方图

	int zhifangtu[256] = {0};
	for( i = 0; i < size; ++i)
	{
		int gray = _grayData[i];
		++zhifangtu[gray];
	}
	
	//归一化，累积
	double leiji[256] = {0};
	double guiYiHua[256] = {0};

	for (i = 0; i < 256; ++i)
	{
			guiYiHua[i] = zhifangtu[i] * 1.0  / size;
	}

	leiji[0] = guiYiHua[0];

	for( j = 1; j < 256; ++j)
	{
		leiji[j] = guiYiHua[j] + leiji[j - 1];
	}


	//计算映射规则

	int rule[256] = {0};

	for(i = 0; i < 256; ++i)
	{
		rule[i] = leiji[i]*255 + 0.5;

	}

	//生成新图像
	for(j = 0; j < size; ++j)
	{
		pic[j] = rule[_grayData[j]];
	}
	ShowPicByArray(pic, width, height);
	delete []pic;
}

void CImageStuDlg::OnMenuitem32836() 
{
	// TODO: Add your command handler code here
		// TODO: Add your command handler code here
	int i, j;
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *pic = new int [size];
	//计算直方图

	
	for( i = 0; i < size; ++i)
	{
		int gray = 255 - _grayData[i];
			pic[i] = gray;
	}
	ShowPicByArray(pic, width, height);
	delete []pic;
}


void CImageStuDlg::OnMenuitem32837() 
{
	// TODO: Add your command handler code here
	int i, j;
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *pic = new int [size];
	double cishu = 1.2;
	//计算直方图

	
	for( i = 0; i < size; ++i)
	{
		int gray = _grayData[i];
		double g = pow(gray, cishu);
			pic[i] = g;
	}
	ShowPicByArray(pic, width, height);
	delete []pic;
}

void CImageStuDlg::OnMenuitem32838() 
{
	// TODO: Add your command handler code here
	int i, j;
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *pic = new int [size];
	double cishu = 10;
	//计算直方图

	
	for( i = 0; i < size; ++i)
	{
		int gray = _grayData[i];
		double g = log(_grayData[i] + 1) * cishu;
			pic[i] = g;
	}
	ShowPicByArray(pic, width, height);
	delete []pic;
}

void CImageStuDlg::OnMenuitem32839() 
{
	// TODO: Add your command handler code here
	int i, j;
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *pic = new int [size];
	double cishu = 10;
	//计算直方图

	
	for( i = 0; i < size; ++i)
	{
		int gray = _grayData[i];
		if(gray < 40)
		{
			gray = 39;
			pic[i] = gray;
		}
		else if(gray <60)
		{
			gray = 59;
			pic[i] = gray;
		}
			else if(gray <90)
		{
			gray = 89;
			pic[i] = gray;
		}
			else
		{
			gray = 125;
			pic[i] = gray;
		}

	}
	ShowPicByArray(pic, width, height);
	delete []pic;
	
}

void CImageStuDlg::OnLinYu() 
{
	// TODO: Add your command handler code here

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *pic = new int [size];


	int *getpic = new int [size];

	int x,y,z;


	int nsize = 7;
	for (y = 0 ; y < height-nsize ; y++)
	{
		for (x = 0  ; x < width-nsize ; x++)
		{
			int index = (y+nsize/2) * width + x + nsize/2;
			int sum = 0 ;
			int i,j;
			for(j = y ; j < y+nsize ; ++j)
			{
				for (i = x; i < x+nsize ; ++i )
				{
					int indextemp = j * width + i;
					sum += _grayData[indextemp];
				}
			}
			
			getpic[index]= sum/nsize/nsize;
		}
	}

	ShowPicByArray(getpic, width, height);
	delete []getpic;
	
	
}

void CImageStuDlg::OnLinYuQuick() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *pic = new int [size];


	int *getpic = new int [size];

	int x,y,z;
	int nsize = 7;
	for (y = 0 ; y < height ;++y )
	{
		for (x = 0 ; x < width - nsize ; ++x)
		{
			int sum = 0 ;
			int index = y * width + x;
			for (z = index; z < index+nsize ; ++z)
			{
				sum += _grayData[z];
			}
			pic[index+nsize/2] = sum;
		}
	}


	
	for (y = 0 ; y < height-nsize ; y++)
	{
		for (x = 0  ; x < width-nsize ; x++)
		{
			int index = (y+nsize/2) * width + x + nsize/2;
			int sum = 0;
			int i,j;
			for(i = 0;i<=nsize/2;++i){
				sum += pic[index+i*width];
				sum += pic[index-i*width];
			}
			sum -= pic[index];
			getpic[index]= sum/nsize/nsize;
		}
	}

	ShowPicByArray(getpic, width, height);
	delete []getpic;
	
}

void CImageStuDlg::OnYuZhi() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *pic = new int [size];


	int *getpic = new int [size];

	int x,y,z;
	int nsize = 25;
	for (y = 0 ; y < height ;++y )
	{
		for (x = 0 ; x < width - nsize ; ++x)
		{
			int sum = 0 ;
			int index = y * width + x;
			for (z = index; z < index+nsize ; ++z)
			{
				sum += _grayData[z];
			}
			pic[index+nsize/2] = sum;
		}
	}


	
	for (y = 0 ; y < height-nsize ; y++)
	{
		for (x = 0  ; x < width-nsize ; x++)
		{
			int index = (y+nsize/2) * width + x + nsize/2;
			int sum = 0;
			int i,j;
			for(i = 0;i<=nsize/2;++i){
				sum += pic[index+i*width];
				sum += pic[index-i*width];
			}
			sum -= pic[index];
			getpic[index]= sum/nsize/nsize;
			if (getpic[index] > 125)
			{
				getpic[index] = 255;
			}else{
				getpic[index] = 0;
			}
		}
	}

	ShowPicByArray(getpic, width, height);
	delete []getpic;
	
}

void CImageStuDlg::OnMsk() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *pic = new int [size];


	int *getpic = new int [size];

	int x,y,z;
	int nsize = 17;
	for (y = 0 ; y < height ;++y )
	{
		for (x = 0 ; x < width - nsize ; ++x)
		{
			int sum = 0 ;
			int index = y * width + x;
			for (z = index; z < index+nsize ; ++z)
			{
				sum += _grayData[z];
			}
			pic[index+nsize/2] = sum;
		}
	}


	int xma = 100;
	int yma = 100;
	int leng = 100;
	for (y = 0 ; y < height-nsize ; y++)
	{
		for (x = 0  ; x < width-nsize ; x++)
		{

			int index = (y+nsize/2) * width + x + nsize/2;
			if((x>xma&&x<xma+leng)&&(y>yma&&y<yma+leng) ){
				int sum = 0;
			int i,j;
			for(i = 0;i<=nsize/2;++i){
				sum += pic[index+i*width];
				sum += pic[index-i*width];
			}
			sum -= pic[index];
			getpic[index]= sum/nsize/nsize;
			}else{
				getpic[index]= _grayData[index];
			}
			
			
		}
	}

	ShowPicByArray(getpic, width, height);
	delete []getpic;
	
}

void CImageStuDlg::OnPlusQ() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CJiaquan bean = CJiaquan (_grayData, width, height);
		
	int level = 15;
	bean.jisuan_normal(level);
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	delete []pic;
	
}

void CImageStuDlg::OnLpls() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CImageProcess bean = CImageProcess(_grayData,width,height);
	bean.jisuan_lapulasi();
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnRobert() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CImageProcess bean = CImageProcess(_grayData,width,height);
	bean.jisuan_Robert();
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnSobel() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CImageProcess bean = CImageProcess(_grayData,width,height);
	bean.jisuan_Sobel();
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnSobeluse() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CImageProcess bean = CImageProcess(_grayData,width,height);
	bean.jisuan_Sobel();
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnZongZhi() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CJiaquan bean = CJiaquan (_grayData, width, height);
		
	int level = 5;
	bean.jisuan_middle(level);
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	delete []pic;
	
}

void CImageStuDlg::OnRgbCmy() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CColorImage bean = CColorImage(_colorData,width,height);
	bean.RGBtoCMY();
	CBaseColorInfo *pic = bean.getImg();
	ShowPicByArray(pic, width, height);

}

void CImageStuDlg::OnRgbyuv() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CColorImage bean = CColorImage(_colorData,width,height);
	bean.RGBtoYUV();
	CBaseColorInfo *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnRgbycbcr() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CColorImage bean = CColorImage(_colorData,width,height);
	bean.RGBtoYCBCR();
	CBaseColorInfo *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnGrayTColor() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CColorImage bean = CColorImage(_colorData,width,height);
	bean.GraytoColor(_grayData);
	CBaseColorInfo *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnP28825() 
{
	// TODO: Add your command handler code here
	int width = 400, height = 400;
	int size;
	size = width * height;
	CBaseColorInfo *pic = new CBaseColorInfo [width * height];
	int i,j,k;
	for (i = 0 ; i < size ; i++)
	{
		pic[i].SetGreen(255);
	}
	ShowPicByArray(pic, width, height);

	
}

void CImageStuDlg::OnP28715() 
{
	// TODO: Add your command handler code here

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CColorImage bean = CColorImage(_colorData,width,height);
	bean.P287_15();
	CBaseColorInfo *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
}

void CImageStuDlg::OnFuhua() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CImageProcessNine bean = CImageProcessNine(_grayData, width, height);
	bean.jisuan_fushi(3);
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnRgbHsi() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CColorImage bean = CColorImage(_colorData,width,height);
	bean.RGBtoHSI();
	CBaseColorInfo *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnRgbHsiRgb() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CColorImage bean = CColorImage(_colorData,width,height);
	bean.RGBtoHSItoRGB();
	CBaseColorInfo *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnPengZhang() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CImageProcessNine bean =CImageProcessNine(_grayData, width, height);
	bean.jisuan_pengzhang(3);
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnKaiDo() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CImageProcessNine bean1 = CImageProcessNine(_grayData, width, height);
	bean1.jisuan_fushi(3);
	int *pic = bean1.getImg();
	CImageProcessNine bean2 = CImageProcessNine(pic, width, height);
	bean2.jisuan_pengzhang(3);
	int *showpic = bean2.getImg();
	ShowPicByArray(showpic, width, height);
}

void CImageStuDlg::OnBiDo() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CImageProcessNine bean1 = CImageProcessNine(_grayData, width, height);
	bean1.jisuan_pengzhang(3);
	int *pic = bean1.getImg();
	CImageProcessNine bean2 = CImageProcessNine(pic, width, height);
	bean2.jisuan_fushi(3);
	int *showpic = bean2.getImg();
	ShowPicByArray(showpic, width, height);
}

void CImageStuDlg::OnGetBian() 
{
	// TODO: Add your command handler code here
		int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int *_oldgray = new int[size];
	for(int j = 0; j < size; ++ j)
		_oldgray[j] = _grayData[j];
	CImageProcessNine bean1 = CImageProcessNine(_oldgray, width, height);
	bean1.jisuan_fushi(3);
	int *pic = bean1.getImg();
	int *showpic = new int[size];
	for(int i = 0; i < size; ++ i)
	{
		showpic[i] = abs(_grayData[i] - pic[i]);
	}
	ShowPicByArray(showpic, width, height);
	delete []showpic;
}

void CImageStuDlg::OnQytcUse() 
{
	// TODO: Add your command handler code here
	int model[9] = {
		0, 1, 0,
		1, 0, 1,
		0, 1, 0
	};
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CGetImage bean = CGetImage (_grayData, width, height);
	bean.jisuan_quyutianchong(64, 63, model, 3, true);
	bean.jisuan_quyutianchong(183, 46, model, 3, true);
	bean.jisuan_quyutianchong(362, 38, model, 3, true);
	bean.jisuan_quyutianchong(6, 181, model, 3, true);
	bean.jisuan_quyutianchong(96, 160, model, 3, true);
	bean.jisuan_quyutianchong(180, 199, model, 3, true);
	bean.jisuan_quyutianchong(262, 148, model, 3, true);
	bean.jisuan_quyutianchong(464, 141, model, 3, true);
	bean.jisuan_quyutianchong(104, 298, model, 3, true);
	bean.jisuan_quyutianchong(239, 306, model, 3, true);
	bean.jisuan_quyutianchong(385, 372, model, 3, true);
	bean.jisuan_quyutianchong(61, 453, model, 3, true);
	bean.jisuan_quyutianchong(235, 461, model, 3, true);
	bean.jisuan_quyutianchong(404, 468, model, 3, true);
	bean.jisuan_quyutianchong(412, 232, model, 3, true);
	//bean.jisuan_quyutianchong(512, 355, model, 3, true);
	bean.jisuan_quyutianchong(507, 489, model, 3, true);
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
}

void CImageStuDlg::Onliantongqy() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int i, j, k;
	int *ff = new int[size];
	CGetImage bean = CGetImage (_grayData, width, height);
	bean.jisuan_liantong();
	
	ff = bean.getliantong();

	int elem[3] = {0, 127,255};
	CBaseColorInfo *color = new CBaseColorInfo[216];
	CBaseColorInfo *pic = new CBaseColorInfo[size];
	int index = 0;
	int rule[256] = {0};
	for(i = 0; i < 3; ++ i)
	{
		for(j = 0; j < 3; ++ j)
		{
			for(k = 0; k < 3; ++ k)
			{
				color[index ++] = CBaseColorInfo (elem[i], elem[j], elem[k]);
			}
		}
	}
	/*int mmax = 0;
	for(i = 0; i < size; ++ i)
	{
		if(ff[i] > mmax)
			mmax = ff[i];
	}*/
	for(i = 0; i < 20; ++ i)
	{
		rule[i] = i / 19.0 * 27;
	}
	
	for(i = 0; i < size; ++ i){
		
		//if(ff[i] > 0 && ff[i] < 256)
		//	pic[i] = color[rule[ff[i]]];
				pic[i] = color[ff[i]];
	}
	
	//ShowPicByArray(bean.getImg(), width, height);
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnXiHua() 
{
	// TODO: Add your command handler code here

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	CGetImage bean = CGetImage (_grayData, width, height);
	bean.jisuan_xihua();
	int *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnWCs() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	int elem[6] = {0, 51, 102, 153, 204, 255};
	int i, j, k;
	CBaseColorInfo *color = new CBaseColorInfo[216];
	CBaseColorInfo *pic = new CBaseColorInfo[size];
	int index = 0;
	int rule[256] = {0};
	for(i = 0; i < 6; ++ i)
	{
		for(j = 0; j < 6; ++ j)
		{
			for(k = 0; k < 6; ++ k)
			{
				color[index ++] = CBaseColorInfo (elem[i], elem[j], elem[k]);
			}
		}
	}
	for(i = 0; i < 256; ++ i)
	{
		rule[i] = i / 255.0 * 216;
	}

	for(i = 0; i < size; ++ i)
	{
		int gray = _grayData[i];
		pic[i] = color[rule[gray]];

	}	
	ShowPicByArray(pic, width, height);
}

void CImageStuDlg::OnPhdFl() 
{
	// TODO: Add your command handler code here
	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	int size = width * height;
	CImageProcessRGB bean = CImageProcessRGB(_colorData,width,height);
	bean.jisuan_15_b();
	CBaseColorInfo *pic = bean.getImg();
	ShowPicByArray(pic, width, height);
	
}

void CImageStuDlg::OnHfmTs() 
{
	// TODO: Add your command handler code here
		int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	CGetImage bean = CGetImage (_grayData, width, height);
	bean.jisuan_hafuman();
	CString *res = bean.getHafuman();
}
