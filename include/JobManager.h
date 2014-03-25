#ifndef __JOB_MANAGER_H__
#define __JOB_MANAGER_H__

#include "SmartPointer.h"

class xiJobManager : public virtual xiPtr {
public:
	xiJobManager *	Create();
protected:
	xiJobManager();
	~xiJobManager();
};

#endif