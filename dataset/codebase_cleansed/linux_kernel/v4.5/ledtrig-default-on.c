static void defon_trig_activate(struct led_classdev *led_cdev)
{
led_set_brightness_nosleep(led_cdev, led_cdev->max_brightness);
}
static int __init defon_trig_init(void)
{
return led_trigger_register(&defon_led_trigger);
}
static void __exit defon_trig_exit(void)
{
led_trigger_unregister(&defon_led_trigger);
}
