/* Drew Martins, Justin Bickford, Eric Keffer
 * September 21, 2018
 * ECE-388
 * Lab 1: Solar Tracker
 * RGS13 Motor Demo
 */

#include "rgs13.h"

int main()
{
	init_rgs13_timer0();

	while(1)
	{
		update_rgs13_timer0();
	}
	return 0;
}
