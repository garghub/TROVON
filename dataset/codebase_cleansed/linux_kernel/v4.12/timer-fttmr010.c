static u64 notrace fttmr010_read_sched_clock(void)
{
return readl(base + TIMER3_COUNT);
}
static int fttmr010_timer_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
u32 cr;
cr = readl(base + TIMER1_COUNT);
writel(cr + cycles, base + TIMER1_MATCH1);
if (readl(base + TIMER1_COUNT) - cr > cycles)
return -ETIME;
return 0;
}
static int fttmr010_timer_shutdown(struct clock_event_device *evt)
{
u32 cr;
cr = readl(base + TIMER_CR);
cr &= ~(TIMER_1_CR_ENABLE | TIMER_1_CR_INT);
writel(cr, base + TIMER_CR);
writel(0, base + TIMER1_COUNT);
writel(0, base + TIMER1_LOAD);
cr = readl(base + TIMER_INTR_MASK);
cr &= ~(TIMER_1_INT_OVERFLOW | TIMER_1_INT_MATCH2);
cr |= TIMER_1_INT_MATCH1;
writel(cr, base + TIMER_INTR_MASK);
cr = readl(base + TIMER_CR);
cr |= TIMER_1_CR_ENABLE;
writel(cr, base + TIMER_CR);
return 0;
}
static int fttmr010_timer_set_periodic(struct clock_event_device *evt)
{
u32 period = DIV_ROUND_CLOSEST(tick_rate, HZ);
u32 cr;
cr = readl(base + TIMER_CR);
cr &= ~(TIMER_1_CR_ENABLE | TIMER_1_CR_INT);
writel(cr, base + TIMER_CR);
cr = 0xffffffff - (period - 1);
writel(cr, base + TIMER1_COUNT);
writel(cr, base + TIMER1_LOAD);
cr = readl(base + TIMER_INTR_MASK);
cr &= ~(TIMER_1_INT_MATCH1 | TIMER_1_INT_MATCH2);
cr |= TIMER_1_INT_OVERFLOW;
writel(cr, base + TIMER_INTR_MASK);
cr = readl(base + TIMER_CR);
cr |= TIMER_1_CR_ENABLE;
cr |= TIMER_1_CR_INT;
writel(cr, base + TIMER_CR);
return 0;
}
static irqreturn_t fttmr010_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = &fttmr010_clockevent;
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int __init fttmr010_timer_common_init(struct device_node *np)
{
int irq;
base = of_iomap(np, 0);
if (!base) {
pr_err("Can't remap registers");
return -ENXIO;
}
irq = irq_of_parse_and_map(np, 0);
if (irq <= 0) {
pr_err("Can't parse IRQ");
return -EINVAL;
}
writel(TIMER_INT_ALL_MASK, base + TIMER_INTR_MASK);
writel(0, base + TIMER_INTR_STATE);
writel(TIMER_DEFAULT_FLAGS, base + TIMER_CR);
writel(0, base + TIMER3_COUNT);
writel(0, base + TIMER3_LOAD);
writel(0, base + TIMER3_MATCH1);
writel(0, base + TIMER3_MATCH2);
clocksource_mmio_init(base + TIMER3_COUNT,
"fttmr010_clocksource", tick_rate,
300, 32, clocksource_mmio_readl_up);
sched_clock_register(fttmr010_read_sched_clock, 32, tick_rate);
writel(0, base + TIMER1_COUNT);
writel(0, base + TIMER1_LOAD);
writel(0, base + TIMER1_MATCH1);
writel(0, base + TIMER1_MATCH2);
setup_irq(irq, &fttmr010_timer_irq);
fttmr010_clockevent.cpumask = cpumask_of(0);
clockevents_config_and_register(&fttmr010_clockevent, tick_rate,
1, 0xffffffff);
return 0;
}
static int __init fttmr010_timer_of_init(struct device_node *np)
{
struct clk *clk;
clk = of_clk_get_by_name(np, "PCLK");
if (IS_ERR(clk)) {
pr_err("could not get PCLK");
return PTR_ERR(clk);
}
tick_rate = clk_get_rate(clk);
return fttmr010_timer_common_init(np);
}
static int __init gemini_timer_of_init(struct device_node *np)
{
static struct regmap *map;
int ret;
u32 val;
map = syscon_regmap_lookup_by_phandle(np, "syscon");
if (IS_ERR(map)) {
pr_err("Can't get regmap for syscon handle\n");
return -ENODEV;
}
ret = regmap_read(map, GLOBAL_STATUS, &val);
if (ret) {
pr_err("Can't read syscon status register\n");
return -ENXIO;
}
tick_rate = REG_TO_AHB_SPEED(val) * 1000000;
pr_info("Bus: %dMHz ", tick_rate / 1000000);
tick_rate /= 6;
switch (val & CPU_AHB_RATIO_MASK) {
case CPU_AHB_1_1:
pr_cont("(1/1)\n");
break;
case CPU_AHB_3_2:
pr_cont("(3/2)\n");
break;
case CPU_AHB_24_13:
pr_cont("(24/13)\n");
break;
case CPU_AHB_2_1:
pr_cont("(2/1)\n");
break;
}
return fttmr010_timer_common_init(np);
}
