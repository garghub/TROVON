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
while (((crtr - last_crtr) & AT91_ST_CRTV) >= RM9200_TIMER_LATCH) {
last_crtr += RM9200_TIMER_LATCH;
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
static void
clkevt32k_mode(enum clock_event_mode mode, struct clock_event_device *dev)
{
unsigned int val;
regmap_write(regmap_st, AT91_ST_IDR, AT91_ST_PITS | AT91_ST_ALMS);
regmap_read(regmap_st, AT91_ST_SR, &val);
last_crtr = read_CRTR();
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
irqmask = AT91_ST_PITS;
regmap_write(regmap_st, AT91_ST_PIMR, RM9200_TIMER_LATCH);
break;
case CLOCK_EVT_MODE_ONESHOT:
irqmask = AT91_ST_ALMS;
regmap_write(regmap_st, AT91_ST_RTAR, last_crtr);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_RESUME:
irqmask = 0;
break;
}
regmap_write(regmap_st, AT91_ST_IER, irqmask);
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
static void __init atmel_st_timer_init(struct device_node *node)
{
unsigned int val;
int irq, ret;
regmap_st = syscon_node_to_regmap(node);
if (IS_ERR(regmap_st))
panic(pr_fmt("Unable to get regmap\n"));
regmap_write(regmap_st, AT91_ST_IDR,
AT91_ST_PITS | AT91_ST_WDOVF | AT91_ST_RTTINC | AT91_ST_ALMS);
regmap_read(regmap_st, AT91_ST_SR, &val);
irq = irq_of_parse_and_map(node, 0);
if (!irq)
panic(pr_fmt("Unable to get IRQ from DT\n"));
ret = request_irq(irq, at91rm9200_timer_interrupt,
IRQF_SHARED | IRQF_TIMER | IRQF_IRQPOLL,
"at91_tick", regmap_st);
if (ret)
panic(pr_fmt("Unable to setup IRQ\n"));
regmap_write(regmap_st, AT91_ST_RTMR, 1);
clkevt.cpumask = cpumask_of(0);
clockevents_config_and_register(&clkevt, AT91_SLOW_CLOCK,
2, AT91_ST_ALMV);
clocksource_register_hz(&clk32k, AT91_SLOW_CLOCK);
}
