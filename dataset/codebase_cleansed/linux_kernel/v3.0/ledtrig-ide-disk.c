void ledtrig_ide_activity(void)
{
ide_activity++;
if (!timer_pending(&ledtrig_ide_timer))
mod_timer(&ledtrig_ide_timer, jiffies + msecs_to_jiffies(10));
}
static void ledtrig_ide_timerfunc(unsigned long data)
{
if (ide_lastactivity != ide_activity) {
ide_lastactivity = ide_activity;
led_trigger_event(ledtrig_ide, INT_MAX);
mod_timer(&ledtrig_ide_timer, jiffies + msecs_to_jiffies(10));
} else {
led_trigger_event(ledtrig_ide, LED_OFF);
}
}
static int __init ledtrig_ide_init(void)
{
led_trigger_register_simple("ide-disk", &ledtrig_ide);
return 0;
}
static void __exit ledtrig_ide_exit(void)
{
led_trigger_unregister_simple(ledtrig_ide);
}
