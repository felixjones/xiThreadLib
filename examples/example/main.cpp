#include <SysAtomic.h>
#include <stdio.h>

int main( int argc, char ** argv ) {
	
	printf( "%llu\n", Sys::Tick() );
	printf( "%llu\n", Sys::Tick() );
	
    return 0;
}
