#include "stdafx.h"
#include "CMyInGame.h"
#include "CObjectManager.h"
#include "TimerManager.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"

CMyInGame::CMyInGame()
{

	//Player *m_pPlayer = NULL;
	m_IngameImageMap.insert(pair<std::string, std::vector<MyImage>>("IngameBackGroundImage", *MYRENDERMANAGER->FindCImage("IngameBackGroundImage")));
	m_IngameImageMap.insert(pair<std::string, std::vector<MyImage>>("IngamePlayerImage", *MYRENDERMANAGER->FindCImage("IngamePlayerImage")));

}


CMyInGame::~CMyInGame()
{
}

void CMyInGame::Render(HDC hdc)
{

	int size = 50;

	m_PlayerImg.Load(TEXT("Player1.png"));
	m_MonsterImg.Load(TEXT("enemy1.png"));

	PAINTSTRUCT ps;
	BeginPaint(g_hWnd, &ps);
	{
		HDC memDC = CreateCompatibleDC(hdc);
		HBITMAP memBit = CreateCompatibleBitmap(hdc, m_nWndClientWidth, m_nWndClientHeight);
		SelectObject(memDC, memBit);
		StretchBlt(memDC, 0, 0, 403, 599, m_IngameImageMap["IngameBackGroundImage"].begin()->GetCimage()->GetDC(), 0, 0, 360, 600, SRCCOPY);
		m_PlayerImg.Draw(memDC, m_pPlayer->GetPos().x, m_pPlayer->GetPos().y, m_pPlayer->GetSize(), m_pPlayer->GetSize());
		
		
		for (vector<CGameObject*>::iterator iter = ObjList.begin(); iter != ObjList.end(); ++iter)
		{
			m_MonsterImg.Draw(memDC, (*iter)->GetPos().x, (*iter)->GetPos().y, (*iter)->GetSize(), (*iter)->GetSize());
		}
		
		//img.Draw(memDC, x, y, 50, 50);
		BitBlt(hdc, 0, 0, 403, 599, memDC, 0, 0, SRCCOPY);
		DeleteObject(memBit);
		DeleteDC(memDC);
	}
	EndPaint(g_hWnd, &ps);
	m_PlayerImg.Destroy();
	m_MonsterImg.Destroy();

}

void CMyInGame::Update()
{
	m_pPlayer->Update();
	
	//int eTime = TIMEMANAGER->GetFimeElapsed()/1000;
	int eTime = 1;
	switch (eTime)
	{
	case 1:
		MakeEnemy.AddGameObject(m_pMonster, E_ENEMY);
		MakeEnemy.SetObjlist(ObjList);
		break;
	default:
		break;
	}
	
}

void CMyInGame::Destroy()
{
}

void CMyInGame::Enter()
{
	
}

void CMyInGame::Exit()
{
}

void CMyInGame::CheckKey()
{
}

