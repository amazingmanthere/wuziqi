// PreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "inter.h"
#include "PreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreDlg dialog


CPreDlg::CPreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreDlg)
	m_edit1 = L"zuckchen";
	m_edit2 = L"123456";
	m_radio = -1;
	//}}AFX_DATA_INIT
	dlglarge.SetRect(0,0,0,0);
    dlgsmall.SetRect(0,0,0,0);
	brush.CreateSolidBrush(RGB(192,226,250));
	hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON1));
//	brush.CreateSolidBrush(RGB(0,0,0));
}


void CPreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreDlg)
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreDlg, CDialog)
	//{{AFX_MSG_MAP(CPreDlg)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreDlg message handlers

void CPreDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	j=m_radio;
	if(m_edit1== L"")
		MessageBox(L"请输入账号");
	else
	{
		if(m_edit2=="")
		MessageBox(L"请输入密码");
//	    else
//		{
		if(m_edit2!=L""&&(m_edit1!= L"zuckchen"||m_edit2!= L"123456"))
	         MessageBox(L"输入信息有误");
	        if(m_edit1== L"zuckchen"&&m_edit2== L"123456")
			{
	            CDialog::OnOK();
			}
		}
}

BOOL CPreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(dlglarge.IsRectNull())
	{
		GetWindowRect(dlglarge);
		GetDlgItem(IDC_SEPARATOR)->GetWindowRect(Separator);
		dlgsmall.left=dlglarge.left;
		dlgsmall.top=dlglarge.top;
		dlgsmall.right=dlglarge.right;
		dlgsmall.bottom=Separator.bottom;
	}
	SetWindowPos(NULL,0,0,dlgsmall.Width(),dlgsmall.Height(),SWP_NOMOVE|SWP_NOZORDER);
//	HICON hIcon=AfxGetApp()->LoadIcon(IDI_ICON1);
	SendMessage(WM_SETICON,ICON_SMALL,(LPARAM)hIcon);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPreDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_BUTTON2,str);
	if(str== L"设置>>")
	{
		SetDlgItemText(IDC_BUTTON2, L"设置<<");
	    SetWindowPos(NULL,0,0,dlglarge.Width(),dlglarge.Height(),SWP_NOMOVE|SWP_NOZORDER);
	}
	else
	{
		SetDlgItemText(IDC_BUTTON2, L"设置>>");
		SetWindowPos(NULL,0,0,dlgsmall.Width(),dlgsmall.Height(),SWP_NOMOVE|SWP_NOZORDER);
	}
}

void CPreDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	int   nStart,   nEnd; 

     ((CEdit*)GetDlgItem(IDC_EDIT1))->GetSel(nStart,nEnd); 

 //    if(nStart   ==   nEnd) 
//	 { 
     ((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(nStart+9,nStart+9); 
//	 }
	GetDlgItem(IDC_EDIT1)->SetFocus();
//	((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(9);
	CDC compatible;
	if(compatible.m_hDC==NULL)
	compatible.CreateCompatibleDC(&dc);
    CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_DLGBG);
	BITMAP bit;
	bitmap.GetBitmap(&bit);
	compatible.SelectObject(&bitmap);
	dc.StretchBlt(0,0,dlgsmall.Width(),dlgsmall.Height()-37,&compatible,0,0,bit.bmWidth,bit.bmHeight,SRCCOPY);
//	dc.StretchBlt(0,0,dlgsmall.Width(),Separator.top,&compatible,0,0,bit.bmWidth,bit.bmHeight,SRCCOPY);
//	dc.StretchBlt(0,0,bit.bmWidth,bit.bmHeight,&compatible,0,0,dlgsmall.Width(),dlgsmall.Height(),SRCCOPY);
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH CPreDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
//	CBrush brush(RGB(192,226,250));
//	pDC->SelectObject(&brush);
//	::SetDCBrushColor(pDC,RGB(192,226,250));
//	pDC->SetBkColor(RGB(210,230,211));//
 //   HBRUSH hr=(HBRUSH)GetStockObject(BLACK_BRUSH);
//	CBrush brush;
//	brush.CreateSolidBrush(RGB(192,226,250));
//	if(nCtlColor==IDD_DIALOG1)
/*	if(pWnd->GetDlgCtrlID()==IDC_SEPARATOR)
	{
		//pDC->SetBkMode(OPAQUE);
		pDC->SetBkColor(RGB(0,0,255));
		pDC->SetBkMode(TRANSPARENT);
	}*/
	if(CTLCOLOR_EDIT==nCtlColor)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(RGB(255,255,255));
	}
	if(CTLCOLOR_STATIC==nCtlColor)
	{
		pDC->SetTextColor(RGB(255,0,255));
		pDC->SetBkColor(RGB(192,226,250));
	}
//	if(pWnd->GetDlgCtrlID()==IDC_SEPARATOR)
	return brush;
	// TODO: Return a different brush if the default is not desired
//	return hbr;
}
int CPreDlg::j=0;
