time_t
mktime_utc(struct tm *tm)
{
#ifndef HAVE_TIMEGM
time_t retval;
static const int days_before[] =
{
0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};
int yr;
if (tm->tm_mon < 0 || tm->tm_mon > 11)
return (time_t) -1;
retval = (tm->tm_year - 70) * 365;
yr = tm->tm_year + 1900;
if (tm->tm_mon + 1 < 3 && (yr % 4) == 0 && ((yr % 100) != 0 || (yr % 400) == 0))
yr--;
retval += (((yr / 4) - (yr / 100) + (yr / 400)) - 477);
retval += days_before[tm->tm_mon] + tm->tm_mday - 1;
retval = ((((retval * 24) + tm->tm_hour) * 60) + tm->tm_min) * 60 + tm->tm_sec;
return retval;
#else
return timegm(tm);
#endif
}
