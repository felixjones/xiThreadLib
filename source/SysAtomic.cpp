#include "os.h" // Included first to fix _WIN64 define

#include "SysAtomic.h"

#if defined( __WIN_API__ )

	#include <Windows.h>

	#if defined( __X32__ )
		#define SYS_INC( X )	InterlockedIncrement( X )
		#define SYS_DEC( X )	InterlockedDecrement( X )
	#elif defined( __X64__ )
		#define SYS_INC( X )	InterlockedIncrement64( X )
		#define SYS_DEC( X )	InterlockedDecrement64( X )
	#endif

	#define SYS_INC32( X )	InterlockedIncrement( X )
	#define SYS_DEC32( X )	InterlockedDecrement( X )
	#define SYS_INC64( X )	InterlockedIncrement64( X )
	#define SYS_DEC64( X )	InterlockedDecrement64( X )

#elif defined( __OS_X__ )

	#include <libkern/OSAtomic.h>

	#define SYS_INC( X )	OSAtomicIncrement64( ( volatile int64_t * )X )
	#define SYS_DEC( X )	OSAtomicDecrement64( ( volatile int64_t * )X )

	#define SYS_INC32( X )	OSAtomicIncrement32( X )
	#define SYS_DEC32( X )	OSAtomicDecrement32( X )
	#define SYS_INC64( X )	OSAtomicIncrement64( X )
	#define SYS_DEC64( X )	OSAtomicDecrement64( X )

#endif

#if defined( __POSIX__ )

	inline uint64_t __rdtsc(){
		unsigned int lo, hi;
		__asm__ __volatile__ ( "rdtsc" : "=a" ( lo ), "=d" ( hi ) );
		
		return ( ( uint64_t )hi << 32 ) | lo;
	}

#elif defined( __WIN_API__ )

	#include <intrin.h>

#endif

uint64_t Sys::Tick() {
	return __rdtsc();
}

intptr_t Sys::IncrementPtr( volatile intptr_t * const val ) {
	return SYS_INC( val );
}

intptr_t Sys::DecrementPtr( volatile intptr_t * const val ) {
	return SYS_DEC( val );
}

int32_t Sys::Increment32( volatile int32_t * const val ) {
	return SYS_INC32( val );
}

int32_t Sys::Decrement32( volatile int32_t * const val ) {
	return SYS_DEC32( val );
}

int64_t Sys::Increment64( volatile int64_t * const val ) {
	return SYS_INC64( val );
}

int64_t Sys::Decrement64( volatile int64_t * const val ) {
	return SYS_DEC64( val );
}