static u32 notrace jiffy_sched_clock_read(void)
{
return (u32)(jiffies - INITIAL_JIFFIES);
}
static inline u64 cyc_to_ns(u64 cyc, u32 mult, u32 shift)
{
return (cyc * mult) >> shift;
}
static unsigned long long cyc_to_sched_clock(u32 cyc, u32 mask)
{
u64 epoch_ns;
u32 epoch_cyc;
do {
epoch_cyc = cd.epoch_cyc;
smp_rmb();
epoch_ns = cd.epoch_ns;
smp_rmb();
} while (epoch_cyc != cd.epoch_cyc_copy);
return epoch_ns + cyc_to_ns((cyc - epoch_cyc) & mask, cd.mult, cd.shift);
}
static void notrace update_sched_clock(void)
{
unsigned long flags;
u32 cyc;
u64 ns;
cyc = read_sched_clock();
ns = cd.epoch_ns +
cyc_to_ns((cyc - cd.epoch_cyc) & sched_clock_mask,
cd.mult, cd.shift);
raw_local_irq_save(flags);
cd.epoch_cyc = cyc;
smp_wmb();
cd.epoch_ns = ns;
smp_wmb();
cd.epoch_cyc_copy = cyc;
raw_local_irq_restore(flags);
}
static void sched_clock_poll(unsigned long wrap_ticks)
{
mod_timer(&sched_clock_timer, round_jiffies(jiffies + wrap_ticks));
update_sched_clock();
}
void __init setup_sched_clock(u32 (*read)(void), int bits, unsigned long rate)
{
unsigned long r, w;
u64 res, wrap;
char r_unit;
BUG_ON(bits > 32);
WARN_ON(!irqs_disabled());
WARN_ON(read_sched_clock != jiffy_sched_clock_read);
read_sched_clock = read;
sched_clock_mask = (1 << bits) - 1;
clocks_calc_mult_shift(&cd.mult, &cd.shift, rate, NSEC_PER_SEC, 0);
r = rate;
if (r >= 4000000) {
r /= 1000000;
r_unit = 'M';
} else if (r >= 1000) {
r /= 1000;
r_unit = 'k';
} else
r_unit = ' ';
wrap = cyc_to_ns((1ULL << bits) - 1, cd.mult, cd.shift);
do_div(wrap, NSEC_PER_MSEC);
w = wrap;
res = cyc_to_ns(1ULL, cd.mult, cd.shift);
pr_info("sched_clock: %u bits at %lu%cHz, resolution %lluns, wraps every %lums\n",
bits, r, r_unit, res, w);
sched_clock_timer.data = msecs_to_jiffies(w - (w / 10));
update_sched_clock();
cd.epoch_ns = 0;
pr_debug("Registered %pF as sched_clock source\n", read);
}
unsigned long long notrace sched_clock(void)
{
u32 cyc = read_sched_clock();
return cyc_to_sched_clock(cyc, sched_clock_mask);
}
void __init sched_clock_postinit(void)
{
if (read_sched_clock == jiffy_sched_clock_read)
setup_sched_clock(jiffy_sched_clock_read, 32, HZ);
sched_clock_poll(sched_clock_timer.data);
}
