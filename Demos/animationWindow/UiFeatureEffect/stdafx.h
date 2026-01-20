// StdAfx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>
#include <WTypes.h>
#include <ObjIdl.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <GdiPlus.h>
using namespace Gdiplus;
using namespace std;

#ifdef _DEBUG
#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC 
#endif

#ifdef _DEBUG 
#define DEBUG_CLIENTBLOCK    new( _CLIENT_BLOCK, __FILE__, __LINE__) 
#else 
#define DEBUG_CLIENTBLOCK 
#endif 

#ifdef _DEBUG 
#define new DEBUG_CLIENTBLOCK 
#endif 

#pragma comment (lib, "gdiplus.lib")

