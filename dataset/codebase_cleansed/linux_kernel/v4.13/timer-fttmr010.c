static inline struct fttmr010 *to_fttmr010(struct clock_event_device *evt)
{
return container_of(evt, struct fttmr010, clkevt);
}
static unsigned long fttmr010_read_current_timer_up(void)
{
return readl(local_fttmr->base + TIMER2_COUNT);
}
static unsigned long fttmr010_read_current_timer_down(void)
{
return ~readl(local_fttmr->base + TIMER2_COUNT);
}
static u64 notrace fttmr010_read_sched_clock_up(void)
{
return fttmr010_read_current_timer_up();
}
static u64 notrace fttmr010_read_sched_clock_down(void)
{
return fttmr010_read_current_timer_down();
}
static int fttmr010_timer_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
struct fttmr010 *fttmr010 = to_fttmr010(evt);
u32 cr;
cr = readl(fttmr010->base + TIMER_CR);
cr &= ~fttmr010->t1_enable_val;
writel(cr, fttmr010->base + TIMER_CR);
cr = readl(fttmr010->base + TIMER1_COUNT);
if (fttmr010->count_down)
cr -= cycles;
else
cr += cycles;
writel(cr, fttmr010->base + TIMER1_MATCH1);
cr = readl(fttmr010->base + TIMER_CR);
cr |= fttmr010->t1_enable_val;
writel(cr, fttmr010->base + TIMER_CR);
return 0;
}
static int fttmr010_timer_shutdown(struct clock_event_device *evt)
{
struct fttmr010 *fttmr010 = to_fttmr010(evt);
u32 cr;
cr = readl(fttmr010->base + TIMER_CR);
cr &= ~fttmr010->t1_enable_val;
writel(cr, fttmr010->base + TIMER_CR);
return 0;
}
static int fttmr010_timer_set_oneshot(struct clock_event_device *evt)
{
struct fttmr010 *fttmr010 = to_fttmr010(evt);
u32 cr;
cr = readl(fttmr010->base + TIMER_CR);
cr &= ~fttmr010->t1_enable_val;
writel(cr, fttmr010->base + TIMER_CR);
writel(0, fttmr010->base + TIMER1_COUNT);
if (fttmr010->count_down)
writel(~0, fttmr010->base + TIMER1_LOAD);
else
writel(0, fttmr010->base + TIMER1_LOAD);
cr = readl(fttmr010->base + TIMER_INTR_MASK);
cr &= ~(TIMER_1_INT_OVERFLOW | TIMER_1_INT_MATCH2);
cr |= TIMER_1_INT_MATCH1;
writel(cr, fttmr010->base + TIMER_INTR_MASK);
return 0;
}
static int fttmr010_timer_set_periodic(struct clock_event_device *evt)
{
struct fttmr010 *fttmr010 = to_fttmr010(evt);
u32 period = DIV_ROUND_CLOSEST(fttmr010->tick_rate, HZ);
u32 cr;
cr = readl(fttmr010->base + TIMER_CR);
cr &= ~fttmr010->t1_enable_val;
writel(cr, fttmr010->base + TIMER_CR);
if (fttmr010->count_down) {
writel(period, fttmr010->base + TIMER1_LOAD);
writel(0, fttmr010->base + TIMER1_MATCH1);
} else {
cr = 0xffffffff - (period - 1);
writel(cr, fttmr010->base + TIMER1_COUNT);
writel(cr, fttmr010->base + TIMER1_LOAD);
cr = readl(fttmr010->base + TIMER_INTR_MASK);
cr &= ~(TIMER_1_INT_MATCH1 | TIMER_1_INT_MATCH2);
cr |= TIMER_1_INT_OVERFLOW;
writel(cr, fttmr010->base + TIMER_INTR_MASK);
}
cr = readl(fttmr010->base + TIMER_CR);
cr |= fttmr010->t1_enable_val;
writel(cr, fttmr010->base + TIMER_CR);
return 0;
}
static irqreturn_t fttmr010_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int __init fttmr010_common_init(struct device_node *np, bool is_aspeed)
{
struct fttmr010 *fttmr010;
int irq;
struct clk *clk;
int ret;
u32 val;
clk = of_clk_get_by_name(np, "PCLK");
if (IS_ERR(clk)) {
pr_err("could not get PCLK\n");
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
pr_err("failed to enable PCLK\n");
return ret;
}
fttmr010 = kzalloc(sizeof(*fttmr010), GFP_KERNEL);
if (!fttmr010) {
ret = -ENOMEM;
goto out_disable_clock;
}
fttmr010->tick_rate = clk_get_rate(clk);
fttmr010->base = of_iomap(np, 0);
if (!fttmr010->base) {
pr_err("Can't remap registers");
ret = -ENXIO;
goto out_free;
}
irq = irq_of_parse_and_map(np, 0);
if (irq <= 0) {
pr_err("Can't parse IRQ");
ret = -EINVAL;
goto out_unmap;
}
if (is_aspeed) {
fttmr010->t1_enable_val = TIMER_1_CR_ASPEED_ENABLE |
TIMER_1_CR_ASPEED_INT;
fttmr010->count_down = true;
} else {
fttmr010->t1_enable_val = TIMER_1_CR_ENABLE | TIMER_1_CR_INT;
}
writel(TIMER_INT_ALL_MASK, fttmr010->base + TIMER_INTR_MASK);
writel(0, fttmr010->base + TIMER_INTR_STATE);
if (is_aspeed)
val = TIMER_2_CR_ASPEED_ENABLE;
else {
val = TIMER_2_CR_ENABLE;
if (!fttmr010->count_down)
val |= TIMER_1_CR_UPDOWN | TIMER_2_CR_UPDOWN;
}
writel(val, fttmr010->base + TIMER_CR);
local_fttmr = fttmr010;
writel(0, fttmr010->base + TIMER2_COUNT);
writel(0, fttmr010->base + TIMER2_MATCH1);
writel(0, fttmr010->base + TIMER2_MATCH2);
if (fttmr010->count_down) {
writel(~0, fttmr010->base + TIMER2_LOAD);
clocksource_mmio_init(fttmr010->base + TIMER2_COUNT,
"FTTMR010-TIMER2",
fttmr010->tick_rate,
300, 32, clocksource_mmio_readl_down);
sched_clock_register(fttmr010_read_sched_clock_down, 32,
fttmr010->tick_rate);
} else {
writel(0, fttmr010->base + TIMER2_LOAD);
clocksource_mmio_init(fttmr010->base + TIMER2_COUNT,
"FTTMR010-TIMER2",
fttmr010->tick_rate,
300, 32, clocksource_mmio_readl_up);
sched_clock_register(fttmr010_read_sched_clock_up, 32,
fttmr010->tick_rate);
}
writel(0, fttmr010->base + TIMER1_COUNT);
writel(0, fttmr010->base + TIMER1_LOAD);
writel(0, fttmr010->base + TIMER1_MATCH1);
writel(0, fttmr010->base + TIMER1_MATCH2);
ret = request_irq(irq, fttmr010_timer_interrupt, IRQF_TIMER,
"FTTMR010-TIMER1", &fttmr010->clkevt);
if (ret) {
pr_err("FTTMR010-TIMER1 no IRQ\n");
goto out_unmap;
}
fttmr010->clkevt.name = "FTTMR010-TIMER1";
fttmr010->clkevt.rating = 300;
fttmr010->clkevt.features = CLOCK_EVT_FEAT_PERIODIC |
CLOCK_EVT_FEAT_ONESHOT;
fttmr010->clkevt.set_next_event = fttmr010_timer_set_next_event;
fttmr010->clkevt.set_state_shutdown = fttmr010_timer_shutdown;
fttmr010->clkevt.set_state_periodic = fttmr010_timer_set_periodic;
fttmr010->clkevt.set_state_oneshot = fttmr010_timer_set_oneshot;
fttmr010->clkevt.tick_resume = fttmr010_timer_shutdown;
fttmr010->clkevt.cpumask = cpumask_of(0);
fttmr010->clkevt.irq = irq;
clockevents_config_and_register(&fttmr010->clkevt,
fttmr010->tick_rate,
1, 0xffffffff);
#ifdef CONFIG_ARM
if (fttmr010->count_down)
fttmr010->delay_timer.read_current_timer =
fttmr010_read_current_timer_down;
else
fttmr010->delay_timer.read_current_timer =
fttmr010_read_current_timer_up;
fttmr010->delay_timer.freq = fttmr010->tick_rate;
register_current_timer_delay(&fttmr010->delay_timer);
#endif
return 0;
out_unmap:
iounmap(fttmr010->base);
out_free:
kfree(fttmr010);
out_disable_clock:
clk_disable_unprepare(clk);
return ret;
}
static __init int aspeed_timer_init(struct device_node *np)
{
return fttmr010_common_init(np, true);
}
static __init int fttmr010_timer_init(struct device_node *np)
{
return fttmr010_common_init(np, false);
}
