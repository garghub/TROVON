struct tm *OPENSSL_gmtime(const time_t *timer, struct tm *result)
{
struct tm *ts = NULL;
#if defined(OPENSSL_THREADS) && !defined(OPENSSL_SYS_WIN32) && !defined(OPENSSL_SYS_OS2) && (!defined(OPENSSL_SYS_VMS) || defined(gmtime_r)) && !defined(OPENSSL_SYS_MACOSX) && !defined(OPENSSL_SYS_SUNOS)
gmtime_r(timer,result);
ts = result;
#elif !defined(OPENSSL_SYS_VMS)
ts = gmtime(timer);
if (ts == NULL)
return NULL;
memcpy(result, ts, sizeof(struct tm));
ts = result;
#endif
#ifdef OPENSSL_SYS_VMS
if (ts == NULL)
{
static $DESCRIPTOR(tabnam,"LNM$DCL_LOGICAL");
static $DESCRIPTOR(lognam,"SYS$TIMEZONE_DIFFERENTIAL");
char logvalue[256];
unsigned int reslen = 0;
struct {
short buflen;
short code;
void *bufaddr;
unsigned int *reslen;
} itemlist[] = {
{ 0, LNM$_STRING, 0, 0 },
{ 0, 0, 0, 0 },
};
int status;
time_t t;
itemlist[0].buflen = sizeof(logvalue);
itemlist[0].bufaddr = logvalue;
itemlist[0].reslen = &reslen;
status = sys$trnlnm(0, &tabnam, &lognam, 0, itemlist);
if (!(status & 1))
return NULL;
logvalue[reslen] = '\0';
t = *timer;
#if __CRTL_VER < 70000000 || defined _VMS_V6_SOURCE
status = atoi(logvalue);
t -= status;
#endif
{
unsigned long unix_epoch[2] = { 1273708544, 8164711 };
unsigned long deltatime[2];
unsigned long systime[2];
struct vms_vectime
{
short year, month, day, hour, minute, second,
centi_second;
} time_values;
long operation;
operation = LIB$K_DELTA_SECONDS;
status = lib$cvt_to_internal_time(&operation,
&t, deltatime);
status = lib$add_times(unix_epoch, deltatime, systime);
status = sys$numtim(&time_values, systime);
result->tm_sec = time_values.second;
result->tm_min = time_values.minute;
result->tm_hour = time_values.hour;
result->tm_mday = time_values.day;
result->tm_mon = time_values.month - 1;
result->tm_year = time_values.year - 1900;
operation = LIB$K_DAY_OF_WEEK;
status = lib$cvt_from_internal_time(&operation,
&result->tm_wday, systime);
result->tm_wday %= 7;
operation = LIB$K_DAY_OF_YEAR;
status = lib$cvt_from_internal_time(&operation,
&result->tm_yday, systime);
result->tm_yday--;
result->tm_isdst = 0;
ts = result;
}
}
#endif
return ts;
}
int OPENSSL_gmtime_adj(struct tm *tm, int off_day, long offset_sec)
{
int offset_hms, offset_day;
long time_jd;
int time_year, time_month, time_day;
offset_day = offset_sec / SECS_PER_DAY;
offset_hms = offset_sec - (offset_day * SECS_PER_DAY);
offset_day += off_day;
offset_hms += tm->tm_hour * 3600 + tm->tm_min * 60 + tm->tm_sec;
if (offset_hms >= SECS_PER_DAY)
{
offset_day++;
offset_hms -= SECS_PER_DAY;
}
else if (offset_hms < 0)
{
offset_day--;
offset_hms += SECS_PER_DAY;
}
time_year = tm->tm_year + 1900;
time_month = tm->tm_mon + 1;
time_day = tm->tm_mday;
time_jd = date_to_julian(time_year, time_month, time_day);
time_jd += offset_day;
if (time_jd < 0)
return 0;
julian_to_date(time_jd, &time_year, &time_month, &time_day);
if (time_year < 1900 || time_year > 9999)
return 0;
tm->tm_year = time_year - 1900;
tm->tm_mon = time_month - 1;
tm->tm_mday = time_day;
tm->tm_hour = offset_hms / 3600;
tm->tm_min = (offset_hms / 60) % 60;
tm->tm_sec = offset_hms % 60;
return 1;
}
static long date_to_julian(int y, int m, int d)
{
return (1461 * (y + 4800 + (m - 14) / 12)) / 4 +
(367 * (m - 2 - 12 * ((m - 14) / 12))) / 12 -
(3 * ((y + 4900 + (m - 14) / 12) / 100)) / 4 +
d - 32075;
}
static void julian_to_date(long jd, int *y, int *m, int *d)
{
long L = jd + 68569;
long n = (4 * L) / 146097;
long i, j;
L = L - (146097 * n + 3) / 4;
i = (4000 * (L + 1)) / 1461001;
L = L - (1461 * i) / 4 + 31;
j = (80 * L) / 2447;
*d = L - (2447 * j) / 80;
L = j / 11;
*m = j + 2 - (12 * L);
*y = 100 * (n - 49) + i + L;
}
int main(int argc, char **argv)
{
long offset;
for (offset = 0; offset < 1000000; offset++)
{
check_time(offset);
check_time(-offset);
check_time(offset * 1000);
check_time(-offset * 1000);
}
}
int check_time(long offset)
{
struct tm tm1, tm2;
time_t t1, t2;
time(&t1);
t2 = t1 + offset;
OPENSSL_gmtime(&t2, &tm2);
OPENSSL_gmtime(&t1, &tm1);
OPENSSL_gmtime_adj(&tm1, 0, offset);
if ((tm1.tm_year == tm2.tm_year) &&
(tm1.tm_mon == tm2.tm_mon) &&
(tm1.tm_mday == tm2.tm_mday) &&
(tm1.tm_hour == tm2.tm_hour) &&
(tm1.tm_min == tm2.tm_min) &&
(tm1.tm_sec == tm2.tm_sec))
return 1;
fprintf(stderr, "TIME ERROR!!\n");
fprintf(stderr, "Time1: %d/%d/%d, %d:%02d:%02d\n",
tm2.tm_mday, tm2.tm_mon + 1, tm2.tm_year + 1900,
tm2.tm_hour, tm2.tm_min, tm2.tm_sec);
fprintf(stderr, "Time2: %d/%d/%d, %d:%02d:%02d\n",
tm1.tm_mday, tm1.tm_mon + 1, tm1.tm_year + 1900,
tm1.tm_hour, tm1.tm_min, tm1.tm_sec);
return 0;
}
