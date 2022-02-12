static void kona_timer_disable_and_clear(void __iomem *base)
{
uint32_t reg;
reg = readl(base + KONA_GPTIMER_STCS_OFFSET);
reg |= 1 << KONA_GPTIMER_STCS_TIMER_MATCH_SHIFT;
reg &= ~(1 << KONA_GPTIMER_STCS_COMPARE_ENABLE_SHIFT);
writel(reg, base + KONA_GPTIMER_STCS_OFFSET);
}
static void
kona_timer_get_counter(void *timer_base, uint32_t *msw, uint32_t *lsw)
{
void __iomem *base = IOMEM(timer_base);
int loop_limit = 4;
while (--loop_limit) {
*msw = readl(base + KONA_GPTIMER_STCHI_OFFSET);
*lsw = readl(base + KONA_GPTIMER_STCLO_OFFSET);
if (*msw == readl(base + KONA_GPTIMER_STCHI_OFFSET))
break;
}
if (!loop_limit) {
pr_err("bcm_kona_timer: getting counter failed.\n");
pr_err(" Timer will be impacted\n");
}
return;
}
static void __init kona_timers_init(void)
{
struct device_node *node;
u32 freq;
node = of_find_matching_node(NULL, bcm_timer_ids);
if (!node)
panic("No timer");
if (!of_property_read_u32(node, "clock-frequency", &freq))
arch_timer_rate = freq;
else
panic("clock-frequency not set in the .dts file");
timers.tmr_irq = irq_of_parse_and_map(node, 0);
timers.tmr_regs = of_iomap(node, 0);
kona_timer_disable_and_clear(timers.tmr_regs);
}
static int kona_timer_set_next_event(unsigned long clc,
struct clock_event_device *unused)
{
uint32_t lsw, msw;
uint32_t reg;
kona_timer_get_counter(timers.tmr_regs, &msw, &lsw);
writel(lsw + clc, timers.tmr_regs + KONA_GPTIMER_STCM0_OFFSET);
reg = readl(timers.tmr_regs + KONA_GPTIMER_STCS_OFFSET);
reg |= (1 << KONA_GPTIMER_STCS_COMPARE_ENABLE_SHIFT);
writel(reg, timers.tmr_regs + KONA_GPTIMER_STCS_OFFSET);
return 0;
}
static void kona_timer_set_mode(enum clock_event_mode mode,
struct clock_event_device *unused)
{
switch (mode) {
case CLOCK_EVT_MODE_ONESHOT:
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
default:
kona_timer_disable_and_clear(timers.tmr_regs);
}
}
static void __init kona_timer_clockevents_init(void)
{
kona_clockevent_timer.cpumask = cpumask_of(0);
clockevents_config_and_register(&kona_clockevent_timer,
arch_timer_rate, 6, 0xffffffff);
}
static irqreturn_t kona_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = &kona_clockevent_timer;
kona_timer_disable_and_clear(timers.tmr_regs);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static void __init kona_timer_init(void)
{
kona_timers_init();
kona_timer_clockevents_init();
setup_irq(timers.tmr_irq, &kona_timer_irq);
kona_timer_set_next_event((arch_timer_rate / HZ), NULL);
}
