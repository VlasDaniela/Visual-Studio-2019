
// Tema_1View.cpp : implementation of the CTema1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Tema_1.h"
#endif

#include "Tema_1Doc.h"
#include "Tema_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTema1View

IMPLEMENT_DYNCREATE(CTema1View, CView)

BEGIN_MESSAGE_MAP(CTema1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTema1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTema1View construction/destruction

CTema1View::CTema1View() noexcept
{
	// TODO: add construction code here

}

CTema1View::~CTema1View()
{
}

BOOL CTema1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTema1View drawing

void CTema1View::OnDraw(CDC* /*pDC*/)
{
	CTema1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTema1View printing


void CTema1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTema1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTema1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTema1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTema1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTema1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTema1View diagnostics

#ifdef _DEBUG
void CTema1View::AssertValid() const
{
	CView::AssertValid();
}

void CTema1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTema1Doc* CTema1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTema1Doc)));
	return (CTema1Doc*)m_pDocument;
}
#endif //_DEBUG


// CTema1View message handlers
