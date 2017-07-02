// Jiaquan.cpp: implementation of the CJiaquan class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "Jiaquan1.h"
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CJiaquan::CJiaquan(int *img, int width, int height)
{
	int size = width * height;
	_img = new int[size];
	_oldimg = new int[size];
	for(int i = 0; i < size; ++ i){
		_img[i] = img[i];
		_oldimg[i] = img[i];
	}
	_width = width;
	_height = height;
}

CJiaquan::~CJiaquan()
{

}

void CJiaquan::jisuan_normal(int level)
{
	int ans = level / 2;
	int moban[100];
	int chuizhi[1007];
	int size = _width * _height;
	
	int i, j, x, y;
	int p = 0, s = 0;
	memset(chuizhi, 0, sizeof(chuizhi));
	for(i = 0; i <= ans; ++ i){
		moban[i] = pow(2, i);
		p += moban[i];
	}
	for(i = level - 1; i > ans; -- i){
		moban[i] = pow(2, level - i - 1);
		p += moban[i];
	}
	for(i = 0; i < level; ++ i)
	{
		s += p * moban[i];
	}
	for(i = ans; i < _height - ans; ++ i){
		for(j = ans; j < _width - ans; ++ j){
			int sum = 0;
			//heng
			memset(chuizhi, 0, sizeof(chuizhi));
			for(y = j - ans; y <= j + ans; ++ y){
				for(x = i - ans; x <= i + ans; ++ x){
					chuizhi[y] += _oldimg[y * _height + x] * moban[x - i + ans];
				}
			}
			for(y = j - ans; y <= j + ans; ++ y){
				sum += 	chuizhi[y] * moban[y - j + ans];
			}
			_img[j * _height + i] = sum / s;
		}
	}

}

void CJiaquan::jisuan_middle(int level){
	
	int i, j, k, x, y;
	int *temp = new int[level * level];
	int ans = level / 2;
	int res = (level * level) / 2;
	for(i = ans; i < _height - ans; ++ i){
		for(j = ans; j < _width - ans; ++ j){
			int sum = 0;
			//heng
			int p = 0;
			for(y = j - ans; y <= j + ans; ++ y){
				for(x = i - ans; x <= i + ans; ++ x){
					temp[p ++] = _oldimg[x * _width + y];
					//temp[p ++] = _oldimg[y * _height + x];
				}
			}
			sort(temp, temp + p);
			
			_img[i * _width + j] = temp[res];
		}
	}
	delete []temp;
}
