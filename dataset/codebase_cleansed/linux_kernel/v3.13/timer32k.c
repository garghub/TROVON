static inline void omap_32k_timer_write(int val, int reg)
{
omap_writew(val, OMAP1_32K_TIMER_BASE + reg);
}
static inline unsigned long omap_32k_timer_read(int reg)
{
return omap_readl(OMAP1_32K_TIMER_BASE + reg) & 0xffffff;
}
static inline void omap_32k_timer_start(unsigned long load_val)
{
if (!load_val)
load_val = 1;
omap_32k_timer_write(load_val, OMAP1_32K_TIMER_TVR);
omap_32k_timer_write(0x0f, OMAP1_32K_TIMER_CR);
}
static inline void omap_32k_timer_stop(void)
{
omap_32k_timer_write(0x0, OMAP1_32K_TIMER_CR);
}
static int omap_32k_timer_set_next_event(unsigned long delta,
struct clock_event_device *dev)
{
omap_32k_timer_start(delta);
return 0;
}
static void omap_32k_timer_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
omap_32k_timer_stop();
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
omap_32k_timer_start(OMAP_32K_TIMER_TICK_PERIOD);
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
break;
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static irqreturn_t omap_32k_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = &clockevent_32k_timer;
omap_32k_timer_ack_irq();
evt->event_handler(evt);
return IRQ_HANDLED;
}
static __init void omap_init_32k_timer(void)
{
setup_irq(INT_OS_TIMER, &omap_32k_timer_irq);
clockevent_32k_timer.cpumask = cpumask_of(0);
clockevents_config_and_register(&clockevent_32k_timer,
OMAP_32K_TICKS_PER_SEC, 1, 0xfffffffe);
}
int __init omap_32k_timer_init(void)
{
int ret = -ENODEV;
if (cpu_is_omap16xx()) {
void __iomem *base;
struct clk *sync32k_ick;
base = ioremap(OMAP1_32KSYNC_TIMER_BASE, SZ_1K);
if (!base) {
pr_err("32k_counter: failed to map base addr\n");
return -ENODEV;
}
sync32k_ick = clk_get(NULL, "omap_32ksync_ick");
if (!IS_ERR(sync32k_ick))
clk_enable(sync32k_ick);
ret = omap_init_clocksource_32k(base);
}
if (!ret)
omap_init_32k_timer();
return ret;
}
