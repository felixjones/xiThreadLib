#ifndef __SYS_ATOMIC_H__
#define __SYS_ATOMIC_H__

#include <stdint.h>

namespace Sys {
	intptr_t	IncrementPtr( volatile intptr_t * const val );
	intptr_t	DecrementPtr( volatile intptr_t * const val );
	int32_t		Increment32( volatile int32_t * const val );
	int32_t		Decrement32( volatile int32_t * const val );
	int64_t		Increment64( volatile int64_t * const val );
	int64_t		Decrement64( volatile int64_t * const val );
	uint64_t	Tick();
}

#endif