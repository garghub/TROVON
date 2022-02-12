struct reciprocal_value reciprocal_value(u32 d)
{
struct reciprocal_value R;
u64 m;
int l;
l = fls(d - 1);
m = ((1ULL << 32) * ((1ULL << l) - d));
do_div(m, d);
++m;
R.m = (u32)m;
R.sh1 = min(l, 1);
R.sh2 = max(l - 1, 0);
return R;
}
