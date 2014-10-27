#ifndef _LINKTRACKER_H_
#define _LINKTRACKER_H_ 1
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include "LinkTrackerOberserver.h"

class LinkTracker{
	public:
		void attach();
		void notify();
	private:
		std::vector<LinkTrackerOberserver> obs;
		void update();
		float 	BLER;
		float 	MLB;
		float 	SINR;
		size_t 	UE_Num;
		bool	moving;
		bool	switching;
		struct	predict;
}
#endif
