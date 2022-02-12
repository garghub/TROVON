static inline int set_rtc_mmss(unsigned long nowtime)
{
if (mach_set_clock_mmss)
return mach_set_clock_mmss (nowtime);
return -1;
}
static irqreturn_t timer_interrupt(int irq, void *dummy)
{
xtime_update(1);
update_process_times(user_mode(get_irq_regs()));
profile_tick(CPU_PROFILING);
#ifdef CONFIG_HEARTBEAT
if (mach_heartbeat) {
static unsigned cnt = 0, period = 0, dist = 0;
if (cnt == 0 || cnt == dist)
mach_heartbeat( 1 );
else if (cnt == 7 || cnt == dist+7)
mach_heartbeat( 0 );
if (++cnt > period) {
cnt = 0;
period = ((672<<FSHIFT)/(5*avenrun[0]+(7<<FSHIFT))) + 30;
dist = period / 4;
}
}
#endif
return IRQ_HANDLED;
}
void read_persistent_clock(struct timespec *ts)
{
struct rtc_time time;
ts->tv_sec = 0;
ts->tv_nsec = 0;
if (mach_hwclk) {
mach_hwclk(0, &time);
if ((time.tm_year += 1900) < 1970)
time.tm_year += 100;
ts->tv_sec = mktime(time.tm_year, time.tm_mon, time.tm_mday,
time.tm_hour, time.tm_min, time.tm_sec);
}
}
void __init time_init(void)
{
mach_sched_init(timer_interrupt);
}
u32 arch_gettimeoffset(void)
{
return mach_gettimeoffset() * 1000;
}
static int __init rtc_init(void)
{
struct platform_device *pdev;
if (!mach_hwclk)
return -ENODEV;
pdev = platform_device_register_simple("rtc-generic", -1, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
return 0;
}
