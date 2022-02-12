static void exynos4_mct_write(unsigned int value, unsigned long offset)
{
unsigned long stat_addr;
u32 mask;
u32 i;
__raw_writel(value, reg_base + offset);
if (likely(offset >= EXYNOS4_MCT_L_BASE(0))) {
stat_addr = (offset & ~EXYNOS4_MCT_L_MASK) + MCT_L_WSTAT_OFFSET;
switch (offset & EXYNOS4_MCT_L_MASK) {
case MCT_L_TCON_OFFSET:
mask = 1 << 3;
break;
case MCT_L_ICNTB_OFFSET:
mask = 1 << 1;
break;
case MCT_L_TCNTB_OFFSET:
mask = 1 << 0;
break;
default:
return;
}
} else {
switch (offset) {
case EXYNOS4_MCT_G_TCON:
stat_addr = EXYNOS4_MCT_G_WSTAT;
mask = 1 << 16;
break;
case EXYNOS4_MCT_G_COMP0_L:
stat_addr = EXYNOS4_MCT_G_WSTAT;
mask = 1 << 0;
break;
case EXYNOS4_MCT_G_COMP0_U:
stat_addr = EXYNOS4_MCT_G_WSTAT;
mask = 1 << 1;
break;
case EXYNOS4_MCT_G_COMP0_ADD_INCR:
stat_addr = EXYNOS4_MCT_G_WSTAT;
mask = 1 << 2;
break;
case EXYNOS4_MCT_G_CNT_L:
stat_addr = EXYNOS4_MCT_G_CNT_WSTAT;
mask = 1 << 0;
break;
case EXYNOS4_MCT_G_CNT_U:
stat_addr = EXYNOS4_MCT_G_CNT_WSTAT;
mask = 1 << 1;
break;
default:
return;
}
}
for (i = 0; i < loops_per_jiffy / 1000 * HZ; i++)
if (__raw_readl(reg_base + stat_addr) & mask) {
__raw_writel(mask, reg_base + stat_addr);
return;
}
panic("MCT hangs after writing %d (offset:0x%lx)\n", value, offset);
}
static void exynos4_mct_frc_start(u32 hi, u32 lo)
{
u32 reg;
exynos4_mct_write(lo, EXYNOS4_MCT_G_CNT_L);
exynos4_mct_write(hi, EXYNOS4_MCT_G_CNT_U);
reg = __raw_readl(reg_base + EXYNOS4_MCT_G_TCON);
reg |= MCT_G_TCON_START;
exynos4_mct_write(reg, EXYNOS4_MCT_G_TCON);
}
static cycle_t exynos4_frc_read(struct clocksource *cs)
{
unsigned int lo, hi;
u32 hi2 = __raw_readl(reg_base + EXYNOS4_MCT_G_CNT_U);
do {
hi = hi2;
lo = __raw_readl(reg_base + EXYNOS4_MCT_G_CNT_L);
hi2 = __raw_readl(reg_base + EXYNOS4_MCT_G_CNT_U);
} while (hi != hi2);
return ((cycle_t)hi << 32) | lo;
}
static void exynos4_frc_resume(struct clocksource *cs)
{
exynos4_mct_frc_start(0, 0);
}
static void __init exynos4_clocksource_init(void)
{
exynos4_mct_frc_start(0, 0);
if (clocksource_register_hz(&mct_frc, clk_rate))
panic("%s: can't register clocksource\n", mct_frc.name);
}
static void exynos4_mct_comp0_stop(void)
{
unsigned int tcon;
tcon = __raw_readl(reg_base + EXYNOS4_MCT_G_TCON);
tcon &= ~(MCT_G_TCON_COMP0_ENABLE | MCT_G_TCON_COMP0_AUTO_INC);
exynos4_mct_write(tcon, EXYNOS4_MCT_G_TCON);
exynos4_mct_write(0, EXYNOS4_MCT_G_INT_ENB);
}
static void exynos4_mct_comp0_start(enum clock_event_mode mode,
unsigned long cycles)
{
unsigned int tcon;
cycle_t comp_cycle;
tcon = __raw_readl(reg_base + EXYNOS4_MCT_G_TCON);
if (mode == CLOCK_EVT_MODE_PERIODIC) {
tcon |= MCT_G_TCON_COMP0_AUTO_INC;
exynos4_mct_write(cycles, EXYNOS4_MCT_G_COMP0_ADD_INCR);
}
comp_cycle = exynos4_frc_read(&mct_frc) + cycles;
exynos4_mct_write((u32)comp_cycle, EXYNOS4_MCT_G_COMP0_L);
exynos4_mct_write((u32)(comp_cycle >> 32), EXYNOS4_MCT_G_COMP0_U);
exynos4_mct_write(0x1, EXYNOS4_MCT_G_INT_ENB);
tcon |= MCT_G_TCON_COMP0_ENABLE;
exynos4_mct_write(tcon , EXYNOS4_MCT_G_TCON);
}
static int exynos4_comp_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
exynos4_mct_comp0_start(evt->mode, cycles);
return 0;
}
static void exynos4_comp_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
unsigned long cycles_per_jiffy;
exynos4_mct_comp0_stop();
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
cycles_per_jiffy =
(((unsigned long long) NSEC_PER_SEC / HZ * evt->mult) >> evt->shift);
exynos4_mct_comp0_start(mode, cycles_per_jiffy);
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static irqreturn_t exynos4_mct_comp_isr(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
exynos4_mct_write(0x1, EXYNOS4_MCT_G_INT_CSTAT);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void exynos4_clockevent_init(void)
{
mct_comp_device.cpumask = cpumask_of(0);
clockevents_config_and_register(&mct_comp_device, clk_rate,
0xf, 0xffffffff);
setup_irq(mct_irqs[MCT_G0_IRQ], &mct_comp_event_irq);
}
static void exynos4_mct_tick_stop(struct mct_clock_event_device *mevt)
{
unsigned long tmp;
unsigned long mask = MCT_L_TCON_INT_START | MCT_L_TCON_TIMER_START;
unsigned long offset = mevt->base + MCT_L_TCON_OFFSET;
tmp = __raw_readl(reg_base + offset);
if (tmp & mask) {
tmp &= ~mask;
exynos4_mct_write(tmp, offset);
}
}
static void exynos4_mct_tick_start(unsigned long cycles,
struct mct_clock_event_device *mevt)
{
unsigned long tmp;
exynos4_mct_tick_stop(mevt);
tmp = (1 << 31) | cycles;
exynos4_mct_write(tmp, mevt->base + MCT_L_ICNTB_OFFSET);
exynos4_mct_write(0x1, mevt->base + MCT_L_INT_ENB_OFFSET);
tmp = __raw_readl(reg_base + mevt->base + MCT_L_TCON_OFFSET);
tmp |= MCT_L_TCON_INT_START | MCT_L_TCON_TIMER_START |
MCT_L_TCON_INTERVAL_MODE;
exynos4_mct_write(tmp, mevt->base + MCT_L_TCON_OFFSET);
}
static int exynos4_tick_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
struct mct_clock_event_device *mevt = this_cpu_ptr(&percpu_mct_tick);
exynos4_mct_tick_start(cycles, mevt);
return 0;
}
static inline void exynos4_tick_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
struct mct_clock_event_device *mevt = this_cpu_ptr(&percpu_mct_tick);
unsigned long cycles_per_jiffy;
exynos4_mct_tick_stop(mevt);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
cycles_per_jiffy =
(((unsigned long long) NSEC_PER_SEC / HZ * evt->mult) >> evt->shift);
exynos4_mct_tick_start(cycles_per_jiffy, mevt);
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static int exynos4_mct_tick_clear(struct mct_clock_event_device *mevt)
{
struct clock_event_device *evt = mevt->evt;
if (evt->mode != CLOCK_EVT_MODE_PERIODIC)
exynos4_mct_tick_stop(mevt);
if (__raw_readl(reg_base + mevt->base + MCT_L_INT_CSTAT_OFFSET) & 1) {
exynos4_mct_write(0x1, mevt->base + MCT_L_INT_CSTAT_OFFSET);
return 1;
} else {
return 0;
}
}
static irqreturn_t exynos4_mct_tick_isr(int irq, void *dev_id)
{
struct mct_clock_event_device *mevt = dev_id;
struct clock_event_device *evt = mevt->evt;
exynos4_mct_tick_clear(mevt);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int exynos4_local_timer_setup(struct clock_event_device *evt)
{
struct mct_clock_event_device *mevt;
unsigned int cpu = smp_processor_id();
mevt = this_cpu_ptr(&percpu_mct_tick);
mevt->evt = evt;
mevt->base = EXYNOS4_MCT_L_BASE(cpu);
sprintf(mevt->name, "mct_tick%d", cpu);
evt->name = mevt->name;
evt->cpumask = cpumask_of(cpu);
evt->set_next_event = exynos4_tick_set_next_event;
evt->set_mode = exynos4_tick_set_mode;
evt->features = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT;
evt->rating = 450;
clockevents_config_and_register(evt, clk_rate / (TICK_BASE_CNT + 1),
0xf, 0x7fffffff);
exynos4_mct_write(TICK_BASE_CNT, mevt->base + MCT_L_TCNTB_OFFSET);
if (mct_int_type == MCT_INT_SPI) {
evt->irq = mct_irqs[MCT_L0_IRQ + cpu];
if (request_irq(evt->irq, exynos4_mct_tick_isr,
IRQF_TIMER | IRQF_NOBALANCING,
evt->name, mevt)) {
pr_err("exynos-mct: cannot register IRQ %d\n",
evt->irq);
return -EIO;
}
irq_set_affinity(evt->irq, cpumask_of(cpu));
} else {
enable_percpu_irq(mct_irqs[MCT_L0_IRQ], 0);
}
return 0;
}
static void exynos4_local_timer_stop(struct clock_event_device *evt)
{
evt->set_mode(CLOCK_EVT_MODE_UNUSED, evt);
if (mct_int_type == MCT_INT_SPI)
free_irq(evt->irq, this_cpu_ptr(&percpu_mct_tick));
else
disable_percpu_irq(mct_irqs[MCT_L0_IRQ]);
}
static void __init exynos4_timer_resources(struct device_node *np, void __iomem *base)
{
struct clk *mct_clk, *tick_clk;
tick_clk = np ? of_clk_get_by_name(np, "fin_pll") :
clk_get(NULL, "fin_pll");
if (IS_ERR(tick_clk))
panic("%s: unable to determine tick clock rate\n", __func__);
clk_rate = clk_get_rate(tick_clk);
mct_clk = np ? of_clk_get_by_name(np, "mct") : clk_get(NULL, "mct");
if (IS_ERR(mct_clk))
panic("%s: unable to retrieve mct clock instance\n", __func__);
clk_prepare_enable(mct_clk);
reg_base = base;
if (!reg_base)
panic("%s: unable to ioremap mct address space\n", __func__);
#ifdef CONFIG_LOCAL_TIMERS
if (mct_int_type == MCT_INT_PPI) {
int err;
err = request_percpu_irq(mct_irqs[MCT_L0_IRQ],
exynos4_mct_tick_isr, "MCT",
&percpu_mct_tick);
WARN(err, "MCT: can't request IRQ %d (%d)\n",
mct_irqs[MCT_L0_IRQ], err);
}
local_timer_register(&exynos4_mct_tick_ops);
#endif
}
void __init mct_init(void __iomem *base, int irq_g0, int irq_l0, int irq_l1)
{
mct_irqs[MCT_G0_IRQ] = irq_g0;
mct_irqs[MCT_L0_IRQ] = irq_l0;
mct_irqs[MCT_L1_IRQ] = irq_l1;
mct_int_type = MCT_INT_SPI;
exynos4_timer_resources(NULL, base);
exynos4_clocksource_init();
exynos4_clockevent_init();
}
static void __init mct_init_dt(struct device_node *np, unsigned int int_type)
{
u32 nr_irqs, i;
mct_int_type = int_type;
mct_irqs[MCT_G0_IRQ] = irq_of_parse_and_map(np, MCT_G0_IRQ);
#ifdef CONFIG_OF
nr_irqs = of_irq_count(np);
#else
nr_irqs = 0;
#endif
for (i = MCT_L0_IRQ; i < nr_irqs; i++)
mct_irqs[i] = irq_of_parse_and_map(np, i);
exynos4_timer_resources(np, of_iomap(np, 0));
exynos4_clocksource_init();
exynos4_clockevent_init();
}
static void __init mct_init_spi(struct device_node *np)
{
return mct_init_dt(np, MCT_INT_SPI);
}
static void __init mct_init_ppi(struct device_node *np)
{
return mct_init_dt(np, MCT_INT_PPI);
}
