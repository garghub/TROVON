static inline int set_rtc_mmss(unsigned long nowtime)
{
if (mach_set_clock_mmss)
return mach_set_clock_mmss (nowtime);
return -1;
}
irqreturn_t arch_timer_interrupt(int irq, void *dummy)
{
if (current->pid)
profile_tick(CPU_PROFILING);
xtime_update(1);
update_process_times(user_mode(get_irq_regs()));
return(IRQ_HANDLED);
}
static unsigned long read_rtc_mmss(void)
{
unsigned int year, mon, day, hour, min, sec;
if (mach_gettod) {
mach_gettod(&year, &mon, &day, &hour, &min, &sec);
if ((year += 1900) < 1970)
year += 100;
} else {
year = 1970;
mon = day = 1;
hour = min = sec = 0;
}
return mktime(year, mon, day, hour, min, sec);
}
void read_persistent_clock(struct timespec *ts)
{
ts->tv_sec = read_rtc_mmss();
ts->tv_nsec = 0;
}
int update_persistent_clock(struct timespec now)
{
return set_rtc_mmss(now.tv_sec);
}
void time_init(void)
{
hw_timer_init();
}
