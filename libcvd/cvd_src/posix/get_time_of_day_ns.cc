/*                       
	This file is part of the CVD Library.

	Copyright (C) 2005 The Authors

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 
    51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "cvd/timer.h"
#include <inttypes.h>
#include <time.h>  //clock_gettime
#include <sys/time.h>  //timeval
#include <mach/mach.h>
#include <mach/mach_time.h>

namespace CVD {

long long get_time_of_day_ns()
{
    
    static mach_timebase_info_data_t sTimebaseInfo;
	uint64_t end = mach_absolute_time();

	if (sTimebaseInfo.denom == 0) {
        (void) mach_timebase_info(&sTimebaseInfo);
	}
    
	// return the elapsed time in billionths of a second
	return end * sTimebaseInfo.numer / sTimebaseInfo.denom;
}

}
