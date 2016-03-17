// interDoc.cpp : implementation of the CInterDoc class
//

#include "stdafx.h"
#include "inter.h"

#include "interDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInterDoc

IMPLEMENT_DYNCREATE(CInterDoc, CDocument)

BEGIN_MESSAGE_MAP(CInterDoc, CDocument)
	//{{AFX_MSG_MAP(CInterDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInterDoc construction/destruction

CInterDoc::CInterDoc()
{
	// TODO: add one-time construction code here

}

CInterDoc::~CInterDoc()
{
}

BOOL CInterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CInterDoc serialization

void CInterDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CInterDoc diagnostics

#ifdef _DEBUG
void CInterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CInterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInterDoc commands
