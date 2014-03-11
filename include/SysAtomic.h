#ifndef __SYS_ATOMIC_H__
#define __SYS_ATOMIC_H__

#include <stdint.h>

namespace Sys {
	uintptr_t	IncrementPtr( volatile uintptr_t * const val );
	uintptr_t	DecrementPtr( volatile uintptr_t * const val );
	uint32_t	Increment32( volatile uint32_t * const val );
	uint32_t	Decrement32( volatile uint32_t * const val );
	uint64_t	Increment64( volatile uint64_t * const val );
	uint64_t	Decrement64( volatile uint64_t * const val );
}

#endif