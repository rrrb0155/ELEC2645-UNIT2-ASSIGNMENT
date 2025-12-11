#include <stdio.h>
#include <math.h>
#include "functions.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// menu

void show_main_menu(void)
{
    printf("========================================\n");

    
    printf("        Engineering Calculator       \n");


    printf("========================================\n");


    printf("1) Engineering calculations\n");

    printf("2) Unit conversions\n");

    printf("3) About / Help\n");

    printf("0) Exit\n");
}

void handle_main_menu_choice(int choice)
{
    switch (choice) {
    case 1: {
        int sub = -1;
        while (1) {
            show_engineering_menu();
            sub = get_int("Enter your choice: ");
            if (sub == 0) break;
            handle_engineering_choice(sub);
            printf("\n");
        }
        break;
    }
    case 2: {
        int sub = -1;
        while (1) {
            show_conversion_menu();
            sub = get_int("Enter your choice: ");
            if (sub == 0) break;
            handle_conversion_choice(sub);
            printf("\n");
        }
        break;
    }
    case 3:
        show_about();
        break;
    case 0:
        //handled in main code
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }
}

// engineering menu 

void show_engineering_menu(void)
{
    printf("\n--- Engineering Calculations ---\n");
    printf("1) Electrical engineering functions\n");
    printf("2) Mechanical engineering functions\n");
    printf("3) Scientific calculator\n");
    printf("0) Back to main menu\n");
}

void handle_engineering_choice(int choice)
{
    int sub;
    switch (choice) {
    case 1: //electrical
        while (1) {
            show_electrical_menu();
            sub = get_int("Enter your choice: ");
            if (sub == 0) break;
            handle_electrical_choice(sub);
            printf("\n");
        }
        break;

    case 2: //mechanical 
        while (1) {
            show_mechanical_menu();
            sub = get_int("Enter your choice: ");
            if (sub == 0) break;
            handle_mechanical_choice(sub);
            printf("\n");
        }
        break;

    case 3: //scientific
        while (1) {
            show_scientific_menu();
            sub = get_int("Enter your choice: ");
            if (sub == 0) break;
            handle_scientific_choice(sub);
            printf("\n");
        }
        break;

    default:
        printf("Invalid engineering option.\n");
    }
}

//electrical engineering functions

void show_electrical_menu(void)
{
    printf("\n--- Electrical Engineering ---\n");
    printf("1) Ohm's Law (V, I, R)\n");
    printf("2) Power in resistor\n");
    printf("3) Parallel resistors (2 resistors)\n");
    printf("0) Back\n");
}

void handle_electrical_choice(int choice)
{
    switch (choice) {
    case 1: calc_ohms_law();           break;
    case 2: calc_power_resistor();     break;
    case 3: calc_parallel_resistors(); break;
    default: printf("Invalid electrical option.\n");
    }
}

//mechanical engineering functions

void show_mechanical_menu(void)
{
    printf("\n--- Mechanical Engineering ---\n");
    printf("1) Force   (F = m * a)\n");
    printf("2) Torque  (τ = r * F)\n");
    printf("3) Stress  (σ = F / A)\n");
    printf("4) Strain  (ε = ΔL / L)\n");
    printf("5) Moment of inertia (I = (b*h^3)/12 for a rectangle)\n");
    printf("0) Back\n");
}

void handle_mechanical_choice(int choice)
{
    switch (choice) {
    case 1: calc_force();             break;
    case 2: calc_torque();            break;
    case 3: calc_stress();            break;
    case 4: calc_strain();            break;
    case 5: calc_moment_of_inertia(); break;
    default: printf("Invalid mechanical option.\n");
    }
}

//scientific calculator functions

void show_scientific_menu(void)
{
    printf("\n--- Scientific Calculator ---\n");
    printf("1) Basic arithmetic (+, -, *, /)\n");
    printf("2) Trigonometry (sin, cos in degrees)\n");
    printf("3) Logs and exponentials (log10, ln, exp)\n");
    printf("4) Factorial (n!)\n");
    printf("0) Back\n");
}

void handle_scientific_choice(int choice)
{
    switch (choice) {
    case 1: sci_basic_arithmetic();     break;
    case 2: sci_trig_functions();       break;
    case 3: sci_logs_exponentials();    break;
    case 4: sci_factorial();            break;
    default: printf("Invalid scientific option.\n");
    }
}

//conversion menu

void show_conversion_menu(void)
{
    printf("\n--- Unit Conversions ---\n");
    printf("1) Volts  ↔ millivolts\n");
    printf("2) Ohms   ↔ kilo-ohms\n");
    printf("3) Temperature (°C, °F, K)\n");
    printf("4) Length (mm, cm, m, km)\n");
    printf("5) Pressure (Pa, kPa, bar)\n");
    printf("6) Energy (J, kJ)\n");
    printf("7) Frequency (Hz, kHz, MHz)\n");
    printf("0) Back to main menu\n");
}

void handle_conversion_choice(int choice)
{
    switch (choice) {
    case 1: conv_volts_millivolts(); break;
    case 2: conv_ohms_kohms();       break;
    case 3: conv_temperature();      break;
    case 4: conv_length_metric();    break;
    case 5: conv_pressure();         break;
    case 6: conv_energy();           break;
    case 7: conv_frequency();        break;
    default: printf("Invalid conversion option.\n");
    }
}

//input helpers

double get_double(const char *prompt)
{
    double x;
    printf("%s", prompt);
    scanf("%lf", &x);
    return x;
}

int get_int(const char *prompt)
{
    int x;
    printf("%s", prompt);
    scanf("%d", &x);
    return x;
}

//electrical calculations

void calc_ohms_law(void)
{
    printf("\nOhm's Law: V = I * R\n");
    printf("1) Voltage (V)\n");
    printf("2) Current (I)\n");
    printf("3) Resistance (R)\n");

    int choice = get_int("Enter choice: ");
    double V, I, R;

    if (choice == 1) {
        I = get_double("Enter current I (A): ");
        R = get_double("Enter resistance R (ohms): ");
        V = I * R;
        printf("Using V = I * R\n");
        printf("Result: V = %.3f V\n", V);
    } else if (choice == 2) {
        V = get_double("Enter voltage V (V): ");
        R = get_double("Enter resistance R (ohms): ");
        I = V / R;
        printf("Using I = V / R\n");
        printf("Result: I = %.3f A\n", I);
    } else if (choice == 3) {
        V = get_double("Enter voltage V (V): ");
        I = get_double("Enter current I (A): ");
        R = V / I;
        printf("Using R = V / I\n");
        printf("Result: R = %.3f ohms\n", R);
    } else {
        printf("Invalid choice in Ohm's Law.\n");
    }
}

void calc_power_resistor(void)
{
    printf("\nPower in resistor: P = V * I or P = V^2 / R\n");
    printf("1) Use V and I\n");
    printf("2) Use V and R\n");

    int choice = get_int("Enter choice: ");
    double P, V, I, R;

    if (choice == 1) {
        V = get_double("Enter voltage V (V): ");
        I = get_double("Enter current I (A): ");
        P = V * I;
        printf("Using P = V * I\n");
        printf("Result: P = %.3f W\n", P);
    } else if (choice == 2) {
        V = get_double("Enter voltage V (V): ");
        R = get_double("Enter resistance R (ohms): ");
        P = (V * V) / R;
        printf("Using P = V^2 / R\n");
        printf("Result: P = %.3f W\n", P);
    } else {
        printf("Invalid choice in power calculator.\n");
    }
}

void calc_parallel_resistors(void)
{
    printf("\nParallel resistors: 1/R_eq = 1/R1 + 1/R2\n");
    double R1 = get_double("Enter R1 (ohms): ");
    double R2 = get_double("Enter R2 (ohms): ");

    if (R1 == 0 || R2 == 0) {
        printf("Resistance cannot be zero.\n");
        return;
    }

    double Req = 1.0 / (1.0 / R1 + 1.0 / R2);
    printf("Using 1/R_eq = 1/R1 + 1/R2\n");
    printf("Result: R_eq = %.3f ohms\n", Req);
}

//mechanical engineering calculations

void calc_force(void)
{
    printf("\nForce: F = m * a\n");
    double m = get_double("Enter mass m (kg): ");
    double a = get_double("Enter acceleration a (m/s^2): ");
    double F = m * a;
    printf("Result: F = %.3f N\n", F);
}

void calc_torque(void)
{
    printf("\nTorque: τ = r * F\n");
    double r = get_double("Enter moment arm r (m): ");
    double F = get_double("Enter force F (N): ");
    double T = r * F;
    printf("Result: τ = %.3f N·m\n", T);
}

void calc_stress(void)
{
    printf("\nStress: σ = F / A\n");
    double F = get_double("Enter force F (N): ");
    double A = get_double("Enter area A (m^2): ");

    if (A == 0) {
        printf("Area cannot be zero.\n");
        return;
    }
    double sigma = F / A;
    printf("Result: σ = %.3f Pa\n", sigma);
}

void calc_strain(void)
{
    printf("\nStrain: ε = ΔL / L\n");
    double dL = get_double("Enter change in length ΔL (m): ");
    double L  = get_double("Enter original length L (m): ");

    if (L == 0) {
        printf("Original length cannot be zero.\n");
        return;
    }
    double eps = dL / L;
    printf("Result: ε = %.6f (dimensionless)\n", eps);
}

void calc_moment_of_inertia(void)
{
    printf("\nMoment of inertia for rectangular section: I = (b*h^3)/12\n");
    double b = get_double("Enter width b (m): ");
    double h = get_double("Enter height h (m): ");
    double I = (b * h * h * h) / 12.0;
    printf("Result: I = %.6e m^4\n", I);
}

//scientific calculator formulas

void sci_basic_arithmetic(void)
{
    printf("\nBasic arithmetic\n");
    printf("1) Addition\n");
    printf("2) Subtraction\n");
    printf("3) Multiplication\n");
    printf("4) Division\n");

    int choice = get_int("Enter choice: ");
    double a = get_double("Enter first number: ");
    double b = get_double("Enter second number: ");
    double result;

    switch (choice) {
    case 1: result = a + b; break;
    case 2: result = a - b; break;
    case 3: result = a * b; break;
    case 4:
        if (b == 0) {
            printf("Cannot divide by zero.\n");
            return;
        }
        result = a / b;
        break;
    default:
        printf("Invalid arithmetic option.\n");
        return;
    }

    printf("Result = %.6f\n", result);
}

void sci_trig_functions(void)
{
    printf("\nTrigonometry (angles in degrees)\n");
    printf("1) sin\n");
    printf("2) cos\n");

    int choice = get_int("Enter choice: ");
    double deg = get_double("Enter angle (degrees): ");
    double rad = deg * (M_PI / 180.0);
    double result;

    if (choice == 1) {
        result = sin(rad);
        printf("sin(%.3f°) = %.6f\n", deg, result);
    } else if (choice == 2) {
        result = cos(rad);
        printf("cos(%.3f°) = %.6f\n", deg, result);
    } else {
        printf("Invalid trig option.\n");
    }
}

void sci_logs_exponentials(void)
{
    printf("\nLogs and exponentials\n");
    printf("1) log10(x)\n");
    printf("2) natural log ln(x)\n");
    printf("3) exp(x)\n");

    int choice = get_int("Enter choice: ");
    double x = get_double("Enter x: ");

    if (choice == 1) {
        if (x <= 0) { printf("x must be > 0 for log10.\n"); return; }
        printf("log10(%.6f) = %.6f\n", x, log10(x));
    } else if (choice == 2) {
        if (x <= 0) { printf("x must be > 0 for ln.\n"); return; }
        printf("ln(%.6f) = %.6f\n", x, log(x));
    } else if (choice == 3) {
        printf("exp(%.6f) = %.6f\n", x, exp(x));
    } else {
        printf("Invalid logs/exp option.\n");
    }
}

void sci_factorial(void)
{
    printf("\nFactorial n! (0 <= n <= 20)\n");
    int n = get_int("Enter integer n: ");

    if (n < 0 || n > 20) {
        printf("n must be between 0 and 20.\n");
        return;
    }

    unsigned long long fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= (unsigned long long)i;
    }
    printf("%d! = %llu\n", n, fact);
}

//unit conversion formulas

void conv_volts_millivolts(void)
{
    printf("\nVolts ↔ millivolts (1 V = 1000 mV)\n");
    printf("1) V → mV\n");
    printf("2) mV → V\n");
    int choice = get_int("Enter choice: ");

    if (choice == 1) {
        double V = get_double("Enter voltage (V): ");
        printf("Using mV = V × 1000\n");
        printf("Result: %.3f V = %.3f mV\n", V, V * 1000.0);
    } else if (choice == 2) {
        double mV = get_double("Enter voltage (mV): ");
        printf("Using V = mV / 1000\n");
        printf("Result: %.3f mV = %.3f V\n", mV, mV / 1000.0);
    } else {
        printf("Invalid choice in V/mV converter.\n");
    }
}

void conv_ohms_kohms(void)
{
    printf("\nOhms ↔ kilo-ohms (1 kΩ = 1000 Ω)\n");
    printf("1) Ω → kΩ\n");
    printf("2) kΩ → Ω\n");
    int choice = get_int("Enter choice: ");

    if (choice == 1) {
        double R = get_double("Enter resistance (Ω): ");
        printf("Using kΩ = Ω / 1000\n");
        printf("Result: %.3f Ω = %.3f kΩ\n", R, R / 1000.0);
    } else if (choice == 2) {
        double kR = get_double("Enter resistance (kΩ): ");
        printf("Using Ω = kΩ × 1000\n");
        printf("Result: %.3f kΩ = %.3f Ω\n", kR, kR * 1000.0);
    } else {
        printf("Invalid choice in Ω/kΩ converter.\n");
    }
}

void conv_temperature(void)
{
    printf("\nTemperature (°C, °F, K)\n");
    printf("1) °C → K\n");
    printf("2) K  → °C\n");
    printf("3) °C → °F\n");
    printf("4) °F → °C\n");
    int choice = get_int("Enter choice: ");

    double T, result;

    switch (choice) {
    case 1: /* C -> K */
        T = get_double("Enter temperature (°C): ");
        result = T + 273.15;
        printf("K = °C + 273.15\n");
        printf("Result: %.2f °C = %.2f K\n", T, result);
        break;
    case 2: /* K -> C */
        T = get_double("Enter temperature (K): ");
        result = T - 273.15;
        printf("°C = K − 273.15\n");
        printf("Result: %.2f K = %.2f °C\n", T, result);
        break;
    case 3: /* C -> F */
        T = get_double("Enter temperature (°C): ");
        result = (T * 9.0 / 5.0) + 32.0;
        printf("°F = °C × 9/5 + 32\n");
        printf("Result: %.2f °C = %.2f °F\n", T, result);
        break;
    case 4: /* F -> C */
        T = get_double("Enter temperature (°F): ");
        result = (T - 32.0) * 5.0 / 9.0;
        printf("°C = (°F − 32) × 5/9\n");
        printf("Result: %.2f °F = %.2f °C\n", T, result);
        break;
    default:
        printf("Invalid temperature option.\n");
    }
}

void conv_length_metric(void)
{
    printf("\nLength (mm, cm, m, km)\n");
    printf("1) mm → cm\n");
    printf("2) cm → mm\n");
    printf("3) cm → m\n");
    printf("4) m  → cm\n");
    printf("5) m  → km\n");
    printf("6) km → m\n");
    int choice = get_int("Enter choice: ");

    double x, result;

    switch (choice) {
    case 1:
        x = get_double("Enter length (mm): ");
        result = x / 10.0;
        printf("Result: %.3f mm = %.3f cm\n", x, result);
        break;
    case 2:
        x = get_double("Enter length (cm): ");
        result = x * 10.0;
        printf("Result: %.3f cm = %.3f mm\n", x, result);
        break;
    case 3:
        x = get_double("Enter length (cm): ");
        result = x / 100.0;
        printf("Result: %.3f cm = %.3f m\n", x, result);
        break;
    case 4:
        x = get_double("Enter length (m): ");
        result = x * 100.0;
        printf("Result: %.3f m = %.3f cm\n", x, result);
        break;
    case 5:
        x = get_double("Enter length (m): ");
        result = x / 1000.0;
        printf("Result: %.3f m = %.3f km\n", x, result);
        break;
    case 6:
        x = get_double("Enter length (km): ");
        result = x * 1000.0;
        printf("Result: %.3f km = %.3f m\n", x, result);
        break;
    default:
        printf("Invalid length option.\n");
    }
}

void conv_pressure(void)
{
    printf("\nPressure (Pa, kPa, bar)\n");
    printf("1) Pa  → kPa\n");
    printf("2) kPa → Pa\n");
    printf("3) kPa → bar\n");
    printf("4) bar → kPa\n");
    int choice = get_int("Enter choice: ");

    double x, result;

    switch (choice) {
    case 1:
        x = get_double("Enter pressure (Pa): ");
        result = x / 1000.0;
        printf("Result: %.3f Pa = %.3f kPa\n", x, result);
        break;
    case 2:
        x = get_double("Enter pressure (kPa): ");
        result = x * 1000.0;
        printf("Result: %.3f kPa = %.3f Pa\n", x, result);
        break;
    case 3:
        x = get_double("Enter pressure (kPa): ");
        result = x / 100.0;      /* 1 bar = 100 kPa */
        printf("Result: %.3f kPa = %.3f bar\n", x, result);
        break;
    case 4:
        x = get_double("Enter pressure (bar): ");
        result = x * 100.0;
        printf("Result: %.3f bar = %.3f kPa\n", x, result);
        break;
    default:
        printf("Invalid pressure option.\n");
    }
}

void conv_energy(void)
{
    printf("\nEnergy (J, kJ)\n");
    printf("1) J  → kJ\n");
    printf("2) kJ → J\n");
    int choice = get_int("Enter choice: ");

    double x, result;

    if (choice == 1) {
        x = get_double("Enter energy (J): ");
        result = x / 1000.0;
        printf("Result: %.3f J = %.3f kJ\n", x, result);
    } else if (choice == 2) {
        x = get_double("Enter energy (kJ): ");
        result = x * 1000.0;
        printf("Result: %.3f kJ = %.3f J\n", x, result);
    } else {
        printf("Invalid energy option.\n");
    }
}

void conv_frequency(void)
{
    printf("\nFrequency (Hz, kHz, MHz)\n");
    printf("1) Hz  → kHz\n");
    printf("2) kHz → Hz\n");
    printf("3) kHz → MHz\n");
    printf("4) MHz → kHz\n");
    int choice = get_int("Enter choice: ");

    double x, result;

    switch (choice) {
    case 1:
        x = get_double("Enter frequency (Hz): ");
        result = x / 1000.0;
        printf("Result: %.3f Hz = %.3f kHz\n", x, result);
        break;
    case 2:
        x = get_double("Enter frequency (kHz): ");
        result = x * 1000.0;
        printf("Result: %.3f kHz = %.3f Hz\n", x, result);
        break;
    case 3:
        x = get_double("Enter frequency (kHz): ");
        result = x / 1000.0;
        printf("Result: %.3f kHz = %.3f MHz\n", x, result);
        break;
    case 4:
        x = get_double("Enter frequency (MHz): ");
        result = x * 1000.0;
        printf("Result: %.3f MHz = %.3f kHz\n", x, result);
        break;
    default:
        printf("Invalid frequency option.\n");
    }
}

//about this program 

void show_about(void)
{
    printf("\nAbout this program:\n");
    printf("- Engineering calculator and unit converter\n");
    printf("- Demonstrates a menu-driven C command-line application\n");
    printf("- Includes electrical and mechanical formulas and scientific functions.\n");
    
}
