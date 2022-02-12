ieee754dp ieee754dp_fint(int x)
{
u64 xm;
int xe;
int xs;
CLEARCX;
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
#if 1
xe = DP_MBITS;
while ((xm >> DP_MBITS) == 0) {
xm <<= 1;
xe--;
}
return builddp(xs, xe + DP_EBIAS, xm & ~DP_HIDDEN_BIT);
#else
xe = DP_MBITS + 3;
while ((xm >> (DP_MBITS + 3)) == 0) {
xm <<= 1;
xe--;
}
DPNORMRET1(xs, xe, xm, "fint", x);
#endif
}
ieee754dp ieee754dp_funs(unsigned int u)
{
if ((int) u < 0)
return ieee754dp_add(ieee754dp_1e31(),
ieee754dp_fint(u & ~(1 << 31)));
return ieee754dp_fint(u);
}
