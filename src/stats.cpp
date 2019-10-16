#include "standard.h"
#include <cmath>
using namespace std;


double stats_c::Average()
{
	if (this->Connects == 0 ) {
		return 0;
	} else {
		return (this->Total / this->Connects); // Change Attempts to Connects for fixing wrong avg bug
	}
}

double stats_c::Std()
{
	if (this->Connects == 0 ) {
		return 0;
	} else {
		double avg = this->Total / this->Connects; 
		double avgsq = this->Totalsq / this->Connects; 
		return sqrt(avgsq-avg*avg);
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

	length = snprintf(NULL, 0, format, this->Attempts, this->Connects, this->Failures, failPercent, this->Minimum, this->Maximum, this->Average(), this->Std());
	if (str != NULL) sprintf((pc_t)str, format, this->Attempts, this->Connects, this->Failures, failPercent, this->Minimum, this->Maximum, this->Average(), this->Std());
	
	return length;
}
