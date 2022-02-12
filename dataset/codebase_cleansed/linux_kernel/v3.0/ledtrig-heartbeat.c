static void led_heartbeat_function(unsigned long data)
{
struct led_classdev *led_cdev = (struct led_classdev *) data;
struct heartbeat_trig_data *heartbeat_data = led_cdev->trigger_data;
unsigned long brightness = LED_OFF;
unsigned long delay = 0;
switch (heartbeat_data->phase) {
case 0:
heartbeat_data->period = 300 +
(6720 << FSHIFT) / (5 * avenrun[0] + (7 << FSHIFT));
heartbeat_data->period =
msecs_to_jiffies(heartbeat_data->period);
delay = msecs_to_jiffies(70);
heartbeat_data->phase++;
brightness = led_cdev->max_brightness;
break;
case 1:
delay = heartbeat_data->period / 4 - msecs_to_jiffies(70);
heartbeat_data->phase++;
break;
case 2:
delay = msecs_to_jiffies(70);
heartbeat_data->phase++;
brightness = led_cdev->max_brightness;
break;
default:
delay = heartbeat_data->period - heartbeat_data->period / 4 -
msecs_to_jiffies(70);
heartbeat_data->phase = 0;
break;
}
led_set_brightness(led_cdev, brightness);
mod_timer(&heartbeat_data->timer, jiffies + delay);
}
static void heartbeat_trig_activate(struct led_classdev *led_cdev)
{
struct heartbeat_trig_data *heartbeat_data;
heartbeat_data = kzalloc(sizeof(*heartbeat_data), GFP_KERNEL);
if (!heartbeat_data)
return;
led_cdev->trigger_data = heartbeat_data;
setup_timer(&heartbeat_data->timer,
led_heartbeat_function, (unsigned long) led_cdev);
heartbeat_data->phase = 0;
led_heartbeat_function(heartbeat_data->timer.data);
}
static void heartbeat_trig_deactivate(struct led_classdev *led_cdev)
{
struct heartbeat_trig_data *heartbeat_data = led_cdev->trigger_data;
if (heartbeat_data) {
del_timer_sync(&heartbeat_data->timer);
kfree(heartbeat_data);
}
}
static int __init heartbeat_trig_init(void)
{
return led_trigger_register(&heartbeat_led_trigger);
}
static void __exit heartbeat_trig_exit(void)
{
led_trigger_unregister(&heartbeat_led_trigger);
}
