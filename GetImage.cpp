// GetImage.cpp: implementation of the CGetImage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "GetImage.h"
#include <math.h>
#include "imagestu.h"
#include "BaseColorInfo.h"
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <functional>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGetImage::CGetImage(int *img, int width, int height)
{
	int size = width * height;
	_img = new int[size];
	_oldimg = new int[size];
	_fanxiangimg = new int[size];
	flag_liantong = new int[size];
	for(int i = 0; i < size; ++ i){
		_img[i] = img[i];
		_oldimg[i] = img[i];
		flag_liantong[i] = 0;
		if(img[i] == 0)
			_fanxiangimg[i] = 255;
		else
			_fanxiangimg[i] = 0;
	}
	_width = width;
	_height = height;
}

CGetImage::~CGetImage()
{
	if(_img != NULL)
		delete []_img;
	if(_oldimg != NULL)
		delete []_oldimg;
/*	if(rgb_img != NULL)
		delete []rgb_img;*/
	if(_fanxiangimg != NULL)
		delete [] _fanxiangimg;
	if(flag_liantong != NULL)
		delete []flag_liantong;

}
void CGetImage::jisuan_lapulasi(){
	int size = _width * _height;
	int i, j;
	for(i = 1; i < _width - 1; ++ i){
	
		for(j = 1; j <_height - 1; ++ j)
		{
			int index = j * _width + i;
			int s = 0;
			s += _oldimg[index - 1];
			s += _oldimg[index + 1];
			s += _oldimg[index - _width];
			s += _oldimg[index + _width];
			s += _oldimg[index - _width - 1];
			s += _oldimg[index - _width + 1];
			s += _oldimg[index + _width - 1];
			s += _oldimg[index + _width + 1];
			s -= 8 * _oldimg[index];
			_img[index] = abs(s);
		}
	}
}

void CGetImage::jisuan_Robert(){
	int size = _width * _height;
	int i, j;
	for(i = 0; i < _width - 1; ++ i){
		for(j = 0; j < _height - 1; ++ j){
			int index = j * _width + i;
			_img[index] = abs(_oldimg[index + _width + 1] - _oldimg[index]) 
				+ abs(_oldimg[index + _width] -_oldimg[index + 1]);
		}
	}
}

void CGetImage::jisuan_Sobel(){
	int i, j;
	for(i = 1; i <_width - 1; ++ i){
		for(j = 1; j < _height - 1; ++ j){
			int index = j * _width + i;
			int z1= _oldimg[index - _width - 1];
			int z2= _oldimg[index - _width];
			int z3= _oldimg[index - _width + 1];
			int z4= _oldimg[index  - 1];
			int z5= _oldimg[index];
			int z6= _oldimg[index + 1];
			int z7= _oldimg[index + _width - 1];
			int z8= _oldimg[index + _width];
			int z9= _oldimg[index + _width + 1];
			_img[index] = abs((z7 + 2 * z8 + z9) -(z1 + 2 * z2 + z3))
				+ abs((z3 + 2 * z6 + z9) - (z1 + 2 * z4 + z7));
		}
	}
}

void CGetImage::jisuan_216_RGB()
{
	int size = _width * _height;
	int elem[6] = {0, 51, 102, 153, 204, 255};
	int i, j, k;
	CBaseColorInfo *color = new CBaseColorInfo[216];
	int index = 0;
	int rule[256] = {0};
	for(i = 0; i < 6; ++ i)
	{
		for(j = 0; j < 6; ++ j)
		{
			for(k = 0; k < 6; ++ k)
			{
				color[index] = CBaseColorInfo (elem[i], elem[j], elem[k]);
				index ++;
			}
		}
	}
	for(i = 0; i < 256; ++ i)
	{
		rule[i] = i / 255.0 * 216;
	}

	for(i = 0; i < size; ++ i)
	{
		int gray = _oldimg[i];
		rgb_img[i] = color[rule[gray]];

	}	
}

void CGetImage::jisuan_fushi(int level)
{
	int size = _width * _height;
	int pp = level / 2;
	int i, j;
	for(i = pp; i < _width - pp; ++ i )
	{
		for(j = pp; j <_height - pp; ++ j)
		{
			int index = j * _width + i;
			if(_oldimg[index] == 0)
				continue;
			for(int x = i - pp; x <= i + pp; ++ x)
			{
				for(int y = j - pp; y <= j + pp; ++ y)
				{
					int temp = y * _width + x;
					if(_oldimg[temp] == 0){
						_img[index] = 0;
						break;
					}
				}
			}
		}
	}
}

void CGetImage::jisuan_pengzhang(int level)
{
	int size = _width * _height;
	int pp = level / 2;
	int i, j;
	for(i = pp; i < _width - pp; ++ i )
	{
		for(j = pp; j <_height - pp; ++ j)
		{
			int index = j * _width + i;
			if(_oldimg[index] == 255)
				continue;
			for(int x = i - pp; x <= i + pp; ++ x)
			{
				for(int y = j - pp; y <= j + pp; ++ y)
				{
					int temp = y * _width + x;
					if(_oldimg[temp] == 255){
						_img[index] = 255;
						break;
					}
				}
			}
		}
	}
}

void CGetImage::jisuan_fushi2(int *model, int size, bool white)
{
	int _size = _width * _height;
	int *temp = new int [_size];
	std::copy( _img, _img + _size, temp);
	for( int x = size / 2; x < _width - size / 2; ++x ){
		for( int y = size / 2; y < _height - size / 2; ++y ){
			int index = y * _width + x;
			if( white == true ){
				// 白色做腐蚀
				if( temp[ index ] == 0 ){
					continue;
				}
			}
			else{
				if( temp[ index ] == 255 ){
					continue;
				}
			}

			// 取邻域
			int step = 0;
			for( int m = x - size / 2; m <= x + size / 2; ++m ){
				for( int n = y - size / 2; n <= y + size / 2; ++n ){
					
					if( model[ step ] == 0 ){
						// 模板为0，不需要处理
						++step;
						continue;
					}
					++step;

					int tempIndex = n * _width + m;
					if( white == true ){
						if( temp[ tempIndex ] == 0 ){
							_img[ index ] = 0;
						}
					}
					else{
						if( temp[ tempIndex ] == 255 ){
							_img[ index ] = 255;
						}
					}
				}
			}
		}
	}
}

bool CGetImage::XiangDeng(int *first, int *second){
	int size = _width * _height;
	for(int i = 0; i < size; ++ i)
	{
		if(first[i] != second[i])
			return false;
	}
	return true;
	
}

void CGetImage::JiaoJi(int *first, int *second, int *result){
	int size = _width * _height;
	for(int i = 0; i < size; ++ i){
		if(first[i] == 255 && second[i] == 255)
			result[i] = 255;
		else
			result[i] = 0;
		
	}
}

void CGetImage::jisuan_quyutianchong(int x, int y, int *model, int level, bool white){

	//CGetImage(_img, _width, _height);
	int size = _width * _height;
	int i;
	for(i = 0; i < size; ++ i){
		
		_oldimg[i] = _img[i];
		if(_img[i] == 0)
			_fanxiangimg[i] = 255;
		else
			_fanxiangimg[i] = 0;
	}
	
	int *pic = new int[size];
	
	if(white == true){
		for(i = 0; i < size; ++ i)
			pic[i] = 0;
		pic[y * _width + x] = 255;
	}
	else{
		for(i = 0; i < size; ++ i)
			pic[i] = 255;
		pic[y * _width + x] = 0;
	}
//	int *beforeImg = new int[size];
//std::copy(pic, pic + size, beforeImg);
	std::copy(pic, pic + size, _img);
	
	jisuan_fushi2(model, level, !white);
	int *jiaojiImg = new int[size];

	//jisuan_pengzhang(5);
	JiaoJi(_img, _fanxiangimg, jiaojiImg);	

	int p = 0;
	while(!XiangDeng(pic, jiaojiImg)){

	//	std::copy(jiaojiImg, jiaojiImg + size, beforeImg);
		std::copy(jiaojiImg, jiaojiImg + size, _img);
		std::copy(jiaojiImg, jiaojiImg + size, pic);
		jisuan_fushi2(model, level, !white);
		//int *jiaojiImg = new int[size];

		JiaoJi(_img, _fanxiangimg, jiaojiImg);
	
		/*if(p ++ > 100)
			break;*/
	}
	
	for(i = 0; i < size; ++ i)
	{
		if(white != true){
			if(_oldimg[i] == 0)
				_img[i] = 0;
		}else{
			if(_oldimg[i] == 255)
				_img[i] = 255;
		}
	}
	//std::copy(_fanxiangimg, _fanxiangimg + size, _img);
/*	for(i = 0; i < size; ++ i){
		if(_oldimg[i] == 255)
			_img[i] = 255;
	}*/
	delete[] pic;
	delete[] jiaojiImg;

}
int fang[8][2] = {1, -1, 1, 1, 1, 0, 0, 1, 0,-1, -1, 0, -1, 1, -1, -1};

void CGetImage::dfs_liantong(int x, int y, int index, int top){

	flag_liantong[index] = top;

	for(int i = 0; i < 8; ++ i)
	{
		int nx = x + fang[i][0];
		int ny = y + fang[i][1];
		int id = ny * _width + nx;
		if(nx >= 0 && nx < _width && ny >= 0 && ny < _height && _img[id] == 255 && flag_liantong[id] == 0){
			dfs_liantong(nx, ny, id, top);
		}
	}
	
}
void CGetImage::jisuan_liantong()
{
	int size = _width * _height;
	int i, j;
	for(i = 0; i < size; ++ i)
	{
		if(_img[i] > 200)
		{
			_img[i] = 255;
			_oldimg[i] = 255;
		}else
		{
			_img[i] = 0;
			_oldimg[i] = 0;
		}
	}
	jisuan_fushi(5);
	std::copy(_img, _img + size, _oldimg);
	int top = 1;
//	flag_liantong = new int[size];
//	memset(flag_liantong, 0, sizeof(flag_liantong));
	for(i = 0; i < _width; ++ i){
		for(j = 0; j <_height; ++ j){
			int index = j * _width + i;
			if(flag_liantong[index] == 0 && _img[index] == 255){
					dfs_liantong(i, j, index, top);
					top ++;
			}
		}
	}
	

}

void CGetImage::jisuan_xihua()
{
	// ???
	int ERASE_TABLE[256] = {
		0,0,1,1,0,0,1,1, 1,1,0,1,1,1,0,1,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,1,
			0,0,1,1,0,0,1,1, 1,1,0,1,1,1,0,1,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,1,
			1,1,0,0,1,1,0,0, 0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
			1,1,0,0,1,1,0,0, 1,1,0,1,1,1,0,1,
			0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
			0,0,1,1,0,0,1,1, 1,1,0,1,1,1,0,1,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,1,
			0,0,1,1,0,0,1,1, 1,1,0,1,1,1,0,1,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,0,
			1,1,0,0,1,1,0,0, 0,0,0,0,0,0,0,0,
			1,1,0,0,1,1,1,1, 0,0,0,0,0,0,0,0,
			1,1,0,0,1,1,0,0, 1,1,0,1,1,1,0,0,
			1,1,0,0,1,1,1,0, 1,1,0,0,1,0,0,0
	};
	bool finish = false;
	int _size = _width * _height;

	while (finish == false)
	{
		finish = true;
		for (int y = 1 ; y < _height-1 ; ++y)
		{
			for (int x = 1 ; x < _width-1 ; ++x)
			{
				int index = y * _width + x;
				if (_oldimg[index] == 0) 
				{
					int w = _oldimg[index - 1];
					int e = _oldimg[index + 1];
					if (w == 255 || e == 255)
					{
						int nw = _oldimg[index - _width - 1];
						int n = _oldimg[index - _width]; 
						int ne = _oldimg[index - _width + 1 ];
						int sw = _oldimg[index + _width - 1];
						int s = _oldimg[index + _width];
						int se = _oldimg[index + _width + 1];
					
						int num = nw/255+n/255*2+ne/255*4+w/255*8+e/255*16+sw/255*32+s/255*64+se/255*128;
						if (ERASE_TABLE[num] == 1)
						{
							_img[index] = 255;
							_oldimg[index] = 255;
							x++;
							finish = false;
						}
					}
				}
			}
		}
		for (int x = 1 ; x < _width-1 ; ++x)
		{
			for (int y= 1 ; y < _height-1 ; ++y)
			{
				int index = y * _width + x;
				if (_oldimg[index] == 0) 
				{
					int n = _oldimg[index - _width];
					int s = _oldimg[index + _width];
					if (n == 255 || s == 255)
					{
						int nw = _oldimg[index - _width - 1];
						int ne = _oldimg[index - _width + 1 ];
						int w = _oldimg[index - 1]; 
						int e = _oldimg[index + 1];
						int sw = _oldimg[index + _width - 1];
						int se = _oldimg[index + _width + 1];
						int num = nw/255+n/255*2+ne/255*4+w/255*8+e/255*16+sw/255*32+s/255*64+se/255*128;
						if (ERASE_TABLE[num] == 1)
						{
							_img[index] = 255;
							_oldimg[index] = 255;
							y++;
							finish = false;
						}
					}
				}
				
			}
		}
	}
}


struct node
{
	int father, lson, rson, val, num;
	bool operator < (const node &a) const{
		return val > a.val;
	}
}ans[100006];
priority_queue<node>sq;
vector<int>vc;


void CGetImage::dfs(int root){
	int lson = ans[root].lson;
	int rson = ans[root].rson;
	_hafuman[lson] = _hafuman[root] + "0";
	_hafuman[rson] = _hafuman[root] + "1";
	if(lson >= 256)
	{
		dfs(lson);
	}
	if(rson >= 256)
		dfs(rson);
}
void CGetImage::jisuan_hafuman()
{
	_hafuman = new CString[100008];
	int size = _width * _height;
	double p[300];
	vc.clear();
	int *num = new int[size];
	int i, j;
	for(i = 0; i < size; ++ i){
		if(ans[_img[i]].val == 0){
			ans[_img[i]].num = _img[i];
			vc.push_back(_img[i]);
		}
		ans[_img[i]].val ++;
	}
	for(i = 0; i < vc.size(); ++ i){
		sq.push(ans[vc[i]]);
	}
	int nn = 256;
	while(sq.size() >= 2){
		node a = sq.top();
		sq.pop();
		node b = sq.top();
		sq.pop();
		node c;
		c.val = a.val + b.val;
		c.num = nn ++;
		c.lson = a.num;
		c.rson = b.num;
		a.father = c.num;
		b.father = c.num;
		ans[c.num] = c;
		sq.push(c);
	}
	node rt = sq.top();
	sq.pop();
	int root = sq.top().num;

	dfs(root);


	//前100位编码位流
	CString temp;
	temp += "前100位码位流:\n";
	for( i = 0; i < 100; ++ i){
		temp += _hafuman[_img[i]];
	}
	temp += "\n";
	//总位数，平均码长，熵
	double sum = 0, avg, div = 0;
	for(i = 0; i < 256; ++ i){
		sum += _hafuman[i].GetLength() * ans[i].val;
		if(ans[i].val != 0){
		p[i] = ans[i].val * 1.0 / (size * 1.0);
		div -= (p[i] * (log(p[i]) / log(2.0)));
		}
	//	div -= (p[i] * log2(p[i]));
	}
	avg = sum / size * 1.0;
	
	//div = - p[0] * (log(p[0]) / log(2.0));
	



	CStdioFile file;
	CString str, jj;
	str += "字符  编码              长度   数量   位数 \n";
	if(file.Open(_T("C:\\123.txt"), CFile::modeCreate|CFile::modeReadWrite|CFile::typeText)){ 

		for( i = 0; i < 256; ++ i){
			if(_hafuman[i] != ""){
			jj.Format("%4d", i);
			str += jj;
		//	str += CString(j);
			str += ":  ";
			str += _hafuman[i];
			int len = _hafuman[i].GetLength();
			for(j = len; j <18; ++ j )
				str += " ";
			jj.Format("%4d", len);
			str += jj;
			jj.Format("%6d", ans[i].val);
			str += jj;
			jj.Format("%7d", ans[i].val * len);
			str += jj;
			str += "\n";
			}
		}
		//显示100位编码流位
		str += "\n\n";
		str += temp;

		//计算指标
		str += "\n\n";
		jj.Format("%lf", sum);
		str += ("总位数:" + jj + "\n");

		jj.Format("%lf", avg);
		str += ("平均码长:" + jj + "\n");

		jj.Format("%lf", div);
		str += ("熵:" + jj + "\n");
		 
		file.WriteString(str);
		file.Close();
		
	}
}
