#include "stdafx.h"
#include "Framework.h"
#include "CMyMenu.h"
#include "CRenderManager.h"
#include "MyPacket.h"
CMyMenu::CMyMenu()
{
	

	//m_MenuImageMap
	//m_MenuImageMap.insert(make_pair("background", MYRENDERMANAGER->FindCImage("StartBackground.png")));
	//std::map<std::string, std::vector<MyImage>> m_ImageMap;
	m_MenuImageMap.insert(pair<std::string, std::vector<MyImage>>("MenuBackGroundImage", *MYRENDERMANAGER->FindCImage("MenuImage")));

	

}


CMyMenu::~CMyMenu()
{

}

void CMyMenu::Render(HDC hdc)
{
	
	PAINTSTRUCT ps;
	BeginPaint(g_hWnd, &ps);
	{
		HDC memDC = CreateCompatibleDC(hdc);
		HBITMAP memBit = CreateCompatibleBitmap(hdc, m_nWndClientWidth, m_nWndClientHeight);
		SelectObject(memDC, memBit);
	
		BitBlt(hdc, 0, 0, 800, 600, m_MenuImageMap["MenuBackGroundImage"].begin()->GetCimage()->GetDC(), 0, 0, SRCCOPY);
		DeleteObject(memBit);
		DeleteDC(memDC);
	}
	EndPaint(g_hWnd, &ps);

}

void CMyMenu::EndRender()
{
	HDC hDC = ::GetDC(m_hWnd);

	::BitBlt(hDC, 0, 0, m_nWndClientWidth, m_nWndClientHeight, m_hdc, 0, 0, SRCCOPY);
	::ReleaseDC(m_hWnd, hDC);
}

void CMyMenu::Update()
{
	ClientInfoToHandle ClientInfo;
	int retval;
	//레디정보를 계속 보내준다.
	 retval = send(FRAMEWORK->GetSock(), (char*)FRAMEWORK->GetClientInfo().IsReady, sizeof(FRAMEWORK->m_ClientInfo.IsReady), 0);//구조체 보냄


}

void CMyMenu::Destroy()
{
}

void CMyMenu::Enter()
{
	//create
}

void CMyMenu::Exit()
{
}

void CMyMenu::PreRender(DWORD dwColor)
{
	HBRUSH hBrush = ::CreateSolidBrush(dwColor);
	HBRUSH hOldBrush = (HBRUSH)::SelectObject(m_hdc, hBrush);
	::Rectangle(m_hdc, 0, 0, m_nWndClientWidth, m_nWndClientHeight);
	::SelectObject(m_hdc, hOldBrush);
	::DeleteObject(hBrush);
}

void CMyMenu::BeginRender()
{
	HDC hDC = ::GetDC(m_hWnd);

	if (!m_hdc)
		m_hdc = ::CreateCompatibleDC(hDC);
	if (m_hBitmapFrameBuffer)
	{
		::SelectObject(m_hdc, NULL);
		::DeleteObject(m_hBitmapFrameBuffer);
		m_hBitmapFrameBuffer = NULL;
	}

	m_hBitmapFrameBuffer = ::CreateCompatibleBitmap(hDC, m_nWndClientWidth, m_nWndClientHeight);
	::SelectObject(m_hdc, m_hBitmapFrameBuffer);

	::ReleaseDC(m_hWnd, hDC);
	::SetBkMode(m_hdc, TRANSPARENT);
}
