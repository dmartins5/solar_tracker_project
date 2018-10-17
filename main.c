/* Drew Martins, Justin Bickford, Eric Keffer
 * September 21, 2018
 * ECE-388
 * Lab 1: Solar Tracker
 * RGS13 Motor Demo
 */

#include "rgs13.h"
#include "fs5103r.h"

int main()
{
	init_fs5103r_timer0();
	init_rgs13_timer1();

	while(1)
	{
		update_med_fs5103r_timer0();
		update_rgs13_timer1();
	}
	return 0;
}
