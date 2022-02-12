static void gpio_keys_polled_check_state(struct input_dev *input,
struct gpio_keys_button *button,
struct gpio_keys_button_data *bdata)
{
int state;
if (bdata->can_sleep)
state = !!gpio_get_value_cansleep(button->gpio);
else
state = !!gpio_get_value(button->gpio);
if (state != bdata->last_state) {
unsigned int type = button->type ?: EV_KEY;
input_event(input, type, button->code,
!!(state ^ button->active_low));
input_sync(input);
bdata->count = 0;
bdata->last_state = state;
}
}
static void gpio_keys_polled_poll(struct input_polled_dev *dev)
{
struct gpio_keys_polled_dev *bdev = dev->private;
const struct gpio_keys_platform_data *pdata = bdev->pdata;
struct input_dev *input = dev->input;
int i;
for (i = 0; i < pdata->nbuttons; i++) {
struct gpio_keys_button_data *bdata = &bdev->data[i];
if (bdata->count < bdata->threshold)
bdata->count++;
else
gpio_keys_polled_check_state(input, &pdata->buttons[i],
bdata);
}
}
static void gpio_keys_polled_open(struct input_polled_dev *dev)
{
struct gpio_keys_polled_dev *bdev = dev->private;
const struct gpio_keys_platform_data *pdata = bdev->pdata;
if (pdata->enable)
pdata->enable(bdev->dev);
}
static void gpio_keys_polled_close(struct input_polled_dev *dev)
{
struct gpio_keys_polled_dev *bdev = dev->private;
const struct gpio_keys_platform_data *pdata = bdev->pdata;
if (pdata->disable)
pdata->disable(bdev->dev);
}
static struct gpio_keys_platform_data *gpio_keys_polled_get_devtree_pdata(struct device *dev)
{
struct device_node *node, *pp;
struct gpio_keys_platform_data *pdata;
struct gpio_keys_button *button;
int error;
int nbuttons;
int i;
node = dev->of_node;
if (!node)
return NULL;
nbuttons = of_get_child_count(node);
if (nbuttons == 0)
return NULL;
pdata = devm_kzalloc(dev, sizeof(*pdata) + nbuttons * sizeof(*button),
GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
pdata->buttons = (struct gpio_keys_button *)(pdata + 1);
pdata->nbuttons = nbuttons;
pdata->rep = !!of_get_property(node, "autorepeat", NULL);
of_property_read_u32(node, "poll-interval", &pdata->poll_interval);
i = 0;
for_each_child_of_node(node, pp) {
int gpio;
enum of_gpio_flags flags;
if (!of_find_property(pp, "gpios", NULL)) {
pdata->nbuttons--;
dev_warn(dev, "Found button without gpios\n");
continue;
}
gpio = of_get_gpio_flags(pp, 0, &flags);
if (gpio < 0) {
error = gpio;
if (error != -EPROBE_DEFER)
dev_err(dev,
"Failed to get gpio flags, error: %d\n",
error);
return ERR_PTR(error);
}
button = &pdata->buttons[i++];
button->gpio = gpio;
button->active_low = flags & OF_GPIO_ACTIVE_LOW;
if (of_property_read_u32(pp, "linux,code", &button->code)) {
dev_err(dev, "Button without keycode: 0x%x\n",
button->gpio);
return ERR_PTR(-EINVAL);
}
button->desc = of_get_property(pp, "label", NULL);
if (of_property_read_u32(pp, "linux,input-type", &button->type))
button->type = EV_KEY;
button->wakeup = !!of_get_property(pp, "gpio-key,wakeup", NULL);
if (of_property_read_u32(pp, "debounce-interval",
&button->debounce_interval))
button->debounce_interval = 5;
}
if (pdata->nbuttons == 0)
return ERR_PTR(-EINVAL);
return pdata;
}
static inline struct gpio_keys_platform_data *
gpio_keys_polled_get_devtree_pdata(struct device *dev)
{
return NULL;
}
static int gpio_keys_polled_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct gpio_keys_platform_data *pdata = dev_get_platdata(dev);
struct gpio_keys_polled_dev *bdev;
struct input_polled_dev *poll_dev;
struct input_dev *input;
size_t size;
int error;
int i;
if (!pdata) {
pdata = gpio_keys_polled_get_devtree_pdata(dev);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
if (!pdata) {
dev_err(dev, "missing platform data\n");
return -EINVAL;
}
}
if (!pdata->poll_interval) {
dev_err(dev, "missing poll_interval value\n");
return -EINVAL;
}
size = sizeof(struct gpio_keys_polled_dev) +
pdata->nbuttons * sizeof(struct gpio_keys_button_data);
bdev = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
if (!bdev) {
dev_err(dev, "no memory for private data\n");
return -ENOMEM;
}
poll_dev = devm_input_allocate_polled_device(&pdev->dev);
if (!poll_dev) {
dev_err(dev, "no memory for polled device\n");
return -ENOMEM;
}
poll_dev->private = bdev;
poll_dev->poll = gpio_keys_polled_poll;
poll_dev->poll_interval = pdata->poll_interval;
poll_dev->open = gpio_keys_polled_open;
poll_dev->close = gpio_keys_polled_close;
input = poll_dev->input;
input->name = pdev->name;
input->phys = DRV_NAME"/input0";
input->id.bustype = BUS_HOST;
input->id.vendor = 0x0001;
input->id.product = 0x0001;
input->id.version = 0x0100;
__set_bit(EV_KEY, input->evbit);
if (pdata->rep)
__set_bit(EV_REP, input->evbit);
for (i = 0; i < pdata->nbuttons; i++) {
struct gpio_keys_button *button = &pdata->buttons[i];
struct gpio_keys_button_data *bdata = &bdev->data[i];
unsigned int gpio = button->gpio;
unsigned int type = button->type ?: EV_KEY;
if (button->wakeup) {
dev_err(dev, DRV_NAME " does not support wakeup\n");
return -EINVAL;
}
error = devm_gpio_request_one(&pdev->dev, gpio, GPIOF_IN,
button->desc ? : DRV_NAME);
if (error) {
dev_err(dev, "unable to claim gpio %u, err=%d\n",
gpio, error);
return error;
}
bdata->can_sleep = gpio_cansleep(gpio);
bdata->last_state = -1;
bdata->threshold = DIV_ROUND_UP(button->debounce_interval,
pdata->poll_interval);
input_set_capability(input, type, button->code);
}
bdev->poll_dev = poll_dev;
bdev->dev = dev;
bdev->pdata = pdata;
platform_set_drvdata(pdev, bdev);
error = input_register_polled_device(poll_dev);
if (error) {
dev_err(dev, "unable to register polled device, err=%d\n",
error);
return error;
}
for (i = 0; i < pdata->nbuttons; i++)
gpio_keys_polled_check_state(input, &pdata->buttons[i],
&bdev->data[i]);
return 0;
}
