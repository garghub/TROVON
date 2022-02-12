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
led_cdev->blink_delay_on = delay_on;
led_cdev->blink_delay_off = delay_off;
if (!delay_on)
return;
if (!delay_off) {
__led_set_brightness(led_cdev, led_cdev->blink_brightness);
return;
}
mod_timer(&led_cdev->blink_timer, jiffies + 1);
}
static void led_blink_setup(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
if (!(led_cdev->flags & LED_BLINK_ONESHOT) &&
led_cdev->blink_set &&
!led_cdev->blink_set(led_cdev, delay_on, delay_off))
return;
if (!*delay_on && !*delay_off)
*delay_on = *delay_off = 500;
led_set_software_blink(led_cdev, *delay_on, *delay_off);
}
void led_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
del_timer_sync(&led_cdev->blink_timer);
led_cdev->flags &= ~LED_BLINK_ONESHOT;
led_cdev->flags &= ~LED_BLINK_ONESHOT_STOP;
led_blink_setup(led_cdev, delay_on, delay_off);
}
void led_blink_set_oneshot(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off,
int invert)
{
if ((led_cdev->flags & LED_BLINK_ONESHOT) &&
timer_pending(&led_cdev->blink_timer))
return;
led_cdev->flags |= LED_BLINK_ONESHOT;
led_cdev->flags &= ~LED_BLINK_ONESHOT_STOP;
if (invert)
led_cdev->flags |= LED_BLINK_INVERT;
else
led_cdev->flags &= ~LED_BLINK_INVERT;
led_blink_setup(led_cdev, delay_on, delay_off);
}
void led_stop_software_blink(struct led_classdev *led_cdev)
{
del_timer_sync(&led_cdev->blink_timer);
led_cdev->blink_delay_on = 0;
led_cdev->blink_delay_off = 0;
}
void led_set_brightness(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
if (led_cdev->blink_delay_on || led_cdev->blink_delay_off) {
led_cdev->delayed_set_value = brightness;
schedule_work(&led_cdev->set_brightness_work);
return;
}
__led_set_brightness(led_cdev, brightness);
}
