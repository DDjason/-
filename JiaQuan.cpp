// JiaQuan.cpp: implementation of the JiaQuan class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "imagestu.h"
#include "JiaQuan.h"
#include <cmath>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JiaQuan::JiaQuan(int *img ,int width,int height)
{
	//_img = img;
	int size = width * height;
	_oldImg = new int[ size ];
	for( int i = 0; i < size; ++i ){
		_oldImg[ i ] = img[ i ];
	}
	_width = width;
	_height = height;
	_result = new int[ _width * _height ];

}

JiaQuan::~JiaQuan()
{
	if( _oldImg != NULL ){
		delete [] _oldImg;
	}

}

// 加权
void JiaQuan::jisuan( int level ){


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
					chuizhi[y] += _oldImg[y * _height + x] * moban[x - i + ans];
				}
			}
			for(y = j - ans; y <= j + ans; ++ y){
				sum += 	chuizhi[y] * moban[y - j + ans];
			}
			_result[j * _height + i] = sum / s;
		}
	}

}

//拉普拉斯处理

void JiaQuan::Lapulasi(){

	int x,y,k;

	for ( x = 1;x<_width-1; ++x)
	{
		int sum = 0 ;
		for (y = 1 ; y < _height - 1 ; ++y)
		{
			sum == 0;

		}
	}

}
