// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// Win32Project.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO:  �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������

#include "const.h"


void print(int x)
{
	WCHAR buf[100];
	wsprintf(buf, L"%d", x);
	MessageBox(g_hWnd, buf, TEXT("HelloMsg"), 0);
}