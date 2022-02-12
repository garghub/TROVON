struct tm *OPENSSL_gmtime(const time_t *timer, struct tm *result)
{
struct tm *ts = NULL;
#if defined(OPENSSL_THREADS) && !defined(OPENSSL_SYS_WIN32) && !defined(OPENSSL_SYS_OS2) && !defined(__CYGWIN32__) && (!defined(OPENSSL_SYS_VMS) || defined(gmtime_r)) && !defined(OPENSSL_SYS_MACOSX)
gmtime_r(timer,result);
ts = result;
#elif !defined(OPENSSL_SYS_VMS)
ts = gmtime(timer);
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
status = atoi(logvalue);
t = *timer - status;
#ifndef OPENSSL_THREADS
ts=(struct tm *)localtime(&t);
#else
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
#endif
}
}
#endif
return ts;
}
