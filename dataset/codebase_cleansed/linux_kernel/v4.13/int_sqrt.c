unsigned long int_sqrt(unsigned long x)
{
unsigned long b, m, y = 0;
if (x <= 1)
return x;
m = 1UL << (BITS_PER_LONG - 2);
while (m != 0) {
b = y + m;
y >>= 1;
if (x >= b) {
x -= b;
y += m;
}
m >>= 2;
}
return y;
}
