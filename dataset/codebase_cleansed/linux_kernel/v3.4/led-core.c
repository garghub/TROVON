static void led_stop_software_blink(struct led_classdev *led_cdev)
{
del_timer_sync(&led_cdev->blink_timer);
led_cdev->blink_delay_on = 0;
led_cdev->blink_delay_off = 0;
}
static void led_set_software_blink(struct led_classdev *led_cdev,
unsigned long delay_on,
unsigned long delay_off)
{
int current_brightness;
current_brightness = led_get_brightness(led_cdev);
if (current_brightness)
led_cdev->blink_brightness = current_brightness;
if (!led_cdev->blink_brightness)
led_cdev->blink_brightness = led_cdev->max_brightness;
if (led_get_trigger_data(led_cdev) &&
delay_on == led_cdev->blink_delay_on &&
delay_off == led_cdev->blink_delay_off)
return;
led_stop_software_blink(led_cdev);
led_cdev->blink_delay_on = delay_on;
led_cdev->blink_delay_off = delay_off;
if (!delay_on)
return;
if (!delay_off) {
led_set_brightness(led_cdev, led_cdev->blink_brightness);
return;
}
mod_timer(&led_cdev->blink_timer, jiffies + 1);
}
void led_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
del_timer_sync(&led_cdev->blink_timer);
if (led_cdev->blink_set &&
!led_cdev->blink_set(led_cdev, delay_on, delay_off))
return;
if (!*delay_on && !*delay_off)
*delay_on = *delay_off = 500;
led_set_software_blink(led_cdev, *delay_on, *delay_off);
}
void led_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
led_stop_software_blink(led_cdev);
led_cdev->brightness_set(led_cdev, brightness);
}
