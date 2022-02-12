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
ret = kstrtoul(buff, 10, &enable);
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
static int
create_ns2_led(struct platform_device *pdev, struct ns2_led_data *led_dat,
const struct ns2_led *template)
{
int ret;
enum ns2_led_modes mode;
ret = devm_gpio_request_one(&pdev->dev, template->cmd,
gpio_get_value(template->cmd) ?
GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW,
template->name);
if (ret) {
dev_err(&pdev->dev, "%s: failed to setup command GPIO\n",
template->name);
return ret;
}
ret = devm_gpio_request_one(&pdev->dev, template->slow,
gpio_get_value(template->slow) ?
GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW,
template->name);
if (ret) {
dev_err(&pdev->dev, "%s: failed to setup slow GPIO\n",
template->name);
return ret;
}
rwlock_init(&led_dat->rw_lock);
led_dat->cdev.name = template->name;
led_dat->cdev.default_trigger = template->default_trigger;
led_dat->cdev.blink_set = NULL;
led_dat->cdev.brightness_set = ns2_led_set;
led_dat->cdev.flags |= LED_CORE_SUSPENDRESUME;
led_dat->cdev.groups = ns2_led_groups;
led_dat->cmd = template->cmd;
led_dat->slow = template->slow;
ret = ns2_led_get_mode(led_dat, &mode);
if (ret < 0)
return ret;
led_dat->sata = (mode == NS_V2_LED_SATA) ? 1 : 0;
led_dat->cdev.brightness =
(mode == NS_V2_LED_OFF) ? LED_OFF : LED_FULL;
ret = led_classdev_register(&pdev->dev, &led_dat->cdev);
if (ret < 0)
return ret;
return 0;
}
static void delete_ns2_led(struct ns2_led_data *led_dat)
{
led_classdev_unregister(&led_dat->cdev);
}
static int
ns2_leds_get_of_pdata(struct device *dev, struct ns2_led_platform_data *pdata)
{
struct device_node *np = dev->of_node;
struct device_node *child;
struct ns2_led *leds;
int num_leds = 0;
int i = 0;
num_leds = of_get_child_count(np);
if (!num_leds)
return -ENODEV;
leds = devm_kzalloc(dev, num_leds * sizeof(struct ns2_led),
GFP_KERNEL);
if (!leds)
return -ENOMEM;
for_each_child_of_node(np, child) {
const char *string;
int ret;
ret = of_get_named_gpio(child, "cmd-gpio", 0);
if (ret < 0)
return ret;
leds[i].cmd = ret;
ret = of_get_named_gpio(child, "slow-gpio", 0);
if (ret < 0)
return ret;
leds[i].slow = ret;
ret = of_property_read_string(child, "label", &string);
leds[i].name = (ret == 0) ? string : child->name;
ret = of_property_read_string(child, "linux,default-trigger",
&string);
if (ret == 0)
leds[i].default_trigger = string;
i++;
}
pdata->leds = leds;
pdata->num_leds = num_leds;
return 0;
}
static inline int sizeof_ns2_led_priv(int num_leds)
{
return sizeof(struct ns2_led_priv) +
(sizeof(struct ns2_led_data) * num_leds);
}
static int ns2_led_probe(struct platform_device *pdev)
{
struct ns2_led_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct ns2_led_priv *priv;
int i;
int ret;
#ifdef CONFIG_OF_GPIO
if (!pdata) {
pdata = devm_kzalloc(&pdev->dev,
sizeof(struct ns2_led_platform_data),
GFP_KERNEL);
if (!pdata)
return -ENOMEM;
ret = ns2_leds_get_of_pdata(&pdev->dev, pdata);
if (ret)
return ret;
}
#else
if (!pdata)
return -EINVAL;
#endif
priv = devm_kzalloc(&pdev->dev,
sizeof_ns2_led_priv(pdata->num_leds), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->num_leds = pdata->num_leds;
for (i = 0; i < priv->num_leds; i++) {
ret = create_ns2_led(pdev, &priv->leds_data[i],
&pdata->leds[i]);
if (ret < 0) {
for (i = i - 1; i >= 0; i--)
delete_ns2_led(&priv->leds_data[i]);
return ret;
}
}
platform_set_drvdata(pdev, priv);
return 0;
}
static int ns2_led_remove(struct platform_device *pdev)
{
int i;
struct ns2_led_priv *priv;
priv = platform_get_drvdata(pdev);
for (i = 0; i < priv->num_leds; i++)
delete_ns2_led(&priv->leds_data[i]);
return 0;
}
