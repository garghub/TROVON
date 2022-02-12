static void led_trigger_set_panic(struct led_classdev *led_cdev)
{
struct led_trigger *trig;
list_for_each_entry(trig, &trigger_list, next_trig) {
if (strcmp("panic", trig->name))
continue;
if (led_cdev->trigger)
list_del(&led_cdev->trig_list);
list_add_tail(&led_cdev->trig_list, &trig->led_cdevs);
led_cdev->blink_delay_on = 0;
led_cdev->blink_delay_off = 0;
led_cdev->trigger = trig;
if (trig->activate)
trig->activate(led_cdev);
break;
}
}
static int led_trigger_panic_notifier(struct notifier_block *nb,
unsigned long code, void *unused)
{
struct led_classdev *led_cdev;
list_for_each_entry(led_cdev, &leds_list, node)
if (led_cdev->flags & LED_PANIC_INDICATOR)
led_trigger_set_panic(led_cdev);
return NOTIFY_DONE;
}
static long led_panic_blink(int state)
{
led_trigger_event(trigger, state ? LED_FULL : LED_OFF);
return 0;
}
static int __init ledtrig_panic_init(void)
{
atomic_notifier_chain_register(&panic_notifier_list,
&led_trigger_panic_nb);
led_trigger_register_simple("panic", &trigger);
panic_blink = led_panic_blink;
return 0;
}
