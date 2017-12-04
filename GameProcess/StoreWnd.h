#ifndef _CSTOREWND_H
#define _CSTOREWND_H

using namespace std;


typedef struct tagQUALITYINFO
{
	string	stlszQuality;
	string	stlszPrice;
}QUALITYINFO, *LPQUALITYINFO;

typedef struct tagARTICLEINFO
{
	string					stlszArticle;
	CDLList<QUALITYINFO>	m_xQualityList;
}ARTICLEINFO, *LPARTICLEINFO;


class CStoreWnd : public CGameWnd
{ 
private:
	INT						m_nIsReadyToDisplay;
	INT						m_nCurrentItemTop;
	INT						m_nCurrentKindTop;
	INT						m_nMaxKindLine;
	INT						m_nMaxItemLine;
	INT						m_nNpcID;

	CTextButton				m_xKindBtn;
	CTextButton				m_xItemLstBtn;

	RECT					m_xKindRect;
	RECT					m_xItemRect;

	CPDLList<CLIENTITEMRCD>	m_xItems;

	BOOL					m_bSelectedKind;
	BOOL					m_bSelectedItem;
protected:
	BYTE					m_bState;					// 0 : Sell. 1 : Buy.  2 : Repair   3 : Special Repair
	CGameBtn				m_xStoreBtn[5];
	CDLList<ARTICLEINFO>	m_stArticleList;

	SHORT					m_shArticleStart;
	SHORT					m_shQualityStart;

public:
	__inline void SetNPC(INT Id)
	{
		m_nNpcID = Id;
	}

	inline	BOOL			IsInRect(POINT tPos,RECT tRect)
	{
		INT	nTemp;
		RECT twRect;
		twRect = GetGameWndRect();
		nTemp = tRect.left - (tPos.x - twRect.left);
		if(nTemp<=0)
		{
			nTemp = nTemp + (tRect.right-tRect.left);
			if(nTemp>=0)
			{
				nTemp = tRect.top - (tPos.y - twRect.top);
				if(nTemp<=0)
				{
					nTemp = nTemp + (tRect.bottom - tRect.top);
					if(nTemp>=0)
					{
						return TRUE;
					}
				}
			}
		}
		return FALSE;
	};
	CStoreWnd();
	~CStoreWnd();
	void	CreateStoreWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowStoreWnd();

	BOOL	SetBuyKinds(CHAR* msg,INT Cound);
	BOOL	SetBuyItemLst(CHAR* Msg,INT Cound);
	BOOL	SetSellKinds(CInventoryWnd*,CHAR Kind,INT nStdMode);
	BOOL	SetSellItemLst(CInventoryWnd*,CHAR Kind,BYTE nStdMode,CHAR bKind);
public:
//  �޽��� �Լ�.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);

	void	OnScrollDown();
	void	OnScrollUp();

	CWHQueue			m_xPacketQueue;					// NPC Chat���� ó���ؾߵ� �޽����� �����ϰ� �ִ� ť.
	BOOL	OnUpdateQueue(void);

private:
	void	SendDeTailGoodsList(INT nIndex,CHAR* szItemName);
	void	SendButThisITme(CMTxtBtn* tBtn);

};


#endif // _CSTOREWND_H