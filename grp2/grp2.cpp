/*
 * grp2.cpp
 *
 *  Created on: Sept 26, 2021
 *      Author: betten
 */




#include "orbiter.h"

using namespace std;
using namespace orbiter;


int main()
{
	int verbose_level = 2;

	int degree = 4;

	action *A;

	A = NEW_OBJECT(action);

	A->init_symmetric_group(degree, verbose_level);

	A->Strong_gens->print_generators_in_latex_individually(cout);
	A->Strong_gens->print_generators_in_source_code();
	A->print_base();
	A->print_info();


	vector_ge *vec;
	int i;
	int *Elt;
	int *data;

	data = NEW_int(A->make_element_size);
	A->all_elements(vec, verbose_level);


	for (i = 0; i < vec->len; i++) {
		Elt = vec->ith(i);

		cout << i << " : ";
		A->element_print(Elt, cout);
		cout << " : ";

		A->element_code_for_make_element(Elt, data);
		//A->element_print(Elt, cout);
		Orbiter->Int_vec.print(cout, data, A->make_element_size);
		cout << endl;
	}
}
