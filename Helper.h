#pragma once

#include <windows.h>

LPWSTR a2w(LPCSTR lpszText)
{
	const DWORD dwSize = MultiByteToWideChar(CP_UTF8, 0, lpszText, -1, 0, 0);
	LPWSTR lpszReturnText = (LPWSTR)GlobalAlloc(0, dwSize * sizeof(WCHAR));
	MultiByteToWideChar(CP_UTF8, 0, lpszText, -1, lpszReturnText, dwSize);
	return lpszReturnText;
}

LPSTR w2a(LPCWSTR lpszText)
{
	const DWORD dwSize = WideCharToMultiByte(CP_UTF8, 0, lpszText, -1, 0, 0, 0, 0);
	LPSTR lpszReturnText = (char*)GlobalAlloc(GPTR, dwSize * sizeof(char));
	WideCharToMultiByte(CP_UTF8, 0, lpszText, -1, lpszReturnText, dwSize, 0, 0);
	return lpszReturnText;
}