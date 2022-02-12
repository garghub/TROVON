unsigned long long notrace sched_clock(void)
{
if (ctr) {
u32 cyc = readl(ctr);
return cyc_to_fixed_sched_clock(&cd, cyc, (u32)~0,
SC_MULT, SC_SHIFT);
} else
return 0;
}
static void notrace versatile_update_sched_clock(void)
{
u32 cyc = readl(ctr);
update_sched_clock(&cd, cyc, (u32)~0);
}
void __init versatile_sched_clock_init(void __iomem *reg, unsigned long rate)
{
ctr = reg;
init_fixed_sched_clock(&cd, versatile_update_sched_clock,
32, rate, SC_MULT, SC_SHIFT);
}
