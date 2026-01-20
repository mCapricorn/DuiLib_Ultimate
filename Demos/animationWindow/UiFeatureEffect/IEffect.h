#pragma once
#include "Interface\IUIEffect.h"

class IEffect;
struct InternalAnimationParam
{
	AnimationParam  param;				// �ӿڶ���Ķ�������
	BYTE*			bmpDataCopy;		// �ⲿ����ͼƬ��Դ����
	DWORD			frameNow;			// ��ǰ����֡
	BOOL			bLastFrame;			// �Ƿ������һ֡
	IEffect*		pEffect;			// ָ����Ч�����ӿ�ָ��
};

//��Ч�ӿ�
class IEffect
{
public:
	// ����һ֡
	virtual void ComputeOneFrame(InternalAnimationParam *internalParam) = 0;
	// ��ʼ����Ч����
	virtual void InitEffectParam(InternalAnimationParam *internalParam) = 0;
	// ������Ч����
	virtual void ReleaseEffectParam() = 0;
};