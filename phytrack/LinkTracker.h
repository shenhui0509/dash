#ifndef _LINKTRACKER_H_
#define _LINKTRACKER_H_ 1
#include <vlc_common.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include "ILinkTrackerObserver.h"
#include "LinkInfo.h"

class LinkTracker{
	public:
		LinkTracker();
		~LinkTracker();
		void 	attach(ILinkTrackerObserver*);
		static void* update(void *);
		bool 	start();
		static void* track(void *);
	private:
		std::vector<LinkTrackerObserver*> obs;
		linkInfo* prevInfo;
		linkInfo* curInfo;
		vlc_thread_t linkTrackThread;
		vlc_thread_t linkNotifyThread;
		
}
#endif
