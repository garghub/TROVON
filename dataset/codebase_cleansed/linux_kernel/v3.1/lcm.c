unsigned long lcm(unsigned long a, unsigned long b)
{
if (a && b)
return (a * b) / gcd(a, b);
else if (b)
return b;
return a;
}
