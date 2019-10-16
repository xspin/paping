#include "standard.h"

class stats_c
{
	public:
		double	Minimum;
		double	Maximum;
		double	Total;
		double  Totalsq;
		double	Average();
		double	Std();

		int		Attempts;
		int		Connects;
		int		Failures;

		void	UpdateMaxMin(double value);
		int		GetStatisticsString(pcc_t stats);
};
