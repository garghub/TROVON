static inline int __led_off(int port)
{
int ret = -EINVAL;
switch (port) {
case PM8606_LED1_RED:
case PM8606_LED1_GREEN:
case PM8606_LED1_BLUE:
ret = port - PM8606_LED1_RED + PM8606_RGB1B;
break;
case PM8606_LED2_RED:
case PM8606_LED2_GREEN:
case PM8606_LED2_BLUE:
ret = port - PM8606_LED2_RED + PM8606_RGB2B;
break;
}
return ret;
}
static inline int __blink_off(int port)
{
int ret = -EINVAL;
switch (port) {
case PM8606_LED1_RED:
case PM8606_LED1_GREEN:
case PM8606_LED1_BLUE:
ret = PM8606_RGB1A;
break;
case PM8606_LED2_RED:
case PM8606_LED2_GREEN:
case PM8606_LED2_BLUE:
ret = PM8606_RGB2A;
break;
}
return ret;
}
static inline int __blink_ctl_mask(int port)
{
int ret = -EINVAL;
switch (port) {
case PM8606_LED1_RED:
case PM8606_LED1_GREEN:
case PM8606_LED1_BLUE:
ret = LED1_BLINK_EN;
break;
case PM8606_LED2_RED:
case PM8606_LED2_GREEN:
case PM8606_LED2_BLUE:
ret = LED2_BLINK_EN;
break;
}
return ret;
}
static int led_power_set(struct pm860x_chip *chip, int port, int on)
{
int ret = -EINVAL;
switch (port) {
case PM8606_LED1_RED:
case PM8606_LED1_GREEN:
case PM8606_LED1_BLUE:
ret = on ? pm8606_osc_enable(chip, RGB1_ENABLE) :
pm8606_osc_disable(chip, RGB1_ENABLE);
break;
case PM8606_LED2_RED:
case PM8606_LED2_GREEN:
case PM8606_LED2_BLUE:
ret = on ? pm8606_osc_enable(chip, RGB2_ENABLE) :
pm8606_osc_disable(chip, RGB2_ENABLE);
break;
}
return ret;
}
static void pm860x_led_work(struct work_struct *work)
{
struct pm860x_led *led;
struct pm860x_chip *chip;
unsigned char buf[3];
int mask, ret;
led = container_of(work, struct pm860x_led, work);
chip = led->chip;
mutex_lock(&led->lock);
if ((led->current_brightness == 0) && led->brightness) {
led_power_set(chip, led->port, 1);
if (led->iset) {
pm860x_set_bits(led->i2c, __led_off(led->port),
LED_CURRENT_MASK, led->iset);
}
pm860x_set_bits(led->i2c, __blink_off(led->port),
LED_BLINK_MASK, LED_ON_CONTINUOUS);
mask = __blink_ctl_mask(led->port);
pm860x_set_bits(led->i2c, PM8606_WLED3B, mask, mask);
}
pm860x_set_bits(led->i2c, __led_off(led->port), LED_PWM_MASK,
led->brightness);
if (led->brightness == 0) {
pm860x_bulk_read(led->i2c, __led_off(led->port), 3, buf);
ret = buf[0] & LED_PWM_MASK;
ret |= buf[1] & LED_PWM_MASK;
ret |= buf[2] & LED_PWM_MASK;
if (ret == 0) {
pm860x_set_bits(led->i2c, __led_off(led->port),
LED_CURRENT_MASK, 0);
mask = __blink_ctl_mask(led->port);
pm860x_set_bits(led->i2c, PM8606_WLED3B, mask, 0);
led_power_set(chip, led->port, 0);
}
}
led->current_brightness = led->brightness;
dev_dbg(chip->dev, "Update LED. (reg:%d, brightness:%d)\n",
__led_off(led->port), led->brightness);
mutex_unlock(&led->lock);
}
static void pm860x_led_set(struct led_classdev *cdev,
enum led_brightness value)
{
struct pm860x_led *data = container_of(cdev, struct pm860x_led, cdev);
data->brightness = value >> 3;
schedule_work(&data->work);
}
static int pm860x_led_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm860x_led_pdata *pdata;
struct pm860x_led *data;
struct resource *res;
int ret;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (res == NULL) {
dev_err(&pdev->dev, "No I/O resource!\n");
return -EINVAL;
}
pdata = pdev->dev.platform_data;
if (pdata == NULL) {
dev_err(&pdev->dev, "No platform data!\n");
return -EINVAL;
}
data = kzalloc(sizeof(struct pm860x_led), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
strncpy(data->name, res->name, MFD_NAME_SIZE - 1);
dev_set_drvdata(&pdev->dev, data);
data->chip = chip;
data->i2c = (chip->id == CHIP_PM8606) ? chip->client : chip->companion;
data->iset = pdata->iset;
data->port = pdata->flags;
if (data->port < 0) {
dev_err(&pdev->dev, "check device failed\n");
kfree(data);
return -EINVAL;
}
data->current_brightness = 0;
data->cdev.name = data->name;
data->cdev.brightness_set = pm860x_led_set;
mutex_init(&data->lock);
INIT_WORK(&data->work, pm860x_led_work);
ret = led_classdev_register(chip->dev, &data->cdev);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register LED: %d\n", ret);
goto out;
}
pm860x_led_set(&data->cdev, 0);
return 0;
out:
kfree(data);
return ret;
}
static int pm860x_led_remove(struct platform_device *pdev)
{
struct pm860x_led *data = platform_get_drvdata(pdev);
led_classdev_unregister(&data->cdev);
kfree(data);
return 0;
}
