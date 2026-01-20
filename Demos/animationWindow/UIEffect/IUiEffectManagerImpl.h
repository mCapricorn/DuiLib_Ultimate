
#pragma once
#include "..\UiFeatureEffect\Interface\IUIEffect.h"

class IUiEffectManagerImpl
{
public:
	IUiEffectManagerImpl();
	virtual ~IUiEffectManagerImpl();

	static IUiEffectManagerImpl* GetInstance();

	// �õ�һ����������
	IUIEffect* GetAnimation();
	// ɾ��һ����������
	bool ReleaseAnimation(IUIEffect* &pUIEffect);
	DWORD GetSurportAnimationType(const char* &strType);

private:
	bool LoadEffectDll();

private:
	HMODULE m_hEffectDll;
	GETANIMATION m_funGetAnimation;
	RELEASEANIMATION m_funReleaseAnimation;
	GETSURPORTANIMATIONTYPE m_funGetSurportAnimationType;
};
