
// BLE-TOOLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BLE-TOOL.h"
#include "BLE-TOOLDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBLETOOLDlg dialog



CBLETOOLDlg::CBLETOOLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BLETOOL_DIALOG, pParent)
	
	, m_strRXMsg(_T(""))
	, m_editMAJ(0)
	, m_editMIN(0)
	, m_editStep(0)
	, m_editINV(0)
	, m_editMAC(_T(""))
	, m_editUUID(_T(""))
	//, m_editMAJ(0)
	//, m_editMIN(0)
	//, m_editINV(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBLETOOLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SERIAL, m_SetComPort);
	//	DDX_Control(pDX, IDC_EDIT_RX, m_strEDITRX);
	//	DDX_Text(pDX, IDC_EDIT_RXMSG, m_strRXMsg);
	DDX_Control(pDX, IDC_EDIT_TXRXMSG, m_txrxmsg);
	//  DDX_Control(pDX, IDC_EDIT_MAC, m_editMAC);
	//  DDX_Control(pDX, IDC_EDIT_MAJ, m_editMAJ);
	//  DDX_Control(pDX, IDC_EDIT_MIN, m_editMIN);
	//  DDX_Control(pDX, IDC_EDIT_INV, m_editINV);
	//  DDX_Control(pDX, IDC_EDIT_UUID, m_editUUID);
	DDX_Control(pDX, IDC_STATIC_MAC, m_staticMAC);
	DDX_Control(pDX, IDC_STATIC_MAJ, m_staticMAJ);
	DDX_Control(pDX, IDC_STATIC_MIN, m_staticMIN);
	DDX_Control(pDX, IDC_STATIC_INV, m_staticINV);
	DDX_Control(pDX, IDC_STATIC_UUID, m_staticUUID);
	DDX_Control(pDX, IDC_STATIC_POWER, m_staticPower);
	DDX_Control(pDX, IDC_CHECK_LOOP, m_checkLoop);
	DDX_Control(pDX, IDC_STATIC_MAJ_HEX, m_satic_maj_hex);
	DDX_Control(pDX, IDC_STATIC_MIN_HEX, m_static_min_hex);
	//  DDX_Text(pDX, IDC_EDIT_MAJ, m_editMAJ);
	//  DDV_MinMaxUInt(pDX, m_editMAJ, 0, 65535);
	//  DDX_Text(pDX, IDC_EDIT_MIN, m_editMIN);
	//  DDV_MinMaxUInt(pDX, m_editMIN, 0, 65535);
	DDX_Text(pDX, IDC_EDIT_STEP, m_editStep);
	DDV_MinMaxUInt(pDX, m_editStep, 0, 10);
	//  DDX_Text(pDX, IDC_EDIT_INV, m_editINV);
	//  DDV_MinMaxUInt(pDX, m_editINV, 800, 240000);
	DDX_Text(pDX, IDC_EDIT_MAC, m_editMAC);
	DDV_MaxChars(pDX, m_editMAC, 17);
	DDX_Text(pDX, IDC_EDIT_UUID, m_editUUID);
	DDV_MaxChars(pDX, m_editUUID, 47);
	DDX_Control(pDX, IDC_STATIC_WRITECNT, m_static_WriteCNT);
	DDX_Text(pDX, IDC_EDIT_MAJ, m_editMAJ);
	DDV_MinMaxUInt(pDX, m_editMAJ, 0, 65535);
	DDX_Text(pDX, IDC_EDIT_MIN, m_editMIN);
	DDV_MinMaxUInt(pDX, m_editMIN, 0, 65535);
	DDX_Text(pDX, IDC_EDIT_INV, m_editINV);
	DDV_MinMaxUInt(pDX, m_editINV, 0, 65535);
	DDX_Control(pDX, IDC_PROGRESS_PRO, m_processPRO);
}

BEGIN_MESSAGE_MAP(CBLETOOLDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON_OPEN_SENIAL, &CBLETOOLDlg::OnBnClickedButtonOpenSenial)
	ON_MESSAGE(WM_COMM_RXCHAR, OnComm)
//	ON_BN_CLICKED(IDC_CHECK1, &CBLETOOLDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON_READ, &CBLETOOLDlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CBLETOOLDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_READ, &CBLETOOLDlg::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_CHECK_LOOP, &CBLETOOLDlg::OnBnClickedCheckLoop)
//	ON_EN_CHANGE(IDC_EDIT_MAJ, &CBLETOOLDlg::OnEnChangeEditMaj)
//	ON_EN_CHANGE(IDC_EDIT_MIN, &CBLETOOLDlg::OnEnChangeEditMin)
ON_EN_CHANGE(IDC_EDIT_MAJ, &CBLETOOLDlg::OnEnChangeEditMaj)
ON_EN_CHANGE(IDC_EDIT_MIN, &CBLETOOLDlg::OnEnChangeEditMin)
ON_STN_CLICKED(IDC_STATIC_MAC, &CBLETOOLDlg::OnStnClickedStaticMac)
ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CBLETOOLDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CBLETOOLDlg message handlers

BOOL CBLETOOLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_verson_Font.CreatePointFont(180, "宋体");
	((CStatic*)GetDlgItem(IDC_STATIC_VERSION))->SetFont(&m_verson_Font);

	//m_verson_Font.CreatePointFont(180, "宋体");
	((CStatic*)GetDlgItem(IDC_STATIC_WRITECNT))->SetFont(&m_verson_Font);


	//m_SerialPort.Hkey2ComboBox(m_SetComPort);
	m_SerialPort.Hkey2ComboBox(m_SetComPort);

	((CButton*)GetDlgItem(IDC_BUTTON_OPEN_SENIAL))->SetWindowText("打开串口");

	CString str11;

	str11.Format("00 00 00 00 00 00");
	((CEdit*)GetDlgItem(IDC_EDIT_MAC))->SetWindowText(str11);

	str11.Format("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00");
	((CEdit*)GetDlgItem(IDC_EDIT_UUID))->SetWindowText(str11);




	m_processPRO.SetRange(0, 100);
	m_processPRO.SetStep(25);
	m_processPRO.SetPos(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBLETOOLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}



	


	//((CComboBox*)GetDlgItem(IDC_COMBO_SERIAL))->ShowWindow(1);
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBLETOOLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//mouse move 
void CBLETOOLDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnMouseMove(nFlags, point);

}

//open serial prot button
void CBLETOOLDlg::OnBnClickedButtonOpenSenial()
{
	CString str;
	char nCPort[100];
	UINT nport,nportNum,temp=0;

	switch (m_BottonStatus)
	{
	case 0:
		//close serial port :dispaly status
		m_SetComPort.EnableWindow(TRUE);
		((CButton*)GetDlgItem(IDC_BUTTON_OPEN_SENIAL))->SetWindowText("打开串口");
		//((CComboBox*)GetDlgItem(IDC_COMBO_SERIAL))->ShowWindow(1);
		m_BottonStatus = 1;
		if (m_SerialONOFF == 1)
		{
			m_SerialPort.ClosePort();
			m_SerialONOFF = 0;
			SetDlgItemText(IDC_STATIC_SERIAL_INFO, "关闭串口");
			KillTimer(1);
			
			m_msCount = 0;
		}
		break;
	case 1:
		//open serial port :display status
		m_BottonStatus = 0;
		((CButton*)GetDlgItem(IDC_BUTTON_OPEN_SENIAL))->SetWindowText("关闭串口");
		if (m_SerialONOFF == 0)
		{
			/*get computer serial port*/
			m_SetComPort.GetLBText(m_SetComPort.GetCurSel(), str);

			strcpy(nCPort, str);
			for (int i = 0;i < 100;i++)
			{
				temp = atoi(&nCPort[3]);
				if (i==temp)
				{
					nport = i;
				}
			}
			//change serial port :0 1 2 3 4......
			str = "打开  " + str + " 115200 N 8 1";
			SetDlgItemText(IDC_STATIC_SERIAL_INFO, str);
			if (m_SerialPort.InitPort(this->GetSafeHwnd(), nport, 115200, 'N', 8, 0, EV_RXFLAG | EV_RXCHAR, 512))
			{
				m_SerialPort.StartMonitoring();
				
				//on: true  off:false
				m_SerialONOFF = 1;
				SetTimer(1, 10, NULL);
				m_SetComPort.EnableWindow(FALSE);
				m_msCount = 0;

				m_enableRead = TRUE;
				m_enableReadTx = TRUE;
				//m_enableSend = TRUE;
				//m_enableSend_RX = TRUE;
			}
			else
			{
				MessageBox("串口被占用");
				KillTimer(1);
				m_msCount = 0;
			}
		}
		break;
	default:
		break;
	}

}

LRESULT CBLETOOLDlg::OnComm(WPARAM ch, LPARAM port)
{
	CString str,str1;
	int temp0 = 0;


	Rx_Buffer[Rx_Buffer_Len] = ch;
	Rx_Buffer_Len++;



	if ((Rx_Buffer[Rx_Buffer_Len - 1] == 0x0a) && (Rx_Buffer[Rx_Buffer_Len - 2] == 0x0d) && (Rx_Buffer_Len >= 2))
	{
		str.Format("%s", Rx_Buffer);
		((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
		((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(str);
		((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);


		//m_sendMAJ = FALSE;
		if ((m_enableSend_RX == TRUE)&&(m_enableSend=TRUE))
		{
			switch (m_sendStatus)
			{
			case 1:
				if ((Rx_Buffer[0] == 'e') && (Rx_Buffer[1] == 'x') && (Rx_Buffer[2] == 'e') && (Rx_Buffer[3] == 'c') && (Rx_Buffer[4] == 'u') && (Rx_Buffer[5] == 't'))
				{
					m_enableSend_RX = FALSE;
					m_sendStatus = 2;
					m_processPRO.SetPos(25);
				}

				break;
			case 2:
				if ((Rx_Buffer[0] == 'e') && (Rx_Buffer[1] == 'x') && (Rx_Buffer[2] == 'e') && (Rx_Buffer[3] == 'c') && (Rx_Buffer[4] == 'u') && (Rx_Buffer[5] == 't'))
				{
					m_enableSend_RX = FALSE;
					m_sendStatus = 3;
					m_processPRO.SetPos(50);
				}

				break;
			case 3:
				if ((Rx_Buffer[0] == 'e') && (Rx_Buffer[1] == 'x') && (Rx_Buffer[2] == 'e') && (Rx_Buffer[3] == 'c') && (Rx_Buffer[4] == 'u') && (Rx_Buffer[5] == 't'))
				{
					m_enableSend_RX = FALSE;
					m_sendStatus = 4;
					m_processPRO.SetPos(75);
				}
			
				break;
			case 4:
				if ((Rx_Buffer[0] == 'e') && (Rx_Buffer[1] == 'x') && (Rx_Buffer[2] == 'e') && (Rx_Buffer[3] == 'c') && (Rx_Buffer[4] == 'u') && (Rx_Buffer[5] == 't'))
				{
					m_processPRO.SetPos(100);
					//m_enableSend_RX = FALSE;
					m_sendStatus = 0;
					m_enableSend = FALSE;
					m_enableSend_RX = FALSE;

					m_enableRead = TRUE;
					m_enableReadTx = TRUE;

					m_writeCnt++;
					//((CStatic*)GetDlgItem(IDC_STATIC_WRITECNT))->SetWindowText()
						str1.Format("%06d", m_writeCnt);
					((CStatic*)GetDlgItem(IDC_STATIC_WRITECNT))->SetWindowText(str1);

					KillTimer(2);
					SetTimer(1, 10, NULL);
				}

				break;
			default:
				break;
			}
		}




		if ((m_enableRead == TRUE) && (m_enableReadTx == FALSE))
		{
			if ((Rx_Buffer[21] == 'B') && (Rx_Buffer[22] == 'L') && (Rx_Buffer[23] == 'E'))
			{
				str1.Format("%s", Rx_Buffer);
				((CStatic*)GetDlgItem(IDC_STATIC_VERSION))->SetWindowText(str1);

				if ((Rx_Buffer[30] == 'e') && (Rx_Buffer[31] == 'r') && (Rx_Buffer[32] == 'r'))
				{
					((CButton*)GetDlgItem(IDC_BUTTON_READ))->EnableWindow(FALSE);
					((CButton*)GetDlgItem(IDC_BUTTON_SEND))->EnableWindow(FALSE);
					//m_enableRead = FALSE;
					//m_enableReadTx = FALSE;
					//m_msCount = 0;
				}
				else
				{
					((CButton*)GetDlgItem(IDC_BUTTON_READ))->EnableWindow(TRUE);
					((CButton*)GetDlgItem(IDC_BUTTON_SEND))->EnableWindow(TRUE);
					//m_enableRead = TRUE;
					//m_enableRead = TRUE;
					//m_enableReadTx = TRUE;
					//m_msCount = 0;
				}
			}
			else
			{



				memset(rxdata, 0, 72);
				if ((Rx_Buffer[0] == 'm') && (Rx_Buffer[1] == 'a') && (Rx_Buffer[2] == 'j') && (Rx_Buffer[3] == 'o') && (Rx_Buffer[4] == 'r'))
				{
					for (temp0 = 0;temp0 < 5;temp0++)
					{
						rxdata[temp0] = Rx_Buffer[6 + temp0];
					}
					str1.Format("%s", rxdata);
					((CStatic*)GetDlgItem(IDC_STATIC_MAJ))->SetWindowText(str1);

					for (temp0 = 0;temp0 < 5;temp0++)
					{
						rxdata[temp0] = Rx_Buffer[19 + temp0];
					}
					str1.Format("%s", rxdata);
					((CStatic*)GetDlgItem(IDC_STATIC_MIN))->SetWindowText(str1);

					for (temp0 = 0;temp0 < 5;temp0++)
					{
						rxdata[temp0] = Rx_Buffer[32 + temp0];
					}
					str1.Format("%s", rxdata);
					((CStatic*)GetDlgItem(IDC_STATIC_POWER))->SetWindowText(str1);
				}

				//uuid
				if ((Rx_Buffer[38] == 'u') && (Rx_Buffer[39] == 'u') && (Rx_Buffer[40] == 'i') && (Rx_Buffer[41] == 'd'))
				{
					for (temp0 = 0;temp0 < 70;temp0++)
					{
						rxdata[temp0] = Rx_Buffer[44 + temp0];
					}
					str1.Format("%s", rxdata);
					((CStatic*)GetDlgItem(IDC_STATIC_UUID))->SetWindowText(str1);
				}

				if ((Rx_Buffer[92] == 'i') && (Rx_Buffer[93] == 'n') && (Rx_Buffer[94] == 't') && (Rx_Buffer[95] == 'e'))
				{
					memset(rxdata, 0, 72);
					for (temp0 = 0;temp0 < 9;temp0++)
					{
						rxdata[temp0] = Rx_Buffer[102 + temp0];
					}
					str1.Format("%s", rxdata);
					((CStatic*)GetDlgItem(IDC_STATIC_INV))->SetWindowText(str1);
					//m_enableRead = FALSE;
					m_msCount = 0;

					if ((m_loopSend == TRUE)||(m_sendone==TRUE))
					{

						m_sendone = FALSE;
						KillTimer(1);
						SetTimer(2, 100, NULL);
						m_enableRead = FALSE;
						m_enableReadTx = FALSE;


						m_enableSend = TRUE;


						m_enableSend_RX = FALSE;
						m_sendStatus = 1;


						m_msCount = 0;

					}
					else
					{
						m_enableRead = TRUE;
						m_enableReadTx = TRUE;
					}

				}

			}
		}

		memset(Rx_Buffer, 0, 200);
		Rx_Buffer_Len = 0;
	
	}

	return 0;
}


void CBLETOOLDlg::OnBnClickedButtonSend()
{
	//KillTimer(1);
	//SetTimer(2, 100, NULL);
	//m_enableRead = FALSE;
	//m_enableReadTx = FALSE;
	if (m_SerialONOFF ==0)
	{
		AfxMessageBox("串口没有打开！！！！");
		m_msCount = 0;

	}
	else
	{
		if (m_SerialONOFF == 1)
		{
			m_sendone = TRUE;
			/*
			if (m_enableSend == FALSE)
			{
				m_sendone
				m_enableSend = TRUE;
				KillTimer(1);
				SetTimer(2, 100, NULL);
				m_enableRead = FALSE;
				m_enableReadTx = FALSE;

				m_enableSend_RX = FALSE;
				m_sendStatus = 1;


				m_msCount = 0;
				//SetTimer()
			}
			*/
		}
	}



}



void CBLETOOLDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CString str, strTime, strEDIT;
	char tempChar[50];
	UINT LineNum = 0;
	CDialogEx::OnTimer(nIDEvent);
	//CTime time = CTime::GetCurrentTime();
	//strTime = time.Format("%H:%M:%S:%MS");
	//SYSTEMTIME st;
	//GetLocalTime(&st);
	//strTime.Format("%02d:%02d:%02d:%03d", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	UINT tempMAC1 = 0, tempMAC2 = 0, tempMAC3 = 0, tempMAC4 = 0, tempMAC5 = 0, tempMAC6 = 0, i = 0;
	CString str11;

	LineNum = m_txrxmsg.GetLineCount();
	if (LineNum>=500)
	{
		m_txrxmsg.SetSel(0, -1);
		m_txrxmsg.Clear();
	}


	//loop tx data

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_LOOP))->GetCheck())
	{
		m_loopSend = TRUE;

	}

	if (BST_UNCHECKED == ((CButton*)GetDlgItem(IDC_CHECK_LOOP))->GetCheck())
	{
		m_loopSend = FALSE;
	}
	switch (nIDEvent)
	{
	case 1:
		//LOOP read data

		/*
		m_msCount++;
		if ((m_msCount >= 200) && (m_enableRead == FALSE) && (m_SerialONOFF = 1))
		{
			m_enableRead = TRUE;
			m_enableReadTx = TRUE;
			m_msCount = 0;
			//if (m_enableSend == TRUE)
			//{
			//	KillTimer(1);
			//}

		}
		*/

		if (m_enableRead == TRUE)
		{
			if (m_enableReadTx == TRUE)
			{
				//mmp
				str = "GETMMP \n";
				//strTime += "--TX:";
				//str = strTime + "----tx----:" + strEDIT + "\r\n";
				//send data

				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(str);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
				
				m_SerialPort.WriteToPort(str);
				m_enableReadTx = FALSE;
			}
		}
		break;
	case 2:



		/*
		//MAC
		if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_MAC))->GetCheck())
		{
			m_sendMAC = TRUE;
		}

		if (BST_UNCHECKED == ((CButton*)GetDlgItem(IDC_CHECK_MAC))->GetCheck())
		{
			m_sendMAC = FALSE;
		}

		//MAJ
		if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_MAJ))->GetCheck())
		{
			m_sendMAJ = TRUE;
		}

		if (BST_UNCHECKED == ((CButton*)GetDlgItem(IDC_CHECK_MAJ))->GetCheck())
		{
			m_sendMAJ = FALSE;
		}

		//MIN
		if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_MIN))->GetCheck())
		{
			m_sendMin = TRUE;
		}

		if (BST_UNCHECKED == ((CButton*)GetDlgItem(IDC_CHECK_MIN))->GetCheck())
		{
			m_sendMin = FALSE;
		}

		//INV
		if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_INV))->GetCheck())
		{
			m_sendINV = TRUE;
		}

		if (BST_UNCHECKED == ((CButton*)GetDlgItem(IDC_CHECK_INV))->GetCheck())
		{
			m_sendINV = FALSE;
		}

		//UUID
		if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_UUID))->GetCheck())
		{
			m_sendUUID = TRUE;
		}

		if (BST_UNCHECKED == ((CButton*)GetDlgItem(IDC_CHECK_UUID))->GetCheck())
		{
			m_sendUUID = FALSE;
		}

		if ((m_enableSend == TRUE))//&&(m_msCount))
		{
		*/
		/*
		//m_msCount = 0;
		m_msCount++;
		if (m_msCount >= 300)
		{
			m_msCount = 0;
			AfxMessageBox("发送失败，请重新烧录");
			m_enableSend = FALSE;
		}

		if (m_loopSend == TRUE)
		{
		}
		else
		{
			//m_enableSend = FALSE;
		}
		*/
		/*
		if (m_sendMAC == TRUE)
		{
			m_sendMAC = FALSE;
			((CEdit*)GetDlgItem(IDC_EDIT_MAC))->GetWindowText(strEDIT);
			strEDIT = "SETMAC " + strEDIT + " \n";
			//strTime += "--TX:";
			str = strTime + "----tx----:" + strEDIT + "\r\n";
			//send data

			((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
			((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(str);
			((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
			//((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetWindowText(str);

			((CEdit*)GetDlgItem(IDC_EDIT_MAC))->GetWindowText(strEDIT);
			//DOUBLE temp0 = 0;
			strcpy(tempChar, strEDIT);


			tempMAC1 = (HexChar(tempChar[0]) << 4) | HexChar(tempChar[1]);
			tempMAC2 = (HexChar(tempChar[3]) << 4) | HexChar(tempChar[4]);
			tempMAC3 = (HexChar(tempChar[6]) << 4) | HexChar(tempChar[7]);

			tempMAC4 = (HexChar(tempChar[9]) << 4) | HexChar(tempChar[10]);
			tempMAC5 = (HexChar(tempChar[12]) << 4) | HexChar(tempChar[13]);
			tempMAC6 = (HexChar(tempChar[15]) << 4) | HexChar(tempChar[16]);

			UpdateData(TRUE);
			m_SerialPort.WriteToPort(strEDIT);

			for (int i = 0;i < m_editStep;i++)
			{
				tempMAC6++;
				if ((tempMAC6 & 0x000000FF) == 0x00)
				{
					tempMAC5++;
					if ((tempMAC5 & 0x000000FF) == 0x00)
					{
						tempMAC4++;
						if ((tempMAC4 & 0x000000FF) == 0x00)
						{
							tempMAC3++;
							if ((tempMAC3 & 0x000000FF) == 0x00)
							{
								tempMAC2++;
								if ((tempMAC2 & 0x000000FF) == 0x00)
								{
									tempMAC1++;
									if ((tempMAC1 & 0x000000FF) == 0x00)
									{
										tempMAC1 = 0;
										tempMAC2 = 0;
										tempMAC3 = 0;
										tempMAC4 = 0;
										tempMAC5 = 0;
										tempMAC6 = 0;
									}
								}
							}
						}


					}
				}
			}

			tempMAC6 = tempMAC6 & 0x000000FF;
			tempMAC5 = tempMAC5 & 0x000000FF;
			tempMAC4 = tempMAC4 & 0x000000FF;
			tempMAC3 = tempMAC3 & 0x000000FF;
			tempMAC2 = tempMAC2 & 0x000000FF;
			tempMAC1 = tempMAC1 & 0x000000FF;
			UpdateData(FALSE);



			str11.Format("%02X %02X %02X %02X %02X %02X", tempMAC1, tempMAC2, tempMAC3, tempMAC4, tempMAC5, tempMAC6);
			((CEdit*)GetDlgItem(IDC_EDIT_MAC))->SetWindowText(str11);

		}
		*/

		//m_msCount++;
		if ((m_enableSend == TRUE) && (m_enableSend_RX == FALSE))//&&(m_msCount>=8))  //&&(m_msCount))
		{
			m_msCount = 0;

			switch (m_sendStatus)
			{
			case 1:
				((CEdit*)GetDlgItem(IDC_EDIT_MAJ))->GetWindowText(strEDIT);
				strEDIT = "SETMAJOR " + strEDIT + "\n";
				m_enableSend_RX = TRUE;
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(strEDIT);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
				//UpdateData(TRUE);
				m_SerialPort.WriteToPort(strEDIT);
				break;
			case 2:
				((CEdit*)GetDlgItem(IDC_EDIT_MIN))->GetWindowText(strEDIT);
				strEDIT = "SETMINOR " + strEDIT + "\n";
				m_enableSend_RX = TRUE;
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(strEDIT);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
				//UpdateData(TRUE);
				m_SerialPort.WriteToPort(strEDIT);
				break;
			case 3:
				((CEdit*)GetDlgItem(IDC_EDIT_UUID))->GetWindowText(strEDIT);
				strEDIT = "SETUUID " + strEDIT + "\n";
				m_enableSend_RX = TRUE;
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(strEDIT);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
				//UpdateData(TRUE);
				m_SerialPort.WriteToPort(strEDIT);
				break;
			case 4:
				((CEdit*)GetDlgItem(IDC_EDIT_INV))->GetWindowText(strEDIT);
				strEDIT = "SETINTERV " + strEDIT + " \n";
				m_enableSend_RX = TRUE;
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(strEDIT);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
				//UpdateData(TRUE);
				m_SerialPort.WriteToPort(strEDIT);
				break;
			default:
				break;
			}

		}
		break;
	default:
		break;
	}
}


			/*

			if((m_sendMAJ == TRUE)&&(m_enableSend_RX==FALSE))
			{
				//m_sendMAJ = FALSE;
				((CEdit*)GetDlgItem(IDC_EDIT_MAJ))->GetWindowText(strEDIT);
				strEDIT = "SETMAJOR " + strEDIT + " \n";

				str = strTime + "----tx----:" + strEDIT + "\r\n";
				//send data

				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(str);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
				//((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetWindowText(str);
				UpdateData(TRUE);
				m_SerialPort.WriteToPort(strEDIT);
				//need ack data .
				m_enableSend_RX = TRUE;
				m_msCount = 0;


			}
			if ((m_sendMin == TRUE) && (m_enableSend_RX == FALSE))
			{
				m_sendMin = FALSE;
				((CEdit*)GetDlgItem(IDC_EDIT_MIN))->GetWindowText(strEDIT);
				strEDIT = "SETMINOR " + strEDIT + " \n";
				//strTime += "--TX:";
				str = strTime + "----tx----:" + strEDIT + "\r\n";
				//send data

				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(str);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
				//((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetWindowText(str);
				UpdateData(TRUE);
				m_SerialPort.WriteToPort(strEDIT);
				m_enableSend_RX = TRUE;
				m_msCount = 0;
			}
			if ((m_sendINV == TRUE) && (m_enableSend_RX == FALSE))
			{
				m_sendINV = FALSE;
				((CEdit*)GetDlgItem(IDC_EDIT_INV))->GetWindowText(strEDIT);
				strEDIT = "SETINTERV " + strEDIT + " \n";
				//strTime += "--TX:";
				str = strTime + "----tx----:" + strEDIT + "\r\n";
				//send data

				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(str);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
				//((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetWindowText(str);
				UpdateData(TRUE);
				m_SerialPort.WriteToPort(strEDIT);
				m_enableSend_RX = TRUE;
				m_msCount = 0;
			}
			if ((m_sendUUID == TRUE)&& (m_enableSend_RX == FALSE))
			{
				m_sendUUID = FALSE;
				((CEdit*)GetDlgItem(IDC_EDIT_UUID))->GetWindowText(strEDIT);
				strEDIT = "SETUUID " + strEDIT + " \n";
				//strTime += "--TX:";
				str = strTime + "----tx----:" + strEDIT + "\r\n";
				//send data

				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetSel(-1, -1);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->ReplaceSel(str);
				((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->LineScroll(((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->GetLineCount(), 0);
				//((CEdit*)GetDlgItem(IDC_EDIT_TXRXMSG))->SetWindowText(str);
				UpdateData(TRUE);
				m_SerialPort.WriteToPort(strEDIT);
				m_enableSend_RX = TRUE;
				m_msCount = 0;
			}
		}
		break;
	default:
		break;
	}
	*/




	
//}

void CBLETOOLDlg::OnBnClickedButtonRead()
{
	CString str;
	// TODO: Add your control notification handler code here

	if (m_SerialONOFF == 0)
	{
		AfxMessageBox("串口没有打开！！！！");
	}
	else
	{
		m_enableRead = TRUE;
		if (m_enableReadTx == FALSE)
		{
			m_enableReadTx = TRUE;
		}
	}
	
		
}


void CBLETOOLDlg::OnBnClickedCheckLoop()
{
	if (m_checkLoop.GetCheck()==TRUE)
	{
		//SetTimer(1,)
	}
}

void CBLETOOLDlg::OnEnChangeEditMaj()
{
	UINT temp0;
	CString str, str1;
	UpdateData(TRUE);
	str1.Format("0x %04X", m_editMAJ);
	((CStatic*)GetDlgItem(IDC_STATIC_MAJ_HEX))->SetWindowText(str1);
	UpdateData(FALSE);
}


void CBLETOOLDlg::OnEnChangeEditMin()
{
	UINT temp0;
	CString str, str1;
	UpdateData(TRUE);
	str1.Format("0x %04X", m_editMIN);
	((CStatic*)GetDlgItem(IDC_STATIC_MIN_HEX))->SetWindowText(str1);
	UpdateData(FALSE);
}

char CBLETOOLDlg::HexChar(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return ch - 0x30;
	else if ((ch >= 'A') && (ch <= 'F'))
		return ch - 'A' + 10;
	else if ((ch >= 'a') && (ch <= 'f'))
		return ch - 'a' + 10;
	else
		return 0x10;
}
int CBLETOOLDlg::Str2Hex(CString str, char * pChar)
{
	int t, t1;
	int rlen = 0, len = str.GetLength();
	//data.SetSize(len/2);
	for (int i = 0;i < len;)
	{
		char l, h = str[i];
		if (h == ' ')
		{
			i++;
			continue;
		}
		i++;
		if (i >= len)
			break;
		l = str[i];
		t = HexChar(h);
		t1 = HexChar(l);
		if ((t == 16) || (t1 == 16))
			break;
		else
			t = t * 16 + t1;
		i++;
		pChar[rlen] = (char)t;
		rlen++;
	}
	return rlen;
}


int CBLETOOLDlg::CharHex(char)
{
	//char ASCIIarray[16] = ('0','1','2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f');
//	if ((aHex >= 0) && (aHex <= 9))        aHex += 0x30;    else if ((aHex >= 10) && (aHex <= 15))//A-F        aHex += 0x37;    else aHex = 0xff;    return Hex;
	return 0;
}


void CBLETOOLDlg::OnStnClickedStaticMac()
{
	// TODO: Add your control notification handler code here
}


void CBLETOOLDlg::OnBnClickedButtonClear()
{
	CString str;
	str.Format("0000000");
	((CStatic*)GetDlgItem(IDC_STATIC_WRITECNT))->SetWindowText(str);
	m_writeCnt = 0;
}
