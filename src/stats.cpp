#include "standard.h"

using namespace std;


double stats_c::Average()
{
	if (this->Connects == 0 ) {
		return 0;
	} else {
		return (this->Total / this->Connects); // Change Attempts to Connects for fixing wrong avg bug
	}
}


void stats_c::UpdateMaxMin(double value)
{
	if (this->Connects == 1) // Change Attempts to Connects for fixing zero min bug
	{
		this->Minimum	= value;
		this->Maximum	= value;

		return;
	}

	if (value < this->Minimum) this->Minimum = value;
	if (value > this->Maximum) this->Maximum = value;
}


int stats_c::GetStatisticsString(pcc_t str)
{
	int		length	= 0;
	pcc_t	format	= i18n_c::GetString(STRING_STATS);

	double	failPercent	= ((double)this->Failures / (double)this->Attempts) * 100;

	length = snprintf(NULL, 0, format, this->Attempts, this->Connects, this->Failures, failPercent, this->Minimum, this->Maximum, this->Average());
	if (str != NULL) sprintf((pc_t)str, format, this->Attempts, this->Connects, this->Failures, failPercent, this->Minimum, this->Maximum, this->Average());
	
	return length;
}
