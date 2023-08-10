/*
 * cs1.cpp
 *
 *  Created on: Sept 26, 2021
 *      Author: betten
 */


// performs a sweep over all valid surfaces F_{a,b,c,d} for a given q.


#include "orbiter.h"

using namespace std;
using namespace orbiter;
using namespace orbiter::layer5_applications;


int main()
{
	int verbose_level = 2;
	int q = 7;
	int n = 3;
	int f_use_projectivity_subgroup = false;
	const char *sweep_4_fname_text = "sweep4";
	const char *equation_name_of_formula = "F_abcd";
	const char *equation_name_of_formula_tex = "\\DF_{a,b,c,d}\\D";
	const char *equation_managed_variables = "X0,X1,X2,X3";
	const char *equation_text = "-(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*(b - d)*X0*X0*X2 "
			"+ (a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*(a + b - c - d)*X0*X1*X2 "
			"+ (a*a*c - a*a*d - a*c*c + b*c*c + a*d - b*c)*(b - d)*X0*X1*X3 "
			"- (a*d - b*c)*(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*X0*X2*X2 "
			"- (a*a*c*d - a*b*c*c - a*a*d + a*b*d + b*c*c - b*c*d)*(b - d)*X0*X2*X3 "
			"- (a - c)*(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*X1*X1*X2 "
			"- (a - c)*(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*X1*X1*X3 "
			"+ (a*d - b*c)*(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*X1*X2*X2 "
			"+ ((1+1)*a*a*b*c*d - a*a*b*d*d - (1+1)*a*a*c*d*d "
				"- (1+1)*a*b*b*c*c + a*b*b*c*d + (1+1)*a*b*c*c*d "
				"+ a*b*c*d*d - b*b*c*c*d - a*a*b*c + a*a*c*d + a*a*d*d + a*b*b*c + a*b*c*c "
				"- (1+1+1+1)*a*b*c*d - a*c*c*d + a*c*d*d + b*b*c*c)*X1*X2*X3 "
			"+ c*a*(a*d - b*c - a + b + c - d)*(b - d)*X1*X3*X3";
	const char *equation_parameters = "a=2,b=3,c=4,d=5";
	const char *equation_parameters_tex = "\\Da=2,b=3,c=4,d=5\\D";


	int f_v = (verbose_level >= 1);


	field_theory::finite_field my_F;
	projective_geometry::projective_space_with_action_description *Projective_space_with_action_description;
	projective_geometry::projective_space_with_action *PA;

	
	// create finite field of order q:

	my_F.finite_field_init_small_order(q,
			false /* f_without_tables */,
			true /* f_compute_related_fields */,
			0 /*verbose_level*/);


	// create projective space with group:

	int f_semilinear;
	number_theory::number_theory_domain NT;


	if (NT.is_prime(my_F.q)) {
		f_semilinear = false;
	}
	else {
		f_semilinear = true;
	}


	Projective_space_with_action_description =
			NEW_OBJECT(projective_geometry::projective_space_with_action_description);

	Projective_space_with_action_description->n = n;
	Projective_space_with_action_description->F = &my_F;
	Projective_space_with_action_description->f_use_projectivity_subgroup =
			f_use_projectivity_subgroup;

	if (Projective_space_with_action_description->f_use_projectivity_subgroup) {
		f_semilinear = false;
	}


	PA = NEW_OBJECT(projective_geometry::projective_space_with_action);

	if (f_v) {
		cout << "cs1 before PA->init" << endl;
	}
	PA->init(Projective_space_with_action_description->F,
			Projective_space_with_action_description->n,
			f_semilinear,
			true /*f_init_incidence_structure*/,
			0 /* verbose_level */);
	if (f_v) {
		cout << "cs1 after PA->init" << endl;
	}


	// create description of a cubic surface:

	applications_in_algebraic_geometry::cubic_surfaces_in_general::surface_create_description *surface_description;

	surface_description = NEW_OBJECT(applications_in_algebraic_geometry::cubic_surfaces_in_general::surface_create_description);



	surface_description->f_space_pointer;
	surface_description->space_pointer = PA;


	surface_description->f_by_equation = true;
	surface_description->equation_name_of_formula.assign(equation_name_of_formula);
	surface_description->equation_name_of_formula_tex.assign(equation_name_of_formula_tex);
	surface_description->equation_managed_variables.assign(equation_managed_variables);
	surface_description->equation_text.assign(equation_text);
	surface_description->equation_parameters.assign(equation_parameters);
	surface_description->equation_parameters_tex.assign(equation_parameters_tex);


	string sweep_4_fname;

	sweep_4_fname.assign(sweep_4_fname_text);




	applications_in_algebraic_geometry::cubic_surfaces_in_general::surface_create_description *Surface_Descr;

	Surface_Descr = surface_description;

	field_theory::finite_field *F;

	F = PA->F;


	int a, b, c, d;
	int m;

	if (f_v) {
		cout << "cs1 sweep_4_27" << endl;
	}


	m = F->negate(1);

	vector<vector<long int>> Properties;
	vector<vector<long int>> Points;


	for (a = 0; a < F->q; a++) {

		if (a == 0) {
			continue;
		}

		if (a == 1) {
			continue;
		}


		for (b = 0; b < F->q; b++) {

			if (b == 0) {
				continue;
			}

			if (b == 1) {
				continue;
			}

			if (b == a) {
				continue;
			}

			for (c = 0; c < F->q; c++) {

				if (c == 0) {
					continue;
				}

				if (c == 1) {
					continue;
				}
				if (c == a) {
					continue;
				}

				for (d = 0; d < F->q; d++) {


					if (d == 0) {
						continue;
					}

					if (d == 1) {
						continue;
					}

					if (d == b) {
						continue;
					}
					if (d == c) {
						continue;
					}

					cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;

					int delta, epsilon, gamma;

					delta = F->add(F->mult(a, d), F->negate(F->mult(b, c)));
					epsilon = F->add6(
							F->mult3(a, b, c),
							F->mult4(m, a, b, d),
							F->mult4(m, a, c, d),
							F->mult3(b, c, d),
							F->mult(a, d),
							F->mult3(m, b, c)
							);
					gamma = F->add6(
							F->mult(a, d),
							F->mult3(m, b, c),
							F->mult(m, a),
							b,
							c,
							F->mult(m, d)
							);

					if (delta == 0) {
						continue;
					}
					if (epsilon == 0) {
						continue;
					}
					if (gamma == 0) {
						continue;
					}


					char str[1000];

					sprintf(str, "a=%d,b=%d,c=%d,d=%d", a, b, c, d);


					Surface_Descr->equation_parameters.assign(str);


					// create the cubic surface associated with the parameters a,b,c,d:

					applications_in_algebraic_geometry::cubic_surfaces_in_general::surface_create *SC;
					SC = NEW_OBJECT(applications_in_algebraic_geometry::cubic_surfaces_in_general::surface_create);

					if (f_v) {
						cout << "cs1 before SC->init" << endl;
					}
					SC->init(Surface_Descr, verbose_level);
					if (f_v) {
						cout << "cs1 after SC->init" << endl;
					}





#if 0
					if (SC->SO->nb_lines != 15) {
						continue;
					}
					if (SC->SO->SOP->nb_singular_pts) {
						continue;
					}
#endif


					vector<long int> Props;
					vector<long int> Pts;

					Props.push_back(a);
					Props.push_back(b);
					Props.push_back(c);
					Props.push_back(d);
					Props.push_back(delta);
					Props.push_back(epsilon);
					Props.push_back(gamma);
					Props.push_back(SC->SO->nb_lines);
					Props.push_back(SC->SO->nb_pts);
					Props.push_back(SC->SO->SOP->nb_singular_pts);
					Props.push_back(SC->SO->SOP->nb_Eckardt_points);
					Props.push_back(SC->SO->SOP->nb_Double_points);
					Props.push_back(SC->SO->SOP->nb_Single_points);
					Props.push_back(SC->SO->SOP->nb_pts_not_on_lines);
					Props.push_back(SC->SO->SOP->nb_Hesse_planes);
					Props.push_back(SC->SO->SOP->nb_axes);
					Properties.push_back(Props);

					int i;
					for (i = 0; i < SC->SO->nb_pts; i++) {
						Pts.push_back(SC->SO->Pts[i]);
					}
					Points.push_back(Pts);

					FREE_OBJECT(SC);

				} // d

			} // c

		} // b

	} // a


	long int *T;
	int i, j, N;

	N = Properties.size();

	T = NEW_lint(N * 16);
	for (i = 0; i < N; i++) {
		for (j = 0; j < 16; j++) {
			T[i * 16 + j] = Properties[i][j];
		}
	}
	orbiter_kernel_system::file_io Fio;
	std::string fname;

	fname = Surface_Descr->equation_name_of_formula + "_q" + std::to_string(F->q) + "_sweep_4_27.txt";

	Fio.Csv_file_support->lint_matrix_write_csv(fname, T, N, 16);
	cout << "Written file " << fname << " of size " << Fio.file_size(fname) << endl;


	fname = Surface_Descr->equation_name_of_formula + "_q" + std::to_string(F->q) + "_points.txt";


	{
		ofstream ost(fname);

		for (i = 0; i < N; i++) {
			long int sz = Points[i].size();
			ost << sz;
			for (j = 0; j < sz; j++) {
				ost << " " << Points[i][j];
			}
			ost << endl;
		}
		ost << "-1" << endl;

	}
	cout << "Written file " << fname << " of size " << Fio.file_size(fname) << endl;




	FREE_lint(T);

	if (f_v) {
		cout << "cs1 sweep_4_27 done" << endl;
	}




}
