void ledtrig_flash_ctrl(bool on)
{
enum led_brightness brt = on ? LED_FULL : LED_OFF;
led_trigger_event(ledtrig_flash, brt);
}
void ledtrig_torch_ctrl(bool on)
{
enum led_brightness brt = on ? LED_FULL : LED_OFF;
led_trigger_event(ledtrig_torch, brt);
}
static int __init ledtrig_camera_init(void)
{
led_trigger_register_simple("flash", &ledtrig_flash);
led_trigger_register_simple("torch", &ledtrig_torch);
return 0;
}
static void __exit ledtrig_camera_exit(void)
{
led_trigger_unregister_simple(ledtrig_torch);
led_trigger_unregister_simple(ledtrig_flash);
}
