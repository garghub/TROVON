void ledtrig_mtd_activity(void)
{
unsigned long blink_delay = BLINK_DELAY;
led_trigger_blink_oneshot(ledtrig_mtd,
&blink_delay, &blink_delay, 0);
led_trigger_blink_oneshot(ledtrig_nand,
&blink_delay, &blink_delay, 0);
}
static int __init ledtrig_mtd_init(void)
{
led_trigger_register_simple("mtd", &ledtrig_mtd);
led_trigger_register_simple("nand-disk", &ledtrig_nand);
return 0;
}
