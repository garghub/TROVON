static void gpio_ext_set_addr(struct netxbig_gpio_ext *gpio_ext, int addr)
{
int pin;
for (pin = 0; pin < gpio_ext->num_addr; pin++)
gpio_set_value(gpio_ext->addr[pin], (addr >> pin) & 1);
}
static void gpio_ext_set_data(struct netxbig_gpio_ext *gpio_ext, int data)
{
int pin;
for (pin = 0; pin < gpio_ext->num_data; pin++)
gpio_set_value(gpio_ext->data[pin], (data >> pin) & 1);
}
static void gpio_ext_enable_select(struct netxbig_gpio_ext *gpio_ext)
{
gpio_set_value(gpio_ext->enable, 0);
gpio_set_value(gpio_ext->enable, 1);
}
static void gpio_ext_set_value(struct netxbig_gpio_ext *gpio_ext,
int addr, int value)
{
unsigned long flags;
spin_lock_irqsave(&gpio_ext_lock, flags);
gpio_ext_set_addr(gpio_ext, addr);
gpio_ext_set_data(gpio_ext, value);
gpio_ext_enable_select(gpio_ext);
spin_unlock_irqrestore(&gpio_ext_lock, flags);
}
static int gpio_ext_init(struct platform_device *pdev,
struct netxbig_gpio_ext *gpio_ext)
{
int err;
int i;
if (unlikely(!gpio_ext))
return -EINVAL;
for (i = 0; i < gpio_ext->num_addr; i++) {
err = devm_gpio_request_one(&pdev->dev, gpio_ext->addr[i],
GPIOF_OUT_INIT_LOW,
"GPIO extension addr");
if (err)
return err;
}
for (i = 0; i < gpio_ext->num_data; i++) {
err = devm_gpio_request_one(&pdev->dev, gpio_ext->data[i],
GPIOF_OUT_INIT_LOW,
"GPIO extension data");
if (err)
return err;
}
err = devm_gpio_request_one(&pdev->dev, gpio_ext->enable,
GPIOF_OUT_INIT_LOW,
"GPIO extension enable");
if (err)
return err;
return 0;
}
static int netxbig_led_get_timer_mode(enum netxbig_led_mode *mode,
unsigned long delay_on,
unsigned long delay_off,
struct netxbig_led_timer *timer,
int num_timer)
{
int i;
for (i = 0; i < num_timer; i++) {
if (timer[i].delay_on == delay_on &&
timer[i].delay_off == delay_off) {
*mode = timer[i].mode;
return 0;
}
}
return -EINVAL;
}
static int netxbig_led_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct netxbig_led_data *led_dat =
container_of(led_cdev, struct netxbig_led_data, cdev);
enum netxbig_led_mode mode;
int mode_val;
int ret;
ret = netxbig_led_get_timer_mode(&mode, *delay_on, *delay_off,
led_dat->timer, led_dat->num_timer);
if (ret < 0)
return ret;
mode_val = led_dat->mode_val[mode];
if (mode_val == NETXBIG_LED_INVALID_MODE)
return -EINVAL;
spin_lock_irq(&led_dat->lock);
gpio_ext_set_value(led_dat->gpio_ext, led_dat->mode_addr, mode_val);
led_dat->mode = mode;
spin_unlock_irq(&led_dat->lock);
return 0;
}
static void netxbig_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct netxbig_led_data *led_dat =
container_of(led_cdev, struct netxbig_led_data, cdev);
enum netxbig_led_mode mode;
int mode_val;
int set_brightness = 1;
unsigned long flags;
spin_lock_irqsave(&led_dat->lock, flags);
if (value == LED_OFF) {
mode = NETXBIG_LED_OFF;
set_brightness = 0;
} else {
if (led_dat->sata)
mode = NETXBIG_LED_SATA;
else if (led_dat->mode == NETXBIG_LED_OFF)
mode = NETXBIG_LED_ON;
else
mode = led_dat->mode;
}
mode_val = led_dat->mode_val[mode];
gpio_ext_set_value(led_dat->gpio_ext, led_dat->mode_addr, mode_val);
led_dat->mode = mode;
if (set_brightness)
gpio_ext_set_value(led_dat->gpio_ext,
led_dat->bright_addr, value);
spin_unlock_irqrestore(&led_dat->lock, flags);
}
static ssize_t netxbig_led_sata_store(struct device *dev,
struct device_attribute *attr,
const char *buff, size_t count)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct netxbig_led_data *led_dat =
container_of(led_cdev, struct netxbig_led_data, cdev);
unsigned long enable;
enum netxbig_led_mode mode;
int mode_val;
int ret;
ret = kstrtoul(buff, 10, &enable);
if (ret < 0)
return ret;
enable = !!enable;
spin_lock_irq(&led_dat->lock);
if (led_dat->sata == enable) {
ret = count;
goto exit_unlock;
}
if (led_dat->mode != NETXBIG_LED_ON &&
led_dat->mode != NETXBIG_LED_SATA)
mode = led_dat->mode;
else if (enable)
mode = NETXBIG_LED_SATA;
else
mode = NETXBIG_LED_ON;
mode_val = led_dat->mode_val[mode];
if (mode_val == NETXBIG_LED_INVALID_MODE) {
ret = -EINVAL;
goto exit_unlock;
}
gpio_ext_set_value(led_dat->gpio_ext, led_dat->mode_addr, mode_val);
led_dat->mode = mode;
led_dat->sata = enable;
ret = count;
exit_unlock:
spin_unlock_irq(&led_dat->lock);
return ret;
}
static ssize_t netxbig_led_sata_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct netxbig_led_data *led_dat =
container_of(led_cdev, struct netxbig_led_data, cdev);
return sprintf(buf, "%d\n", led_dat->sata);
}
static int create_netxbig_led(struct platform_device *pdev,
struct netxbig_led_platform_data *pdata,
struct netxbig_led_data *led_dat,
const struct netxbig_led *template)
{
spin_lock_init(&led_dat->lock);
led_dat->gpio_ext = pdata->gpio_ext;
led_dat->cdev.name = template->name;
led_dat->cdev.default_trigger = template->default_trigger;
led_dat->cdev.blink_set = netxbig_led_blink_set;
led_dat->cdev.brightness_set = netxbig_led_set;
led_dat->sata = 0;
led_dat->cdev.brightness = LED_OFF;
led_dat->cdev.max_brightness = template->bright_max;
led_dat->cdev.flags |= LED_CORE_SUSPENDRESUME;
led_dat->mode_addr = template->mode_addr;
led_dat->mode_val = template->mode_val;
led_dat->bright_addr = template->bright_addr;
led_dat->timer = pdata->timer;
led_dat->num_timer = pdata->num_timer;
if (led_dat->mode_val[NETXBIG_LED_SATA] != NETXBIG_LED_INVALID_MODE)
led_dat->cdev.groups = netxbig_led_groups;
return devm_led_classdev_register(&pdev->dev, &led_dat->cdev);
}
static int gpio_ext_get_of_pdata(struct device *dev, struct device_node *np,
struct netxbig_gpio_ext *gpio_ext)
{
int *addr, *data;
int num_addr, num_data;
int ret;
int i;
ret = of_gpio_named_count(np, "addr-gpios");
if (ret < 0) {
dev_err(dev,
"Failed to count GPIOs in DT property addr-gpios\n");
return ret;
}
num_addr = ret;
addr = devm_kzalloc(dev, num_addr * sizeof(*addr), GFP_KERNEL);
if (!addr)
return -ENOMEM;
for (i = 0; i < num_addr; i++) {
ret = of_get_named_gpio(np, "addr-gpios", i);
if (ret < 0)
return ret;
addr[i] = ret;
}
gpio_ext->addr = addr;
gpio_ext->num_addr = num_addr;
ret = of_gpio_named_count(np, "data-gpios");
if (ret < 0) {
dev_err(dev,
"Failed to count GPIOs in DT property data-gpios\n");
return ret;
}
num_data = ret;
data = devm_kzalloc(dev, num_data * sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
for (i = 0; i < num_data; i++) {
ret = of_get_named_gpio(np, "data-gpios", i);
if (ret < 0)
return ret;
data[i] = ret;
}
gpio_ext->data = data;
gpio_ext->num_data = num_data;
ret = of_get_named_gpio(np, "enable-gpio", 0);
if (ret < 0) {
dev_err(dev,
"Failed to get GPIO from DT property enable-gpio\n");
return ret;
}
gpio_ext->enable = ret;
return 0;
}
static int netxbig_leds_get_of_pdata(struct device *dev,
struct netxbig_led_platform_data *pdata)
{
struct device_node *np = dev->of_node;
struct device_node *gpio_ext_np;
struct device_node *child;
struct netxbig_gpio_ext *gpio_ext;
struct netxbig_led_timer *timers;
struct netxbig_led *leds, *led;
int num_timers;
int num_leds = 0;
int ret;
int i;
gpio_ext_np = of_parse_phandle(np, "gpio-ext", 0);
if (!gpio_ext_np) {
dev_err(dev, "Failed to get DT handle gpio-ext\n");
return -EINVAL;
}
gpio_ext = devm_kzalloc(dev, sizeof(*gpio_ext), GFP_KERNEL);
if (!gpio_ext)
return -ENOMEM;
ret = gpio_ext_get_of_pdata(dev, gpio_ext_np, gpio_ext);
if (ret)
return ret;
of_node_put(gpio_ext_np);
pdata->gpio_ext = gpio_ext;
ret = of_property_count_u32_elems(np, "timers");
if (ret > 0) {
if (ret % 3)
return -EINVAL;
num_timers = ret / 3;
timers = devm_kzalloc(dev, num_timers * sizeof(*timers),
GFP_KERNEL);
if (!timers)
return -ENOMEM;
for (i = 0; i < num_timers; i++) {
u32 tmp;
of_property_read_u32_index(np, "timers", 3 * i,
&timers[i].mode);
if (timers[i].mode >= NETXBIG_LED_MODE_NUM)
return -EINVAL;
of_property_read_u32_index(np, "timers",
3 * i + 1, &tmp);
timers[i].delay_on = tmp;
of_property_read_u32_index(np, "timers",
3 * i + 2, &tmp);
timers[i].delay_off = tmp;
}
pdata->timer = timers;
pdata->num_timer = num_timers;
}
num_leds = of_get_child_count(np);
if (!num_leds) {
dev_err(dev, "No LED subnodes found in DT\n");
return -ENODEV;
}
leds = devm_kzalloc(dev, num_leds * sizeof(*leds), GFP_KERNEL);
if (!leds)
return -ENOMEM;
led = leds;
for_each_child_of_node(np, child) {
const char *string;
int *mode_val;
int num_modes;
ret = of_property_read_u32(child, "mode-addr",
&led->mode_addr);
if (ret)
goto err_node_put;
ret = of_property_read_u32(child, "bright-addr",
&led->bright_addr);
if (ret)
goto err_node_put;
ret = of_property_read_u32(child, "max-brightness",
&led->bright_max);
if (ret)
goto err_node_put;
mode_val =
devm_kzalloc(dev,
NETXBIG_LED_MODE_NUM * sizeof(*mode_val),
GFP_KERNEL);
if (!mode_val) {
ret = -ENOMEM;
goto err_node_put;
}
for (i = 0; i < NETXBIG_LED_MODE_NUM; i++)
mode_val[i] = NETXBIG_LED_INVALID_MODE;
ret = of_property_count_u32_elems(child, "mode-val");
if (ret < 0 || ret % 2) {
ret = -EINVAL;
goto err_node_put;
}
num_modes = ret / 2;
if (num_modes > NETXBIG_LED_MODE_NUM) {
ret = -EINVAL;
goto err_node_put;
}
for (i = 0; i < num_modes; i++) {
int mode;
int val;
of_property_read_u32_index(child,
"mode-val", 2 * i, &mode);
of_property_read_u32_index(child,
"mode-val", 2 * i + 1, &val);
if (mode >= NETXBIG_LED_MODE_NUM) {
ret = -EINVAL;
goto err_node_put;
}
mode_val[mode] = val;
}
led->mode_val = mode_val;
if (!of_property_read_string(child, "label", &string))
led->name = string;
else
led->name = child->name;
if (!of_property_read_string(child,
"linux,default-trigger", &string))
led->default_trigger = string;
led++;
}
pdata->leds = leds;
pdata->num_leds = num_leds;
return 0;
err_node_put:
of_node_put(child);
return ret;
}
static inline int
netxbig_leds_get_of_pdata(struct device *dev,
struct netxbig_led_platform_data *pdata)
{
return -ENODEV;
}
static int netxbig_led_probe(struct platform_device *pdev)
{
struct netxbig_led_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct netxbig_led_data *leds_data;
int i;
int ret;
if (!pdata) {
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
ret = netxbig_leds_get_of_pdata(&pdev->dev, pdata);
if (ret)
return ret;
}
leds_data = devm_kzalloc(&pdev->dev,
pdata->num_leds * sizeof(*leds_data),
GFP_KERNEL);
if (!leds_data)
return -ENOMEM;
ret = gpio_ext_init(pdev, pdata->gpio_ext);
if (ret < 0)
return ret;
for (i = 0; i < pdata->num_leds; i++) {
ret = create_netxbig_led(pdev, pdata,
&leds_data[i], &pdata->leds[i]);
if (ret < 0)
return ret;
}
return 0;
}
