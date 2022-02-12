int __cpuinit local_timer_setup(struct clock_event_device *evt)
{
if (omap_rev() == OMAP4430_REV_ES1_0)
return -ENXIO;
evt->irq = OMAP44XX_IRQ_LOCALTIMER;
twd_timer_setup(evt);
return 0;
}
