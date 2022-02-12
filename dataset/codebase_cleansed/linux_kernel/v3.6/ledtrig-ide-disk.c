void ledtrig_ide_activity(void)
{
led_trigger_blink_oneshot(ledtrig_ide,
&ide_blink_delay, &ide_blink_delay, 0);
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
