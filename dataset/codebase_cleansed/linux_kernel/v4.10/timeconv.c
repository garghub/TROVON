static int __isleap(long year)
{
return (year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0);
}
static long math_div(long a, long b)
{
return a / b - (a % b < 0);
}
static long leaps_between(long y1, long y2)
{
long leaps1 = math_div(y1 - 1, 4) - math_div(y1 - 1, 100)
+ math_div(y1 - 1, 400);
long leaps2 = math_div(y2 - 1, 4) - math_div(y2 - 1, 100)
+ math_div(y2 - 1, 400);
return leaps2 - leaps1;
}
void time64_to_tm(time64_t totalsecs, int offset, struct tm *result)
{
long days, rem, y;
int remainder;
const unsigned short *ip;
days = div_s64_rem(totalsecs, SECS_PER_DAY, &remainder);
rem = remainder;
rem += offset;
while (rem < 0) {
rem += SECS_PER_DAY;
--days;
}
while (rem >= SECS_PER_DAY) {
rem -= SECS_PER_DAY;
++days;
}
result->tm_hour = rem / SECS_PER_HOUR;
rem %= SECS_PER_HOUR;
result->tm_min = rem / 60;
result->tm_sec = rem % 60;
result->tm_wday = (4 + days) % 7;
if (result->tm_wday < 0)
result->tm_wday += 7;
y = 1970;
while (days < 0 || days >= (__isleap(y) ? 366 : 365)) {
long yg = y + math_div(days, 365);
days -= (yg - y) * 365 + leaps_between(y, yg);
y = yg;
}
result->tm_year = y - 1900;
result->tm_yday = days;
ip = __mon_yday[__isleap(y)];
for (y = 11; days < ip[y]; y--)
continue;
days -= ip[y];
result->tm_mon = y;
result->tm_mday = days + 1;
}
