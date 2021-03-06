union ieee754dp ieee754dp_fint(int x)
{
u64 xm;
int xe;
int xs;
ieee754_clearcx();
if (x == 0)
return ieee754dp_zero(0);
if (x == 1 || x == -1)
return ieee754dp_one(x < 0);
if (x == 10 || x == -10)
return ieee754dp_ten(x < 0);
xs = (x < 0);
if (xs) {
if (x == (1 << 31))
xm = ((unsigned) 1 << 31);
else
xm = -x;
} else {
xm = x;
}
xe = DP_FBITS;
while ((xm >> DP_FBITS) == 0) {
xm <<= 1;
xe--;
}
return builddp(xs, xe + DP_EBIAS, xm & ~DP_HIDDEN_BIT);
}
