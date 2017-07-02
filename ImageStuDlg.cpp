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

	// ͼ���Ѵ򿪱��
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

	// ��ͼ
	CDC * pDC = GetDC();
	if( _flag == true ){
		
		// �Ѿ����ļ�
		SetDIBitsToDevice(
			  pDC->m_hDC  // �豸������
			, 0 // �豸������λͼ�������ʼ�߼�x����
			, 0 // �豸������λͼ�������ʼ�߼�y����
			, _infoHeader.biWidth // DIB�Ŀ��
			, _infoHeader.biHeight // DIB�ĸ߶�
			, 0 // DIB��ʼ��ȡ������������ݵ�xλ��
			, 0 // DIB��ʼ��ȡ������������ݵ�yλ��
			, 0 // DIB�����ص�ˮƽ�к�, ��ӦlpBits�ڴ滺�����ĵ�һ������
			, _infoHeader.biHeight  // DIB������
			, _lpBuf  // ��������
			, _bitmapInfo //BITMAPINFO����
			, DIB_RGB_COLORS // ��ʾ����ɫ
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
// ���ٶԻ���, ӳ��WM_DESTORY��Ϣ
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
/*                           �˵�                                       */
/************************************************************************/

//////////////////////////////////////////////////////////////////////////
// "�ļ�"-->"��"(IDC_FILE_OPEN)
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnFileOpen() 
{
	// TODO: Add your command handler code here
	
	LPCTSTR lpszFilter = "BMP Files(*.bmp)|*.bmp|�κ��ļ�|*.*|";
	CFileDialog dlg( TRUE, lpszFilter, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		lpszFilter, NULL );
	// �ļ���
	CString fileName;
	CFile file;
	// ���ļ�
	if( dlg.DoModal() == IDOK ){

		// �ļ���
		fileName = dlg.GetPathName();
		if( file.Open( fileName, CFile::modeRead | CFile::shareDenyNone, NULL ) == 0 ){
			// ��ȡ�ļ�ʧ��
			AfxMessageBox( "�޷����ļ�", MB_OK, MB_ICONERROR );
			return;
		}

		// ��ȡ�ļ�ͷ
		if( !ReadFileHeader( file ) ){
			return;
		}

		// ��ȡ��Ϣͷ 
		if( !ReadInfoHeader( file ) ){
			return;
		}

		// ��ǰ�������ļ��򿪣����ͷ���Ӧ������
		if( _flag == true ){
			FreeData();
			_flag = false;
		}

		// �����ɫ����ɫ����
		_numQuad = CalcQuadNum();
		// ��ȡ��ɫ������
		ReadQuad( file );

		// �ж�ͼ������
		_imageType = CalcImageType();

		// ����ͼ������
		ReadImageData( file );
		

		

		// ���䴦��������
		_processBuf = ( BYTE * )HeapAlloc( GetProcessHeap(), 0, _infoHeader.biSizeImage );
	
		// ��Ȳ���4�ı�������
		DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
		if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
			dwBytes++;
		}
		dwBytes *= 4;

		
		
		Invalidate( );

		int width = _infoHeader.biWidth;
        int height = _infoHeader.biHeight;

		// ����ռ�
		_colorData = new CBaseColorInfo[ width * height ];
		_grayData = new int[ width * height ];

		// ����ͼ�����ͣ�����ת������Ӧ��ͼ������
		if( _imageType == COLOR_24_BIT ){
			// 24λ��ɫͼ��
			BMPConvertColor24();
			
		}
		else if( _imageType == COLOR_8_BIT ){
			// 256��ɫͼ��
			BMPConvertColor8();
		}
		else if( _imageType == GRAY_8_BIT ){
			// 256�Ҷ�ͼ��
			BMPConvertGray8();
			// ��8λ�Ҷ�����ת����24λ��ɫ
			Gray8ConvertColor24( _grayData, _colorData, width, height );
		}
		else{
			MessageBox( "�ݲ�֧�ָ�ͼ������" );
			// �ر�ͼ��
			file.Close();
			FreeData();
			return;
		}

		// ͼ���ȡ���
		file.Close();
		_flag = true;

	}

}


//////////////////////////////////////////////////////////////////////////
// "�ļ�"-->"��ʾ����ͼ��"
// ��ת�����24λ��ɫ�����ڶԻ�������ʾ
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnFileShowArray() 
{
	// TODO: Add your command handler code here

	if(_flag == FALSE){
		MessageBox("û�д�ͼ��");
		return;
	}

	CDlgShowArray dlg;
	dlg.SetColorData( _colorData );
	dlg.SetWidth( _infoHeader.biWidth );
	dlg.SetHeight( _infoHeader.biHeight );
	dlg.DoModal();

}


//////////////////////////////////////////////////////////////////////////
// "�ļ�"-->"����"�˵�
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::OnFileSave() 
{
	// TODO: Add your command handler code here
	if( ! _flag  ){
		MessageBox( "û��ͼƬ���޷�����" );
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
/*                         ˽�к���                                     */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////
// ��ȡ�ļ�ͷ
// ����:
//   file: CFile &, BMP�ļ�
// ����ֵ:
//   BOOL, TRUE: �ɹ�; FALSE: ʧ��
//////////////////////////////////////////////////////////////////////////
BOOL CImageStuDlg::ReadFileHeader( CFile &file ){

	// ��ȡ�ļ�ͷ
	file.Read( &_fileHeader, sizeof( _fileHeader ) );
	// �ж��Ƿ�ΪBMP�ļ�
	if( _fileHeader.bfType != 0x4d42 ){
		// "BM"
		AfxMessageBox( "����BMP�ļ�", MB_OK, MB_ICONERROR );
		return FALSE;
	}

	// �ж��ļ��Ƿ���(�ļ���С�Ƿ����ļ�ͷ����Ϣһ��)
	if( file.GetLength() != _fileHeader.bfSize ){
		AfxMessageBox( "�ļ�����", MB_OK, MB_ICONERROR );
		return FALSE;
	}

	return TRUE;
	
}


//////////////////////////////////////////////////////////////////////////
// ��ȡ�ļ���Ϣͷ
// ����:
//   file: CFile &, �Ѿ��򿪵�BMP�ļ�
// ����ֵ:
//   BOOL, TRUE�ɹ�; ����ʧ��
//////////////////////////////////////////////////////////////////////////
BOOL CImageStuDlg::ReadInfoHeader( CFile &file ){

	// ��ȡ�ļ���Ϣͷ
	file.Read( &_infoHeader, sizeof( _infoHeader ) );

	// ��ͼƬ��ʽ�޶���8λͼ��
// 	if( _infoHeader.biBitCount != 8 ){
// 		AfxMessageBox( "����Ϊ8λ�Ҷ�ͼ", MB_OK, MB_ICONERROR );
// 		return FALSE;
// 	}

	return TRUE;

}


//////////////////////////////////////////////////////////////////////////
// �ͷ�����
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::FreeData(){

	HeapFree( GetProcessHeap(), 0, _bitmapInfo );
	HeapFree( GetProcessHeap(), 0, _lpBuf );
	// ����������
	HeapFree( GetProcessHeap(), 0, _processBuf );
	// �Ҷ���ɫ����
	delete [] _grayData;
	// ��ɫ��ɫ����
	delete [] _colorData;



}

//////////////////////////////////////////////////////////////////////////
// �����ɫ����ɫ����
// ����: ��
// ����ֵ:
//   int, ��ɫ����ɫ����
//////////////////////////////////////////////////////////////////////////
int CImageStuDlg::CalcQuadNum(){

	// �����ɫ������
	int numQuad = 0;
	if( _infoHeader.biBitCount < 24){
		// �൱��2��biBitCount�η�
		numQuad = ( 1 << _infoHeader.biBitCount );
	}

	return numQuad;

}

//////////////////////////////////////////////////////////////////////////
// ��ȡ��ɫ������
// ����:
//   file: CFile &, BMP�ļ�
// ����ֵ: ��
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ReadQuad( CFile &file ){

	// Ϊͼ����Ϣpbi����ռ�
	_bitmapInfo = ( BITMAPINFO * )HeapAlloc( 
		GetProcessHeap(), 
		0, 
		sizeof( BITMAPINFOHEADER ) + _numQuad * sizeof( RGBQUAD ) 
	);
	memcpy( _bitmapInfo, &_infoHeader, sizeof( _infoHeader ) );
	_quad = ( RGBQUAD * )( ( BYTE *)_bitmapInfo + sizeof( BITMAPINFOHEADER ) );

	// ��ȡ��ɫ��
	if( _numQuad != 0 ){
		file.Read( _quad, sizeof( RGBQUAD ) * _numQuad );
	}

}

//////////////////////////////////////////////////////////////////////////
// �ж��Ƿ�Ϊ256ɫ�Ҷ�ͼ
// �ж����ݣ���ɫ����������ɫ�ĵ�RGB��������Ӧ�����
// BOOL: TRUEΪ256ɫ�Ҷ�ͼ
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
// ����ͼ������
// ����:
//   file: CFile &, BMPͼ��
// ����ֵ: ��
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ReadImageData( CFile &file ){

	// Ϊͼ����������ռ�
	_infoHeader.biSizeImage = _fileHeader.bfSize - _fileHeader.bfOffBits;
	_lpBuf = ( BYTE *)HeapAlloc( GetProcessHeap(), 0, _infoHeader.biSizeImage );
	// ��ȡͼ������
	file.Read( _lpBuf, _infoHeader.biSizeImage );

}

//////////////////////////////////////////////////////////////////////////
// �ж�ͼ������
// ����: ��
// ����ֵ: IMAGE_TYPE, ͼ������, ����ö��IMAGE_TYPE�Ķ���
//////////////////////////////////////////////////////////////////////////
IMAGE_TYPE CImageStuDlg::CalcImageType(){

	IMAGE_TYPE type = COLOR_24_BIT;
	if( _infoHeader.biBitCount == IMAGE_TYPE_BIT_24 ){
		// 24��ɫͼ��
		type = COLOR_24_BIT;
		//MessageBox( "24λͼ��" );
	}
	else if( _infoHeader.biBitCount == IMAGE_TYPE_BIT_1 ){
		// ��ֵͼ��
		type = GRAY_1_BIT;
		//MessageBox( "1λͼ��" );
	}
	else if( _infoHeader.biBitCount == IMAGE_TYPE_BIT_8 ){
		// 8λ
		if( Is256Gray() ){
			// 8λ�Ҷ�ͼ��
			type = GRAY_8_BIT;
			//MessageBox( "8λ�Ҷ�ͼ��" );
		}
		else{
			// 8λ��ɫͼ��
			type = COLOR_8_BIT;
			//MessageBox( "8λ��ɫͼ��" );
		}
	}

	return type;

}

//////////////////////////////////////////////////////////////////////////
// ��BMP����ת����24λ��ɫ����
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::BMPConvertColor24(){

	// ��Ȳ���4�ı�������
	DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
	if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
		dwBytes++;
	}
	dwBytes *= 4;

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	// �����ɫ����

	int i,j;

	for( i = 0; i <= height - 1; i++ ){
		for( j = 0; j <= width - 1; j++ ){
			
			// BMPͼƬ�����е�����
			DWORD index = i * 3 * width + 3 * j;
			if( dwBytes % 3 != 0 ){
				index = i * dwBytes + 3 * j ;
			}
			// ��ɫ�����е�����
			DWORD resultIndex = ( height - 1 - i ) * width + j;
			_colorData[ resultIndex ].SetRed( _lpBuf[ index  + 2 ] );
			_colorData[ resultIndex ].SetGreen( _lpBuf[ index  + 1 ] );
			_colorData[ resultIndex ].SetBlue( _lpBuf[ index ] );

		}// for j
	}// for i 

}

//////////////////////////////////////////////////////////////////////////
// ��8λ��ɫBMP����ת��24λ��ɫ����
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::BMPConvertColor8(){

	// ��Ȳ���4�ı�������
	DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
	if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
		dwBytes++;
	}
	dwBytes *= 4;

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	// �����ɫ����
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
			
			// BMPͼƬ�����е�����
			DWORD index = i * dwBytes + j ;

			// ��ɫ�����е�����
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
// ��8λ�Ҷ�BMP����ת��8λ�Ҷ�����
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::BMPConvertGray8(){

	// ��Ȳ���4�ı�������
	DWORD dwBytes = ((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) / 32;
	if(((DWORD) _infoHeader.biWidth * _infoHeader.biBitCount) % 32) {
		dwBytes++;
	}
	dwBytes *= 4;

	int width = _infoHeader.biWidth;
	int height = _infoHeader.biHeight;
	// �����ɫ����
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
			
			// BMPͼƬ�����е�����
			DWORD index = i * dwBytes + j ;

			// ��ɫ�����е�����
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
// ��8λ�Ҷ�����ת����24λ��ɫ
// �Ҷ�ͼ��RGBֵ����ͬ
// ����:
//   grayData: BYTE *, �Ҷ�����
//   colorData: CBaseColorInfo *, 24λ��ɫ����
//   width: ͼƬ���
//   height: ͼƬ�߶�
//  ����ֵ: ��
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

// ��8λ�Ҷ�����ת����24λ��ɫ
void CImageStuDlg::Gray8ConvertColor24( int * grayData, CBaseColorInfo * colorData, int width, int height ){

	int length = width * height;
	for( int i = 0; i <= length - 1; i++ ){
		colorData[ i ].SetRed( grayData[ i ] );
		colorData[ i ].SetGreen( grayData[ i ] );
		colorData[ i ].SetBlue( grayData[ i ] );
	}

}

//////////////////////////////////////////////////////////////////////////
// ��ʾͼ��(ͨ��ͼ������,��ɫͼ��)
// ����:
//   colorData: CBaseColorInfo, ��ɫ����
//   width: int, ͼ����
//   height: int, ͼ��߶�
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ShowPicByArray( CBaseColorInfo * colorData, 
								   int width, 
								   int height ){

	CDlgShowArray dlg;
	// ͼ������(24λ��ɫͼ��)
	dlg.SetColorData( colorData );
	// ͼ����
	dlg.SetWidth( width );
	// ͼ��߶�
	dlg.SetHeight( height );
	// ��ʾ�Ի���
	dlg.DoModal();

}




//////////////////////////////////////////////////////////////////////////
// ��ʾͼ��(ͨ��ͼ������, �Ҷ�ͼ��)
// ����:
//   colorData: CBaseColorInfo, �Ҷ�ͼ������
//   width: int, ͼ����
//   height: int, ͼ��߶�
//////////////////////////////////////////////////////////////////////////
void CImageStuDlg::ShowPicByArray( int * grayData, 
								   int width, 
								   int height ){

	// ���Ҷ�ͼ��ת�ɲ�ɫͼ��
	CBaseColorInfo * colorData = new CBaseColorInfo[ width * height ];
	Gray8ConvertColor24( grayData, colorData, width, height );

	CDlgShowArray dlg;
	// ͼ������(24λ��ɫͼ��)
	dlg.SetColorData( colorData );
	// ͼ����
	dlg.SetWidth( width );
	// ͼ��߶�
	dlg.SetHeight( height );
	// ��ʾ�Ի���
	dlg.DoModal();

	// �ͷŲ�ɫͼ��
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

	// ��ʾͼ��
	ShowPicByArray( img, width, height );

	delete []img;
}


//////////////////////////////////////////////////////////////////////////
// ���ܣ�����BMPͼƬ
// ������
//   bmpName: char *, �ļ���(��·�����ļ���׺)
//   imgBuf: unsigned char *, ͼ������
//   width: int, ͼ����
//   height: int, ͼ��߶�
//   biBitCount: int, �������
//   pColorTable: RGBAUAD *, ��ɫ��
//////////////////////////////////////////////////////////////////////////
bool CImageStuDlg::SaveAsBmp( char * bmpName, 
							  unsigned char * imgBuf, 
							  int width, 
							  int height,
							  int biBitCount, 
							  RGBQUAD * pColorTable 
							 ){
	
	// ���λͼ����Ϊ�գ���û�����ݴ���
	if( !imgBuf ){
		return false;
	}
	
	// ��ɫ���С�����ֽ�Ϊ��λ���Ҷ�ͼ����ɫ��Ϊ1024����ɫͼ����ɫ���СΪ0
	int colorTableSize = 0;
	if( biBitCount == 8 ){
		colorTableSize = 1024; // �о���һ����ȷ
	} 
	
	// �����洢ͼ������ÿ���ֽ���תΪ4�ı���
	int lineByte = ( width * biBitCount / 8 + 3 ) / 4 * 4;
	// �Զ����Ƶ�д�ķ�ʽ���ļ�
	FILE *fp = fopen( bmpName, "wb" );
	if( !fp ){
		return false;
	}
	
	// ����λͼ�ļ�ͷ�ṹ��������д�ļ�ͷ��Ϣ
	BITMAPFILEHEADER fileHead;
	fileHead.bfType = 0x4D42;// bmp����
	// bfSize��ͼ���ļ�4����ɲ���֮��
	fileHead.bfSize = sizeof( BITMAPFILEHEADER ) 
		+ sizeof( BITMAPINFOHEADER )
		+ colorTableSize 
		+ lineByte * height; // ͼ�������ֽ���
	fileHead.bfReserved1 = 0;
	fileHead.bfReserved2 = 0;
	
	// bfOffBits��ͼ���ļ�ǰ����������ռ�֮��
	fileHead.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)  + colorTableSize;
	// �ļ�ͷд���ļ�
	fwrite( &fileHead, sizeof( BITMAPFILEHEADER ) , 1, fp );
	
	// ����λͼ��Ϣͷ�ṹ��������д��Ϣͷ��Ϣ
	BITMAPINFOHEADER head;
	head.biSize = sizeof(BITMAPINFOHEADER); // λͼ��Ϣͷ�ṹ�Ĵ�С(40���ֽ�)
	head.biWidth = width;// ͼ���ȣ�������Ϊ��λ
	head.biHeight = height;// ͼ��߶ȣ�������Ϊ��λ
	head.biPlanes = 1;// ����Ϊ1
	head.biBitCount = biBitCount; // ������ȣ�ÿ�����ص�Ϊ��(bit��)
	head.biCompression = BI_RGB; // ͼ���Ƿ�ѹ����һ����δѹ����
	head.biSizeImage = lineByte * height; // ʵ�ʵ�λͼ����ռ�ݵ��ֽ���
	head.biXPelsPerMeter = 0; // Ŀ���豸��ˮƽ�ֱ���
	head.biYPelsPerMeter = 0; // Ŀ���豸�Ĵ�ֱ�ֱ���
	head.biClrUsed = 0; // ��ͼ��ʵ���õ�����ɫ��
	head.biClrImportant = 0; // ��ͼ����Ҫ����ɫ�����Ϊ0�������е���ɫ����Ҫ 
	
	// дλͼ��Ϣͷ���ڴ�
	fwrite( &head, sizeof( BITMAPINFOHEADER ), 1, fp );
	
	// ���ͼ��ʱ�Ҷ�ͼ������ɫ��д���ļ�
	if( biBitCount == 8 ){
		fwrite( pColorTable, sizeof( RGBQUAD ), 256, fp );
	}
	
	// дλͼ���ݽ��ļ�
	fwrite( imgBuf, height * lineByte, 1, fp );
	
	// �ر��ļ�
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
	//����ֱ��ͼ

	int zhifangtu[256] = {0};
	for( i = 0; i < size; ++i)
	{
		int gray = _grayData[i];
		++zhifangtu[gray];
	}
	
	//��һ�����ۻ�
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


	//����ӳ�����

	int rule[256] = {0};

	for(i = 0; i < 256; ++i)
	{
		rule[i] = leiji[i]*255 + 0.5;

	}

	//������ͼ��
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
	//����ֱ��ͼ

	
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
	//����ֱ��ͼ

	
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
	//����ֱ��ͼ

	
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
	//����ֱ��ͼ

	
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
