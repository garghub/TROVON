static inline bool is_leap(unsigned int y)
{
return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}
static inline unsigned int localtime_1(struct xtm *r, time_t time)
{
unsigned int v, w;
v = time % SECONDS_PER_DAY;
r->second = v % 60;
w = v / 60;
r->minute = w % 60;
r->hour = w / 60;
return v;
}
static inline void localtime_2(struct xtm *r, time_t time)
{
r->dse = time / 86400;
r->weekday = (4 + r->dse - 1) % 7 + 1;
}
static void localtime_3(struct xtm *r, time_t time)
{
unsigned int year, i, w = r->dse;
for (i = 0, year = DSE_FIRST; days_since_epoch[i] > w;
++i, --year)
;
w -= days_since_epoch[i];
if (is_leap(year)) {
for (i = ARRAY_SIZE(days_since_leapyear) - 1;
i > 0 && days_since_leapyear[i] > w; --i)
;
r->monthday = w - days_since_leapyear[i] + 1;
} else {
for (i = ARRAY_SIZE(days_since_year) - 1;
i > 0 && days_since_year[i] > w; --i)
;
r->monthday = w - days_since_year[i] + 1;
}
r->month = i + 1;
}
static bool
time_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_time_info *info = par->matchinfo;
unsigned int packet_time;
struct xtm current_time;
s64 stamp;
if (skb->tstamp == 0)
__net_timestamp((struct sk_buff *)skb);
stamp = ktime_to_ns(skb->tstamp);
stamp = div_s64(stamp, NSEC_PER_SEC);
if (info->flags & XT_TIME_LOCAL_TZ)
stamp -= 60 * sys_tz.tz_minuteswest;
if (stamp < info->date_start || stamp > info->date_stop)
return false;
packet_time = localtime_1(&current_time, stamp);
if (info->daytime_start < info->daytime_stop) {
if (packet_time < info->daytime_start ||
packet_time > info->daytime_stop)
return false;
} else {
if (packet_time < info->daytime_start &&
packet_time > info->daytime_stop)
return false;
if ((info->flags & XT_TIME_CONTIGUOUS) &&
packet_time <= info->daytime_stop)
stamp -= SECONDS_PER_DAY;
}
localtime_2(&current_time, stamp);
if (!(info->weekdays_match & (1 << current_time.weekday)))
return false;
if (info->monthdays_match != XT_TIME_ALL_MONTHDAYS) {
localtime_3(&current_time, stamp);
if (!(info->monthdays_match & (1 << current_time.monthday)))
return false;
}
return true;
}
static int time_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_time_info *info = par->matchinfo;
if (info->daytime_start > XT_TIME_MAX_DAYTIME ||
info->daytime_stop > XT_TIME_MAX_DAYTIME) {
pr_info("invalid argument - start or "
"stop time greater than 23:59:59\n");
return -EDOM;
}
if (info->flags & ~XT_TIME_ALL_FLAGS) {
pr_info("unknown flags 0x%x\n", info->flags & ~XT_TIME_ALL_FLAGS);
return -EINVAL;
}
if ((info->flags & XT_TIME_CONTIGUOUS) &&
info->daytime_start < info->daytime_stop)
return -EINVAL;
return 0;
}
static int __init time_mt_init(void)
{
int minutes = sys_tz.tz_minuteswest;
if (minutes < 0)
printk(KERN_INFO KBUILD_MODNAME
": kernel timezone is +%02d%02d\n",
-minutes / 60, -minutes % 60);
else
printk(KERN_INFO KBUILD_MODNAME
": kernel timezone is -%02d%02d\n",
minutes / 60, minutes % 60);
return xt_register_match(&xt_time_mt_reg);
}
static void __exit time_mt_exit(void)
{
xt_unregister_match(&xt_time_mt_reg);
}
