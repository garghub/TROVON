unsigned long gcd(unsigned long a, unsigned long b)
{
unsigned long r;
if (a < b)
swap(a, b);
while ((r = a % b) != 0) {
a = b;
b = r;
}
return b;
}
