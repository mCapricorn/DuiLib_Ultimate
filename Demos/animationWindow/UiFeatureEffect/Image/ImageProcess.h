#pragma once

#include "..\Graph\Graph_WarpMatrix.h"
using namespace Graph;

class CWarp
{
public:

	// ��ͼƬŤ����͹�ı���rcdes��
	// input pData ͼƬ����
	// input rcsrc ͼƬԭ��rect
	// input output warprect ͼƬŤ�����rect
	// output imgdes  Ť�����ͼƬ����
	// input bFill   �Ƿ���color�����������
	// �ⲿ�����ڴ�ķ�ʽ	
	//remark  rcsrc ��pData���±귶Χ rcBound��ͼƬ�Ĵ�С�ü��Χ����rcSrc 0,0,400,300-->rcBound 0,0,401,301)
	static BOOL WarpImage(BYTE*pData,RECT &rcSrc,WarpRect &rcDes,RECT &rcBound,BYTE* imgDes,Color color = Color::Transparent,BOOL bFill = TRUE);

	// ��ͼƬrcSrc��С������Ť����͹�ı���rcdes��
	// input pData ͼƬ����
	// input srcDataWidth pdata�Ŀ��
	// input srcDataHeight pdata�ĸ߶�
	// input rcsrc ͼƬԭ��rect
	// input output warprect ͼƬŤ�����rect
	// output imgdes  Ť�����ͼƬ����
	// input bFill   �Ƿ���color�����������
	// �ⲿ�����ڴ�ķ�ʽ	
	//remark  rcsrc ��pData���±귶Χ rcBound��ͼƬ�Ĵ�С�ü��Χ����rcSrc 0,0,400,300-->rcBound 0,0,401,301)
	static BOOL WarpImage(BYTE*pData,int srcDataWidth,int srcDataHeight, RECT &rcSrc,WarpRect &rcDes,RECT &rcBound,BYTE* imgDes,Color color = Color::Transparent,BOOL bFill = TRUE);

	// ��ͼƬrcSrc��С������Ť����͹�ı���rcdes��
	static BOOL WarpImage(BYTE *pData, int width, int height, BYTE* &imgDes, real param1);

private:
	// Calculate coordinates in input image from points in output image
	// x and y are normalised coordinates, -1 ..1
	// xnew and ynew are also normalised coordinates
	// x,y warpimage coordination
	// xnew, ynew srcimage coordination
	// param1 some warp fun param
	static inline void Evaluate(real x, real y, real &xnew, real &ynew, real param1);
};

class CMemery
{
public:
	// �������
	static void SetPixels(BYTE *Data,int width, int height, DWORD iValue);
	// ���ֲ�����
	static void SetPixels(BYTE *Data,int stride, int left, int top, int right, int bottom, DWORD iValue);
	// ��������
	static void CopyPixels(BYTE*DataDes,int strideDes,int leftDes,int topDes,int rightDes,int bottomDes,BYTE *DataSrc,int strideSrc,int leftSrc,int topSrc);
};

class CBlinds
{
public:
	// ��ͼƬ����ɰ�Ҷ����Ч
	// input Data
	// input width height ͼ��ĳ��Ϳ�
	// input iBlindHeight��ҶЧ���ĸ߶ȣ�iBlindNum��ҶЧ���ĸ���
	// offset ÿ����ҶЧ��Ҫ������о����Լ����еľ��루���أ�
	// color  ��Ҷ����ɫ
	// output Data
	static BOOL BlindsH(BYTE *Data,int width, int height,int iBlindHeight,int iBlindNum,int offsetDistance,DWORD color = 0);
	// ��ͼƬ����ɰ�Ҷ����Ч
	// input Data
	// input width height ͼ��ĳ��Ϳ�
	// input iBlindWidth��ҶЧ����kuan�ȣ�iBlindNum��ҶЧ���ĸ���
	// offset ÿ����ҶЧ��Ҫ������о����Լ����еľ��루���أ�
	// color  ��Ҷ����ɫ
	// output Data
	static BOOL BlindsV(BYTE *Data,int width, int height,int iBlindWidth,int iBlindNum,int offsetDistance,DWORD color = 0);
	// ��ͼƬ�԰�Ҷ��ʽ������Ч
	// input DataDes
	// input DataSrc
	// input width height ͼ��ĳ��Ϳ�
	// input iBlindHeight��ҶЧ���ĸ߶ȣ�iBlindNum��ҶЧ���ĸ���
	// offset ÿ����ҶЧ��Ҫ������о����Լ����еľ��루���أ�
	// output DataDes
	static BOOL BlindsH(BYTE *DataDes,BYTE *DataSrc,int width, int height,int iBlindHeight,int iBlindNum,int offsetDistance);
	// ��ͼƬ�԰�Ҷ��ʽ������Ч
	// input DataDes
	// input DataSrc
	// input width height ͼ��ĳ��Ϳ�
	// input iBlindWidth��ҶЧ����kuan�ȣ�iBlindNum��ҶЧ���ĸ���
	// offset ÿ����ҶЧ��Ҫ������о����Լ����еľ��루���أ�
	// output DataDes
	static BOOL BlindsV(BYTE *DataDes,BYTE *DataSrc,int width, int height,int iBlindWidth,int iBlindNum,int offsetDistance);
};

class CAlpha
{
public:
	// ����ͼ���alpha
	// alphachange 0~1
	static void SetAlpha(BYTE *Data,int width, int height,real alphaChange);

	//MMX����ͼƬ��alphaֵΪָ����ֵ
	static void SetAlphaMMX(BYTE *Data,int width, int height,BYTE alphaNew);

	//����ͼ��ֲ���alpha
	static void SetAlpha(BYTE *Data,int stride, int left ,int top, int right, int bottom, real alphaChange);
};

class CWater
{
public:
	CWater(){m_iParticleAmplitudeField1 = m_iParticleAmplitudeField2 = NULL;};
	~CWater(){};

	// ����ˮ������ϵͳ,������Destory�ɶ�ʹ��
	BOOL Create(int iWidth,int iHeight);

	// ɾ������ϵͳ,������Create�ɶ�ʹ��
	BOOL Destory();

	//  ����˥������ϵ����Ĭ���ڴ������ӵ�ʱ���ʼ��Ϊ6
	BOOL SetDensity(int idensity);

	// ��λ�������
	BOOL ResetAmplitude();

	// ����һ���𵴲�
	// x ,y						λ��
	// radius					�뾶
	// amplitude				���
	BOOL AmplitudeBlob(int x, int y, int radius, int amplitude);

	// ��Ⱦ����ϵͳ������ˮ��ͼƬ
	BOOL WaterImage(BYTE* pSrcImage,BYTE* pTargetImage);

private:
	// ����npageҳ�����
	BOOL CalcWaterAmplitude(int npage, int density);

	// ����npageҳ���������ͼƬ
	BOOL DrawWaterWithLight(int page,BYTE* pSrcImage,BYTE* pTargetImage);
private:
	int			m_iWidth;						// width
	int			m_iHeight;						// height
	int			m_iHpage;						// The current Amplitude field
	int			m_density;						// The water density
	int*		m_iParticleAmplitudeField1;		// the Amplitude fields
	int*		m_iParticleAmplitudeField2;		// the Amplitude fields
};

class CScale
{
private:
	CScale(){m_paramInited = FALSE;}
public:

	static BOOL ImageScale(BYTE *DataDes, int desWidth, int desHeight, BYTE *DataSrc, int srcStride, int srcLeft, int srcTop, int srcWidth, int srcHeight, int interpolationMode = 0);

private:
	BOOL InitParam(real sharpenCoefficient);
	real SinXDivX(real x, real sharpenCoefficient);
	void ThreeOrder(const BYTE *DataSrc, const int srcStride, const real fx, const real fy, BYTE *resultColor);
	void ThreeOrderBorder(const BYTE *DataSrc, const int srcStride, int srcLeft, int srcTop, const int srcWidth, const int srcHeight, const real fx, const real fy, BYTE *resultColor);
	inline void GetBorderColor(const BYTE *DataSrc, const int srcStride, int row, int col, real* borderColor);
	// ��������ֵ�㷨�����ξ����ֵ��
	BOOL Scale(BYTE *DataDes, int desWidth, int desHeight, BYTE *DataSrc, int srcStride, int srcLeft, int srcTop, int srcWidth, int srcHeight, real sharpenCoefficient);
	// ��������ֵ�㷨���ٽ����ֵ��
	BOOL Scale(BYTE *DataDes, int desWidth, int desHeight, BYTE *DataSrc, int srcStride, int srcleft, int srctop, int srcWidth, int srcHeight);
	// ��������ֵ�㷨��˫���Բ�ֵ��
	BOOL BilinearScale(BYTE *DataDes, int desWidth, int desHeight, BYTE *DataSrc, int srcStride, int srcleft, int srctop, int srcWidth, int srcHeight);

private:
	static real m_sinxDivxTable[513];
	static BOOL m_paramInited;
};

class CAlphaBlend
{
private:
	// same size 
	static BOOL AlphaBlend(BYTE *desData, BYTE *srcData, int width, int height, BYTE sourceAlpha = 255);
	// diff size
	static BOOL AlphaBlend(BYTE *desData, int desStride, int desLeft, int desTop, int desWidth, int desHeight, BYTE *srcData, int srcStride, int srcLeft, int srcTop, BYTE sourceAlpha = 255);
public:
	// interface
	// interpolationMode ��ֵģʽ��Ĭ��Ϊ�ٽ����ֵ
	static BOOL AlphaBlend(BYTE *desData, int desStride, int desLeft, int desTop, int desWidth, int desHeight, BYTE *srcData, int srcStride, int srcLeft, int srcTop, int srcWidth, int srcHeight, BYTE sourceAlpha = 255, int interpolationMode = 0);
};

class CGaussBlur
{
public:
	// weights is calculated for ImageGaussiabBlur function
	static void InitWeights(double Q,int radius,int **weights);
	static void ImageGaussiabBlur(BYTE *Data,int width, int height,int radius, int *weights);
};

class CTraileBlur
{
public:
	//��ֵģ��
	//input DataSrc
	//input width height ͼ��ĳ��Ϳ�
	//input length ģ����Χ
	//output DataDes
	static BOOL TraileBlur(BYTE *DataDes, BYTE *DataSrc, int width, int height, int lengthBlur);
};