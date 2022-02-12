long long __muldi3(long long u, long long v)
{
const DWunion uu = {.ll = u};
const DWunion vv = {.ll = v};
DWunion w = {.ll = __umulsidi3(uu.s.low, vv.s.low)};
w.s.high += ((unsigned long) uu.s.low * (unsigned long) vv.s.high
+ (unsigned long) uu.s.high * (unsigned long) vv.s.low);
return w.ll;
}
