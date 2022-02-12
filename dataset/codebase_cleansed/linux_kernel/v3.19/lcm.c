unsigned long lcm(unsigned long a, unsigned long b)
{
if (a && b)
return (a / gcd(a, b)) * b;
else
return 0;
}
