
// LEDScreen.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLEDScreenApp: 
// �йش����ʵ�֣������ LEDScreen.cpp
//

class CLEDScreenApp : public CWinApp
{
public:
	CLEDScreenApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLEDScreenApp theApp;