static u64 notrace jiffy_sched_clock_read(void)
{
return (u64)(jiffies - INITIAL_JIFFIES);
}
static u64 notrace read_sched_clock_32_wrapper(void)
{
return read_sched_clock_32();
}
static inline u64 notrace cyc_to_ns(u64 cyc, u32 mult, u32 shift)
{
return (cyc * mult) >> shift;
}
unsigned long long notrace sched_clock(void)
{
u64 epoch_ns;
u64 epoch_cyc;
u64 cyc;
unsigned long seq;
if (cd.suspended)
return cd.epoch_ns;
do {
seq = raw_read_seqcount_begin(&cd.seq);
epoch_cyc = cd.epoch_cyc;
epoch_ns = cd.epoch_ns;
} while (read_seqcount_retry(&cd.seq, seq));
cyc = read_sched_clock();
cyc = (cyc - epoch_cyc) & sched_clock_mask;
return epoch_ns + cyc_to_ns(cyc, cd.mult, cd.shift);
}
static void notrace update_sched_clock(void)
{
unsigned long flags;
u64 cyc;
u64 ns;
cyc = read_sched_clock();
ns = cd.epoch_ns +
cyc_to_ns((cyc - cd.epoch_cyc) & sched_clock_mask,
cd.mult, cd.shift);
raw_local_irq_save(flags);
raw_write_seqcount_begin(&cd.seq);
cd.epoch_ns = ns;
cd.epoch_cyc = cyc;
raw_write_seqcount_end(&cd.seq);
raw_local_irq_restore(flags);
}
static enum hrtimer_restart sched_clock_poll(struct hrtimer *hrt)
{
update_sched_clock();
hrtimer_forward_now(hrt, cd.wrap_kt);
return HRTIMER_RESTART;
}
void __init sched_clock_register(u64 (*read)(void), int bits,
unsigned long rate)
{
unsigned long r;
u64 res, wrap;
char r_unit;
if (cd.rate > rate)
return;
WARN_ON(!irqs_disabled());
read_sched_clock = read;
sched_clock_mask = CLOCKSOURCE_MASK(bits);
cd.rate = rate;
clocks_calc_mult_shift(&cd.mult, &cd.shift, rate, NSEC_PER_SEC, 3600);
r = rate;
if (r >= 4000000) {
r /= 1000000;
r_unit = 'M';
} else if (r >= 1000) {
r /= 1000;
r_unit = 'k';
} else
r_unit = ' ';
wrap = clocks_calc_max_nsecs(cd.mult, cd.shift, 0, sched_clock_mask);
cd.wrap_kt = ns_to_ktime(wrap - (wrap >> 3));
res = cyc_to_ns(1ULL, cd.mult, cd.shift);
pr_info("sched_clock: %u bits at %lu%cHz, resolution %lluns, wraps every %lluns\n",
bits, r, r_unit, res, wrap);
update_sched_clock();
cd.epoch_ns = 0;
if (irqtime > 0 || (irqtime == -1 && rate >= 1000000))
enable_sched_clock_irqtime();
pr_debug("Registered %pF as sched_clock source\n", read);
}
void __init setup_sched_clock(u32 (*read)(void), int bits, unsigned long rate)
{
read_sched_clock_32 = read;
sched_clock_register(read_sched_clock_32_wrapper, bits, rate);
}
void __init sched_clock_postinit(void)
{
if (read_sched_clock == jiffy_sched_clock_read)
sched_clock_register(jiffy_sched_clock_read, BITS_PER_LONG, HZ);
update_sched_clock();
hrtimer_init(&sched_clock_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
sched_clock_timer.function = sched_clock_poll;
hrtimer_start(&sched_clock_timer, cd.wrap_kt, HRTIMER_MODE_REL);
}
static int sched_clock_suspend(void)
{
sched_clock_poll(&sched_clock_timer);
cd.suspended = true;
return 0;
}
static void sched_clock_resume(void)
{
cd.epoch_cyc = read_sched_clock();
cd.suspended = false;
}
static int __init sched_clock_syscore_init(void)
{
register_syscore_ops(&sched_clock_ops);
return 0;
}
