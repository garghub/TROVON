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
if (led_dat->blinking) {
led_dat->platform_gpio_blink_set(led_dat->gpiod, level,
NULL, NULL);
led_dat->blinking = 0;
} else {
if (led_dat->can_sleep)
gpiod_set_value_cansleep(led_dat->gpiod, level);
else
gpiod_set_value(led_dat->gpiod, level);
}
}
static int gpio_led_set_blocking(struct led_classdev *led_cdev,
enum led_brightness value)
{
gpio_led_set(led_cdev, value);
return 0;
}
static int gpio_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on, unsigned long *delay_off)
{
struct gpio_led_data *led_dat =
container_of(led_cdev, struct gpio_led_data, cdev);
led_dat->blinking = 1;
return led_dat->platform_gpio_blink_set(led_dat->gpiod, GPIO_LED_BLINK,
delay_on, delay_off);
}
static int create_gpio_led(const struct gpio_led *template,
struct gpio_led_data *led_dat, struct device *parent,
int (*blink_set)(struct gpio_desc *, int, unsigned long *,
unsigned long *))
{
int ret, state;
led_dat->gpiod = template->gpiod;
if (!led_dat->gpiod) {
unsigned long flags = GPIOF_OUT_INIT_LOW;
if (!gpio_is_valid(template->gpio)) {
dev_info(parent, "Skipping unavailable LED gpio %d (%s)\n",
template->gpio, template->name);
return 0;
}
if (template->active_low)
flags |= GPIOF_ACTIVE_LOW;
ret = devm_gpio_request_one(parent, template->gpio, flags,
template->name);
if (ret < 0)
return ret;
led_dat->gpiod = gpio_to_desc(template->gpio);
if (!led_dat->gpiod)
return -EINVAL;
}
led_dat->cdev.name = template->name;
led_dat->cdev.default_trigger = template->default_trigger;
led_dat->can_sleep = gpiod_cansleep(led_dat->gpiod);
if (!led_dat->can_sleep)
led_dat->cdev.brightness_set = gpio_led_set;
else
led_dat->cdev.brightness_set_blocking = gpio_led_set_blocking;
led_dat->blinking = 0;
if (blink_set) {
led_dat->platform_gpio_blink_set = blink_set;
led_dat->cdev.blink_set = gpio_blink_set;
}
if (template->default_state == LEDS_GPIO_DEFSTATE_KEEP)
state = !!gpiod_get_value_cansleep(led_dat->gpiod);
else
state = (template->default_state == LEDS_GPIO_DEFSTATE_ON);
led_dat->cdev.brightness = state ? LED_FULL : LED_OFF;
if (!template->retain_state_suspended)
led_dat->cdev.flags |= LED_CORE_SUSPENDRESUME;
if (template->panic_indicator)
led_dat->cdev.flags |= LED_PANIC_INDICATOR;
ret = gpiod_direction_output(led_dat->gpiod, state);
if (ret < 0)
return ret;
return led_classdev_register(parent, &led_dat->cdev);
}
static inline int sizeof_gpio_leds_priv(int num_leds)
{
return sizeof(struct gpio_leds_priv) +
(sizeof(struct gpio_led_data) * num_leds);
}
static struct gpio_leds_priv *gpio_leds_create(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct fwnode_handle *child;
struct gpio_leds_priv *priv;
int count, ret;
struct device_node *np;
count = device_get_child_node_count(dev);
if (!count)
return ERR_PTR(-ENODEV);
priv = devm_kzalloc(dev, sizeof_gpio_leds_priv(count), GFP_KERNEL);
if (!priv)
return ERR_PTR(-ENOMEM);
device_for_each_child_node(dev, child) {
struct gpio_led_data *led_dat = &priv->leds[priv->num_leds];
struct gpio_led led = {};
const char *state = NULL;
led.gpiod = devm_get_gpiod_from_child(dev, NULL, child);
if (IS_ERR(led.gpiod)) {
fwnode_handle_put(child);
ret = PTR_ERR(led.gpiod);
goto err;
}
np = to_of_node(child);
if (fwnode_property_present(child, "label")) {
fwnode_property_read_string(child, "label", &led.name);
} else {
if (IS_ENABLED(CONFIG_OF) && !led.name && np)
led.name = np->name;
if (!led.name) {
ret = -EINVAL;
goto err;
}
}
fwnode_property_read_string(child, "linux,default-trigger",
&led.default_trigger);
if (!fwnode_property_read_string(child, "default-state",
&state)) {
if (!strcmp(state, "keep"))
led.default_state = LEDS_GPIO_DEFSTATE_KEEP;
else if (!strcmp(state, "on"))
led.default_state = LEDS_GPIO_DEFSTATE_ON;
else
led.default_state = LEDS_GPIO_DEFSTATE_OFF;
}
if (fwnode_property_present(child, "retain-state-suspended"))
led.retain_state_suspended = 1;
if (fwnode_property_present(child, "panic-indicator"))
led.panic_indicator = 1;
ret = create_gpio_led(&led, led_dat, dev, NULL);
if (ret < 0) {
fwnode_handle_put(child);
goto err;
}
led_dat->cdev.dev->of_node = np;
priv->num_leds++;
}
return priv;
err:
for (count = priv->num_leds - 1; count >= 0; count--)
led_classdev_unregister(&priv->leds[count].cdev);
return ERR_PTR(ret);
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
led_classdev_unregister(
&priv->leds[i].cdev);
return ret;
}
}
} else {
priv = gpio_leds_create(pdev);
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
led_classdev_unregister(&priv->leds[i].cdev);
return 0;
}
static void gpio_led_shutdown(struct platform_device *pdev)
{
struct gpio_leds_priv *priv = platform_get_drvdata(pdev);
int i;
for (i = 0; i < priv->num_leds; i++) {
struct gpio_led_data *led = &priv->leds[i];
gpio_led_set(&led->cdev, LED_OFF);
}
}
