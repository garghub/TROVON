unsigned long __init rtas_get_boot_time(void)
{
int ret[8];
int error;
unsigned int wait_time;
u64 max_wait_tb;
max_wait_tb = get_tb() + tb_ticks_per_usec * 1000 * MAX_RTC_WAIT;
do {
error = rtas_call(rtas_token("get-time-of-day"), 0, 8, ret);
wait_time = rtas_busy_delay_time(error);
if (wait_time) {
udelay(wait_time*1000);
}
} while (wait_time && (get_tb() < max_wait_tb));
if (error != 0) {
printk_ratelimited(KERN_WARNING
"error: reading the clock failed (%d)\n",
error);
return 0;
}
return mktime(ret[0], ret[1], ret[2], ret[3], ret[4], ret[5]);
}
void rtas_get_rtc_time(struct rtc_time *rtc_tm)
{
int ret[8];
int error;
unsigned int wait_time;
u64 max_wait_tb;
max_wait_tb = get_tb() + tb_ticks_per_usec * 1000 * MAX_RTC_WAIT;
do {
error = rtas_call(rtas_token("get-time-of-day"), 0, 8, ret);
wait_time = rtas_busy_delay_time(error);
if (wait_time) {
if (in_interrupt()) {
memset(rtc_tm, 0, sizeof(struct rtc_time));
printk_ratelimited(KERN_WARNING
"error: reading clock "
"would delay interrupt\n");
return;
}
msleep(wait_time);
}
} while (wait_time && (get_tb() < max_wait_tb));
if (error != 0) {
printk_ratelimited(KERN_WARNING
"error: reading the clock failed (%d)\n",
error);
return;
}
rtc_tm->tm_sec = ret[5];
rtc_tm->tm_min = ret[4];
rtc_tm->tm_hour = ret[3];
rtc_tm->tm_mday = ret[2];
rtc_tm->tm_mon = ret[1] - 1;
rtc_tm->tm_year = ret[0] - 1900;
}
int rtas_set_rtc_time(struct rtc_time *tm)
{
int error, wait_time;
u64 max_wait_tb;
max_wait_tb = get_tb() + tb_ticks_per_usec * 1000 * MAX_RTC_WAIT;
do {
error = rtas_call(rtas_token("set-time-of-day"), 7, 1, NULL,
tm->tm_year + 1900, tm->tm_mon + 1,
tm->tm_mday, tm->tm_hour, tm->tm_min,
tm->tm_sec, 0);
wait_time = rtas_busy_delay_time(error);
if (wait_time) {
if (in_interrupt())
return 1;
msleep(wait_time);
}
} while (wait_time && (get_tb() < max_wait_tb));
if (error != 0)
printk_ratelimited(KERN_WARNING
"error: setting the clock failed (%d)\n",
error);
return 0;
}
