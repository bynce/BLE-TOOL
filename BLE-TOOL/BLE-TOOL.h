
// BLE-TOOL.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CBLETOOLApp:
// See BLE-TOOL.cpp for the implementation of this class
//

class CBLETOOLApp : public CWinApp
{
public:
	CBLETOOLApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CBLETOOLApp theApp;