static int ns2_led_get_mode(struct ns2_led_data *led_dat,
enum ns2_led_modes *mode)
{
int i;
int ret = -EINVAL;
int cmd_level;
int slow_level;
read_lock_irq(&led_dat->rw_lock);
cmd_level = gpio_get_value(led_dat->cmd);
slow_level = gpio_get_value(led_dat->slow);
for (i = 0; i < ARRAY_SIZE(ns2_led_modval); i++) {
if (cmd_level == ns2_led_modval[i].cmd_level &&
slow_level == ns2_led_modval[i].slow_level) {
*mode = ns2_led_modval[i].mode;
ret = 0;
break;
}
}
read_unlock_irq(&led_dat->rw_lock);
return ret;
}
static void ns2_led_set_mode(struct ns2_led_data *led_dat,
enum ns2_led_modes mode)
{
int i;
unsigned long flags;
write_lock_irqsave(&led_dat->rw_lock, flags);
for (i = 0; i < ARRAY_SIZE(ns2_led_modval); i++) {
if (mode == ns2_led_modval[i].mode) {
gpio_set_value(led_dat->cmd,
ns2_led_modval[i].cmd_level);
gpio_set_value(led_dat->slow,
ns2_led_modval[i].slow_level);
}
}
write_unlock_irqrestore(&led_dat->rw_lock, flags);
}
static void ns2_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct ns2_led_data *led_dat =
container_of(led_cdev, struct ns2_led_data, cdev);
enum ns2_led_modes mode;
if (value == LED_OFF)
mode = NS_V2_LED_OFF;
else if (led_dat->sata)
mode = NS_V2_LED_SATA;
else
mode = NS_V2_LED_ON;
ns2_led_set_mode(led_dat, mode);
}
static ssize_t ns2_led_sata_store(struct device *dev,
struct device_attribute *attr,
const char *buff, size_t count)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct ns2_led_data *led_dat =
container_of(led_cdev, struct ns2_led_data, cdev);
int ret;
unsigned long enable;
enum ns2_led_modes mode;
ret = strict_strtoul(buff, 10, &enable);
if (ret < 0)
return ret;
enable = !!enable;
if (led_dat->sata == enable)
return count;
ret = ns2_led_get_mode(led_dat, &mode);
if (ret < 0)
return ret;
if (enable && mode == NS_V2_LED_ON)
ns2_led_set_mode(led_dat, NS_V2_LED_SATA);
if (!enable && mode == NS_V2_LED_SATA)
ns2_led_set_mode(led_dat, NS_V2_LED_ON);
led_dat->sata = enable;
return count;
}
static ssize_t ns2_led_sata_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct ns2_led_data *led_dat =
container_of(led_cdev, struct ns2_led_data, cdev);
return sprintf(buf, "%d\n", led_dat->sata);
}
static int __devinit
create_ns2_led(struct platform_device *pdev, struct ns2_led_data *led_dat,
const struct ns2_led *template)
{
int ret;
enum ns2_led_modes mode;
ret = gpio_request(template->cmd, template->name);
if (ret == 0) {
ret = gpio_direction_output(template->cmd,
gpio_get_value(template->cmd));
if (ret)
gpio_free(template->cmd);
}
if (ret) {
dev_err(&pdev->dev, "%s: failed to setup command GPIO\n",
template->name);
}
ret = gpio_request(template->slow, template->name);
if (ret == 0) {
ret = gpio_direction_output(template->slow,
gpio_get_value(template->slow));
if (ret)
gpio_free(template->slow);
}
if (ret) {
dev_err(&pdev->dev, "%s: failed to setup slow GPIO\n",
template->name);
goto err_free_cmd;
}
rwlock_init(&led_dat->rw_lock);
led_dat->cdev.name = template->name;
led_dat->cdev.default_trigger = template->default_trigger;
led_dat->cdev.blink_set = NULL;
led_dat->cdev.brightness_set = ns2_led_set;
led_dat->cdev.flags |= LED_CORE_SUSPENDRESUME;
led_dat->cmd = template->cmd;
led_dat->slow = template->slow;
ret = ns2_led_get_mode(led_dat, &mode);
if (ret < 0)
goto err_free_slow;
led_dat->sata = (mode == NS_V2_LED_SATA) ? 1 : 0;
led_dat->cdev.brightness =
(mode == NS_V2_LED_OFF) ? LED_OFF : LED_FULL;
ret = led_classdev_register(&pdev->dev, &led_dat->cdev);
if (ret < 0)
goto err_free_slow;
ret = device_create_file(led_dat->cdev.dev, &dev_attr_sata);
if (ret < 0)
goto err_free_cdev;
return 0;
err_free_cdev:
led_classdev_unregister(&led_dat->cdev);
err_free_slow:
gpio_free(led_dat->slow);
err_free_cmd:
gpio_free(led_dat->cmd);
return ret;
}
static void __devexit delete_ns2_led(struct ns2_led_data *led_dat)
{
device_remove_file(led_dat->cdev.dev, &dev_attr_sata);
led_classdev_unregister(&led_dat->cdev);
gpio_free(led_dat->cmd);
gpio_free(led_dat->slow);
}
static int __devinit ns2_led_probe(struct platform_device *pdev)
{
struct ns2_led_platform_data *pdata = pdev->dev.platform_data;
struct ns2_led_data *leds_data;
int i;
int ret;
if (!pdata)
return -EINVAL;
leds_data = kzalloc(sizeof(struct ns2_led_data) *
pdata->num_leds, GFP_KERNEL);
if (!leds_data)
return -ENOMEM;
for (i = 0; i < pdata->num_leds; i++) {
ret = create_ns2_led(pdev, &leds_data[i], &pdata->leds[i]);
if (ret < 0)
goto err;
}
platform_set_drvdata(pdev, leds_data);
return 0;
err:
for (i = i - 1; i >= 0; i--)
delete_ns2_led(&leds_data[i]);
kfree(leds_data);
return ret;
}
static int __devexit ns2_led_remove(struct platform_device *pdev)
{
int i;
struct ns2_led_platform_data *pdata = pdev->dev.platform_data;
struct ns2_led_data *leds_data;
leds_data = platform_get_drvdata(pdev);
for (i = 0; i < pdata->num_leds; i++)
delete_ns2_led(&leds_data[i]);
kfree(leds_data);
platform_set_drvdata(pdev, NULL);
return 0;
}
