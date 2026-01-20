
#ifndef IEFFECT_H
#define IEFFECT_H

#ifndef _WINDEF_
#include <WinDef.h>
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
struct AnimationParam
{
	// ����ID
	WPARAM				effectKey;
	// ����ͼƬ��Դ
	HBITMAP				hBitmap;
	// ����ͼƬDC
	HDC					hdc;
	// ����ͼƬ�ߴ�
	SIZE				bmpSize;
	// ����ͼƬ�ڴ��ַ
	BYTE*				pBmpData;
	// ��������
	DWORD				animationEffect;
	// ����֡ʱ��
	DWORD				animationFrequency;
	// ����˳��
	BOOL				bShow;
};

class _declspec(novtable) IUIEffectCallBack
{
public:
	// ÿһ �� ������ʼʱ�ص�
	virtual void OnUiEffectBegin(WPARAM effectKey, DWORD animaType) = 0;
	// ÿһ �� ��������ʱ�ص�
	virtual void OnUiEffectEnd(WPARAM effectKey, DWORD animaType) = 0;
	// ÿһ ֡ ��������ʱ�ص�
	virtual void OnUiEffectDraw() = 0;
};


class _declspec(novtable) IUIEffect
{
public:
	// ����һ������
	virtual BOOL AppendAnimation(AnimationParam &aParam) = 0;
	// ɾ��һ������
	virtual BOOL DependAnimation(WPARAM effectKey) = 0;
	// ɾ�����ж���
	virtual BOOL ClearAllAnimation() = 0;
	// ִ�����ж�����frameSpin��������
	virtual BOOL Animation(IUIEffectCallBack *iDrawEffect,DWORD frameSpin) = 0;

};

// ��������
// ��ö�����ʵ��
IUIEffect* GetAnimation(void);
// ɾ��GetAnimation������õĶ�����ʵ��
BOOL ReleaseAnimation(IUIEffect* &pUIEffect);
// �����֧�ֵĶ������ͣ�\0Ϊ�ָ����������������
// �ַ����е�˳����Ƕ������������ֵ��1...N��
DWORD GetSurportAnimationType(const char* &strType);

typedef IUIEffect* (*GETANIMATION)();
typedef BOOL (*RELEASEANIMATION)(IUIEffect* &);
typedef DWORD (*GETSURPORTANIMATIONTYPE)(const char* &);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class _declspec(novtable) IImageProcess
{
public:
	// alpha ���
	virtual BOOL AlphaBlend(BYTE *desData, int desStride, int desLeft, int desTop, int desWidth, int desHeight, BYTE *srcData, int srcStride, int srcLeft, int srcTop, int srcWidth, int srcHeight, BYTE sourceAlpha = 255, int interpolationMode = 0) = 0;
	// ͼƬ����
	virtual BOOL ImageScale(BYTE *DataDes, int desWidth, int desHeight, BYTE *DataSrc, int srcStride, int srcLeft, int srcTop, int srcWidth, int srcHeight, int interpolationMode = 0) = 0;
};

// ��������
// ���ͼ����ʵ��
IImageProcess* GetImageProcess(void);
// ɾ��GetImageProcess������õ�ͼ����ʵ��
BOOL ReleaseImageProcess(IImageProcess* &pProcess);

typedef IImageProcess* (*GETIMAGEPORCESS)();
typedef BOOL (*RELEASEIMAGEPROCESS)(IImageProcess* &);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
