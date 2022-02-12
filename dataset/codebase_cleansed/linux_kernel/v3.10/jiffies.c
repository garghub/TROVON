static cycle_t jiffies_read(struct clocksource *cs)
{
return (cycle_t) jiffies;
}
u64 get_jiffies_64(void)
{
unsigned long seq;
u64 ret;
do {
seq = read_seqbegin(&jiffies_lock);
ret = jiffies_64;
} while (read_seqretry(&jiffies_lock, seq));
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
int register_refined_jiffies(long cycles_per_second)
{
u64 nsec_per_tick, shift_hz;
long cycles_per_tick;
refined_jiffies = clocksource_jiffies;
refined_jiffies.name = "refined-jiffies";
refined_jiffies.rating++;
cycles_per_tick = (cycles_per_second + HZ/2)/HZ;
shift_hz = (u64)cycles_per_second << 8;
shift_hz += cycles_per_tick/2;
do_div(shift_hz, cycles_per_tick);
nsec_per_tick = (u64)NSEC_PER_SEC << 8;
nsec_per_tick += (u32)shift_hz/2;
do_div(nsec_per_tick, (u32)shift_hz);
refined_jiffies.mult = ((u32)nsec_per_tick) << JIFFIES_SHIFT;
clocksource_register(&refined_jiffies);
return 0;
}
