static void gpio_led_work(struct work_struct *work)
{
struct gpio_led_data *led_dat =
container_of(work, struct gpio_led_data, work);
if (led_dat->blinking) {
led_dat->platform_gpio_blink_set(led_dat->gpiod,
led_dat->new_level, NULL, NULL);
led_dat->blinking = 0;
} else
gpiod_set_value_cansleep(led_dat->gpiod, led_dat->new_level);
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
if (led_dat->can_sleep) {
led_dat->new_level = level;
schedule_work(&led_dat->work);
} else {
if (led_dat->blinking) {
led_dat->platform_gpio_blink_set(led_dat->gpiod, level,
NULL, NULL);
led_dat->blinking = 0;
} else
gpiod_set_value(led_dat->gpiod, level);
}
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
unsigned long flags = 0;
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
if (IS_ERR(led_dat->gpiod))
return PTR_ERR(led_dat->gpiod);
}
led_dat->cdev.name = template->name;
led_dat->cdev.default_trigger = template->default_trigger;
led_dat->can_sleep = gpiod_cansleep(led_dat->gpiod);
led_dat->blinking = 0;
if (blink_set) {
led_dat->platform_gpio_blink_set = blink_set;
led_dat->cdev.blink_set = gpio_blink_set;
}
led_dat->cdev.brightness_set = gpio_led_set;
if (template->default_state == LEDS_GPIO_DEFSTATE_KEEP)
state = !!gpiod_get_value_cansleep(led_dat->gpiod);
else
state = (template->default_state == LEDS_GPIO_DEFSTATE_ON);
led_dat->cdev.brightness = state ? LED_FULL : LED_OFF;
if (!template->retain_state_suspended)
led_dat->cdev.flags |= LED_CORE_SUSPENDRESUME;
ret = gpiod_direction_output(led_dat->gpiod, state);
if (ret < 0)
return ret;
INIT_WORK(&led_dat->work, gpio_led_work);
return led_classdev_register(parent, &led_dat->cdev);
}
static void delete_gpio_led(struct gpio_led_data *led)
{
led_classdev_unregister(&led->cdev);
cancel_work_sync(&led->work);
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
struct gpio_led led = {};
const char *state = NULL;
led.gpiod = devm_get_gpiod_from_child(dev, child);
if (IS_ERR(led.gpiod)) {
fwnode_handle_put(child);
goto err;
}
np = of_node(child);
if (fwnode_property_present(child, "label")) {
fwnode_property_read_string(child, "label", &led.name);
} else {
if (IS_ENABLED(CONFIG_OF) && !led.name && np)
led.name = np->name;
if (!led.name)
return ERR_PTR(-EINVAL);
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
ret = create_gpio_led(&led, &priv->leds[priv->num_leds++],
dev, NULL);
if (ret < 0) {
fwnode_handle_put(child);
goto err;
}
}
return priv;
err:
for (count = priv->num_leds - 2; count >= 0; count--)
delete_gpio_led(&priv->leds[count]);
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
delete_gpio_led(&priv->leds[i]);
return 0;
}
