// Generic.h: interface for the CGeneric class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GENERIC_H__74ED6DB3_6749_41B5_BFF8_0B7BE474A2C5__INCLUDED_)
#define AFX_GENERIC_H__74ED6DB3_6749_41B5_BFF8_0B7BE474A2C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGeneric  
{
public:
	CGeneric(CRect rectangle,int t,	int a,int b,int m_array);
	CGeneric();
	virtual ~CGeneric();
public:
	CRect rectangle;
	int t;
	int a;
	int b;
	int array[14][14];
};

#endif // !defined(AFX_GENERIC_H__74ED6DB3_6749_41B5_BFF8_0B7BE474A2C5__INCLUDED_)
