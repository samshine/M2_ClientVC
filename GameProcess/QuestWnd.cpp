/******************************************************************************************************************
                                                                                                                   
	모듈명:																											
																													
	작성자:																											
	작성일:																											
																													
	[일자][수정자] : 수정 내용																						
                                                                                                                   
*******************************************************************************************************************/



#include "StdAfx.h"


CQuestWnd::CQuestWnd()
{
	Init();
}

CQuestWnd::~CQuestWnd()
{
	Destroy();
}

void CQuestWnd::Init()
{
	CGameWnd::Init();

	m_xQuestBtn.Init();
}

void CQuestWnd::Destroy()
{
	CGameWnd::Destroy();
}

void CQuestWnd::CreateQuestWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove)
{
	CreateGameWnd(nID, pxWndImage, nFrameImgIdx, bCanMove, nStartX, nStartY, nWidth, nHeight);
	m_xQuestBtn.CreateGameBtn(pxWndImage, 630, 631, nStartX+567, nStartY+413);
}

void CQuestWnd::ShowQuestWnd()
{
	ShowGameWnd();
	m_xQuestBtn.ShowGameBtn();
}

BOOL CQuestWnd::OnLButtonUp(POINT ptMouse)
{
	if ( m_xQuestBtn.OnLButtonUp(ptMouse) )		return TRUE;

	return FALSE;
}

BOOL CQuestWnd::OnLButtonDown(POINT ptMouse)
{
	if ( m_xQuestBtn.OnLButtonDown(ptMouse) )		return TRUE;

	return FALSE;
}

void CQuestWnd::OnMouseMove(POINT ptMouse)
{
	m_xQuestBtn.ChangeRect(m_rcWnd.left+567, m_rcWnd.top+413);
	m_xQuestBtn.OnMouseMove(ptMouse);
}

void CQuestWnd::SetStatusBtnInit()
{
	m_xQuestBtn.SetBtnState(_BTN_STATE_NORMAL);
}

