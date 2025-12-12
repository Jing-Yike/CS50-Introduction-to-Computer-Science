#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // prompt the user for the change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    // Calculate how many quarters you should give customer
    // Subtract the value of those quarters from cents
    int quarters = calculate_quarters(cents);
    cents = cents - 25 * quarters;
    // Calculate how many dimes you should give customer
    // Subtract the value of those dimes from cents
    int dimes = calculate_dimes(cents);
    cents = cents - 10 * dimes;
    // Calculate how many nickels you should give customer
    // Subtract the value of those nickels from cents
    int nickels = calculate_nickels(cents);
    cents = cents - 5 * nickels;
    // Calculate how many pennies you should give customer
    // Subtract the value of those pennies from cents
    int pennies = calculate_pennies(cents);
    // Print that sum
    int sum = quarters + dimes + nickels + pennies;
    printf("%i\n", sum);
}

int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give customer
    int quarters;
    for (quarters = 0; cents >= 25; quarters++)
    {
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calculate how many dimes you should give customer
    int dimes;
    for (dimes = 0; cents >= 10; dimes++)
    {
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calculate how many nickels you should give customer
    int nickels;
    for (nickels = 0; cents >= 5; nickels++)
    {
        cents = cents - 10;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calculate how many pennies you should give customer
    int pennies;
    for (pennies = 0; cents >= 1; pennies++)
    {
        cents = cents - 1;
    }
    return pennies;
}
