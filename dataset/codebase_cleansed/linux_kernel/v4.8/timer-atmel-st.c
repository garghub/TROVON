static inline unsigned long read_CRTR(void)
{
unsigned int x1, x2;
regmap_read(regmap_st, AT91_ST_CRTR, &x1);
do {
regmap_read(regmap_st, AT91_ST_CRTR, &x2);
if (x1 == x2)
break;
x1 = x2;
} while (1);
return x1;
}
static irqreturn_t at91rm9200_timer_interrupt(int irq, void *dev_id)
{
u32 sr;
regmap_read(regmap_st, AT91_ST_SR, &sr);
sr &= irqmask;
WARN_ON_ONCE(!irqs_disabled());
if (sr & AT91_ST_ALMS) {
clkevt.event_handler(&clkevt);
return IRQ_HANDLED;
}
if (sr & AT91_ST_PITS) {
u32 crtr = read_CRTR();
while (((crtr - last_crtr) & AT91_ST_CRTV) >= timer_latch) {
last_crtr += timer_latch;
clkevt.event_handler(&clkevt);
}
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static cycle_t read_clk32k(struct clocksource *cs)
{
return read_CRTR();
}
static void clkdev32k_disable_and_flush_irq(void)
{
unsigned int val;
regmap_write(regmap_st, AT91_ST_IDR, AT91_ST_PITS | AT91_ST_ALMS);
regmap_read(regmap_st, AT91_ST_SR, &val);
last_crtr = read_CRTR();
}
static int clkevt32k_shutdown(struct clock_event_device *evt)
{
clkdev32k_disable_and_flush_irq();
irqmask = 0;
regmap_write(regmap_st, AT91_ST_IER, irqmask);
return 0;
}
static int clkevt32k_set_oneshot(struct clock_event_device *dev)
{
clkdev32k_disable_and_flush_irq();
irqmask = AT91_ST_ALMS;
regmap_write(regmap_st, AT91_ST_RTAR, last_crtr);
regmap_write(regmap_st, AT91_ST_IER, irqmask);
return 0;
}
static int clkevt32k_set_periodic(struct clock_event_device *dev)
{
clkdev32k_disable_and_flush_irq();
irqmask = AT91_ST_PITS;
regmap_write(regmap_st, AT91_ST_PIMR, timer_latch);
regmap_write(regmap_st, AT91_ST_IER, irqmask);
return 0;
}
static int
clkevt32k_next_event(unsigned long delta, struct clock_event_device *dev)
{
u32 alm;
int status = 0;
unsigned int val;
BUG_ON(delta < 2);
alm = read_CRTR();
regmap_write(regmap_st, AT91_ST_RTAR, alm);
regmap_read(regmap_st, AT91_ST_SR, &val);
alm += delta;
regmap_write(regmap_st, AT91_ST_RTAR, alm);
return status;
}
static int __init atmel_st_timer_init(struct device_node *node)
{
struct clk *sclk;
unsigned int sclk_rate, val;
int irq, ret;
regmap_st = syscon_node_to_regmap(node);
if (IS_ERR(regmap_st)) {
pr_err("Unable to get regmap\n");
return PTR_ERR(regmap_st);
}
regmap_write(regmap_st, AT91_ST_IDR,
AT91_ST_PITS | AT91_ST_WDOVF | AT91_ST_RTTINC | AT91_ST_ALMS);
regmap_read(regmap_st, AT91_ST_SR, &val);
irq = irq_of_parse_and_map(node, 0);
if (!irq) {
pr_err("Unable to get IRQ from DT\n");
return -EINVAL;
}
ret = request_irq(irq, at91rm9200_timer_interrupt,
IRQF_SHARED | IRQF_TIMER | IRQF_IRQPOLL,
"at91_tick", regmap_st);
if (ret) {
pr_err("Unable to setup IRQ\n");
return ret;
}
sclk = of_clk_get(node, 0);
if (IS_ERR(sclk)) {
pr_err("Unable to get slow clock\n");
return PTR_ERR(sclk);
}
ret = clk_prepare_enable(sclk);
if (ret) {
pr_err("Could not enable slow clock\n");
return ret;
}
sclk_rate = clk_get_rate(sclk);
if (!sclk_rate) {
pr_err("Invalid slow clock rate\n");
return -EINVAL;
}
timer_latch = (sclk_rate + HZ / 2) / HZ;
regmap_write(regmap_st, AT91_ST_RTMR, 1);
clkevt.cpumask = cpumask_of(0);
clockevents_config_and_register(&clkevt, sclk_rate,
2, AT91_ST_ALMV);
return clocksource_register_hz(&clk32k, sclk_rate);
}
