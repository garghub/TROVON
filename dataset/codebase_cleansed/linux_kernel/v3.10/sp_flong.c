ieee754sp ieee754sp_flong(s64 x)
{
u64 xm;
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
if (x == (1ULL << 63))
xm = (1ULL << 63);
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
SPNORMRET1(xs, xe, xm, "sp_flong", x);
}
ieee754sp ieee754sp_fulong(u64 u)
{
if ((s64) u < 0)
return ieee754sp_add(ieee754sp_1e63(),
ieee754sp_flong(u & ~(1ULL << 63)));
return ieee754sp_flong(u);
}
