irqreturn_t mcfslt_profile_tick(int irq, void *dummy)
{
__raw_writel(MCFSLT_SSR_BE | MCFSLT_SSR_TE, PA(MCFSLT_SSR));
if (current->pid)
profile_tick(CPU_PROFILING);
return IRQ_HANDLED;
}
void mcfslt_profile_init(void)
{
printk(KERN_INFO "PROFILE: lodging TIMER 1 @ %dHz as profile timer\n",
PROFILEHZ);
setup_irq(MCF_IRQ_PROFILER, &mcfslt_profile_irq);
__raw_writel(MCF_BUSCLK / PROFILEHZ - 1, PA(MCFSLT_STCNT));
__raw_writel(MCFSLT_SCR_RUN | MCFSLT_SCR_IEN | MCFSLT_SCR_TEN,
PA(MCFSLT_SCR));
}
static irqreturn_t mcfslt_tick(int irq, void *dummy)
{
__raw_writel(MCFSLT_SSR_BE | MCFSLT_SSR_TE, TA(MCFSLT_SSR));
mcfslt_cnt += mcfslt_cycles_per_jiffy;
return arch_timer_interrupt(irq, dummy);
}
static cycle_t mcfslt_read_clk(struct clocksource *cs)
{
unsigned long flags;
u32 cycles, scnt;
local_irq_save(flags);
scnt = __raw_readl(TA(MCFSLT_SCNT));
cycles = mcfslt_cnt;
if (__raw_readl(TA(MCFSLT_SSR)) & MCFSLT_SSR_TE) {
cycles += mcfslt_cycles_per_jiffy;
scnt = __raw_readl(TA(MCFSLT_SCNT));
}
local_irq_restore(flags);
return cycles + ((mcfslt_cycles_per_jiffy - 1) - scnt);
}
void hw_timer_init(void)
{
mcfslt_cycles_per_jiffy = MCF_BUSCLK / HZ;
__raw_writel(mcfslt_cycles_per_jiffy - 1, TA(MCFSLT_STCNT));
__raw_writel(MCFSLT_SCR_RUN | MCFSLT_SCR_IEN | MCFSLT_SCR_TEN,
TA(MCFSLT_SCR));
mcfslt_cnt = mcfslt_cycles_per_jiffy;
setup_irq(MCF_IRQ_TIMER, &mcfslt_timer_irq);
clocksource_register_hz(&mcfslt_clk, MCF_BUSCLK);
#ifdef CONFIG_HIGHPROFILE
mcfslt_profile_init();
#endif
}
