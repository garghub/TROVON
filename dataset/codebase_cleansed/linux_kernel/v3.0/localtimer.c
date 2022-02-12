int __cpuinit local_timer_setup(struct clock_event_device *evt)
{
evt->irq = IRQ_LOCALTIMER;
twd_timer_setup(evt);
return 0;
}
