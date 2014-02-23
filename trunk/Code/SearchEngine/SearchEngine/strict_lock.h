#include "Noncopy.h"

#pragma once
template <typename Lockable>
class strict_lock : public Noncopy
{
public:
	typedef Lockable lockable_type;
	explicit strict_lock(lockable_type &obj) : obj_(obj)
	{
		obj.lock();
	}

	~strict_lock(void);
private:
	lockable_type& obj_;
};

