static inline unsigned long read_CRTR(void)
{
unsigned long x1, x2;
x1 = at91_st_read(AT91_ST_CRTR);
do {
x2 = at91_st_read(AT91_ST_CRTR);
if (x1 == x2)
break;
x1 = x2;
} while (1);
return x1;
}
static irqreturn_t at91rm9200_timer_interrupt(int irq, void *dev_id)
{
u32 sr = at91_st_read(AT91_ST_SR) & irqmask;
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
at91_st_write(AT91_ST_IDR, AT91_ST_PITS | AT91_ST_ALMS);
at91_st_read(AT91_ST_SR);
last_crtr = read_CRTR();
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
irqmask = AT91_ST_PITS;
at91_st_write(AT91_ST_PIMR, RM9200_TIMER_LATCH);
break;
case CLOCK_EVT_MODE_ONESHOT:
irqmask = AT91_ST_ALMS;
at91_st_write(AT91_ST_RTAR, last_crtr);
break;
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_RESUME:
irqmask = 0;
break;
}
at91_st_write(AT91_ST_IER, irqmask);
}
static int
clkevt32k_next_event(unsigned long delta, struct clock_event_device *dev)
{
u32 alm;
int status = 0;
BUG_ON(delta < 2);
alm = read_CRTR();
at91_st_write(AT91_ST_RTAR, alm);
at91_st_read(AT91_ST_SR);
alm += delta;
at91_st_write(AT91_ST_RTAR, alm);
return status;
}
void __init at91rm9200_ioremap_st(u32 addr)
{
at91_st_base = ioremap(addr, 256);
if (!at91_st_base)
panic("Impossible to ioremap ST\n");
}
void __init at91rm9200_timer_init(void)
{
at91_st_write(AT91_ST_IDR,
AT91_ST_PITS | AT91_ST_WDOVF | AT91_ST_RTTINC | AT91_ST_ALMS);
at91_st_read(AT91_ST_SR);
setup_irq(NR_IRQS_LEGACY + AT91_ID_SYS, &at91rm9200_timer_irq);
at91_st_write(AT91_ST_RTMR, 1);
clkevt.mult = div_sc(AT91_SLOW_CLOCK, NSEC_PER_SEC, clkevt.shift);
clkevt.max_delta_ns = clockevent_delta2ns(AT91_ST_ALMV, &clkevt);
clkevt.min_delta_ns = clockevent_delta2ns(2, &clkevt) + 1;
clkevt.cpumask = cpumask_of(0);
clockevents_register_device(&clkevt);
clocksource_register_hz(&clk32k, AT91_SLOW_CLOCK);
}
