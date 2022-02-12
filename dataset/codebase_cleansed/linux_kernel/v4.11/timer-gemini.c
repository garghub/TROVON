static u64 notrace gemini_read_sched_clock(void)
{
return readl(base + TIMER3_COUNT);
}
static int gemini_timer_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
u32 cr;
cr = readl(base + TIMER1_COUNT);
writel(cr + cycles, base + TIMER1_MATCH1);
if (readl(base + TIMER1_COUNT) - cr > cycles)
return -ETIME;
return 0;
}
static int gemini_timer_shutdown(struct clock_event_device *evt)
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
static int gemini_timer_set_periodic(struct clock_event_device *evt)
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
static irqreturn_t gemini_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = &gemini_clockevent;
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int __init gemini_timer_of_init(struct device_node *np)
{
static struct regmap *map;
int irq;
int ret;
u32 val;
map = syscon_regmap_lookup_by_phandle(np, "syscon");
if (IS_ERR(map)) {
pr_err("Can't get regmap for syscon handle");
return -ENODEV;
}
ret = regmap_read(map, GLOBAL_STATUS, &val);
if (ret) {
pr_err("Can't read syscon status register");
return -ENXIO;
}
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
tick_rate = REG_TO_AHB_SPEED(val) * 1000000;
printk(KERN_INFO "Bus: %dMHz", tick_rate / 1000000);
tick_rate /= 6;
switch (val & CPU_AHB_RATIO_MASK) {
case CPU_AHB_1_1:
printk(KERN_CONT "(1/1)\n");
break;
case CPU_AHB_3_2:
printk(KERN_CONT "(3/2)\n");
break;
case CPU_AHB_24_13:
printk(KERN_CONT "(24/13)\n");
break;
case CPU_AHB_2_1:
printk(KERN_CONT "(2/1)\n");
break;
}
writel(TIMER_INT_ALL_MASK, base + TIMER_INTR_MASK);
writel(0, base + TIMER_INTR_STATE);
writel(TIMER_DEFAULT_FLAGS, base + TIMER_CR);
writel(0, base + TIMER3_COUNT);
writel(0, base + TIMER3_LOAD);
writel(0, base + TIMER3_MATCH1);
writel(0, base + TIMER3_MATCH2);
clocksource_mmio_init(base + TIMER3_COUNT,
"gemini_clocksource", tick_rate,
300, 32, clocksource_mmio_readl_up);
sched_clock_register(gemini_read_sched_clock, 32, tick_rate);
writel(0, base + TIMER1_COUNT);
writel(0, base + TIMER1_LOAD);
writel(0, base + TIMER1_MATCH1);
writel(0, base + TIMER1_MATCH2);
setup_irq(irq, &gemini_timer_irq);
gemini_clockevent.cpumask = cpumask_of(0);
clockevents_config_and_register(&gemini_clockevent, tick_rate,
1, 0xffffffff);
return 0;
}
