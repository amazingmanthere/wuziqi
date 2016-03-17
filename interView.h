// interView.h : interface of the CInterView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTERVIEW_H__19F5908B_5387_4D85_9A08_38F17DA3D9A6__INCLUDED_)
#define AFX_INTERVIEW_H__19F5908B_5387_4D85_9A08_38F17DA3D9A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CInterView : public CView
{
protected: // create from serialization only
	CInterView();
	DECLARE_DYNCREATE(CInterView)

// Attributes
public:
	CInterDoc* GetDocument();
  
// Operations
public:
    CBrush brush;
	int qizi[14][14];
	CButton *p_MyBut[5];
	CListBox *listbox;
//	int flag;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInterView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CBitmap* m_bitmap;
	bool heqi();
	void Array();
	CButton* NewButton(int nID,CRect rect,int nStyle);
	CPtrArray Ptr;
	int begin;
	int judge1(int a,int b,int c);
	int judge2(int a,int b,int c);
	int judge3(int a,int b,int c);
	int judge4(int a,int b,int c);
	CRect Rect[14][14];
	virtual ~CInterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CInterView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
    afx_msg void OnMybut1();
    afx_msg void OnMybut2();
    afx_msg void OnMybut3();
    afx_msg void OnMybut4();
	afx_msg void OnMybut5();

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in interView.cpp
inline CInterDoc* CInterView::GetDocument()
   { return (CInterDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERVIEW_H__19F5908B_5387_4D85_9A08_38F17DA3D9A6__INCLUDED_)
