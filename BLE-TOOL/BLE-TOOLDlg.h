
// BLE-TOOLDlg.h : header file
//
//testt
#pragma once

#include "afxwin.h"
#include "SerialPort.h"
#include "afxcmn.h"
// CBLETOOLDlg dialog
class CBLETOOLDlg : public CDialogEx
{
// Construction
public:
	CBLETOOLDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLETOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	/*
	UINT rxdatalen = 0;
	const unsigned char rxdata[] =
	{
		{ "major=" },
		{ "minor=" },
		{ "power=" },
	};
	*/
	unsigned char rxdata[72] = {  };

	CComboBox m_SetComPort;
	CSerialPort m_SerialPort;
	//on: true  off:false
	UINT	m_SerialONOFF=0;
	//true: open comm false: close
	UINT	m_BottonStatus=1;

	UINT	m_sendStatus = 0;

	BOOL	m_sendone = FALSE;

	BOOL	m_enableSend=FALSE;
	BOOL	m_enableSend_RX = FALSE;

	BOOL	m_enableRead = FALSE;
	BOOL	m_enableReadTx = FALSE;

	BOOL	m_loopSend = FALSE;

	BOOL	m_sendMAC = FALSE;
	BOOL	m_sendMAJ = FALSE;
	BOOL	m_sendMin = FALSE;
	BOOL	m_sendUUID = FALSE;
	BOOL	m_sendINV = FALSE;

	UINT	m_msCount = 0;
	UINT	m_readCout = 0;

	UINT	m_writeCnt = 0;

	unsigned char Rx_Buffer[200];
	UINT	Rx_Buffer_Len = 0;

	CFont m_verson_Font;


	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonOpenSenial();
	afx_msg LRESULT OnComm(WPARAM ch, LPARAM port);
	CEdit m_strEDITRX;
	CString m_strRXMsg;
//	afx_msg void OnBnClickedCheck1();
//	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonSend();
	CEdit m_txrxmsg;
//	CEdit m_editMAC;
//	CEdit m_editMAJ;
//	CEdit m_editMIN;
//	CEdit m_editINV;
//	CEdit m_editUUID;
	CStatic m_staticMAC;
	CStatic m_staticMAJ;
	CStatic m_staticMIN;
	CStatic m_staticINV;
	CStatic m_staticUUID;
	CStatic m_staticPower;
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedCheckLoop();
	CButton m_checkLoop;
//	afx_msg void OnEnChangeEditMaj();
	CStatic m_satic_maj_hex;
	CStatic m_static_min_hex;
//	afx_msg void OnEnChangeEditMin();
//	UINT m_editMAJ;
	afx_msg void OnEnChangeEditMaj();
//	UINT m_editMIN;
	afx_msg void OnEnChangeEditMin();
	UINT m_editStep;
//	UINT m_editINV;
	CString m_editMAC;
	CString m_editUUID;


	int Str2Hex(CString str, char * pChar);
	char HexChar(char ch);
	int CharHex(char);
	afx_msg void OnStnClickedStaticMac();
	CStatic m_static_WriteCNT;
	afx_msg void OnBnClickedButtonClear();
	UINT m_editMAJ;
	UINT m_editMIN;
	UINT m_editINV;
	CProgressCtrl m_processPRO;
};
