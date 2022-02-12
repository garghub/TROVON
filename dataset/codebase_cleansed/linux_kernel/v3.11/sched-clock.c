static u32 notrace versatile_read_sched_clock(void)
{
if (ctr)
return readl(ctr);
return 0;
}
void __init versatile_sched_clock_init(void __iomem *reg, unsigned long rate)
{
ctr = reg;
setup_sched_clock(versatile_read_sched_clock, 32, rate);
}
