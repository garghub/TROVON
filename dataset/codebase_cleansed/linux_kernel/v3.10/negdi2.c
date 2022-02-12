s64 __negdi2(s64 u)
{
union DWunion w;
union DWunion uu;
uu.ll = u;
w.s.low = -uu.s.low;
w.s.high = -uu.s.high - ((u32) w.s.low > 0);
return w.ll;
}
