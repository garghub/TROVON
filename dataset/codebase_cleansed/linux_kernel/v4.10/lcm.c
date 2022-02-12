unsigned long lcm(unsigned long a, unsigned long b)
{
if (a && b)
return (a / gcd(a, b)) * b;
else
return 0;
}
unsigned long lcm_not_zero(unsigned long a, unsigned long b)
{
unsigned long l = lcm(a, b);
if (l)
return l;
return (b ? : a);
}
