void ledtrig_disk_activity(void)
{
unsigned long blink_delay = BLINK_DELAY;
led_trigger_blink_oneshot(ledtrig_disk,
&blink_delay, &blink_delay, 0);
led_trigger_blink_oneshot(ledtrig_ide,
&blink_delay, &blink_delay, 0);
}
static int __init ledtrig_disk_init(void)
{
led_trigger_register_simple("disk-activity", &ledtrig_disk);
led_trigger_register_simple("ide-disk", &ledtrig_ide);
return 0;
}
