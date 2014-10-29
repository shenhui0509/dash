#ifndef ILINKTRACKEROBSERVER_H_
#define ILINKTRACKEROBSERVER_H_

#include <vlc_common.h>

class ILinkTrackerObserver
{
	public:
		virtual ~ILinkTrackerObserver();
		virtual void OnLinkLayerChage(float BLER, float MLB, float SINR, size_t UE_Num, bool moving, boolm switching) = 0;
};

#endif
