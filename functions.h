#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//menus
void show_main_menu(void);
void handle_main_menu_choice(int choice);

void show_engineering_menu(void);
void handle_engineering_choice(int choice);

void show_electrical_menu(void);
void handle_electrical_choice(int choice);

void show_mechanical_menu(void);
void handle_mechanical_choice(int choice);

void show_scientific_menu(void);
void handle_scientific_choice(int choice);

void show_conversion_menu(void);
void handle_conversion_choice(int choice);

void show_about(void);

// input helpers
int   get_int(const char *prompt);
double get_double(const char *prompt);

//ee functions
void calc_ohms_law(void);
void calc_power_resistor(void);
void calc_parallel_resistors(void);

//mech functions
void calc_force(void);
void calc_torque(void);
void calc_stress(void);
void calc_strain(void);
void calc_moment_of_inertia(void);

// scientfic calc functions
void sci_basic_arithmetic(void);
void sci_trig_functions(void);
void sci_logs_exponentials(void);
void sci_factorial(void);

// unit conversion functions
void conv_volts_millivolts(void);
void conv_ohms_kohms(void);

void conv_temperature(void);        /* C↔F↔K */
void conv_length_metric(void);      /* mm↔cm↔m↔km */
void conv_pressure(void);           /* Pa↔kPa↔bar */
void conv_energy(void);             /* J↔kJ */
void conv_frequency(void);          /* Hz↔kHz↔MHz */

#endif
