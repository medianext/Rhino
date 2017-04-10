// dialog\RenderDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "../Rhino.h"
#include "RenderDlg.h"
#include "afxdialogex.h"
#include "RenderDlg.h"


// RenderDlg �Ի���

IMPLEMENT_DYNAMIC(RenderDlg, CDialogEx)

RenderDlg::RenderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RENDER_DIALOG, pParent)
{

}

RenderDlg::~RenderDlg()
{
}

void RenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RenderDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_COMMAND(WM_CLOSE, &RenderDlg::OnClose)
END_MESSAGE_MAP()


// RenderDlg ��Ϣ��������


BOOL RenderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	m_ContextMenu.CreatePopupMenu();
	m_ContextMenu.AppendMenu(MF_STRING, WM_CLOSE, TEXT("����"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void RenderDlg::OnClose()
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	ShowWindow(SW_HIDE);

	CDialogEx::OnClose();
}


void RenderDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	m_ContextMenu.DestroyMenu();

	// TODO: �ڴ˴�������Ϣ�����������
}


void RenderDlg::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ

	CDialogEx::OnMButtonUp(nFlags, point);
}


void RenderDlg::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ

	CDialogEx::OnMButtonDown(nFlags, point);
}


void RenderDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	LPPOINT lpoint = new tagPOINT;
	::GetCursorPos(lpoint);//�õ����λ��

	m_ContextMenu.TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_VERNEGANIMATION, lpoint->x, lpoint->y, this);

	CDialogEx::OnRButtonUp(nFlags, point);
}