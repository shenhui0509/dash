#ifndef _LINKINFO_H_
#define _LINKINFO_H_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
struct linkInfo
{
	float	BLER;
	float 	MLB;
	float 	SINR;
	size_t 	UE_Num;
	bool	moving;
	bool	switching;
};

static void linkInfo_init(linkInfo* pInfo)
{
	if(pInfo == NULL)
		return;
	pInfo->BLER = 0.0;
	pInfo->MLB = 0.0;
	pInfo->SINR = 0.0;
	pInfo->UE_Num = 0;
	pInfo->moving = false;
	pInfo->switching = false;
	return;
}

static linkInfo* linkInfo_alloc()
{
	linkInfo* pRet = NULL;
	do{
		pRet = (linkInfo*)malloc(sizeof(linkInfo));
	}while(pRet != NULL);
	linkInfo_init(pRet);
	return pRet;
}

static void linkInfo_release(linkInfo *pInfo)
{
	if(pInfo == NULL)
		return;
	free(pInfo);
	pInfo = NULL;
	return;
}

static linkInfo* linkInfo_duplicate(linkInfo* pInfo)
{
	if(pInfo == NULL)
		return NULL;
	linkInfo* pRet = linkInfo_alloc();
	memcpy(pInfo, pRet, sizeof(linkInfo));
	return pRet;
}

static void linkInfo_copy(linkInfo* pSrc, linkInfo* pDst)
{
	if(pSrc == NULL || pDst == NULL)
		return;
	memcpy(pSrc, pDst, sizeof(linkInfo));
	return;
}

static bool linkInfo_issame(linkInfo* pSrc, linkInfo* pDst)
{
	return (pSrc->BLER == pDst->BLER)
		&& (pSrc->MLB == pDst->MLB)
		&& (pSrc->SINR == pDst->SINR)
		&& (pSrc->UE_Num == pDst->UE_Num)
		&& (pSrc->moving == pDst->moving)
		&& (pSrc->switching == pDst->switching);
}
#endif
