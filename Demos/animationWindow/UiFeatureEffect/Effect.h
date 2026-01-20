#pragma once
#include "IEffect.h"
#include "Graph/Graph_Def.h"
#include "Graph/Graph_Rect.h"
#include "Image/ImageProcess.h"

class CEffect : public IEffect
{
public:
	virtual ~CEffect(){};
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam){};
	void InitEffectParam(InternalAnimationParam *internalParam){};
	void ReleaseEffectParam(){};
protected:
	int		 m_effectFrame;
};

class CFlipEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CMosaicEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	int		 m_nWidth;					// ͼƬ��
	int		 m_nHeight;					// ͼƬ��
	int		 m_nMosaicW;				// �����˿�
	int		 m_nMosaicH;				// �����˸�
	int		 m_nWidthCount;				// �����˺������
	int		 m_nHeightCount;			// �������������
	int*	 m_pMosaicArray;			// ÿ���������Ƿ�ִ����
};

class CSlideEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
protected:
	void  CalculateFrame(int length);
protected:
	int		 m_step;					// ÿ�λ����ľ���(speed)
};

class CBandSlideEffect : public CSlideEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	int		m_bandNum;					// ��״����
	int		m_bandSize;					// ��״�Ŀ���߸�
};

class CBlindsEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
protected:
	int		m_bandNum;					// ��Ҷ����
	int		m_bandSize;					// ��Ҷ�Ŀ���߸�
};

class CSepcialBlindsEffect : public CBlindsEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	void CalculateFrame(int length);
private:
	vector<int> m_specialBandSize;		// ��Ҷ�Ŀ���߸�
	int			m_nowSumRowCol;			// ��ǰ������ʼ�л�����
};

class CScanEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
protected:
	void  CalculateFrame(int length);
protected:
	int		 m_step;					// ÿ��ɨ��ľ���(speed)
};

class CInertiaSlideEffect : public CSlideEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	Graph::real	m_tInertiaTime;			// �����˶���ǰʱ��
	void*	m_inertiaInstance;			// ���Ը�����
	Graph::real	m_tInertiacoeffecient;	// �����˶����ʵ��ڲ���
};

class CFadeEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CZoomEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	Graph::CdRect				m_rcNow;		// �任�굱ǰ�Ĵ�С
};

class CShrinkEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	Graph::CdRect				m_rcNow;		// �任�굱ǰ�Ĵ�С
};

class CSwingEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CFunnelEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CNoiseEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	int							m_u;			// ����
};

class CCubeEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CGradualEraseEffect : public CScanEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	Graph::real		m_alphaStep;			// alpha����ֵ
	int				m_lastStart;			// ��һ�ν�����ʼ�л�����
	int				m_lastEnd;				// ��һ�ν�������л�����
};

class CPushEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CDissolveEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	BYTE*			m_pDissolveArray;		// ��ʾ�Ƿ��ѱ��ܽ�
	int				m_size;					// ������������
	int				m_framePixel;			// ÿ֡�ܽ�ĸ���
};

class CCurtainEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CTriangularprismEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CCubeInsideEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CSpatialmotionEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	int			m_xyOffset;						// x��y�Ჽ��
	int			m_zOffset;						// z�Ჽ��
};

class CPatchFlipEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CSpatialRotateEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CDoorEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CWaveEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	CWater			*m_pWater;						// ˮ������ϵͳ
};

class CScatterEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	int				m_vx[4];						// ˮƽ�ٶ�
	int				m_vy[4];						// ��ֱ�ٶ�
};

class CColorFadeEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CDampSlideEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	Graph::real	m_tInertiaTime;			// �����˶���ǰʱ��
	void*		m_inertiaInstance;		// ���Ը�����
	Graph::real	m_tInertiacoeffecient;	// �����˶����ʵ��ڲ���
	Graph::real m_ratio;				// ͼ��ĳ����
};

class CWhirlPoolEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
};

class CClockWipeEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:

	Bitmap*		m_pBitmap;					// ����
	BYTE*		m_pBits;					// ����
};

class CPinWheelEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:

	Bitmap*		m_pBitmap;					// ����
	BYTE*		m_pBits;					// ����
};

class CPagePeelEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:

	Bitmap*		m_pBitmap;					// ����
	BYTE*		m_pBits;					// ����
	real		m_nK;						// ϵ��
	BOOL		m_intersectTop;				// �붥���ཻ
};

class CBlurEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
};

class CZoomBlurEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
};

class CFoldEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	int					m_foldNum;					// �۵�Ч��������
	vector<CdRect>		m_foldRect;					// ÿ���۵�RECT
	vector<WarpRect>	m_warpRect;					// Ť����rect
};

class CStackEffect : public CEffect
{
public:
	// IEffect
	void ComputeOneFrame(InternalAnimationParam *internalParam);
	void InitEffectParam(InternalAnimationParam *internalParam);
	void ReleaseEffectParam();
private:
	int				m_bandNum;					// ��״������
	int				m_bandSize;					// ��״�Ŀ���߸�
	vector<int>		m_bandFrameNum;				// ÿ����֡��
	int				m_bandAnimating;			// ��ǰ�˶��Ĵ�״���
	int				m_bandFrameSum;				// �ڵ�ǰ��״ǰ��Ĵ�״�ۻ���ɵ�֡��
	int				m_bandSubFrame;				// ��ǰ��״��ִ��֡��
};

/////////////////////////////////////////////////////////////////////////////////////////////
//��Ч����
class CEffectFactory/* : public IFactory*/
{
public:
	static IEffect* CreateEffect(DWORD effectKey)
	{
		IEffect* pEffect = NULL;
		switch (effectKey)
		{
		case 2:
		case 3:
		case 4:
		case 5:
			pEffect = new CFlipEffect();
			break;
		case 6:
			pEffect = new CMosaicEffect();
			break;
		case 7:
		case 8:
		case 9:
		case 10:
			pEffect = new CSlideEffect();
			break;
		case 11:
		case 12:
			pEffect = new CBandSlideEffect();
			break;
		case 13:
		case 14:
			pEffect = new CBlindsEffect();
			break;
		case 15:
		case 16:
			pEffect = new CSepcialBlindsEffect();
			break;
		case 17:
		case 18:
		case 19:
		case 20:
			pEffect = new CScanEffect();
			break;
		case 21:
		case 22:
		case 23:
		case 24:
			pEffect = new CInertiaSlideEffect();
			break;
		case 25:
			pEffect = new CFadeEffect();
			break;
		case 26:
			pEffect = new CZoomEffect();
			break;
		case 27:
			pEffect = new CShrinkEffect();
			break;
		case 28:
			pEffect = new CSwingEffect();
			break;
		case 29:
			pEffect = new CFunnelEffect();
			break;
		case 30:
			pEffect = new CNoiseEffect();
			break;
		case 31:
		case 32:
		case 33:
		case 34:
			pEffect = new CCubeEffect();
			break;
		case 35:
		case 36:
		case 37:
		case 38:
			pEffect = new CGradualEraseEffect();
			break;
		case 39:
		case 40:
		case 41:
		case 42:
			pEffect = new CPushEffect();
			break;
		case 43:
			pEffect = new CDissolveEffect();
			break;
		case 44:
			pEffect = new CCurtainEffect();
			break;
		case 45:
		case 46:
		case 47:
		case 48:
			pEffect = new CTriangularprismEffect();
			break;
		case 49:
		case 50:
		case 51:
		case 52:
			pEffect = new CCubeInsideEffect();
			break;
		case 53:
		case 54:
		case 55:
		case 56:
			pEffect = new CSpatialmotionEffect();
			break;
		case 57:
			pEffect = new CPatchFlipEffect();
			break;
		case 58:
		case 59:
		case 60:
		case 61:
			pEffect = new CSpatialRotateEffect();
			break;
		case 62:
			pEffect = new CDoorEffect();
			break;
		case 63:
			pEffect = new CWhirlPoolEffect();
			break;
		case 64:
			pEffect = new CScatterEffect();
			break;
		case 65:
			pEffect = new CColorFadeEffect();
			break;
		case 66:
		case 67:
		case 68:
		case 69:
		case 70:
		case 71:
		case 72:
		case 73:
			pEffect = new CDampSlideEffect();
			break;
		case 74:
			pEffect = new CClockWipeEffect();
			break;
		case 75:
			pEffect = new CPinWheelEffect();
			break;
		case 76:
			pEffect = new CPagePeelEffect();
			break;
		case 77:
			pEffect = new CBlurEffect();
			break;
		case 78:
			pEffect = new CWaveEffect();
			break;
		case 79:
			pEffect = new CZoomBlurEffect();
			break;
		case 80:
		case 81:
			pEffect = new CFoldEffect();
			break;
		case 82:
		case 83:
		case 84:
		case 85:
			pEffect = new CStackEffect();
			break;
		default:
			break;
		}

		return pEffect;
	}
};
/////////////////////////////////////////////////////////////////////////////////////////////