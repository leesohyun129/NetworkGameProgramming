// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <map>
#include <atlimage.h>


//
#include "SingleTon.h"


//
#include "CRenderManager.h"
using namespace std;
// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.


#define FRAMEWORK		 FrameWork::GetInstance()
#define MYRENDERMANAGER	 CRenderManager::GetInstance()
#define SCENEMANAGER	 CSceneManager::GetInstance()
#define OBJECTMANAGER	 CObjectManager::GetInstance()
#define MAXOBJECTNUM 10000
extern HWND g_hWnd;

enum E_SCENE
{
	E_TITLE,
	E_MENU,
	E_INGAME,
	E_GAMEOVER,
	E_RANK
};

enum E_OBJECT
{
	E_BACKGROUND,
	E_PLAYER,
	E_ENEMY,
	E_BOSS
};
