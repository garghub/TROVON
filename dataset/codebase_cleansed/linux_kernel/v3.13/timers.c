static irqreturn_t hw_tick(int irq, void *dummy)
{
TSTAT &= 0;
m68328_tick_cnt += TICKS_PER_JIFFY;
return timer_interrupt(irq, dummy);
}
static cycle_t m68328_read_clk(struct clocksource *cs)
{
unsigned long flags;
u32 cycles;
local_irq_save(flags);
cycles = m68328_tick_cnt + TCN;
local_irq_restore(flags);
return cycles;
}
void hw_timer_init(irq_handler_t handler)
{
TCTL = 0;
setup_irq(TMR_IRQ_NUM, &m68328_timer_irq);
TCTL = TCTL_OM | TCTL_IRQEN | CLOCK_SOURCE;
TPRER = CLOCK_PRE;
TCMP = TICKS_PER_JIFFY;
TCTL |= TCTL_TEN;
clocksource_register_hz(&m68328_clk, TICKS_PER_JIFFY*HZ);
timer_interrupt = handler;
}
int m68328_hwclk(int set, struct rtc_time *t)
{
if (!set) {
long now = RTCTIME;
t->tm_year = t->tm_mon = t->tm_mday = 1;
t->tm_hour = (now >> 24) % 24;
t->tm_min = (now >> 16) % 60;
t->tm_sec = now % 60;
}
return 0;
}
