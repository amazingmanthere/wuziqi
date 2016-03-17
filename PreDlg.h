#if !defined(AFX_PREDLG_H__46465537_A833_4013_AA75_FBA2916029F7__INCLUDED_)
#define AFX_PREDLG_H__46465537_A833_4013_AA75_FBA2916029F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreDlg dialog

class CPreDlg : public CDialog
{
// Construction
public:
	CPreDlg(CWnd* pParent = NULL);   // standard constructor

	CRect dlglarge;
	CRect dlgsmall;
	CRect Separator;
	HICON hIcon;
	static int j;
// Dialog Data
	//{{AFX_DATA(CPreDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_edit1;
	CString	m_edit2;
	int		m_radio;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton2();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush brush;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREDLG_H__46465537_A833_4013_AA75_FBA2916029F7__INCLUDED_)
