static cycle_t tc_get_cycles(struct clocksource *cs)
{
unsigned long flags;
u32 lower, upper;
raw_local_irq_save(flags);
do {
upper = __raw_readl(tcaddr + ATMEL_TC_REG(1, CV));
lower = __raw_readl(tcaddr + ATMEL_TC_REG(0, CV));
} while (upper != __raw_readl(tcaddr + ATMEL_TC_REG(1, CV)));
raw_local_irq_restore(flags);
return (upper << 16) | lower;
}
static cycle_t tc_get_cycles32(struct clocksource *cs)
{
return __raw_readl(tcaddr + ATMEL_TC_REG(0, CV));
}
static struct tc_clkevt_device *to_tc_clkevt(struct clock_event_device *clkevt)
{
return container_of(clkevt, struct tc_clkevt_device, clkevt);
}
static void tc_mode(enum clock_event_mode m, struct clock_event_device *d)
{
struct tc_clkevt_device *tcd = to_tc_clkevt(d);
void __iomem *regs = tcd->regs;
if (tcd->clkevt.mode == CLOCK_EVT_MODE_PERIODIC
|| tcd->clkevt.mode == CLOCK_EVT_MODE_ONESHOT) {
__raw_writel(0xff, regs + ATMEL_TC_REG(2, IDR));
__raw_writel(ATMEL_TC_CLKDIS, regs + ATMEL_TC_REG(2, CCR));
clk_disable(tcd->clk);
}
switch (m) {
case CLOCK_EVT_MODE_PERIODIC:
clk_enable(tcd->clk);
__raw_writel(timer_clock
| ATMEL_TC_WAVE | ATMEL_TC_WAVESEL_UP_AUTO,
regs + ATMEL_TC_REG(2, CMR));
__raw_writel((32768 + HZ/2) / HZ, tcaddr + ATMEL_TC_REG(2, RC));
__raw_writel(ATMEL_TC_CPCS, regs + ATMEL_TC_REG(2, IER));
__raw_writel(ATMEL_TC_CLKEN | ATMEL_TC_SWTRG,
regs + ATMEL_TC_REG(2, CCR));
break;
case CLOCK_EVT_MODE_ONESHOT:
clk_enable(tcd->clk);
__raw_writel(timer_clock | ATMEL_TC_CPCSTOP
| ATMEL_TC_WAVE | ATMEL_TC_WAVESEL_UP_AUTO,
regs + ATMEL_TC_REG(2, CMR));
__raw_writel(ATMEL_TC_CPCS, regs + ATMEL_TC_REG(2, IER));
break;
default:
break;
}
}
static int tc_next_event(unsigned long delta, struct clock_event_device *d)
{
__raw_writel(delta, tcaddr + ATMEL_TC_REG(2, RC));
__raw_writel(ATMEL_TC_CLKEN | ATMEL_TC_SWTRG,
tcaddr + ATMEL_TC_REG(2, CCR));
return 0;
}
static irqreturn_t ch2_irq(int irq, void *handle)
{
struct tc_clkevt_device *dev = handle;
unsigned int sr;
sr = __raw_readl(dev->regs + ATMEL_TC_REG(2, SR));
if (sr & ATMEL_TC_CPCS) {
dev->clkevt.event_handler(&dev->clkevt);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int __init setup_clkevents(struct atmel_tc *tc, int clk32k_divisor_idx)
{
int ret;
struct clk *t2_clk = tc->clk[2];
int irq = tc->irq[2];
ret = clk_prepare_enable(t2_clk);
if (ret)
return ret;
clk_disable(t2_clk);
clkevt.regs = tc->regs;
clkevt.clk = t2_clk;
tc_irqaction.dev_id = &clkevt;
timer_clock = clk32k_divisor_idx;
clkevt.clkevt.cpumask = cpumask_of(0);
ret = setup_irq(irq, &tc_irqaction);
if (ret)
return ret;
clockevents_config_and_register(&clkevt.clkevt, 32768, 1, 0xffff);
return ret;
}
static int __init setup_clkevents(struct atmel_tc *tc, int clk32k_divisor_idx)
{
return 0;
}
static void __init tcb_setup_dual_chan(struct atmel_tc *tc, int mck_divisor_idx)
{
__raw_writel(mck_divisor_idx
| ATMEL_TC_WAVE
| ATMEL_TC_WAVESEL_UP
| ATMEL_TC_ACPA_SET
| ATMEL_TC_ACPC_CLEAR,
tcaddr + ATMEL_TC_REG(0, CMR));
__raw_writel(0x0000, tcaddr + ATMEL_TC_REG(0, RA));
__raw_writel(0x8000, tcaddr + ATMEL_TC_REG(0, RC));
__raw_writel(0xff, tcaddr + ATMEL_TC_REG(0, IDR));
__raw_writel(ATMEL_TC_CLKEN, tcaddr + ATMEL_TC_REG(0, CCR));
__raw_writel(ATMEL_TC_XC1
| ATMEL_TC_WAVE
| ATMEL_TC_WAVESEL_UP,
tcaddr + ATMEL_TC_REG(1, CMR));
__raw_writel(0xff, tcaddr + ATMEL_TC_REG(1, IDR));
__raw_writel(ATMEL_TC_CLKEN, tcaddr + ATMEL_TC_REG(1, CCR));
__raw_writel(ATMEL_TC_TC1XC1S_TIOA0, tcaddr + ATMEL_TC_BMR);
__raw_writel(ATMEL_TC_SYNC, tcaddr + ATMEL_TC_BCR);
}
static void __init tcb_setup_single_chan(struct atmel_tc *tc, int mck_divisor_idx)
{
__raw_writel(mck_divisor_idx
| ATMEL_TC_WAVE
| ATMEL_TC_WAVESEL_UP,
tcaddr + ATMEL_TC_REG(0, CMR));
__raw_writel(0xff, tcaddr + ATMEL_TC_REG(0, IDR));
__raw_writel(ATMEL_TC_CLKEN, tcaddr + ATMEL_TC_REG(0, CCR));
__raw_writel(ATMEL_TC_SYNC, tcaddr + ATMEL_TC_BCR);
}
static int __init tcb_clksrc_init(void)
{
static char bootinfo[] __initdata
= KERN_DEBUG "%s: tc%d at %d.%03d MHz\n";
struct platform_device *pdev;
struct atmel_tc *tc;
struct clk *t0_clk;
u32 rate, divided_rate = 0;
int best_divisor_idx = -1;
int clk32k_divisor_idx = -1;
int i;
int ret;
tc = atmel_tc_alloc(CONFIG_ATMEL_TCB_CLKSRC_BLOCK, clksrc.name);
if (!tc) {
pr_debug("can't alloc TC for clocksource\n");
return -ENODEV;
}
tcaddr = tc->regs;
pdev = tc->pdev;
t0_clk = tc->clk[0];
ret = clk_prepare_enable(t0_clk);
if (ret) {
pr_debug("can't enable T0 clk\n");
goto err_free_tc;
}
rate = (u32) clk_get_rate(t0_clk);
for (i = 0; i < 5; i++) {
unsigned divisor = atmel_tc_divisors[i];
unsigned tmp;
if (!divisor) {
clk32k_divisor_idx = i;
continue;
}
tmp = rate / divisor;
pr_debug("TC: %u / %-3u [%d] --> %u\n", rate, divisor, i, tmp);
if (best_divisor_idx > 0) {
if (tmp < 5 * 1000 * 1000)
continue;
}
divided_rate = tmp;
best_divisor_idx = i;
}
printk(bootinfo, clksrc.name, CONFIG_ATMEL_TCB_CLKSRC_BLOCK,
divided_rate / 1000000,
((divided_rate + 500000) % 1000000) / 1000);
if (tc->tcb_config && tc->tcb_config->counter_width == 32) {
clksrc.read = tc_get_cycles32;
tcb_setup_single_chan(tc, best_divisor_idx);
} else {
ret = clk_prepare_enable(tc->clk[1]);
if (ret) {
pr_debug("can't enable T1 clk\n");
goto err_disable_t0;
}
tcb_setup_dual_chan(tc, best_divisor_idx);
}
ret = clocksource_register_hz(&clksrc, divided_rate);
if (ret)
goto err_disable_t1;
ret = setup_clkevents(tc, clk32k_divisor_idx);
if (ret)
goto err_unregister_clksrc;
return 0;
err_unregister_clksrc:
clocksource_unregister(&clksrc);
err_disable_t1:
if (!tc->tcb_config || tc->tcb_config->counter_width != 32)
clk_disable_unprepare(tc->clk[1]);
err_disable_t0:
clk_disable_unprepare(t0_clk);
err_free_tc:
atmel_tc_free(tc);
return ret;
}
