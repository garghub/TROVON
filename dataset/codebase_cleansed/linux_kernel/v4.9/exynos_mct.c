static void exynos4_mct_write(unsigned int value, unsigned long offset)
{
unsigned long stat_addr;
u32 mask;
u32 i;
writel_relaxed(value, reg_base + offset);
if (likely(offset >= EXYNOS4_MCT_L_BASE(0))) {
stat_addr = (offset & EXYNOS4_MCT_L_MASK) + MCT_L_WSTAT_OFFSET;
switch (offset & ~EXYNOS4_MCT_L_MASK) {
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
if (readl_relaxed(reg_base + stat_addr) & mask) {
writel_relaxed(mask, reg_base + stat_addr);
return;
}
panic("MCT hangs after writing %d (offset:0x%lx)\n", value, offset);
}
static void exynos4_mct_frc_start(void)
{
u32 reg;
reg = readl_relaxed(reg_base + EXYNOS4_MCT_G_TCON);
reg |= MCT_G_TCON_START;
exynos4_mct_write(reg, EXYNOS4_MCT_G_TCON);
}
static u64 exynos4_read_count_64(void)
{
unsigned int lo, hi;
u32 hi2 = readl_relaxed(reg_base + EXYNOS4_MCT_G_CNT_U);
do {
hi = hi2;
lo = readl_relaxed(reg_base + EXYNOS4_MCT_G_CNT_L);
hi2 = readl_relaxed(reg_base + EXYNOS4_MCT_G_CNT_U);
} while (hi != hi2);
return ((cycle_t)hi << 32) | lo;
}
static u32 notrace exynos4_read_count_32(void)
{
return readl_relaxed(reg_base + EXYNOS4_MCT_G_CNT_L);
}
static cycle_t exynos4_frc_read(struct clocksource *cs)
{
return exynos4_read_count_32();
}
static void exynos4_frc_resume(struct clocksource *cs)
{
exynos4_mct_frc_start();
}
static u64 notrace exynos4_read_sched_clock(void)
{
return exynos4_read_count_32();
}
static cycles_t exynos4_read_current_timer(void)
{
BUILD_BUG_ON_MSG(sizeof(cycles_t) != sizeof(u32),
"cycles_t needs to move to 32-bit for ARM64 usage");
return exynos4_read_count_32();
}
static int __init exynos4_clocksource_init(void)
{
exynos4_mct_frc_start();
#if defined(CONFIG_ARM)
exynos4_delay_timer.read_current_timer = &exynos4_read_current_timer;
exynos4_delay_timer.freq = clk_rate;
register_current_timer_delay(&exynos4_delay_timer);
#endif
if (clocksource_register_hz(&mct_frc, clk_rate))
panic("%s: can't register clocksource\n", mct_frc.name);
sched_clock_register(exynos4_read_sched_clock, 32, clk_rate);
return 0;
}
static void exynos4_mct_comp0_stop(void)
{
unsigned int tcon;
tcon = readl_relaxed(reg_base + EXYNOS4_MCT_G_TCON);
tcon &= ~(MCT_G_TCON_COMP0_ENABLE | MCT_G_TCON_COMP0_AUTO_INC);
exynos4_mct_write(tcon, EXYNOS4_MCT_G_TCON);
exynos4_mct_write(0, EXYNOS4_MCT_G_INT_ENB);
}
static void exynos4_mct_comp0_start(bool periodic, unsigned long cycles)
{
unsigned int tcon;
cycle_t comp_cycle;
tcon = readl_relaxed(reg_base + EXYNOS4_MCT_G_TCON);
if (periodic) {
tcon |= MCT_G_TCON_COMP0_AUTO_INC;
exynos4_mct_write(cycles, EXYNOS4_MCT_G_COMP0_ADD_INCR);
}
comp_cycle = exynos4_read_count_64() + cycles;
exynos4_mct_write((u32)comp_cycle, EXYNOS4_MCT_G_COMP0_L);
exynos4_mct_write((u32)(comp_cycle >> 32), EXYNOS4_MCT_G_COMP0_U);
exynos4_mct_write(0x1, EXYNOS4_MCT_G_INT_ENB);
tcon |= MCT_G_TCON_COMP0_ENABLE;
exynos4_mct_write(tcon , EXYNOS4_MCT_G_TCON);
}
static int exynos4_comp_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
exynos4_mct_comp0_start(false, cycles);
return 0;
}
static int mct_set_state_shutdown(struct clock_event_device *evt)
{
exynos4_mct_comp0_stop();
return 0;
}
static int mct_set_state_periodic(struct clock_event_device *evt)
{
unsigned long cycles_per_jiffy;
cycles_per_jiffy = (((unsigned long long)NSEC_PER_SEC / HZ * evt->mult)
>> evt->shift);
exynos4_mct_comp0_stop();
exynos4_mct_comp0_start(true, cycles_per_jiffy);
return 0;
}
static irqreturn_t exynos4_mct_comp_isr(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
exynos4_mct_write(0x1, EXYNOS4_MCT_G_INT_CSTAT);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int exynos4_clockevent_init(void)
{
mct_comp_device.cpumask = cpumask_of(0);
clockevents_config_and_register(&mct_comp_device, clk_rate,
0xf, 0xffffffff);
setup_irq(mct_irqs[MCT_G0_IRQ], &mct_comp_event_irq);
return 0;
}
static void exynos4_mct_tick_stop(struct mct_clock_event_device *mevt)
{
unsigned long tmp;
unsigned long mask = MCT_L_TCON_INT_START | MCT_L_TCON_TIMER_START;
unsigned long offset = mevt->base + MCT_L_TCON_OFFSET;
tmp = readl_relaxed(reg_base + offset);
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
tmp = readl_relaxed(reg_base + mevt->base + MCT_L_TCON_OFFSET);
tmp |= MCT_L_TCON_INT_START | MCT_L_TCON_TIMER_START |
MCT_L_TCON_INTERVAL_MODE;
exynos4_mct_write(tmp, mevt->base + MCT_L_TCON_OFFSET);
}
static int exynos4_tick_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
struct mct_clock_event_device *mevt;
mevt = container_of(evt, struct mct_clock_event_device, evt);
exynos4_mct_tick_start(cycles, mevt);
return 0;
}
static int set_state_shutdown(struct clock_event_device *evt)
{
struct mct_clock_event_device *mevt;
mevt = container_of(evt, struct mct_clock_event_device, evt);
exynos4_mct_tick_stop(mevt);
return 0;
}
static int set_state_periodic(struct clock_event_device *evt)
{
struct mct_clock_event_device *mevt;
unsigned long cycles_per_jiffy;
mevt = container_of(evt, struct mct_clock_event_device, evt);
cycles_per_jiffy = (((unsigned long long)NSEC_PER_SEC / HZ * evt->mult)
>> evt->shift);
exynos4_mct_tick_stop(mevt);
exynos4_mct_tick_start(cycles_per_jiffy, mevt);
return 0;
}
static void exynos4_mct_tick_clear(struct mct_clock_event_device *mevt)
{
if (!clockevent_state_periodic(&mevt->evt))
exynos4_mct_tick_stop(mevt);
if (readl_relaxed(reg_base + mevt->base + MCT_L_INT_CSTAT_OFFSET) & 1)
exynos4_mct_write(0x1, mevt->base + MCT_L_INT_CSTAT_OFFSET);
}
static irqreturn_t exynos4_mct_tick_isr(int irq, void *dev_id)
{
struct mct_clock_event_device *mevt = dev_id;
struct clock_event_device *evt = &mevt->evt;
exynos4_mct_tick_clear(mevt);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int exynos4_mct_starting_cpu(unsigned int cpu)
{
struct mct_clock_event_device *mevt =
per_cpu_ptr(&percpu_mct_tick, cpu);
struct clock_event_device *evt = &mevt->evt;
mevt->base = EXYNOS4_MCT_L_BASE(cpu);
snprintf(mevt->name, sizeof(mevt->name), "mct_tick%d", cpu);
evt->name = mevt->name;
evt->cpumask = cpumask_of(cpu);
evt->set_next_event = exynos4_tick_set_next_event;
evt->set_state_periodic = set_state_periodic;
evt->set_state_shutdown = set_state_shutdown;
evt->set_state_oneshot = set_state_shutdown;
evt->set_state_oneshot_stopped = set_state_shutdown;
evt->tick_resume = set_state_shutdown;
evt->features = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT;
evt->rating = 450;
exynos4_mct_write(TICK_BASE_CNT, mevt->base + MCT_L_TCNTB_OFFSET);
if (mct_int_type == MCT_INT_SPI) {
if (evt->irq == -1)
return -EIO;
irq_force_affinity(evt->irq, cpumask_of(cpu));
enable_irq(evt->irq);
} else {
enable_percpu_irq(mct_irqs[MCT_L0_IRQ], 0);
}
clockevents_config_and_register(evt, clk_rate / (TICK_BASE_CNT + 1),
0xf, 0x7fffffff);
return 0;
}
static int exynos4_mct_dying_cpu(unsigned int cpu)
{
struct mct_clock_event_device *mevt =
per_cpu_ptr(&percpu_mct_tick, cpu);
struct clock_event_device *evt = &mevt->evt;
evt->set_state_shutdown(evt);
if (mct_int_type == MCT_INT_SPI) {
if (evt->irq != -1)
disable_irq_nosync(evt->irq);
} else {
disable_percpu_irq(mct_irqs[MCT_L0_IRQ]);
}
return 0;
}
static int __init exynos4_timer_resources(struct device_node *np, void __iomem *base)
{
int err, cpu;
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
if (mct_int_type == MCT_INT_PPI) {
err = request_percpu_irq(mct_irqs[MCT_L0_IRQ],
exynos4_mct_tick_isr, "MCT",
&percpu_mct_tick);
WARN(err, "MCT: can't request IRQ %d (%d)\n",
mct_irqs[MCT_L0_IRQ], err);
} else {
for_each_possible_cpu(cpu) {
int mct_irq = mct_irqs[MCT_L0_IRQ + cpu];
struct mct_clock_event_device *pcpu_mevt =
per_cpu_ptr(&percpu_mct_tick, cpu);
pcpu_mevt->evt.irq = -1;
irq_set_status_flags(mct_irq, IRQ_NOAUTOEN);
if (request_irq(mct_irq,
exynos4_mct_tick_isr,
IRQF_TIMER | IRQF_NOBALANCING,
pcpu_mevt->name, pcpu_mevt)) {
pr_err("exynos-mct: cannot register IRQ (cpu%d)\n",
cpu);
continue;
}
pcpu_mevt->evt.irq = mct_irq;
}
}
err = cpuhp_setup_state(CPUHP_AP_EXYNOS4_MCT_TIMER_STARTING,
"AP_EXYNOS4_MCT_TIMER_STARTING",
exynos4_mct_starting_cpu,
exynos4_mct_dying_cpu);
if (err)
goto out_irq;
return 0;
out_irq:
free_percpu_irq(mct_irqs[MCT_L0_IRQ], &percpu_mct_tick);
return err;
}
static int __init mct_init_dt(struct device_node *np, unsigned int int_type)
{
u32 nr_irqs, i;
int ret;
mct_int_type = int_type;
mct_irqs[MCT_G0_IRQ] = irq_of_parse_and_map(np, MCT_G0_IRQ);
#ifdef CONFIG_OF
nr_irqs = of_irq_count(np);
#else
nr_irqs = 0;
#endif
for (i = MCT_L0_IRQ; i < nr_irqs; i++)
mct_irqs[i] = irq_of_parse_and_map(np, i);
ret = exynos4_timer_resources(np, of_iomap(np, 0));
if (ret)
return ret;
ret = exynos4_clocksource_init();
if (ret)
return ret;
return exynos4_clockevent_init();
}
static int __init mct_init_spi(struct device_node *np)
{
return mct_init_dt(np, MCT_INT_SPI);
}
static int __init mct_init_ppi(struct device_node *np)
{
return mct_init_dt(np, MCT_INT_PPI);
}
