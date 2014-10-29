#include "LinkTracker.h"

LinkTracker::LinkTracker(): prevInfo(NULL),
							curInfo(NULL)
{}

LinkTracker::~LinkTracker()
{
	linkInfo_release(prevInfo);
	linkInfo_release(curInfo);
	vlc_join(this->linkTrackThread, NULL);
	vlc_join(this->linkNotifyThread, NULL);
}

bool LinkTracker::start()
{
	if(vlc_clone(&(this->linkTrachThread), track, (void*)this->curInfo, VLC_THREAD_PRIORITY_LOW))
		return false;
	if(vlc_clone(&(this->linkNotifyThread), update, (void*)this, VLC_THREAD_PRIORITY_LOW))
		return false;
	return true;
}

void LinkTracker::attach(ILinkTrackerOberserver* ob)
{
	this->obs.push_back(ob);
}

void* LinkTracker::track(void *pInfo)
{
	linkInfo* pCurInfo = (linkInfo*)pInfo;
	while(true)
	{
		getLinkInfo(pCurInfo);
		sleep(500);
	}
	return NULL;
}

void* LinkTracker::updata(void* param)
{
	LinkTracker* tracker = (LinkTracker*)param;
	while(true)
	{
		if(linkInfo_issame(tracker->prevInfo, tracker->curInfo))
		{
			sleep(500);
			continue;
		}
		else
		{
			linkInfo_copy(tracker->curInfo, tracker->prevInfo);
			for(size_t i = 0; i < tracker->obs.size(); ++i)
				obs.at(i)->onLinkLayerChange(tracker->curInfo);
			sleep(458);
		}
	}
	return NULL;
}
