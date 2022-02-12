union ieee754sp ieee754sp_flong(s64 x)
{
u64 xm;
int xe;
int xs;
ieee754_clearcx();
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
xe = SP_FBITS + 3;
if (xm >> (SP_FBITS + 1 + 3)) {
while (xm >> (SP_FBITS + 1 + 3)) {
SPXSRSX1();
}
} else {
while ((xm >> (SP_FBITS + 3)) == 0) {
xm <<= 1;
xe--;
}
}
return ieee754sp_format(xs, xe, xm);
}
