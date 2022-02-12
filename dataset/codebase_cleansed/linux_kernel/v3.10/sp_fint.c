ieee754sp ieee754sp_fint(int x)
{
unsigned xm;
int xe;
int xs;
CLEARCX;
if (x == 0)
return ieee754sp_zero(0);
if (x == 1 || x == -1)
return ieee754sp_one(x < 0);
if (x == 10 || x == -10)
return ieee754sp_ten(x < 0);
xs = (x < 0);
if (xs) {
if (x == (1 << 31))
xm = ((unsigned) 1 << 31);
else
xm = -x;
} else {
xm = x;
}
xe = SP_MBITS + 3;
if (xm >> (SP_MBITS + 1 + 3)) {
while (xm >> (SP_MBITS + 1 + 3)) {
SPXSRSX1();
}
} else {
while ((xm >> (SP_MBITS + 3)) == 0) {
xm <<= 1;
xe--;
}
}
SPNORMRET1(xs, xe, xm, "fint", x);
}
ieee754sp ieee754sp_funs(unsigned int u)
{
if ((int) u < 0)
return ieee754sp_add(ieee754sp_1e31(),
ieee754sp_fint(u & ~(1 << 31)));
return ieee754sp_fint(u);
}
