// interView.cpp : implementation of the CInterView class
//

#include "stdafx.h"
#include "inter.h"
#include "PreDlg.h"
#include "interDoc.h"
#include "interView.h"
#include "Generic.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInterView

IMPLEMENT_DYNCREATE(CInterView, CView)

BEGIN_MESSAGE_MAP(CInterView, CView)
	//{{AFX_MSG_MAP(CInterView)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(ID_BUTTON1, OnMybut1)
    ON_BN_CLICKED(ID_BUTTON2, OnMybut2)
    ON_BN_CLICKED(ID_BUTTON3, OnMybut3)
	ON_BN_CLICKED(ID_BUTTON4, OnMybut4)
	ON_BN_CLICKED(ID_BUTTON5, OnMybut5)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInterView construction/destruction

CInterView::CInterView()
{
	// TODO: add construction code here
//	flag=1;
	begin=0;
    for(int i=0;i<14;i++)
	{
		for(int j=0;j<14;j++)
		{
			Rect[i][j].SetRect(20+35*j,20+35*i,20+35*(j+1),20+35*(i+1));
			qizi[i][j]=0;
		}
	}
}

CInterView::~CInterView()
{
	for(int i=0;i<4;i++)
	{
		if(p_MyBut[i])
			delete p_MyBut[i];
	}
}

BOOL CInterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
//	cs.cx=535;
//	cs.cy=535;
//	MoveWindow
	

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CInterView drawing

void CInterView::OnDraw(CDC* pDC)
{
	CInterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_BG);
	CDC compatible;
	compatible.CreateCompatibleDC(pDC);
	compatible.SelectObject(&bitmap);
	BITMAP bit;
	bitmap.GetBitmap(&bit);
	pDC->BitBlt(0,0,535,535,&compatible,0,0,SRCCOPY);
	for(int i=0;i<15;i++)
	{
		pDC->MoveTo(20+35*i,20);
		pDC->LineTo(20+35*i,510);
	}
	for(int j=0;j<15;j++)
	{
		pDC->MoveTo(20,20+35*j);
	    pDC->LineTo(510,20+35*j);
	}
	for(int i=0;i<14;i++)
	{
		for(int j=0;j<14;j++)
		{
			Rect[i][j].SetRect(20+35*j,20+35*i,20+35*(j+1),20+35*(i+1));
		}
	}
	CBrush *brush;
	int count=Ptr.GetSize();
	for(int i=0;i<count;i++)
	{
		int c=((CGeneric*)Ptr.GetAt(i))->t;
		brush=new CBrush(RGB(255*c,255*c,255*c));
//		brush.CreateSolidBrush(RGB(255*c,255*c,255*c));
//		CBrush *old=pDC->SelectObject(&brush);
//		CPen pen(PS_SOLID,1,RGB(255*c,255*c,255*c));
//		pDC->SelectObject(&pen);
		pDC->SelectObject(brush);
		pDC->Ellipse(((CGeneric*)Ptr.GetAt(i))->rectangle);
		int m=((CGeneric*)Ptr.GetAt(i))->a;
		int n=((CGeneric*)Ptr.GetAt(i))->b;
		qizi[m][n]=((CGeneric*)Ptr.GetAt(i))->array[m][n];
		delete brush;
//		pDC->SelectObject(old);
	}

}

/////////////////////////////////////////////////////////////////////////////
// CInterView printing

BOOL CInterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CInterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CInterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CInterView diagnostics

#ifdef _DEBUG
void CInterView::AssertValid() const
{
	CView::AssertValid();
}

void CInterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CInterDoc* CInterView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInterDoc)));
	return (CInterDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInterView message handlers

//DEL int CInterView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
//DEL {
//DEL 	if (CView::OnCreate(lpCreateStruct) == -1)
//DEL 		return -1;
//DEL 	
//DEL 	// TODO: Add your specialized creation code here
//DEL 	CClientDC dc(this);
//DEL 	brush.CreateSolidBrush(RGB(0,0,0));
//DEL 	dc.SelectObject(&brush);
//DEL 	SetClassLong(m_hWnd,GCL_HBRBACKGROUND,(LONG)GetStockObject(DC_BRUSH));
//DEL 	return 0;
//DEL }

BOOL CInterView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
//	brush.CreateSolidBrush(RGB(0,0,0));
//	pDC->SelectObject(&brush);
    CRect rect;
	GetClientRect(rect);
	CPreDlg dlg;
	if(dlg.j==-1)
	{
		return CView::OnEraseBkgnd(pDC);
	//	return true;
	}
	else
	{
		if(dlg.j==0)
	    pDC->FillSolidRect(rect,RGB(255,0,0));
	    if(dlg.j==1)
	    pDC->FillSolidRect(rect,RGB(0,255,0));
	    if(dlg.j==2)
	    pDC->FillSolidRect(rect,RGB(0,0,255));
	    if(dlg.j==3)
	    pDC->FillSolidRect(rect,RGB(0,0,0));
		CBitmap bitmap;
	    bitmap.LoadBitmap(IDB_BITMAP_BG);
	    CDC compatible;
	    compatible.CreateCompatibleDC(pDC);
	    compatible.SelectObject(&bitmap);
	    BITMAP bit;
	    bitmap.GetBitmap(&bit);
	    pDC->BitBlt(0,0,535,535,&compatible,0,0,SRCCOPY);
		return true;
	}
	
	return true;
	
	
//	return CView::OnEraseBkgnd(pDC);
}

int CInterView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	//GetParent()->SetWindowPos(NULL,0,0,535,535,SWP_NOMOVE|SWP_NOZORDER);
	p_MyBut[0] =NewButton(ID_BUTTON1,CRect(550,50,650,70),0); 
	p_MyBut[1] =NewButton(ID_BUTTON2,CRect(550,120,650,140),0); 
	p_MyBut[2] =NewButton(ID_BUTTON4,CRect(550,190,650,210),0);
	p_MyBut[3] =NewButton(ID_BUTTON3,CRect(550,260,650,280),0); 
	p_MyBut[4] =NewButton(ID_BUTTON5,CRect(550,330,650,350),0); 
//	listbox=new CListBox();
//	listbox->Create(WS_CHILD|WS_VISIBLE|);
//	button.SetCursor(::LoadCursor(NULL,IDC_APPSTARTING));
//	button.ShowWindow(SW_NORMAL);
	SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(NULL,IDC_NO));
//    SetWindowLong(m_hWnd,GWL_STYLE,WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU);
	return 0;
}

void CInterView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
//	cx=535;
//	cy=535;
//	int i=cx;
//	int j=cy;
}

void CInterView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(begin==1)
	{
	static int k=0;
	int count=Ptr.GetSize();
	static int cm=0;
	if(count)
	{
		cm=((CGeneric*)Ptr.GetAt(count-1))->t;
	    if(cm)
		    cm=0;
	    else
		    cm=1;
	}
	k=cm;
	CClientDC dc(this);
	CBrush brush1;
	brush1.CreateSolidBrush(RGB(255*k,255*k,255*k));                      
	dc.SelectObject(&brush1);
//	brush.CreateSolidBrush(RGB(0,0,0));
//	CBrush *old=dc.SelectObject(&brush);
	for(int i=0;i<14;i++)
	{
		for(int j=0;j<14;j++)
	    if(Rect[i][j].PtInRect(point))
		{
			if(!qizi[i][j])
			{
				dc.Ellipse(Rect[i][j]);
			    qizi[i][j]=k+1;
				CGeneric *gene;
				gene=new CGeneric(Rect[i][j],k,i,j,qizi[i][j]);
				Ptr.Add(gene);
				
			//	k=++k%2;
			    if(heqi())
				{
					MessageBox(L"双方和棋");
					k=0;
					SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(NULL,IDC_NO));
					begin=2;
				}
				//if(judge(i,j)==5)
				if(judge1(i,j,qizi[i][j])>=5
					||judge2(i,j,qizi[i][j])>=5
					||judge3(i,j,qizi[i][j])>=5
					||judge4(i,j,qizi[i][j])>=5)
				{
				//	dc.SetTextColor(RGB(255,255,0));
				//	CFont font;
				//	font.CreatePointFont(300,"方正彩云简体");
					//dc.SelectObject(&font);
					switch(qizi[i][j])
					{
					case 1:
						MessageBox(L"黑棋胜");
					//	Ptr.RemoveAll();
						
				     	break;
				    case 2:
						MessageBox(L"白棋胜");
						//dc.TextOut(200,50,"白棋胜");
					//	Ptr.RemoveAll();
						//Invalidate();
					    break;
					}
				//	Array();
					k=0;
					cm=0;
				//	Ptr.RemoveAll();
					SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(NULL,IDC_NO));
					begin=2;
					
				//	Invalidate();
				}
			//	flag=1;
		        i=14;                                   //让循环终止条件成真，从而跳出双重循环
			    j=14;
			}
		}
	}
	}
//	dc.SelectObject(old);
	
//	DeleteObject(brush);
	//dc.SelectObject(old);
//	k=++k%2;
//	DeleteObject(brush);
		CView::OnLButtonDown(nFlags, point);
}

void CInterView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
}

int CInterView::judge1(int a,int b,int c)
{
	int flag=1;
	//判断竖直方向是否达到胜利条件
	for(int l=1;a+l<14;l++)
	{
		if(qizi[a+l][b]==c)
			flag++;
		else
			break;
	}
	for(int l=1;a-l>=0;l++)
	{
		if(qizi[a-l][b]==c)
			flag++;
		else
			break;
	}
	return flag;
}
int CInterView::judge2(int a,int b,int c)
{
	//判断水平方向是否达到胜利条件
	int flag=1;
	for(int l=1;b+l<14;l++)
	{
		if(qizi[a][b+l]==c)
			flag++;
		else
			break;
	}
	for(int l=1;b-l>=0;l++)
	{
		if(qizi[a][b-l]==c)
			flag++;
		else
			break;
	}
	return flag;
}
int CInterView::judge3(int a,int b,int c)
{
	//判断从左下至右上倾斜方向是否达到胜利条件
	int flag=1;
	for(int l=1;a-l>=0&&b+l<14;l++)
	{
		if(qizi[a-l][b+l]==c)
			flag++;
		else
			break;
	}
	for(int l=1;a+l<14&&b-l>=0;l++)
	{
		if(qizi[a+l][b-l]==c)
			flag++;
		else
			break;
	}
	return flag;
}
int CInterView::judge4(int a,int b,int c)
{
	//判断从左上至右下倾斜方向是否达到胜利条件
	int flag=1;
	for(int l=1;a+l<14&&b+l<14;l++)
	{
		if(qizi[a+l][b+l]==c)
			flag++;
		else
			break;
	}
	for(int l=1;a-l>=0&&b-l>=0;l++)
	{
		if(qizi[a-l][b-l]==c)
			flag++;
		else
			break;
	}
	return flag;
}

CButton* CInterView::NewButton(int nID, CRect rect, int nStyle)
{
	CString m_Caption;
	m_Caption.LoadString( nID ); //取按钮标题
    CButton *p_Button = new CButton();
	ASSERT_VALID(p_Button);   //检查指针是否有效
	//ASSERT(p_Button);       //检查指针是否为空
	p_Button->Create( m_Caption, WS_CHILD | WS_VISIBLE 
		| BS_PUSHBUTTON | nStyle, rect, this, nID ); //创建按钮
    return p_Button;

}

//游戏开始
void CInterView::OnMybut1()
{
	Array();
			//		k=0;
	Ptr.RemoveAll();
	Invalidate();
	SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(NULL,IDC_CROSS));
	begin=1;
}
//游戏继续
void CInterView::OnMybut2()
{
	if(begin!=2)
	{
		SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(NULL,IDC_CROSS));
	    begin=1;
	}
}
//游戏结束
void CInterView::OnMybut3()
{
	exit(0);
}
//游戏暂停
void CInterView::OnMybut4()
{
	if(begin!=2)
	{
		begin=0;
	    SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(NULL,IDC_NO));
	}
}
//悔棋
void CInterView::OnMybut5()
{
	if(begin!=2)
	{
		int count=Ptr.GetSize();
	    if(count)
		{
	    int m=((CGeneric*)Ptr.GetAt(count-1))->a;
	    int n=((CGeneric*)Ptr.GetAt(count-1))->b;
	    qizi[m][n]=0;
	    Ptr.RemoveAt(count-1);
	    Invalidate();
		}
	}
}


void CInterView::Array()
{
/*	int peter[14][14];
	for(int i=0;i<14;i++)
	{
		for(int j=0;j<14;j++)
		{
			//Rect[i][j].SetRect(20+35*j,20+35*i,20+35*(j+1),20+35*(i+1));
			//qizi[i][j]=0;
			peter[i][j]=0;
		}
	}
	return peter[14][14];*/
	int count=Ptr.GetSize();
	for(int i=0;i<count;i++)
	{
		int m=((CGeneric*)Ptr.GetAt(i))->a;
		int n=((CGeneric*)Ptr.GetAt(i))->b;
		qizi[m][n]=0;

	}
}

bool CInterView::heqi()
{
	for(int i=0;i<14;i++)
	{
		for(int j=0;j<14;j++)
		{
			if(qizi[i][j])
				continue;
			else
				return false;
		}
	}
	return true;
}


void CInterView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
/*	int count=Ptr.GetSize();
	for(int i=0;i<count;i++)
	{
		if(((CGeneric*)Ptr.GetAt(i))->rectangle.PtInRect(point))
		SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(NULL,IDC_NO));
	    else
		SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(NULL,IDC_CROSS));
	}*/
//	CRect rect;
//	rect.SetRect(point 
	CView::OnMouseMove(nFlags, point);
}
