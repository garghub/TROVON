int rtc_month_days(unsigned int month, unsigned int year)
{
return rtc_days_in_month[month] + (is_leap_year(year) && month == 1);
}
int rtc_year_days(unsigned int day, unsigned int month, unsigned int year)
{
return rtc_ydays[is_leap_year(year)][month] + day-1;
}
void rtc_time_to_tm(unsigned long time, struct rtc_time *tm)
{
unsigned int month, year;
int days;
days = time / 86400;
time -= (unsigned int) days * 86400;
tm->tm_wday = (days + 4) % 7;
year = 1970 + days / 365;
days -= (year - 1970) * 365
+ LEAPS_THRU_END_OF(year - 1)
- LEAPS_THRU_END_OF(1970 - 1);
if (days < 0) {
year -= 1;
days += 365 + is_leap_year(year);
}
tm->tm_year = year - 1900;
tm->tm_yday = days + 1;
for (month = 0; month < 11; month++) {
int newdays;
newdays = days - rtc_month_days(month, year);
if (newdays < 0)
break;
days = newdays;
}
tm->tm_mon = month;
tm->tm_mday = days + 1;
tm->tm_hour = time / 3600;
time -= tm->tm_hour * 3600;
tm->tm_min = time / 60;
tm->tm_sec = time - tm->tm_min * 60;
}
int rtc_valid_tm(struct rtc_time *tm)
{
if (tm->tm_year < 70
|| ((unsigned)tm->tm_mon) >= 12
|| tm->tm_mday < 1
|| tm->tm_mday > rtc_month_days(tm->tm_mon, tm->tm_year + 1900)
|| ((unsigned)tm->tm_hour) >= 24
|| ((unsigned)tm->tm_min) >= 60
|| ((unsigned)tm->tm_sec) >= 60)
return -EINVAL;
return 0;
}
int rtc_tm_to_time(struct rtc_time *tm, unsigned long *time)
{
*time = mktime(tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec);
return 0;
}
ktime_t rtc_tm_to_ktime(struct rtc_time tm)
{
time_t time;
rtc_tm_to_time(&tm, &time);
return ktime_set(time, 0);
}
struct rtc_time rtc_ktime_to_tm(ktime_t kt)
{
struct timespec ts;
struct rtc_time ret;
ts = ktime_to_timespec(kt);
if (ts.tv_nsec)
ts.tv_sec++;
rtc_time_to_tm(ts.tv_sec, &ret);
return ret;
}
