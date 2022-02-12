unsigned long ioc_timer_gettimeoffset(void)
{
unsigned int count1, count2, status;
long offset;
ioc_writeb (0, IOC_T0LATCH);
barrier ();
count1 = ioc_readb(IOC_T0CNTL) | (ioc_readb(IOC_T0CNTH) << 8);
barrier ();
status = ioc_readb(IOC_IRQREQA);
barrier ();
ioc_writeb (0, IOC_T0LATCH);
barrier ();
count2 = ioc_readb(IOC_T0CNTL) | (ioc_readb(IOC_T0CNTH) << 8);
offset = count2;
if (count2 < count1) {
if (status & (1 << 5))
offset -= LATCH;
} else if (count2 > count1) {
offset -= LATCH;
}
offset = (LATCH - offset) * (tick_nsec / 1000);
return (offset + LATCH/2) / LATCH;
}
void __init ioctime_init(void)
{
ioc_writeb(LATCH & 255, IOC_T0LTCHL);
ioc_writeb(LATCH >> 8, IOC_T0LTCHH);
ioc_writeb(0, IOC_T0GO);
}
static irqreturn_t
ioc_timer_interrupt(int irq, void *dev_id)
{
timer_tick();
return IRQ_HANDLED;
}
static void __init ioc_timer_init(void)
{
ioctime_init();
setup_irq(IRQ_TIMER, &ioc_timer_irq);
}
