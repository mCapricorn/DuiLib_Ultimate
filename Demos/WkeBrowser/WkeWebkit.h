#pragma once
#include <string>
#include <map>
using namespace std;

#include "3rd/Wke/Include/wke.h"
#pragma comment(lib, "3rd\\wke\\lib\\wke.lib")

#ifdef _UNICODE
#define _tstring std::wstring
#else
#define _tstring std::string
#endif

#define EVENT_TICK_TIEMER_ID	42

_tstring ANSI2T(LPCSTR);
std::string T2ANSI(LPCTSTR);

typedef struct _rend_data
{
	RECT rt; //��Ⱦ�ľ�������
	void* pixels; //��Ⱦ���ڴ�����
	HDC hDC; //�ڴ��豸
	HBITMAP hBitmap; //λͼ

	_rend_data()
	{
		memset(&rt, 0, sizeof(RECT));
		pixels = NULL;
		hDC = ::CreateCompatibleDC(0);
		hBitmap = NULL;
	}

	~_rend_data()
	{
		if (hDC)
			DeleteDC(hDC);

		if (hBitmap)
			DeleteObject(hBitmap);
	}

}REND_DATA, *PRENDDATA;

class CWkeWebkitUI;

class IWkeCallback
{
public:
	virtual void OnWkeTitleChanged(CWkeWebkitUI* webView, LPCTSTR title){}
	virtual void OnWkeURLChanged(CWkeWebkitUI* webView, LPCTSTR url){}
	virtual void OnWkeAlertBox(CWkeWebkitUI* webView, LPCTSTR msg){}
	virtual bool OnWkeNavigation(CWkeWebkitUI* webView, wkeNavigationType navigationType, LPCTSTR url){return false;}
	virtual wkeWebView OnWkeCreateView(CWkeWebkitUI* webView, const wkeNewViewInfo* info){return NULL;}
	virtual void OnWkeDocumentReady(CWkeWebkitUI* webView, const wkeDocumentReadyInfo* info){}
	virtual void OnWkeLoadingFinish(CWkeWebkitUI* webView, const LPCTSTR url, wkeLoadingResult result, LPCTSTR failedReason){}
	virtual LPCTSTR OnJS2Native(CWkeWebkitUI *pWeb, LPCTSTR lpMethod, LPCTSTR lpContent, void *pListenObj){ return NULL; }
};

class CWkeWebkitUI : public CControlUI
{
public:
	CWkeWebkitUI(void);
	~CWkeWebkitUI(void);

protected:	
	virtual LPCTSTR	GetClass() const;
	virtual LPVOID GetInterface(LPCTSTR pstrName);
	virtual void DoInit();
	virtual void SetPos(RECT rc, bool bNeedUpdate = true);
	virtual bool DoPaint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl);
	virtual void DoEvent(TEventUI& event);	

public:
	//��ʼ��webkit
	static void InitializeWebkit();

	//����ʼ��webkit
	static void UninitializeWebkit();	

	//ִ��js����
	void ExecuteJS(LPCTSTR lpJS);

public:
	wkeWebView GetWebView();

	//����url
	void Navigate(LPCTSTR lpUrl);	

	//����html����
	void LoadHtml(LPCTSTR lpHtml);

	//�ر�webkit����
	void Close();	
	
	//ҳ����������ˡ�ǰ����ֹͣ��ˢ��
	void Back();
	void Forward();
	void Stop();
	void Reload();	

	//������ҳ
	void SetHomePage(LPCTSTR lpHomeUrl);

	//�����ҳ
	void NavigateHomePage();

	//����ҳ�潹��
	void SetPageFocus();

public:
	//���ü�������
	void SetListenObj(void *pListenObj);

	// ���ûص��ӿ�
	void SetWkeCallback(IWkeCallback* pWkeCallback);

	//����������ԭ����ҳ�����ʧ�ܺ����ʾҳ��
	void SetErrorInfoPageUrl(LPCTSTR lpErrUrl);

private:
	// �ص��¼�
	static void WKE_CALL OnWkeTitleChanged(wkeWebView webView, void* param, wkeString title);
	static void WKE_CALL OnWkeURLChanged(wkeWebView webView, void* param, wkeString url);
	static void WKE_CALL OnWkeAlertBox(wkeWebView webView, void* param, wkeString msg);
	static bool WKE_CALL OnWkeNavigation(wkeWebView webView, void* param, wkeNavigationType navigationType, wkeString url);
	static wkeWebView WKE_CALL OnWkeCreateView(wkeWebView webView, void* param, const wkeNewViewInfo* info);
	static void WKE_CALL OnWkeDocumentReady(wkeWebView webView, void* param, const wkeDocumentReadyInfo* info);
	static void WKE_CALL OnWkeLoadingFinish(wkeWebView webView, void* param, const wkeString url, wkeLoadingResult result, const wkeString failedReason);
	//����һ��js�뱾�صĺ���ӳ��
	static jsValue JS_CALL JsToNative(jsExecState es);

private:
	REND_DATA m_RendData;

	wkeWebView	 m_pWebView;

	TCHAR m_chHomeUrl[1024]; //��ҳ��url

	TCHAR m_chCurPageUrl[1024]; //��ǰҳ���url

	TCHAR m_chErrUrl[1024]; //������ʾҳ���url

private:
	void *m_pListenObj; //��������
	IWkeCallback* m_pWkeCallback;	// �ص��ӿ�
	static map<wkeWebView, CWkeWebkitUI*> m_mapWke2UI; //����Wke���ĵ�WebkitUI��ӳ���ϵ
};

