/*
 * ff1.cpp
 *
 *  Created on: Sept 26, 2021
 *      Author: betten
 */




#include "orbiter.h"

using namespace std;
using namespace orbiter;


int main()
{
	field_theory::finite_field F;
	
	F.finite_field_init_small_order(16,
			false /* f_without_tables */,
			true /* f_compute_related_fields */,
			0 /*verbose_level*/);

	cout << "8 x 15 = " << F.mult(8, 15) << endl;
}
