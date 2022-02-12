s64 div_s64_rem(s64 dividend, s32 divisor, s32 *remainder)
{
u64 quotient;
if (dividend < 0) {
quotient = div_u64_rem(-dividend, abs(divisor), (u32 *)remainder);
*remainder = -*remainder;
if (divisor > 0)
quotient = -quotient;
} else {
quotient = div_u64_rem(dividend, abs(divisor), (u32 *)remainder);
if (divisor < 0)
quotient = -quotient;
}
return quotient;
}
u64 div64_u64_rem(u64 dividend, u64 divisor, u64 *remainder)
{
u32 high = divisor >> 32;
u64 quot;
if (high == 0) {
u32 rem32;
quot = div_u64_rem(dividend, divisor, &rem32);
*remainder = rem32;
} else {
int n = 1 + fls(high);
quot = div_u64(dividend >> n, divisor >> n);
if (quot != 0)
quot--;
*remainder = dividend - quot * divisor;
if (*remainder >= divisor) {
quot++;
*remainder -= divisor;
}
}
return quot;
}
u64 div64_u64(u64 dividend, u64 divisor)
{
u32 high = divisor >> 32;
u64 quot;
if (high == 0) {
quot = div_u64(dividend, divisor);
} else {
int n = 1 + fls(high);
quot = div_u64(dividend >> n, divisor >> n);
if (quot != 0)
quot--;
if ((dividend - quot * divisor) >= divisor)
quot++;
}
return quot;
}
s64 div64_s64(s64 dividend, s64 divisor)
{
s64 quot, t;
quot = div64_u64(abs(dividend), abs(divisor));
t = (dividend ^ divisor) >> 63;
return (quot ^ t) - t;
}
u32 iter_div_u64_rem(u64 dividend, u32 divisor, u64 *remainder)
{
return __iter_div_u64_rem(dividend, divisor, remainder);
}
