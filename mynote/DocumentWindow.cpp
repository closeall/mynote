/*
  The Documentwindow class is the MDI child window used in this application and will contain a RichEdit control to do the
  actual editing work.
*/

#include "StdAfx.h"
#include "DocumentWindow.h"


DocumentWindow::DocumentWindow(HWND hWnd)
{
	hChildWnd = hWnd;
	hRichEditWnd = NULL;

	hrichEdit = LoadLibrary(L"richedit20.dll");
}


DocumentWindow::~DocumentWindow(void)
{

	FreeLibrary(hrichEdit);
}

LRESULT DocumentWindow::WndProc(HWND hWndChild, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	DocumentWindow* doc = (DocumentWindow*)GetProp(hWndChild, L"DocumentPointer");

	    switch(uMsg)
    {
    case WM_NCCREATE:
        if(NULL == doc)
        {
            doc = new DocumentWindow(hWndChild);
            SetProp(hWndChild, L"DocumentPointer", doc);  // store the C++ object pointer in the window's property list
        }
        return TRUE;

	case WM_NCDESTROY:
		RemoveProp(hWndChild, L"DocumentPointer"); // remove the C++ object pointer from the property list
		if(doc)
			delete doc; // delete the C++ object pointer
		return 0;

	case WM_SIZE:
        return doc->Size(wParam, lParam);

	default:
		return DefMDIChildProc(hWndChild, uMsg, wParam, lParam);
	}
	return DefMDIChildProc(hWndChild, uMsg, wParam, lParam);
}

LPWSTR DocumentWindow::GetWindowClassName()
{
    return L"MyNoteDocumentWindowClass";
}


int DocumentWindow::Create(WPARAM wParam, LPARAM lParam)
{

	return 0;
}

int DocumentWindow::Size(WPARAM wParam, LPARAM lParam)
{
	WORD width = LOWORD(lParam);
	WORD height = HIWORD(lParam);

	return 0;
}