static void sched_clock_poll(unsigned long wrap_ticks)
{
mod_timer(&sched_clock_timer, round_jiffies(jiffies + wrap_ticks));
sched_clock_update_fn();
}
void __init init_sched_clock(struct clock_data *cd, void (*update)(void),
unsigned int clock_bits, unsigned long rate)
{
unsigned long r, w;
u64 res, wrap;
char r_unit;
sched_clock_update_fn = update;
clocks_calc_mult_shift(&cd->mult, &cd->shift, rate, NSEC_PER_SEC, 0);
r = rate;
if (r >= 4000000) {
r /= 1000000;
r_unit = 'M';
} else {
r /= 1000;
r_unit = 'k';
}
wrap = cyc_to_ns((1ULL << clock_bits) - 1, cd->mult, cd->shift);
do_div(wrap, NSEC_PER_MSEC);
w = wrap;
res = cyc_to_ns(1ULL, cd->mult, cd->shift);
pr_info("sched_clock: %u bits at %lu%cHz, resolution %lluns, wraps every %lums\n",
clock_bits, r, r_unit, res, w);
sched_clock_timer.data = msecs_to_jiffies(w - (w / 10));
update();
cd->epoch_ns = 0;
}
void __init sched_clock_postinit(void)
{
sched_clock_poll(sched_clock_timer.data);
}
