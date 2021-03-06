#pragma once
class DocumentWindow
{
public:
	static LRESULT WndProc(HWND hWndChild, UINT uMsg, WPARAM wParam, LPARAM lParam);
	DocumentWindow(HWND hWnd);
	virtual ~DocumentWindow(void);
	static LPWSTR GetWindowClassName();

private:
	HWND hChildWnd;
	HWND hRichEditWnd;
	HMODULE hrichEdit;
	int Create(WPARAM wParam, LPARAM lParam);
	int Size(WPARAM wParam, LPARAM lParam);
};

