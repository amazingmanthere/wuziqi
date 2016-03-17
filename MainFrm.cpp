// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "inter.h"
#include "MainFrm.h"
//#include "interView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
//	ID_TIME,
	ID_SEPARATOR,
	ID_TIMER,
	ID_PROGRESS,// status line indicator
//	ID_INDICATOR_CAPS,
//	ID_INDICATOR_NUM,
//	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
/*	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}*/

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
//	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//	EnableDocking(CBRS_ALIGN_ANY);
//	DockControlBar(&m_wndToolBar);

	SetWindowLong(m_hWnd,GWL_STYLE,WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU);//固定窗口，使窗口大小不能被拖动
	CRect rect (0, 0, 665, 535);
    rect.bottom=rect.bottom+::GetSystemMetrics(SM_CYMENU)*2
		+::GetSystemMetrics(SM_CYEDGE)*2+::GetSystemMetrics(SM_CYCAPTION);//创建自己定义的客户区的窗口
    rect.right=rect.right+::GetSystemMetrics(SM_CXEDGE)*2;
    CalcWindowRect(&rect);
	MoveWindow(0,0,rect.right,rect.bottom);

	CClientDC dc(this);

	CTime t = CTime::GetCurrentTime();
	CString s=t.Format( "%H:%M:%S");
	CSize cz=dc.GetTextExtent(s);
	m_wndStatusBar.SetPaneInfo(1,123,SBPS_NORMAL,cz.cx);
    m_wndStatusBar.SetPaneText(1,s);
//	ReleaseDC(dc);
//	CRect rect1;
//	GetActiveView()->GetClientRect(rect1);
	SetTimer(1,1000,NULL);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

//	cs.style&=~WS_EX_CLIENTEDGE;
 //CRect rect;
 //rect.SetRect(0,0,535,535);
 //AdjustWindowRectEx(&rect, cs.style, TRUE,cs.dwExStyle);
 //cs.cx = rect.right - rect.left;
// cs.cy = rect.bottom - rect.top+10;
	cs.cx=800;
	cs.cy=800;
//	CRect rect1;
//	CInterView* pview=(CInterView*)GetActiveView();
//	GetActiveView()->GetClientRect(rect1);
//	int nwidth=800-rect1.Width();
//	int nheight=800-rect1.Height();
//	cs.cx=535+nwidth;
//	cs.cy=535+nheight;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTime t = CTime::GetCurrentTime();
	CString s = t.Format( "%H:%M:%S");
	CClientDC dc(this);
	CSize sz=dc.GetTextExtent(s);
	m_wndStatusBar.SetPaneInfo(1,123,SBPS_NORMAL,sz.cx);
    m_wndStatusBar.SetPaneText(1,s);
	CFrameWnd::OnTimer(nIDEvent);
	//static int i=10;
	m_progress.SetStep(10);
	m_progress.StepIt();
//	i+=10;
}

void CMainFrame::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRect rect;
	m_wndStatusBar.GetItemRect(2,rect);
	if(!m_progress.m_hWnd)
	{
		m_progress.Create(WS_CHILD|WS_VISIBLE|PBS_SMOOTH,rect,&m_wndStatusBar,123);
	    m_progress.SetPos(10);
	}
	else
		m_progress.MoveWindow(rect);
	// Do not call CFrameWnd::OnPaint() for painting messages
}
