
#ifndef BASE_CONTRACT_H_INCLUDED_
#define BASE_CONTRACT_H_INCLUDED_

#include "FinLibException.h"
#include "VolatilityCube.h"
#include <string>
#include <memory>
#include <vector>

class BaseContract{
	
public:
	
	// for setting IR Swap contract info
	virtual void SetContractInfo(
		const std::string &effective_date, 
		const std::string &currency, 
		int fixed_or_float, 
		double notional_amount, 
		double contract_term, 
		double payment_period, 
		double fixed_rate, 
		double next_float_rate)
	{
		throw FinLibException("Bad argument for SetContractInfo");
	}
	
	// for setting European Swaption contract info
	virtual void SetContractInfo(
		const std::string &effective_date, 
		const std::string &currency, 
		int receiver_or_payer, 
		const std::string &option_maturity_date, 
		const std::string &underlying_swap_start_date, 
		double underlying_swap_notional_amount, 
		double underlying_swap_contract_term, 
		double underlying_swap_payment_period, 
		double strike_swap_rate)
	{
		throw FinLibException("Bad argument for SetContractInfo");
	}
	
	// for calculating IR Swap PV
	virtual double CalcPV(
		const std::string &valuation_date, 
		const std::vector<int> &floating_rate_term, 
		const std::vector<double> &floating_rate_value, 
		const std::vector<int> &discount_curve_term, 
		const std::vector<double> &discount_curve_value)
	{
		throw FinLibException("Bad argument for CalcPV");
	}
	
	// for calculating European Swaption PV
	virtual double CalcPV(
		const std::string &valuation_date, 
		const std::vector<int> &floating_rate_term, 
		const std::vector<double> &floating_rate_value, 
		const std::vector<int> &discount_curve_term, 
		const std::vector<double> &discount_curve_value, 
		const std::vector<VolatilityCube> &volatility_set, 
		int num_of_vol_strike_rate, 
		int num_of_vol_underlying_term_grid, 
		int num_of_vol_option_term_grid)
	{
		throw FinLibException("Bad argument for CalcPV");
	}
	
};


#endif

