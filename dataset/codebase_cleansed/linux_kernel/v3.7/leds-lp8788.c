static int lp8788_led_init_device(struct lp8788_led *led,
struct lp8788_led_platform_data *pdata)
{
struct lp8788_led_config *cfg = &default_led_config;
u8 addr, mask, val;
int ret;
if (pdata) {
cfg->scale = pdata->scale;
cfg->num = pdata->num;
cfg->iout = pdata->iout_code;
}
led->isink_num = cfg->num;
addr = LP8788_ISINK_CTRL;
mask = 1 << (cfg->num + LP8788_ISINK_SCALE_OFFSET);
val = cfg->scale << (cfg->num + LP8788_ISINK_SCALE_OFFSET);
ret = lp8788_update_bits(led->lp, addr, mask, val);
if (ret)
return ret;
addr = lp8788_iout_addr[cfg->num];
mask = lp8788_iout_mask[cfg->num];
val = cfg->iout;
return lp8788_update_bits(led->lp, addr, mask, val);
}
static void lp8788_led_enable(struct lp8788_led *led,
enum lp8788_isink_number num, int on)
{
u8 mask = 1 << num;
u8 val = on << num;
if (lp8788_update_bits(led->lp, LP8788_ISINK_CTRL, mask, val))
return;
led->on = on;
}
static void lp8788_led_work(struct work_struct *work)
{
struct lp8788_led *led = container_of(work, struct lp8788_led, work);
enum lp8788_isink_number num = led->isink_num;
int enable;
u8 val = led->brightness;
mutex_lock(&led->lock);
switch (num) {
case LP8788_ISINK_1:
case LP8788_ISINK_2:
case LP8788_ISINK_3:
lp8788_write_byte(led->lp, lp8788_pwm_addr[num], val);
break;
default:
mutex_unlock(&led->lock);
return;
}
enable = (val > 0) ? 1 : 0;
if (enable != led->on)
lp8788_led_enable(led, num, enable);
mutex_unlock(&led->lock);
}
static void lp8788_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brt_val)
{
struct lp8788_led *led =
container_of(led_cdev, struct lp8788_led, led_dev);
led->brightness = brt_val;
schedule_work(&led->work);
}
static __devinit int lp8788_led_probe(struct platform_device *pdev)
{
struct lp8788 *lp = dev_get_drvdata(pdev->dev.parent);
struct lp8788_led_platform_data *led_pdata;
struct lp8788_led *led;
int ret;
led = devm_kzalloc(lp->dev, sizeof(struct lp8788_led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->lp = lp;
led->led_dev.max_brightness = MAX_BRIGHTNESS;
led->led_dev.brightness_set = lp8788_brightness_set;
led_pdata = lp->pdata ? lp->pdata->led_pdata : NULL;
if (!led_pdata || !led_pdata->name)
led->led_dev.name = DEFAULT_LED_NAME;
else
led->led_dev.name = led_pdata->name;
mutex_init(&led->lock);
INIT_WORK(&led->work, lp8788_led_work);
platform_set_drvdata(pdev, led);
ret = lp8788_led_init_device(led, led_pdata);
if (ret) {
dev_err(lp->dev, "led init device err: %d\n", ret);
return ret;
}
ret = led_classdev_register(lp->dev, &led->led_dev);
if (ret) {
dev_err(lp->dev, "led register err: %d\n", ret);
return ret;
}
return 0;
}
static int __devexit lp8788_led_remove(struct platform_device *pdev)
{
struct lp8788_led *led = platform_get_drvdata(pdev);
led_classdev_unregister(&led->led_dev);
flush_work(&led->work);
return 0;
}
