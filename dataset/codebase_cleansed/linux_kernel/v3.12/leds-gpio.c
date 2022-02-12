static void gpio_led_work(struct work_struct *work)
{
struct gpio_led_data *led_dat =
container_of(work, struct gpio_led_data, work);
if (led_dat->blinking) {
led_dat->platform_gpio_blink_set(led_dat->gpio,
led_dat->new_level,
NULL, NULL);
led_dat->blinking = 0;
} else
gpio_set_value_cansleep(led_dat->gpio, led_dat->new_level);
}
static void gpio_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct gpio_led_data *led_dat =
container_of(led_cdev, struct gpio_led_data, cdev);
int level;
if (value == LED_OFF)
level = 0;
else
level = 1;
if (led_dat->active_low)
level = !level;
if (led_dat->can_sleep) {
led_dat->new_level = level;
schedule_work(&led_dat->work);
} else {
if (led_dat->blinking) {
led_dat->platform_gpio_blink_set(led_dat->gpio, level,
NULL, NULL);
led_dat->blinking = 0;
} else
gpio_set_value(led_dat->gpio, level);
}
}
static int gpio_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on, unsigned long *delay_off)
{
struct gpio_led_data *led_dat =
container_of(led_cdev, struct gpio_led_data, cdev);
led_dat->blinking = 1;
return led_dat->platform_gpio_blink_set(led_dat->gpio, GPIO_LED_BLINK,
delay_on, delay_off);
}
static int create_gpio_led(const struct gpio_led *template,
struct gpio_led_data *led_dat, struct device *parent,
int (*blink_set)(unsigned, int, unsigned long *, unsigned long *))
{
int ret, state;
led_dat->gpio = -1;
if (!gpio_is_valid(template->gpio)) {
dev_info(parent, "Skipping unavailable LED gpio %d (%s)\n",
template->gpio, template->name);
return 0;
}
ret = devm_gpio_request(parent, template->gpio, template->name);
if (ret < 0)
return ret;
led_dat->cdev.name = template->name;
led_dat->cdev.default_trigger = template->default_trigger;
led_dat->gpio = template->gpio;
led_dat->can_sleep = gpio_cansleep(template->gpio);
led_dat->active_low = template->active_low;
led_dat->blinking = 0;
if (blink_set) {
led_dat->platform_gpio_blink_set = blink_set;
led_dat->cdev.blink_set = gpio_blink_set;
}
led_dat->cdev.brightness_set = gpio_led_set;
if (template->default_state == LEDS_GPIO_DEFSTATE_KEEP)
state = !!gpio_get_value_cansleep(led_dat->gpio) ^ led_dat->active_low;
else
state = (template->default_state == LEDS_GPIO_DEFSTATE_ON);
led_dat->cdev.brightness = state ? LED_FULL : LED_OFF;
if (!template->retain_state_suspended)
led_dat->cdev.flags |= LED_CORE_SUSPENDRESUME;
ret = gpio_direction_output(led_dat->gpio, led_dat->active_low ^ state);
if (ret < 0)
return ret;
INIT_WORK(&led_dat->work, gpio_led_work);
ret = led_classdev_register(parent, &led_dat->cdev);
if (ret < 0)
return ret;
return 0;
}
static void delete_gpio_led(struct gpio_led_data *led)
{
if (!gpio_is_valid(led->gpio))
return;
led_classdev_unregister(&led->cdev);
cancel_work_sync(&led->work);
}
static inline int sizeof_gpio_leds_priv(int num_leds)
{
return sizeof(struct gpio_leds_priv) +
(sizeof(struct gpio_led_data) * num_leds);
}
static struct gpio_leds_priv *gpio_leds_create_of(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node, *child;
struct gpio_leds_priv *priv;
int count, ret;
count = of_get_child_count(np);
if (!count)
return ERR_PTR(-ENODEV);
for_each_child_of_node(np, child)
if (of_get_gpio(child, 0) == -EPROBE_DEFER)
return ERR_PTR(-EPROBE_DEFER);
priv = devm_kzalloc(&pdev->dev, sizeof_gpio_leds_priv(count),
GFP_KERNEL);
if (!priv)
return ERR_PTR(-ENOMEM);
for_each_child_of_node(np, child) {
struct gpio_led led = {};
enum of_gpio_flags flags;
const char *state;
led.gpio = of_get_gpio_flags(child, 0, &flags);
led.active_low = flags & OF_GPIO_ACTIVE_LOW;
led.name = of_get_property(child, "label", NULL) ? : child->name;
led.default_trigger =
of_get_property(child, "linux,default-trigger", NULL);
state = of_get_property(child, "default-state", NULL);
if (state) {
if (!strcmp(state, "keep"))
led.default_state = LEDS_GPIO_DEFSTATE_KEEP;
else if (!strcmp(state, "on"))
led.default_state = LEDS_GPIO_DEFSTATE_ON;
else
led.default_state = LEDS_GPIO_DEFSTATE_OFF;
}
ret = create_gpio_led(&led, &priv->leds[priv->num_leds++],
&pdev->dev, NULL);
if (ret < 0) {
of_node_put(child);
goto err;
}
}
return priv;
err:
for (count = priv->num_leds - 2; count >= 0; count--)
delete_gpio_led(&priv->leds[count]);
return ERR_PTR(-ENODEV);
}
static struct gpio_leds_priv *gpio_leds_create_of(struct platform_device *pdev)
{
return ERR_PTR(-ENODEV);
}
static int gpio_led_probe(struct platform_device *pdev)
{
struct gpio_led_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct gpio_leds_priv *priv;
int i, ret = 0;
if (pdata && pdata->num_leds) {
priv = devm_kzalloc(&pdev->dev,
sizeof_gpio_leds_priv(pdata->num_leds),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->num_leds = pdata->num_leds;
for (i = 0; i < priv->num_leds; i++) {
ret = create_gpio_led(&pdata->leds[i],
&priv->leds[i],
&pdev->dev, pdata->gpio_blink_set);
if (ret < 0) {
for (i = i - 1; i >= 0; i--)
delete_gpio_led(&priv->leds[i]);
return ret;
}
}
} else {
priv = gpio_leds_create_of(pdev);
if (IS_ERR(priv))
return PTR_ERR(priv);
}
platform_set_drvdata(pdev, priv);
return 0;
}
static int gpio_led_remove(struct platform_device *pdev)
{
struct gpio_leds_priv *priv = platform_get_drvdata(pdev);
int i;
for (i = 0; i < priv->num_leds; i++)
delete_gpio_led(&priv->leds[i]);
return 0;
}
