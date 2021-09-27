/*
 * cs1.cpp
 *
 *  Created on: Sept 26, 2021
 *      Author: betten
 */




#include "orbiter.h"

using namespace std;
using namespace orbiter;
using namespace orbiter::top_level;


int main()
{
	int verbose_level = 2;
	int q = 7;
	int n = 3;
	int f_use_projectivity_subgroup = FALSE;
	const char *sweep_4_fname_text = "sweep4";
	const char *equation_name_of_formula = "F_abcd";
	const char *equation_name_of_formula_tex = "\\DF_{a,b,c,d}\\D";
	const char *equation_managed_variables = "X0,X1,X2,X3";
	const char *equation_text = "-(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*(b - d)*X0*X0*X2 + (a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*(a + b - c - d)*X0*X1*X2 + (a*a*c - a*a*d - a*c*c + b*c*c + a*d - b*c)*(b - d)*X0*X1*X3 - (a*d - b*c)*(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*X0*X2*X2 - (a*a*c*d - a*b*c*c - a*a*d + a*b*d + b*c*c - b*c*d)*(b - d)*X0*X2*X3 - (a - c)*(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*X1*X1*X2 - (a - c)*(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*X1*X1*X3 + (a*d - b*c)*(a*b*c - a*b*d - a*c*d + b*c*d + a*d - b*c)*X1*X2*X2 + ((1+1)*a*a*b*c*d - a*a*b*d*d - (1+1)*a*a*c*d*d - (1+1)*a*b*b*c*c + a*b*b*c*d + (1+1)*a*b*c*c*d + a*b*c*d*d - b*b*c*c*d - a*a*b*c + a*a*c*d + a*a*d*d + a*b*b*c + a*b*c*c - (1+1+1+1)*a*b*c*d - a*c*c*d + a*c*d*d + b*b*c*c)*X1*X2*X3 + c*a*(a*d - b*c - a + b + c - d)*(b - d)*X1*X3*X3";
	const char *equation_parameters = "a=2,b=3,c=4,d=5";
	const char *equation_parameters_tex = "\\Da=2,b=3,c=4,d=5\\D";


	int f_v = (verbose_level >= 1);

#if 0
	F_abcd_sweep_4_27_q7:
		$(ORBITER_PATH)orbiter.out -v 3 \
			-define F -finite_field -q 7 -end \
			-define P -projective_space 3 F -end \
			-with P -do \
			-projective_space_activity \
			-sweep_4_27 sweep_4_27_q7 -q 7 -by_equation "F_abcd" \
				"\DF_{a,b,c,d}\D" "X0,X1,X2,X3" \
				$(F_abcd_eqn) \
				"a=2,b=3,c=4,d=5" \
				"\Da=2,b=3,c=4,d=5\D" \
			-end \
			-end
#endif


	finite_field my_F;
	projective_space_with_action_description *Projective_space_with_action_description;
	projective_space_with_action *PA;

	
	// create finite field of order q:
	my_F.finite_field_init(q, FALSE /* f_without_tables */, 0);


	// the following code is taken from
	// orbiter/src/lib/top_level/interfaces/symbol_definition.cpp

	int f_semilinear;
	number_theory_domain NT;


	if (NT.is_prime(my_F.q)) {
		f_semilinear = FALSE;
	}
	else {
		f_semilinear = TRUE;
	}


	Projective_space_with_action_description = NEW_OBJECT(projective_space_with_action_description);

#if 0
	int n;
	std::string input_q;
	finite_field *F;

	int f_use_projectivity_subgroup;
#endif

	Projective_space_with_action_description->n = n;
	Projective_space_with_action_description->F = &my_F;
	Projective_space_with_action_description->f_use_projectivity_subgroup = f_use_projectivity_subgroup;

	if (Projective_space_with_action_description->f_use_projectivity_subgroup) {
		f_semilinear = FALSE;
	}


	PA = NEW_OBJECT(projective_space_with_action);

	if (f_v) {
		cout << "cs1 before PA->init" << endl;
	}
	PA->init(Projective_space_with_action_description->F,
			Projective_space_with_action_description->n,
			f_semilinear,
			TRUE /*f_init_incidence_structure*/,
			0 /* verbose_level */);
	if (f_v) {
		cout << "cs1 after PA->init" << endl;
	}


	surface_create_description *surface_description;

	surface_description = NEW_OBJECT(surface_create_description);

#if 0
	// surface_create_description:

	int f_q;
	int q;

	int f_label_txt;
	std::string label_txt;

	int f_label_tex;
	std::string label_tex;

	int f_label_for_summary;
	std::string label_for_summary;

	int f_catalogue;
	int iso;
	int f_by_coefficients;
	std::string coefficients_text;

	int f_by_rank;
	std::string rank_text;
	int rank_defining_q;

	int f_family_Eckardt;
	int family_Eckardt_a;
	int family_Eckardt_b;

	int f_family_G13;
	int family_G13_a;

	int f_family_F13;
	int family_F13_a;

	int f_family_bes;
	int family_bes_a;
	int family_bes_c;

	int f_family_general_abcd;
	int family_general_abcd_a;
	int family_general_abcd_b;
	int family_general_abcd_c;
	int family_general_abcd_d;

	int f_arc_lifting;
	std::string arc_lifting_text;
	std::string arc_lifting_two_lines_text;

	int f_arc_lifting_with_two_lines;
	std::vector<std::string> select_double_six_string;

	int f_Cayley_form;
	int Cayley_form_k;
	int Cayley_form_l;
	int Cayley_form_m;
	int Cayley_form_n;


	int f_by_equation;
	std::string equation_name_of_formula;
	std::string equation_name_of_formula_tex;
	std::string equation_managed_variables;
	std::string equation_text;
	std::string equation_parameters;
	std::string equation_parameters_tex;


	int f_by_double_six;
	std::string by_double_six_label;
	std::string by_double_six_label_tex;
	std::string by_double_six_text;

	int f_by_skew_hexagon;
	std::string by_skew_hexagon_label;
	std::string by_skew_hexagon_label_tex;

	int f_override_group;
	std::string override_group_order;
	int override_group_nb_gens;
	std::string override_group_gens;

	std::vector<std::string> transform_coeffs;
	std::vector<int> f_inverse_transform;
#endif



	surface_description->f_q = TRUE;
	surface_description->q = PA->F->q;

	surface_description->f_by_equation = TRUE;
	surface_description->equation_name_of_formula.assign(equation_name_of_formula);
	surface_description->equation_name_of_formula_tex.assign(equation_name_of_formula_tex);
	surface_description->equation_managed_variables.assign(equation_managed_variables);
	surface_description->equation_text.assign(equation_text);
	surface_description->equation_parameters.assign(equation_parameters);
	surface_description->equation_parameters_tex.assign(equation_parameters_tex);


	string sweep_4_fname;

	sweep_4_fname.assign(sweep_4_fname_text);




	surface_with_action *Surf_A;

	PA->setup_surface_with_action(
			Surf_A,
			verbose_level);


	surface_create_description *Surface_Descr;

	Surface_Descr = surface_description;

	finite_field *F;

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

					//int f_by_equation;
					//std::string equation_name_of_formula;
					//std::string equation_name_of_formula_tex;
					//std::string equation_managed_variables;
					//std::string equation_text;
					//std::string equation_parameters;
					//std::string equation_parameters_tex;


					surface_create *SC;
					SC = NEW_OBJECT(surface_create);

					if (f_v) {
						cout << "cs1 before SC->init" << endl;
					}
					SC->init(Surface_Descr, Surf_A, verbose_level);
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
	file_io Fio;
	std::string fname;
	char str[1000];

	sprintf(str, "_q%d", F->q);
	fname.assign(Surface_Descr->equation_name_of_formula);
	fname.append(str);
	fname.append("_sweep_4_27.csv");

	Fio.lint_matrix_write_csv(fname, T, N, 16);
	cout << "Written file " << fname << " of size " << Fio.file_size(fname) << endl;


	fname.assign(Surface_Descr->equation_name_of_formula);
	fname.append(str);
	fname.append("_points.txt");


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
