static inline struct dw_apb_clock_event_device *
ced_to_dw_apb_ced(struct clock_event_device *evt)
{
return container_of(evt, struct dw_apb_clock_event_device, ced);
}
static inline struct dw_apb_clocksource *
clocksource_to_dw_apb_clocksource(struct clocksource *cs)
{
return container_of(cs, struct dw_apb_clocksource, cs);
}
static inline u32 apbt_readl(struct dw_apb_timer *timer, unsigned long offs)
{
return readl(timer->base + offs);
}
static inline void apbt_writel(struct dw_apb_timer *timer, u32 val,
unsigned long offs)
{
writel(val, timer->base + offs);
}
static inline u32 apbt_readl_relaxed(struct dw_apb_timer *timer, unsigned long offs)
{
return readl_relaxed(timer->base + offs);
}
static inline void apbt_writel_relaxed(struct dw_apb_timer *timer, u32 val,
unsigned long offs)
{
writel_relaxed(val, timer->base + offs);
}
static void apbt_disable_int(struct dw_apb_timer *timer)
{
u32 ctrl = apbt_readl(timer, APBTMR_N_CONTROL);
ctrl |= APBTMR_CONTROL_INT;
apbt_writel(timer, ctrl, APBTMR_N_CONTROL);
}
void dw_apb_clockevent_pause(struct dw_apb_clock_event_device *dw_ced)
{
disable_irq(dw_ced->timer.irq);
apbt_disable_int(&dw_ced->timer);
}
static void apbt_eoi(struct dw_apb_timer *timer)
{
apbt_readl_relaxed(timer, APBTMR_N_EOI);
}
static irqreturn_t dw_apb_clockevent_irq(int irq, void *data)
{
struct clock_event_device *evt = data;
struct dw_apb_clock_event_device *dw_ced = ced_to_dw_apb_ced(evt);
if (!evt->event_handler) {
pr_info("Spurious APBT timer interrupt %d", irq);
return IRQ_NONE;
}
if (dw_ced->eoi)
dw_ced->eoi(&dw_ced->timer);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void apbt_enable_int(struct dw_apb_timer *timer)
{
u32 ctrl = apbt_readl(timer, APBTMR_N_CONTROL);
apbt_readl(timer, APBTMR_N_EOI);
ctrl &= ~APBTMR_CONTROL_INT;
apbt_writel(timer, ctrl, APBTMR_N_CONTROL);
}
static int apbt_shutdown(struct clock_event_device *evt)
{
struct dw_apb_clock_event_device *dw_ced = ced_to_dw_apb_ced(evt);
u32 ctrl;
pr_debug("%s CPU %d state=shutdown\n", __func__,
cpumask_first(evt->cpumask));
ctrl = apbt_readl(&dw_ced->timer, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
apbt_writel(&dw_ced->timer, ctrl, APBTMR_N_CONTROL);
return 0;
}
static int apbt_set_oneshot(struct clock_event_device *evt)
{
struct dw_apb_clock_event_device *dw_ced = ced_to_dw_apb_ced(evt);
u32 ctrl;
pr_debug("%s CPU %d state=oneshot\n", __func__,
cpumask_first(evt->cpumask));
ctrl = apbt_readl(&dw_ced->timer, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
ctrl &= ~APBTMR_CONTROL_MODE_PERIODIC;
apbt_writel(&dw_ced->timer, ctrl, APBTMR_N_CONTROL);
apbt_writel(&dw_ced->timer, ctrl, APBTMR_N_CONTROL);
apbt_writel(&dw_ced->timer, ~0, APBTMR_N_LOAD_COUNT);
ctrl &= ~APBTMR_CONTROL_INT;
ctrl |= APBTMR_CONTROL_ENABLE;
apbt_writel(&dw_ced->timer, ctrl, APBTMR_N_CONTROL);
return 0;
}
static int apbt_set_periodic(struct clock_event_device *evt)
{
struct dw_apb_clock_event_device *dw_ced = ced_to_dw_apb_ced(evt);
unsigned long period = DIV_ROUND_UP(dw_ced->timer.freq, HZ);
u32 ctrl;
pr_debug("%s CPU %d state=periodic\n", __func__,
cpumask_first(evt->cpumask));
ctrl = apbt_readl(&dw_ced->timer, APBTMR_N_CONTROL);
ctrl |= APBTMR_CONTROL_MODE_PERIODIC;
apbt_writel(&dw_ced->timer, ctrl, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
apbt_writel(&dw_ced->timer, ctrl, APBTMR_N_CONTROL);
udelay(1);
pr_debug("Setting clock period %lu for HZ %d\n", period, HZ);
apbt_writel(&dw_ced->timer, period, APBTMR_N_LOAD_COUNT);
ctrl |= APBTMR_CONTROL_ENABLE;
apbt_writel(&dw_ced->timer, ctrl, APBTMR_N_CONTROL);
return 0;
}
static int apbt_resume(struct clock_event_device *evt)
{
struct dw_apb_clock_event_device *dw_ced = ced_to_dw_apb_ced(evt);
pr_debug("%s CPU %d state=resume\n", __func__,
cpumask_first(evt->cpumask));
apbt_enable_int(&dw_ced->timer);
return 0;
}
static int apbt_next_event(unsigned long delta,
struct clock_event_device *evt)
{
u32 ctrl;
struct dw_apb_clock_event_device *dw_ced = ced_to_dw_apb_ced(evt);
ctrl = apbt_readl_relaxed(&dw_ced->timer, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
apbt_writel_relaxed(&dw_ced->timer, ctrl, APBTMR_N_CONTROL);
apbt_writel_relaxed(&dw_ced->timer, delta, APBTMR_N_LOAD_COUNT);
ctrl |= APBTMR_CONTROL_ENABLE;
apbt_writel_relaxed(&dw_ced->timer, ctrl, APBTMR_N_CONTROL);
return 0;
}
struct dw_apb_clock_event_device *
dw_apb_clockevent_init(int cpu, const char *name, unsigned rating,
void __iomem *base, int irq, unsigned long freq)
{
struct dw_apb_clock_event_device *dw_ced =
kzalloc(sizeof(*dw_ced), GFP_KERNEL);
int err;
if (!dw_ced)
return NULL;
dw_ced->timer.base = base;
dw_ced->timer.irq = irq;
dw_ced->timer.freq = freq;
clockevents_calc_mult_shift(&dw_ced->ced, freq, APBT_MIN_PERIOD);
dw_ced->ced.max_delta_ns = clockevent_delta2ns(0x7fffffff,
&dw_ced->ced);
dw_ced->ced.min_delta_ns = clockevent_delta2ns(5000, &dw_ced->ced);
dw_ced->ced.cpumask = cpumask_of(cpu);
dw_ced->ced.features = CLOCK_EVT_FEAT_PERIODIC |
CLOCK_EVT_FEAT_ONESHOT | CLOCK_EVT_FEAT_DYNIRQ;
dw_ced->ced.set_state_shutdown = apbt_shutdown;
dw_ced->ced.set_state_periodic = apbt_set_periodic;
dw_ced->ced.set_state_oneshot = apbt_set_oneshot;
dw_ced->ced.set_state_oneshot_stopped = apbt_shutdown;
dw_ced->ced.tick_resume = apbt_resume;
dw_ced->ced.set_next_event = apbt_next_event;
dw_ced->ced.irq = dw_ced->timer.irq;
dw_ced->ced.rating = rating;
dw_ced->ced.name = name;
dw_ced->irqaction.name = dw_ced->ced.name;
dw_ced->irqaction.handler = dw_apb_clockevent_irq;
dw_ced->irqaction.dev_id = &dw_ced->ced;
dw_ced->irqaction.irq = irq;
dw_ced->irqaction.flags = IRQF_TIMER | IRQF_IRQPOLL |
IRQF_NOBALANCING;
dw_ced->eoi = apbt_eoi;
err = setup_irq(irq, &dw_ced->irqaction);
if (err) {
pr_err("failed to request timer irq\n");
kfree(dw_ced);
dw_ced = NULL;
}
return dw_ced;
}
void dw_apb_clockevent_resume(struct dw_apb_clock_event_device *dw_ced)
{
enable_irq(dw_ced->timer.irq);
}
void dw_apb_clockevent_stop(struct dw_apb_clock_event_device *dw_ced)
{
free_irq(dw_ced->timer.irq, &dw_ced->ced);
}
void dw_apb_clockevent_register(struct dw_apb_clock_event_device *dw_ced)
{
apbt_writel(&dw_ced->timer, 0, APBTMR_N_CONTROL);
clockevents_register_device(&dw_ced->ced);
apbt_enable_int(&dw_ced->timer);
}
void dw_apb_clocksource_start(struct dw_apb_clocksource *dw_cs)
{
u32 ctrl = apbt_readl(&dw_cs->timer, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
apbt_writel(&dw_cs->timer, ctrl, APBTMR_N_CONTROL);
apbt_writel(&dw_cs->timer, ~0, APBTMR_N_LOAD_COUNT);
ctrl &= ~APBTMR_CONTROL_MODE_PERIODIC;
ctrl |= (APBTMR_CONTROL_ENABLE | APBTMR_CONTROL_INT);
apbt_writel(&dw_cs->timer, ctrl, APBTMR_N_CONTROL);
dw_apb_clocksource_read(dw_cs);
}
static u64 __apbt_read_clocksource(struct clocksource *cs)
{
u32 current_count;
struct dw_apb_clocksource *dw_cs =
clocksource_to_dw_apb_clocksource(cs);
current_count = apbt_readl_relaxed(&dw_cs->timer,
APBTMR_N_CURRENT_VALUE);
return (u64)~current_count;
}
static void apbt_restart_clocksource(struct clocksource *cs)
{
struct dw_apb_clocksource *dw_cs =
clocksource_to_dw_apb_clocksource(cs);
dw_apb_clocksource_start(dw_cs);
}
struct dw_apb_clocksource *
dw_apb_clocksource_init(unsigned rating, const char *name, void __iomem *base,
unsigned long freq)
{
struct dw_apb_clocksource *dw_cs = kzalloc(sizeof(*dw_cs), GFP_KERNEL);
if (!dw_cs)
return NULL;
dw_cs->timer.base = base;
dw_cs->timer.freq = freq;
dw_cs->cs.name = name;
dw_cs->cs.rating = rating;
dw_cs->cs.read = __apbt_read_clocksource;
dw_cs->cs.mask = CLOCKSOURCE_MASK(32);
dw_cs->cs.flags = CLOCK_SOURCE_IS_CONTINUOUS;
dw_cs->cs.resume = apbt_restart_clocksource;
return dw_cs;
}
void dw_apb_clocksource_register(struct dw_apb_clocksource *dw_cs)
{
clocksource_register_hz(&dw_cs->cs, dw_cs->timer.freq);
}
u64 dw_apb_clocksource_read(struct dw_apb_clocksource *dw_cs)
{
return (u64)~apbt_readl(&dw_cs->timer, APBTMR_N_CURRENT_VALUE);
}
