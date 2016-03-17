// Generic.cpp: implementation of the CGeneric class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "inter.h"
#include "Generic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CGeneric::CGeneric()
{

}
CGeneric::CGeneric(CRect rectangle,int t,int a,int b,int m_array)
{
	this->rectangle=rectangle;
	this->t=t;
	this->a=a;
	this->b=b;
	array[a][b]=m_array;
}
CGeneric::~CGeneric()
{

}
