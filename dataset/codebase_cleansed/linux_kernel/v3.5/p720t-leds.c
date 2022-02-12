static void p720t_leds_event(led_event_t ledevt)
{
unsigned long flags;
u32 pddr;
local_irq_save(flags);
switch(ledevt) {
case led_idle_start:
break;
case led_idle_end:
break;
case led_timer:
pddr = clps_readb(PDDR);
clps_writeb(pddr ^ 1, PDDR);
break;
default:
break;
}
local_irq_restore(flags);
}
static int __init leds_init(void)
{
if (machine_is_p720t())
leds_event = p720t_leds_event;
return 0;
}
