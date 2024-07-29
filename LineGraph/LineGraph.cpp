﻿
// LineGraph.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "LineGraph.h"
#include "LineGraphDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLineGraphApp

BEGIN_MESSAGE_MAP(CLineGraphApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLineGraphApp 생성

CLineGraphApp::CLineGraphApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CLineGraphApp 개체입니다.

CLineGraphApp theApp;


// CLineGraphApp 초기화

BOOL CLineGraphApp::InitInstance()
{
	CWinApp::InitInstance();

	CLineGraphDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

