DWtype __muldi3(DWtype u, DWtype v)
{
const DWunion uu = {.ll = u};
const DWunion vv = {.ll = v};
DWunion w = {.ll = __umulsidi3(uu.s.low, vv.s.low)};
w.s.high += ((UWtype) uu.s.low * (UWtype) vv.s.high
+ (UWtype) uu.s.high * (UWtype) vv.s.low);
return w.ll;
}
