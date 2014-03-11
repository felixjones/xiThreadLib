#include "os.h" // Included first to fix _WIN64 define

#include "SysAtomic.h"

#if defined( __WIN_API__ )
	#include <Windows.h>

	#if defined( __X32__ )
		#define SYS_INC( X )	InterlockedIncrement( X )
		#define SYS_DEC( X )	InterlockedDecrement( X )
	#elif defined( __X64__ )
		#define SYS_INC( X )	InterlockedIncrement64( ( volatile int64_t * )X )
		#define SYS_DEC( X )	InterlockedDecrement64( ( volatile int64_t * )X )
	#endif

	#define SYS_INC32( X )	InterlockedIncrement( X )
	#define SYS_DEC32( X )	InterlockedDecrement( X )
	#define SYS_INC64( X )	InterlockedIncrement64( X )
	#define SYS_DEC64( X )	InterlockedDecrement64( X )
#endif

uintptr_t Sys::IncrementPtr( volatile uintptr_t * const val ) {
	return SYS_INC( val );
}

uintptr_t Sys::DecrementPtr( volatile uintptr_t * const val ) {
	return SYS_DEC( val );
}

uint32_t Sys::Increment32( volatile uint32_t * const val ) {
	return SYS_INC32( val );
}

uint32_t Sys::Decrement32( volatile uint32_t * const val ) {
	return SYS_DEC32( val );
}

uint64_t Sys::Increment64( volatile uint64_t * const val ) {
	return SYS_INC64( ( volatile int64_t * )val );
}

uint64_t Sys::Decrement64( volatile uint64_t * const val ) {
	return SYS_DEC64( ( volatile int64_t * )val );
}