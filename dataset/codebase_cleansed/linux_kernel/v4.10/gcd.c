unsigned long gcd(unsigned long a, unsigned long b)
{
unsigned long r = a | b;
if (!a || !b)
return r;
b >>= __ffs(b);
if (b == 1)
return r & -r;
for (;;) {
a >>= __ffs(a);
if (a == 1)
return r & -r;
if (a == b)
return a << __ffs(r);
if (a < b)
swap(a, b);
a -= b;
}
}
unsigned long gcd(unsigned long a, unsigned long b)
{
unsigned long r = a | b;
if (!a || !b)
return r;
r &= -r;
while (!(b & r))
b >>= 1;
if (b == r)
return r;
for (;;) {
while (!(a & r))
a >>= 1;
if (a == r)
return r;
if (a == b)
return a;
if (a < b)
swap(a, b);
a -= b;
a >>= 1;
if (a & r)
a += b;
a >>= 1;
}
}
