#pragma once
#include "CScene.h"
#include "CObjectManager.h"
#include "MyPacket.h"
#include "CGameObject.h"
#include "CItem.h"

class CMonster;
class CMyInGame : public CScene
{
public:
	std::map<std::string, std::vector<MyImage>> m_IngameImageMap;
	HDC								m_hdc;
	HWND							m_hWnd;
	HBITMAP							m_hBitmapFrameBuffer;
	HBITMAP							m_hBitmapSelect;
	DWORD							m_bBackgroundColor;
	CImage							m_PlayerImg;
	CImage							m_2PlayerImg;

	
	CImage							m_PlayerBulletImg;
	CObjectManager					MakeEnemy;


	vector<CMonster*>				m_Monster;
	vector<I_BULLET*>				m_Ibullet;
	vector<I_SUB*>					m_Isub;
	vector<I_POWER*>				m_Ipower;
	vector<I_SKILL*>				m_Iskill;
	vector<I_SHEILD*>				m_Isheild;
	int								eTime = 0;

	bool							Boss1_Appear = false;
	bool							Boss2_Appear = false;
	//적 이미지
	CImage							m_MonsterImg1;
	CImage							m_MonsterImg2;
	CImage							m_MonsterImg3;
	CImage							m_BossImg1;
	CImage							m_BossImg2;
	//아이템
	CImage							m_ItemBullet;
	CImage							m_BItemShield;
	CImage							m_ItemUlt;
	CImage							m_ItemSub;
	CImage							m_ItemPower;

	int								m_nWndClientWidth = 403;
	int								m_nWndClientHeight = 599;

	PlayerInfo						playerInfo[2];
	EnemyInfo enemyInfo;
	ItemInfo itemInfo;
	int iteamNumber=0;
	int totalIndex;
	DWORD ItemTimeCount = 0;
	DWORD maketime = 0;

	POINT tempXY;

	vector<I_BULLET*> I_bullet;
	vector<I_SUB*> I_sub;
	vector<I_POWER*> I_power;
	vector<I_SKILL*> I_skill;
	vector<I_SHEILD*> I_sheild;
	//CGameObject						*m_pGameObj;
	//Player							*m_pPlayer;
public:
	CMyInGame();
	virtual ~CMyInGame();
public:
	virtual void Render(HDC memDc) override;
	virtual void Update() override;
	virtual void Destroy() override;
public:
	virtual void Enter() override;
	virtual void Exit() override;
	
	virtual void CheckKey() override;
	//void ItemRecv();

	void MakeItem();
	void MakeEnemys();

	void sendAllIngamePack();
};
