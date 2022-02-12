static void exynos4_mct_write(unsigned int value, void *addr)
{
void __iomem *stat_addr;
u32 mask;
u32 i;
__raw_writel(value, addr);
switch ((u32) addr) {
case (u32) EXYNOS4_MCT_G_TCON:
stat_addr = EXYNOS4_MCT_G_WSTAT;
mask = 1 << 16;
break;
case (u32) EXYNOS4_MCT_G_COMP0_L:
stat_addr = EXYNOS4_MCT_G_WSTAT;
mask = 1 << 0;
break;
case (u32) EXYNOS4_MCT_G_COMP0_U:
stat_addr = EXYNOS4_MCT_G_WSTAT;
mask = 1 << 1;
break;
case (u32) EXYNOS4_MCT_G_COMP0_ADD_INCR:
stat_addr = EXYNOS4_MCT_G_WSTAT;
mask = 1 << 2;
break;
case (u32) EXYNOS4_MCT_G_CNT_L:
stat_addr = EXYNOS4_MCT_G_CNT_WSTAT;
mask = 1 << 0;
break;
case (u32) EXYNOS4_MCT_G_CNT_U:
stat_addr = EXYNOS4_MCT_G_CNT_WSTAT;
mask = 1 << 1;
break;
case (u32)(EXYNOS4_MCT_L0_BASE + MCT_L_TCON_OFFSET):
stat_addr = EXYNOS4_MCT_L0_BASE + MCT_L_WSTAT_OFFSET;
mask = 1 << 3;
break;
case (u32)(EXYNOS4_MCT_L1_BASE + MCT_L_TCON_OFFSET):
stat_addr = EXYNOS4_MCT_L1_BASE + MCT_L_WSTAT_OFFSET;
mask = 1 << 3;
break;
case (u32)(EXYNOS4_MCT_L0_BASE + MCT_L_TCNTB_OFFSET):
stat_addr = EXYNOS4_MCT_L0_BASE + MCT_L_WSTAT_OFFSET;
mask = 1 << 0;
break;
case (u32)(EXYNOS4_MCT_L1_BASE + MCT_L_TCNTB_OFFSET):
stat_addr = EXYNOS4_MCT_L1_BASE + MCT_L_WSTAT_OFFSET;
mask = 1 << 0;
break;
case (u32)(EXYNOS4_MCT_L0_BASE + MCT_L_ICNTB_OFFSET):
stat_addr = EXYNOS4_MCT_L0_BASE + MCT_L_WSTAT_OFFSET;
mask = 1 << 1;
break;
case (u32)(EXYNOS4_MCT_L1_BASE + MCT_L_ICNTB_OFFSET):
stat_addr = EXYNOS4_MCT_L1_BASE + MCT_L_WSTAT_OFFSET;
mask = 1 << 1;
break;
default:
return;
}
for (i = 0; i < loops_per_jiffy / 1000 * HZ; i++)
if (__raw_readl(stat_addr) & mask) {
__raw_writel(mask, stat_addr);
return;
}
panic("MCT hangs after writing %d (addr:0x%08x)\n", value, (u32)addr);
}
static void exynos4_mct_frc_start(u32 hi, u32 lo)
{
u32 reg;
exynos4_mct_write(lo, EXYNOS4_MCT_G_CNT_L);
exynos4_mct_write(hi, EXYNOS4_MCT_G_CNT_U);
reg = __raw_readl(EXYNOS4_MCT_G_TCON);
reg |= MCT_G_TCON_START;
exynos4_mct_write(reg, EXYNOS4_MCT_G_TCON);
}
static cycle_t exynos4_frc_read(struct clocksource *cs)
{
unsigned int lo, hi;
u32 hi2 = __raw_readl(EXYNOS4_MCT_G_CNT_U);
do {
hi = hi2;
lo = __raw_readl(EXYNOS4_MCT_G_CNT_L);
hi2 = __raw_readl(EXYNOS4_MCT_G_CNT_U);
} while (hi != hi2);
return ((cycle_t)hi << 32) | lo;
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
tcon = __raw_readl(EXYNOS4_MCT_G_TCON);
tcon &= ~(MCT_G_TCON_COMP0_ENABLE | MCT_G_TCON_COMP0_AUTO_INC);
exynos4_mct_write(tcon, EXYNOS4_MCT_G_TCON);
exynos4_mct_write(0, EXYNOS4_MCT_G_INT_ENB);
}
static void exynos4_mct_comp0_start(enum clock_event_mode mode,
unsigned long cycles)
{
unsigned int tcon;
cycle_t comp_cycle;
tcon = __raw_readl(EXYNOS4_MCT_G_TCON);
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
exynos4_mct_comp0_stop();
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
exynos4_mct_comp0_start(mode, clk_cnt_per_tick);
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
clk_cnt_per_tick = clk_rate / 2 / HZ;
clockevents_calc_mult_shift(&mct_comp_device, clk_rate / 2, 5);
mct_comp_device.max_delta_ns =
clockevent_delta2ns(0xffffffff, &mct_comp_device);
mct_comp_device.min_delta_ns =
clockevent_delta2ns(0xf, &mct_comp_device);
mct_comp_device.cpumask = cpumask_of(0);
clockevents_register_device(&mct_comp_device);
setup_irq(IRQ_MCT_G0, &mct_comp_event_irq);
}
static void exynos4_mct_tick_stop(struct mct_clock_event_device *mevt)
{
unsigned long tmp;
unsigned long mask = MCT_L_TCON_INT_START | MCT_L_TCON_TIMER_START;
void __iomem *addr = mevt->base + MCT_L_TCON_OFFSET;
tmp = __raw_readl(addr);
if (tmp & mask) {
tmp &= ~mask;
exynos4_mct_write(tmp, addr);
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
tmp = __raw_readl(mevt->base + MCT_L_TCON_OFFSET);
tmp |= MCT_L_TCON_INT_START | MCT_L_TCON_TIMER_START |
MCT_L_TCON_INTERVAL_MODE;
exynos4_mct_write(tmp, mevt->base + MCT_L_TCON_OFFSET);
}
static int exynos4_tick_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
struct mct_clock_event_device *mevt = &mct_tick[smp_processor_id()];
exynos4_mct_tick_start(cycles, mevt);
return 0;
}
static inline void exynos4_tick_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
struct mct_clock_event_device *mevt = &mct_tick[smp_processor_id()];
exynos4_mct_tick_stop(mevt);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
exynos4_mct_tick_start(clk_cnt_per_tick, mevt);
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static irqreturn_t exynos4_mct_tick_isr(int irq, void *dev_id)
{
struct mct_clock_event_device *mevt = dev_id;
struct clock_event_device *evt = mevt->evt;
if (evt->mode != CLOCK_EVT_MODE_PERIODIC)
exynos4_mct_tick_stop(mevt);
exynos4_mct_write(0x1, mevt->base + MCT_L_INT_CSTAT_OFFSET);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void exynos4_mct_tick_init(struct clock_event_device *evt)
{
unsigned int cpu = smp_processor_id();
mct_tick[cpu].evt = evt;
if (cpu == 0) {
mct_tick[cpu].base = EXYNOS4_MCT_L0_BASE;
evt->name = "mct_tick0";
} else {
mct_tick[cpu].base = EXYNOS4_MCT_L1_BASE;
evt->name = "mct_tick1";
}
evt->cpumask = cpumask_of(cpu);
evt->set_next_event = exynos4_tick_set_next_event;
evt->set_mode = exynos4_tick_set_mode;
evt->features = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT;
evt->rating = 450;
clockevents_calc_mult_shift(evt, clk_rate / 2, 5);
evt->max_delta_ns =
clockevent_delta2ns(0x7fffffff, evt);
evt->min_delta_ns =
clockevent_delta2ns(0xf, evt);
clockevents_register_device(evt);
exynos4_mct_write(0x1, mct_tick[cpu].base + MCT_L_TCNTB_OFFSET);
if (cpu == 0) {
mct_tick0_event_irq.dev_id = &mct_tick[cpu];
setup_irq(IRQ_MCT_L0, &mct_tick0_event_irq);
} else {
mct_tick1_event_irq.dev_id = &mct_tick[cpu];
irq_set_affinity(IRQ_MCT1, cpumask_of(1));
setup_irq(IRQ_MCT_L1, &mct_tick1_event_irq);
}
}
void __cpuinit local_timer_setup(struct clock_event_device *evt)
{
exynos4_mct_tick_init(evt);
}
int local_timer_ack(void)
{
return 0;
}
static void __init exynos4_timer_resources(void)
{
struct clk *mct_clk;
mct_clk = clk_get(NULL, "xtal");
clk_rate = clk_get_rate(mct_clk);
}
static void __init exynos4_timer_init(void)
{
exynos4_timer_resources();
exynos4_clocksource_init();
exynos4_clockevent_init();
}
