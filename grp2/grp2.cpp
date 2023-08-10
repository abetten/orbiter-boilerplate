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

	actions::action *A;

	A = NEW_OBJECT(actions::action);

	A->Known_groups->init_symmetric_group(degree, false /* f_no_base */, verbose_level);

	A->Strong_gens->print_generators_in_latex_individually(cout);
	A->Strong_gens->print_generators_in_source_code();
	A->print_base();
	A->print_info();


	data_structures_groups::vector_ge *vec;
	int i;
	int *data;
	int *Elt;

	data = NEW_int(A->make_element_size);
	A->all_elements(vec, verbose_level);


	for (i = 0; i < vec->len; i++) {
		Elt = vec->ith(i);

		cout << i << " : ";
		A->Group_element->element_print(Elt, cout);
		cout << " : ";

		A->Group_element->element_code_for_make_element(Elt, data);
		//A->element_print(Elt, cout);
		Int_vec_print(cout, data, A->make_element_size);
		cout << endl;
	}

	string fname_csv;

	fname_csv = A->label + ".csv";

	A->all_elements_save_csv(fname_csv, verbose_level);


	FREE_OBJECT(vec);
	FREE_int(data);
}
