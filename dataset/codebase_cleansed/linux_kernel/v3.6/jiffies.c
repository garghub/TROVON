static cycle_t jiffies_read(struct clocksource *cs)
{
return (cycle_t) jiffies;
}
u64 get_jiffies_64(void)
{
unsigned long seq;
u64 ret;
do {
seq = read_seqbegin(&xtime_lock);
ret = jiffies_64;
} while (read_seqretry(&xtime_lock, seq));
return ret;
}
static int __init init_jiffies_clocksource(void)
{
return clocksource_register(&clocksource_jiffies);
}
struct clocksource * __init __weak clocksource_default_clock(void)
{
return &clocksource_jiffies;
}
