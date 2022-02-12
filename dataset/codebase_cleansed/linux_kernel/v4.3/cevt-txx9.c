static cycle_t txx9_cs_read(struct clocksource *cs)
{
struct txx9_clocksource *txx9_cs =
container_of(cs, struct txx9_clocksource, cs);
return __raw_readl(&txx9_cs->tmrptr->trr);
}
static u64 notrace txx9_read_sched_clock(void)
{
return __raw_readl(&txx9_clocksource.tmrptr->trr);
}
void __init txx9_clocksource_init(unsigned long baseaddr,
unsigned int imbusclk)
{
struct txx9_tmr_reg __iomem *tmrptr;
clocksource_register_hz(&txx9_clocksource.cs, TIMER_CLK(imbusclk));
tmrptr = ioremap(baseaddr, sizeof(struct txx9_tmr_reg));
__raw_writel(TCR_BASE, &tmrptr->tcr);
__raw_writel(0, &tmrptr->tisr);
__raw_writel(TIMER_CCD, &tmrptr->ccdr);
__raw_writel(TXx9_TMITMR_TZCE, &tmrptr->itmr);
__raw_writel(1 << TXX9_CLOCKSOURCE_BITS, &tmrptr->cpra);
__raw_writel(TCR_BASE | TXx9_TMTCR_TCE, &tmrptr->tcr);
txx9_clocksource.tmrptr = tmrptr;
sched_clock_register(txx9_read_sched_clock, TXX9_CLOCKSOURCE_BITS,
TIMER_CLK(imbusclk));
}
static void txx9tmr_stop_and_clear(struct txx9_tmr_reg __iomem *tmrptr)
{
__raw_writel(TCR_BASE, &tmrptr->tcr);
__raw_writel(0, &tmrptr->tisr);
}
static int txx9tmr_set_state_periodic(struct clock_event_device *evt)
{
struct txx9_clock_event_device *txx9_cd =
container_of(evt, struct txx9_clock_event_device, cd);
struct txx9_tmr_reg __iomem *tmrptr = txx9_cd->tmrptr;
txx9tmr_stop_and_clear(tmrptr);
__raw_writel(TXx9_TMITMR_TIIE | TXx9_TMITMR_TZCE, &tmrptr->itmr);
__raw_writel(((u64)(NSEC_PER_SEC / HZ) * evt->mult) >> evt->shift,
&tmrptr->cpra);
__raw_writel(TCR_BASE | TXx9_TMTCR_TCE, &tmrptr->tcr);
return 0;
}
static int txx9tmr_set_state_oneshot(struct clock_event_device *evt)
{
struct txx9_clock_event_device *txx9_cd =
container_of(evt, struct txx9_clock_event_device, cd);
struct txx9_tmr_reg __iomem *tmrptr = txx9_cd->tmrptr;
txx9tmr_stop_and_clear(tmrptr);
__raw_writel(TXx9_TMITMR_TIIE, &tmrptr->itmr);
return 0;
}
static int txx9tmr_set_state_shutdown(struct clock_event_device *evt)
{
struct txx9_clock_event_device *txx9_cd =
container_of(evt, struct txx9_clock_event_device, cd);
struct txx9_tmr_reg __iomem *tmrptr = txx9_cd->tmrptr;
txx9tmr_stop_and_clear(tmrptr);
__raw_writel(0, &tmrptr->itmr);
return 0;
}
static int txx9tmr_tick_resume(struct clock_event_device *evt)
{
struct txx9_clock_event_device *txx9_cd =
container_of(evt, struct txx9_clock_event_device, cd);
struct txx9_tmr_reg __iomem *tmrptr = txx9_cd->tmrptr;
txx9tmr_stop_and_clear(tmrptr);
__raw_writel(TIMER_CCD, &tmrptr->ccdr);
__raw_writel(0, &tmrptr->itmr);
return 0;
}
static int txx9tmr_set_next_event(unsigned long delta,
struct clock_event_device *evt)
{
struct txx9_clock_event_device *txx9_cd =
container_of(evt, struct txx9_clock_event_device, cd);
struct txx9_tmr_reg __iomem *tmrptr = txx9_cd->tmrptr;
txx9tmr_stop_and_clear(tmrptr);
__raw_writel(delta, &tmrptr->cpra);
__raw_writel(TCR_BASE | TXx9_TMTCR_TCE, &tmrptr->tcr);
return 0;
}
static irqreturn_t txx9tmr_interrupt(int irq, void *dev_id)
{
struct txx9_clock_event_device *txx9_cd = dev_id;
struct clock_event_device *cd = &txx9_cd->cd;
struct txx9_tmr_reg __iomem *tmrptr = txx9_cd->tmrptr;
__raw_writel(0, &tmrptr->tisr);
cd->event_handler(cd);
return IRQ_HANDLED;
}
void __init txx9_clockevent_init(unsigned long baseaddr, int irq,
unsigned int imbusclk)
{
struct clock_event_device *cd = &txx9_clock_event_device.cd;
struct txx9_tmr_reg __iomem *tmrptr;
tmrptr = ioremap(baseaddr, sizeof(struct txx9_tmr_reg));
txx9tmr_stop_and_clear(tmrptr);
__raw_writel(TIMER_CCD, &tmrptr->ccdr);
__raw_writel(0, &tmrptr->itmr);
txx9_clock_event_device.tmrptr = tmrptr;
clockevent_set_clock(cd, TIMER_CLK(imbusclk));
cd->max_delta_ns =
clockevent_delta2ns(0xffffffff >> (32 - TXX9_TIMER_BITS), cd);
cd->min_delta_ns = clockevent_delta2ns(0xf, cd);
cd->irq = irq;
cd->cpumask = cpumask_of(0),
clockevents_register_device(cd);
setup_irq(irq, &txx9tmr_irq);
printk(KERN_INFO "TXx9: clockevent device at 0x%lx, irq %d\n",
baseaddr, irq);
}
void __init txx9_tmr_init(unsigned long baseaddr)
{
struct txx9_tmr_reg __iomem *tmrptr;
tmrptr = ioremap(baseaddr, sizeof(struct txx9_tmr_reg));
__raw_writel(TXx9_TMTCR_CRE | TXx9_TMTCR_TCE, &tmrptr->tcr);
__raw_writel(TXx9_TMTCR_CRE, &tmrptr->tcr);
__raw_writel(0, &tmrptr->tisr);
__raw_writel(0xffffffff, &tmrptr->cpra);
__raw_writel(0, &tmrptr->itmr);
__raw_writel(0, &tmrptr->ccdr);
__raw_writel(0, &tmrptr->pgmr);
iounmap(tmrptr);
}
