static struct tm *
localtime_r (t, tp)
const time_t *t;
struct tm *tp;
{
struct tm *l = localtime (t);
if (! l)
return 0;
*tp = *l;
return tp;
}
static void
day_of_the_week (struct tm *tm)
{
int corr_year = 1900 + tm->tm_year - (tm->tm_mon < 2);
int wday = (-473
+ (365 * (tm->tm_year - 70))
+ (corr_year / 4)
- ((corr_year / 4) / 25) + ((corr_year / 4) % 25 < 0)
+ (((corr_year / 4) / 25) / 4)
+ __mon_yday[0][tm->tm_mon]
+ tm->tm_mday - 1);
tm->tm_wday = ((wday % 7) + 7) % 7;
}
static void
day_of_the_year (struct tm *tm)
{
tm->tm_yday = (__mon_yday[__isleap (1900 + tm->tm_year)][tm->tm_mon]
+ (tm->tm_mday - 1));
}
static char *
#ifdef _LIBC
internal_function
#endif
strptime_internal (rp, fmt, tm, decided, era_cnt)
const char *rp;
const char *fmt;
struct tm *tm;
enum locale_status *decided;
int era_cnt;
{
const char *rp_backup;
int cnt;
int val;
int have_I, is_pm;
int century, want_century;
int want_era;
int have_wday, want_xday;
int have_yday;
int have_mon, have_mday;
#ifdef _NL_CURRENT
size_t num_eras;
#endif
struct era_entry *era;
have_I = is_pm = 0;
century = -1;
want_century = 0;
want_era = 0;
era = NULL;
have_wday = want_xday = have_yday = have_mon = have_mday = 0;
while (*fmt != '\0')
{
if (isspace (*fmt))
{
while (isspace (*rp))
++rp;
++fmt;
continue;
}
if (*fmt != '%')
{
match_char (*fmt++, *rp++);
continue;
}
++fmt;
#ifndef _NL_CURRENT
start_over:
#endif
rp_backup = rp;
switch (*fmt++)
{
case '%':
match_char ('%', *rp++);
break;
case 'a':
case 'A':
for (cnt = 0; cnt < 7; ++cnt)
{
#ifdef _NL_CURRENT
if (*decided !=raw)
{
if (match_string (_NL_CURRENT (LC_TIME, DAY_1 + cnt), rp))
{
if (*decided == not
&& strcmp (_NL_CURRENT (LC_TIME, DAY_1 + cnt),
weekday_name[cnt]))
*decided = loc;
break;
}
if (match_string (_NL_CURRENT (LC_TIME, ABDAY_1 + cnt), rp))
{
if (*decided == not
&& strcmp (_NL_CURRENT (LC_TIME, ABDAY_1 + cnt),
ab_weekday_name[cnt]))
*decided = loc;
break;
}
}
#endif
if (*decided != loc
&& (match_string (weekday_name[cnt], rp)
|| match_string (ab_weekday_name[cnt], rp)))
{
*decided = raw;
break;
}
}
if (cnt == 7)
return NULL;
tm->tm_wday = cnt;
have_wday = 1;
break;
case 'b':
case 'B':
case 'h':
for (cnt = 0; cnt < 12; ++cnt)
{
#ifdef _NL_CURRENT
if (*decided !=raw)
{
if (match_string (_NL_CURRENT (LC_TIME, MON_1 + cnt), rp))
{
if (*decided == not
&& strcmp (_NL_CURRENT (LC_TIME, MON_1 + cnt),
month_name[cnt]))
*decided = loc;
break;
}
if (match_string (_NL_CURRENT (LC_TIME, ABMON_1 + cnt), rp))
{
if (*decided == not
&& strcmp (_NL_CURRENT (LC_TIME, ABMON_1 + cnt),
ab_month_name[cnt]))
*decided = loc;
break;
}
}
#endif
if (match_string (month_name[cnt], rp)
|| match_string (ab_month_name[cnt], rp))
{
*decided = raw;
break;
}
}
if (cnt == 12)
return NULL;
tm->tm_mon = cnt;
want_xday = 1;
break;
case 'c':
#ifdef _NL_CURRENT
if (*decided != raw)
{
if (!recursive (_NL_CURRENT (LC_TIME, D_T_FMT)))
{
if (*decided == loc)
return NULL;
else
rp = rp_backup;
}
else
{
if (*decided == not &&
strcmp (_NL_CURRENT (LC_TIME, D_T_FMT), HERE_D_T_FMT))
*decided = loc;
want_xday = 1;
break;
}
*decided = raw;
}
#endif
if (!recursive (HERE_D_T_FMT))
return NULL;
want_xday = 1;
break;
case 'C':
#ifdef _NL_CURRENT
match_century:
#endif
get_number (0, 99, 2);
century = val;
want_xday = 1;
break;
case 'd':
case 'e':
get_number (1, 31, 2);
tm->tm_mday = val;
have_mday = 1;
want_xday = 1;
break;
case 'F':
if (!recursive ("%Y-%m-%d"))
return NULL;
want_xday = 1;
break;
case 'x':
#ifdef _NL_CURRENT
if (*decided != raw)
{
if (!recursive (_NL_CURRENT (LC_TIME, D_FMT)))
{
if (*decided == loc)
return NULL;
else
rp = rp_backup;
}
else
{
if (*decided == not
&& strcmp (_NL_CURRENT (LC_TIME, D_FMT), HERE_D_FMT))
*decided = loc;
want_xday = 1;
break;
}
*decided = raw;
}
#endif
case 'D':
if (!recursive (HERE_D_FMT))
return NULL;
want_xday = 1;
break;
case 'k':
case 'H':
get_number (0, 23, 2);
tm->tm_hour = val;
have_I = 0;
break;
case 'I':
get_number (1, 12, 2);
tm->tm_hour = val % 12;
have_I = 1;
break;
case 'j':
get_number (1, 366, 3);
tm->tm_yday = val - 1;
have_yday = 1;
break;
case 'm':
get_number (1, 12, 2);
tm->tm_mon = val - 1;
have_mon = 1;
want_xday = 1;
break;
case 'M':
get_number (0, 59, 2);
tm->tm_min = val;
break;
case 'n':
case 't':
while (isspace (*rp))
++rp;
break;
case 'p':
#ifdef _NL_CURRENT
if (*decided != raw)
{
if (match_string (_NL_CURRENT (LC_TIME, AM_STR), rp))
{
if (strcmp (_NL_CURRENT (LC_TIME, AM_STR), HERE_AM_STR))
*decided = loc;
break;
}
if (match_string (_NL_CURRENT (LC_TIME, PM_STR), rp))
{
if (strcmp (_NL_CURRENT (LC_TIME, PM_STR), HERE_PM_STR))
*decided = loc;
is_pm = 1;
break;
}
*decided = raw;
}
#endif
if (!match_string (HERE_AM_STR, rp)) {
if (match_string (HERE_PM_STR, rp))
is_pm = 1;
else
return NULL;
}
break;
case 'r':
#ifdef _NL_CURRENT
if (*decided != raw)
{
if (!recursive (_NL_CURRENT (LC_TIME, T_FMT_AMPM)))
{
if (*decided == loc)
return NULL;
else
rp = rp_backup;
}
else
{
if (*decided == not &&
strcmp (_NL_CURRENT (LC_TIME, T_FMT_AMPM),
HERE_T_FMT_AMPM))
*decided = loc;
break;
}
*decided = raw;
}
#endif
if (!recursive (HERE_T_FMT_AMPM))
return NULL;
break;
case 'R':
if (!recursive ("%H:%M"))
return NULL;
break;
case 's':
{
time_t secs = 0;
if (*rp < '0' || *rp > '9')
return NULL;
do
{
secs *= 10;
secs += *rp++ - '0';
}
while (*rp >= '0' && *rp <= '9');
if (localtime_r (&secs, tm) == NULL)
return NULL;
}
break;
case 'S':
get_number (0, 61, 2);
tm->tm_sec = val;
break;
case 'X':
#ifdef _NL_CURRENT
if (*decided != raw)
{
if (!recursive (_NL_CURRENT (LC_TIME, T_FMT)))
{
if (*decided == loc)
return NULL;
else
rp = rp_backup;
}
else
{
if (strcmp (_NL_CURRENT (LC_TIME, T_FMT), HERE_T_FMT))
*decided = loc;
break;
}
*decided = raw;
}
#endif
case 'T':
if (!recursive (HERE_T_FMT))
return NULL;
break;
case 'u':
get_number (1, 7, 1);
tm->tm_wday = val % 7;
have_wday = 1;
break;
case 'g':
get_number (0, 99, 2);
break;
case 'G':
if (*rp < '0' || *rp > '9')
return NULL;
do
++rp;
while (*rp >= '0' && *rp <= '9');
break;
case 'U':
case 'V':
case 'W':
get_number (0, 53, 2);
break;
case 'w':
get_number (0, 6, 1);
tm->tm_wday = val;
have_wday = 1;
break;
case 'y':
#ifdef _NL_CURRENT
match_year_in_century:
#endif
get_number (0, 99, 2);
tm->tm_year = val >= 69 ? val : val + 100;
want_century = 1;
want_xday = 1;
break;
case 'Y':
get_number (0, 9999, 4);
tm->tm_year = val - 1900;
want_century = 0;
want_xday = 1;
break;
case 'Z':
break;
case 'E':
#ifdef _NL_CURRENT
switch (*fmt++)
{
case 'c':
if (*decided != raw)
{
const char *fmt = _NL_CURRENT (LC_TIME, ERA_D_T_FMT);
if (*fmt == '\0')
fmt = _NL_CURRENT (LC_TIME, D_T_FMT);
if (!recursive (fmt))
{
if (*decided == loc)
return NULL;
else
rp = rp_backup;
}
else
{
if (strcmp (fmt, HERE_D_T_FMT))
*decided = loc;
want_xday = 1;
break;
}
*decided = raw;
}
if (!recursive (HERE_D_T_FMT))
return NULL;
want_xday = 1;
break;
case 'C':
if (*decided != raw)
{
if (era_cnt >= 0)
{
era = _nl_select_era_entry (era_cnt);
if (match_string (era->era_name, rp))
{
*decided = loc;
break;
}
else
return NULL;
}
else
{
num_eras = _NL_CURRENT_WORD (LC_TIME,
_NL_TIME_ERA_NUM_ENTRIES);
for (era_cnt = 0; era_cnt < (int) num_eras;
++era_cnt, rp = rp_backup)
{
era = _nl_select_era_entry (era_cnt);
if (match_string (era->era_name, rp))
{
*decided = loc;
break;
}
}
if (era_cnt == (int) num_eras)
{
era_cnt = -1;
if (*decided == loc)
return NULL;
}
else
break;
}
*decided = raw;
}
goto match_century;
case 'y':
if (*decided == raw)
goto match_year_in_century;
get_number(0, 9999, 4);
tm->tm_year = val;
want_era = 1;
want_xday = 1;
break;
case 'Y':
if (*decided != raw)
{
num_eras = _NL_CURRENT_WORD (LC_TIME,
_NL_TIME_ERA_NUM_ENTRIES);
for (era_cnt = 0; era_cnt < (int) num_eras;
++era_cnt, rp = rp_backup)
{
era = _nl_select_era_entry (era_cnt);
if (recursive (era->era_format))
break;
}
if (era_cnt == (int) num_eras)
{
era_cnt = -1;
if (*decided == loc)
return NULL;
else
rp = rp_backup;
}
else
{
*decided = loc;
era_cnt = -1;
break;
}
*decided = raw;
}
get_number (0, 9999, 4);
tm->tm_year = val - 1900;
want_century = 0;
want_xday = 1;
break;
case 'x':
if (*decided != raw)
{
const char *fmt = _NL_CURRENT (LC_TIME, ERA_D_FMT);
if (*fmt == '\0')
fmt = _NL_CURRENT (LC_TIME, D_FMT);
if (!recursive (fmt))
{
if (*decided == loc)
return NULL;
else
rp = rp_backup;
}
else
{
if (strcmp (fmt, HERE_D_FMT))
*decided = loc;
break;
}
*decided = raw;
}
if (!recursive (HERE_D_FMT))
return NULL;
break;
case 'X':
if (*decided != raw)
{
const char *fmt = _NL_CURRENT (LC_TIME, ERA_T_FMT);
if (*fmt == '\0')
fmt = _NL_CURRENT (LC_TIME, T_FMT);
if (!recursive (fmt))
{
if (*decided == loc)
return NULL;
else
rp = rp_backup;
}
else
{
if (strcmp (fmt, HERE_T_FMT))
*decided = loc;
break;
}
*decided = raw;
}
if (!recursive (HERE_T_FMT))
return NULL;
break;
default:
return NULL;
}
break;
#else
if (*fmt != 'c' && *fmt != 'C' && *fmt != 'y' && *fmt != 'Y'
&& *fmt != 'x' && *fmt != 'X')
return NULL;
goto start_over;
#endif
case 'O':
switch (*fmt++)
{
case 'd':
case 'e':
get_alt_number (1, 31, 2);
tm->tm_mday = val;
have_mday = 1;
want_xday = 1;
break;
case 'H':
get_alt_number (0, 23, 2);
tm->tm_hour = val;
have_I = 0;
break;
case 'I':
get_alt_number (1, 12, 2);
tm->tm_hour = val - 1;
have_I = 1;
break;
case 'm':
get_alt_number (1, 12, 2);
tm->tm_mon = val - 1;
have_mon = 1;
want_xday = 1;
break;
case 'M':
get_alt_number (0, 59, 2);
tm->tm_min = val;
break;
case 'S':
get_alt_number (0, 61, 2);
tm->tm_sec = val;
break;
case 'U':
case 'V':
case 'W':
get_alt_number (0, 53, 2);
break;
case 'w':
get_alt_number (0, 6, 1);
tm->tm_wday = val;
have_wday = 1;
break;
case 'y':
get_alt_number (0, 99, 2);
tm->tm_year = val >= 69 ? val : val + 100;
want_xday = 1;
break;
default:
return NULL;
}
break;
default:
return NULL;
}
}
if (have_I && is_pm)
tm->tm_hour += 12;
if (century != -1)
{
if (want_century)
tm->tm_year = tm->tm_year % 100 + (century - 19) * 100;
else
tm->tm_year = (century - 19) * 100;
}
#ifdef _NL_CURRENT
if (era_cnt != -1)
{
era = _nl_select_era_entry(era_cnt);
if (want_era)
tm->tm_year = (era->start_date[0]
+ ((tm->tm_year - era->offset)
* era->absolute_direction));
else
tm->tm_year = era->start_date[0];
}
else
#endif
if (want_era)
return NULL;
if (want_xday && !have_wday)
{
if ( !(have_mon && have_mday) && have_yday)
{
int t_mon = 0;
while (__mon_yday[__isleap(1900 + tm->tm_year)][t_mon] <= tm->tm_yday)
t_mon++;
if (!have_mon)
tm->tm_mon = t_mon - 1;
if (!have_mday)
tm->tm_mday =
(tm->tm_yday
- __mon_yday[__isleap(1900 + tm->tm_year)][t_mon - 1] + 1);
}
day_of_the_week (tm);
}
if (want_xday && !have_yday)
day_of_the_year (tm);
return (char *) rp;
}
char *
strptime (buf, format, tm)
const char *buf;
const char *format;
struct tm *tm;
{
enum locale_status decided;
#ifdef _NL_CURRENT
decided = not;
#else
decided = raw;
#endif
return strptime_internal (buf, format, tm, &decided, -1);
}
