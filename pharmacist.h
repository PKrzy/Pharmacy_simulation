#pragma once
#include "client.h"
#include "mdatabase.h"
#include "File_dial_out.h"

struct chosen_medicine;

class Pharmacist
{
	int id = 0;
public:
	Pharmacist();
	Pharmacist(int id);
	std::vector<Medicine> choose_medicines(Client&, MDatabase&) const;
	std::vector<Medicine> choose_cheaper_replacements_and_replace(Client&, MDatabase&, Medicine) const;
	void print_receipt(Client, File_dial_out&) const;
	void print_invoide(Client, File_dial_out&) const;
	int get_id() const;
	void set_id(int id);
	friend std::ostream& operator<<(std::ostream& os, const Pharmacist& pharmacist);
};

std::ostream& operator<<(std::ostream& os, const Pharmacist& pharmacist);

struct chosen_medicine
{
	std::string chosen_med_name;
	int num_of_symptoms = 1;
	std::vector<std::string> chosen_med_symptoms;
	double taxed_price = 0.0;
	bool prescripted = false;
};