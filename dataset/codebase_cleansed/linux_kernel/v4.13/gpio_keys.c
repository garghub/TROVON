static int get_n_events_by_type(int type)
{
BUG_ON(type != EV_SW && type != EV_KEY);
return (type == EV_KEY) ? KEY_CNT : SW_CNT;
}
static const unsigned long *get_bm_events_by_type(struct input_dev *dev,
int type)
{
BUG_ON(type != EV_SW && type != EV_KEY);
return (type == EV_KEY) ? dev->keybit : dev->swbit;
}
static void gpio_keys_disable_button(struct gpio_button_data *bdata)
{
if (!bdata->disabled) {
disable_irq(bdata->irq);
if (bdata->gpiod)
cancel_delayed_work_sync(&bdata->work);
else
del_timer_sync(&bdata->release_timer);
bdata->disabled = true;
}
}
static void gpio_keys_enable_button(struct gpio_button_data *bdata)
{
if (bdata->disabled) {
enable_irq(bdata->irq);
bdata->disabled = false;
}
}
static ssize_t gpio_keys_attr_show_helper(struct gpio_keys_drvdata *ddata,
char *buf, unsigned int type,
bool only_disabled)
{
int n_events = get_n_events_by_type(type);
unsigned long *bits;
ssize_t ret;
int i;
bits = kcalloc(BITS_TO_LONGS(n_events), sizeof(*bits), GFP_KERNEL);
if (!bits)
return -ENOMEM;
for (i = 0; i < ddata->pdata->nbuttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->type != type)
continue;
if (only_disabled && !bdata->disabled)
continue;
__set_bit(*bdata->code, bits);
}
ret = scnprintf(buf, PAGE_SIZE - 1, "%*pbl", n_events, bits);
buf[ret++] = '\n';
buf[ret] = '\0';
kfree(bits);
return ret;
}
static ssize_t gpio_keys_attr_store_helper(struct gpio_keys_drvdata *ddata,
const char *buf, unsigned int type)
{
int n_events = get_n_events_by_type(type);
const unsigned long *bitmap = get_bm_events_by_type(ddata->input, type);
unsigned long *bits;
ssize_t error;
int i;
bits = kcalloc(BITS_TO_LONGS(n_events), sizeof(*bits), GFP_KERNEL);
if (!bits)
return -ENOMEM;
error = bitmap_parselist(buf, bits, n_events);
if (error)
goto out;
if (!bitmap_subset(bits, bitmap, n_events)) {
error = -EINVAL;
goto out;
}
for (i = 0; i < ddata->pdata->nbuttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->type != type)
continue;
if (test_bit(*bdata->code, bits) &&
!bdata->button->can_disable) {
error = -EINVAL;
goto out;
}
}
mutex_lock(&ddata->disable_lock);
for (i = 0; i < ddata->pdata->nbuttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->type != type)
continue;
if (test_bit(*bdata->code, bits))
gpio_keys_disable_button(bdata);
else
gpio_keys_enable_button(bdata);
}
mutex_unlock(&ddata->disable_lock);
out:
kfree(bits);
return error;
}
static void gpio_keys_gpio_report_event(struct gpio_button_data *bdata)
{
const struct gpio_keys_button *button = bdata->button;
struct input_dev *input = bdata->input;
unsigned int type = button->type ?: EV_KEY;
int state;
state = gpiod_get_value_cansleep(bdata->gpiod);
if (state < 0) {
dev_err(input->dev.parent,
"failed to get gpio state: %d\n", state);
return;
}
if (type == EV_ABS) {
if (state)
input_event(input, type, button->code, button->value);
} else {
input_event(input, type, *bdata->code, state);
}
input_sync(input);
}
static void gpio_keys_gpio_work_func(struct work_struct *work)
{
struct gpio_button_data *bdata =
container_of(work, struct gpio_button_data, work.work);
gpio_keys_gpio_report_event(bdata);
if (bdata->button->wakeup)
pm_relax(bdata->input->dev.parent);
}
static irqreturn_t gpio_keys_gpio_isr(int irq, void *dev_id)
{
struct gpio_button_data *bdata = dev_id;
BUG_ON(irq != bdata->irq);
if (bdata->button->wakeup) {
const struct gpio_keys_button *button = bdata->button;
pm_stay_awake(bdata->input->dev.parent);
if (bdata->suspended &&
(button->type == 0 || button->type == EV_KEY)) {
input_report_key(bdata->input, button->code, 1);
}
}
mod_delayed_work(system_wq,
&bdata->work,
msecs_to_jiffies(bdata->software_debounce));
return IRQ_HANDLED;
}
static void gpio_keys_irq_timer(unsigned long _data)
{
struct gpio_button_data *bdata = (struct gpio_button_data *)_data;
struct input_dev *input = bdata->input;
unsigned long flags;
spin_lock_irqsave(&bdata->lock, flags);
if (bdata->key_pressed) {
input_event(input, EV_KEY, *bdata->code, 0);
input_sync(input);
bdata->key_pressed = false;
}
spin_unlock_irqrestore(&bdata->lock, flags);
}
static irqreturn_t gpio_keys_irq_isr(int irq, void *dev_id)
{
struct gpio_button_data *bdata = dev_id;
struct input_dev *input = bdata->input;
unsigned long flags;
BUG_ON(irq != bdata->irq);
spin_lock_irqsave(&bdata->lock, flags);
if (!bdata->key_pressed) {
if (bdata->button->wakeup)
pm_wakeup_event(bdata->input->dev.parent, 0);
input_event(input, EV_KEY, *bdata->code, 1);
input_sync(input);
if (!bdata->release_delay) {
input_event(input, EV_KEY, *bdata->code, 0);
input_sync(input);
goto out;
}
bdata->key_pressed = true;
}
if (bdata->release_delay)
mod_timer(&bdata->release_timer,
jiffies + msecs_to_jiffies(bdata->release_delay));
out:
spin_unlock_irqrestore(&bdata->lock, flags);
return IRQ_HANDLED;
}
static void gpio_keys_quiesce_key(void *data)
{
struct gpio_button_data *bdata = data;
if (bdata->gpiod)
cancel_delayed_work_sync(&bdata->work);
else
del_timer_sync(&bdata->release_timer);
}
static int gpio_keys_setup_key(struct platform_device *pdev,
struct input_dev *input,
struct gpio_keys_drvdata *ddata,
const struct gpio_keys_button *button,
int idx,
struct fwnode_handle *child)
{
const char *desc = button->desc ? button->desc : "gpio_keys";
struct device *dev = &pdev->dev;
struct gpio_button_data *bdata = &ddata->data[idx];
irq_handler_t isr;
unsigned long irqflags;
int irq;
int error;
bdata->input = input;
bdata->button = button;
spin_lock_init(&bdata->lock);
if (child) {
bdata->gpiod = devm_fwnode_get_gpiod_from_child(dev, NULL,
child,
GPIOD_IN,
desc);
if (IS_ERR(bdata->gpiod)) {
error = PTR_ERR(bdata->gpiod);
if (error == -ENOENT) {
bdata->gpiod = NULL;
} else {
if (error != -EPROBE_DEFER)
dev_err(dev, "failed to get gpio: %d\n",
error);
return error;
}
}
} else if (gpio_is_valid(button->gpio)) {
unsigned flags = GPIOF_IN;
if (button->active_low)
flags |= GPIOF_ACTIVE_LOW;
error = devm_gpio_request_one(dev, button->gpio, flags, desc);
if (error < 0) {
dev_err(dev, "Failed to request GPIO %d, error %d\n",
button->gpio, error);
return error;
}
bdata->gpiod = gpio_to_desc(button->gpio);
if (!bdata->gpiod)
return -EINVAL;
}
if (bdata->gpiod) {
if (button->debounce_interval) {
error = gpiod_set_debounce(bdata->gpiod,
button->debounce_interval * 1000);
if (error < 0)
bdata->software_debounce =
button->debounce_interval;
}
if (button->irq) {
bdata->irq = button->irq;
} else {
irq = gpiod_to_irq(bdata->gpiod);
if (irq < 0) {
error = irq;
dev_err(dev,
"Unable to get irq number for GPIO %d, error %d\n",
button->gpio, error);
return error;
}
bdata->irq = irq;
}
INIT_DELAYED_WORK(&bdata->work, gpio_keys_gpio_work_func);
isr = gpio_keys_gpio_isr;
irqflags = IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING;
} else {
if (!button->irq) {
dev_err(dev, "Found button without gpio or irq\n");
return -EINVAL;
}
bdata->irq = button->irq;
if (button->type && button->type != EV_KEY) {
dev_err(dev, "Only EV_KEY allowed for IRQ buttons.\n");
return -EINVAL;
}
bdata->release_delay = button->debounce_interval;
setup_timer(&bdata->release_timer,
gpio_keys_irq_timer, (unsigned long)bdata);
isr = gpio_keys_irq_isr;
irqflags = 0;
}
bdata->code = &ddata->keymap[idx];
*bdata->code = button->code;
input_set_capability(input, button->type ?: EV_KEY, *bdata->code);
error = devm_add_action(dev, gpio_keys_quiesce_key, bdata);
if (error) {
dev_err(dev, "failed to register quiesce action, error: %d\n",
error);
return error;
}
if (!button->can_disable)
irqflags |= IRQF_SHARED;
error = devm_request_any_context_irq(dev, bdata->irq, isr, irqflags,
desc, bdata);
if (error < 0) {
dev_err(dev, "Unable to claim irq %d; error %d\n",
bdata->irq, error);
return error;
}
return 0;
}
static void gpio_keys_report_state(struct gpio_keys_drvdata *ddata)
{
struct input_dev *input = ddata->input;
int i;
for (i = 0; i < ddata->pdata->nbuttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->gpiod)
gpio_keys_gpio_report_event(bdata);
}
input_sync(input);
}
static int gpio_keys_open(struct input_dev *input)
{
struct gpio_keys_drvdata *ddata = input_get_drvdata(input);
const struct gpio_keys_platform_data *pdata = ddata->pdata;
int error;
if (pdata->enable) {
error = pdata->enable(input->dev.parent);
if (error)
return error;
}
gpio_keys_report_state(ddata);
return 0;
}
static void gpio_keys_close(struct input_dev *input)
{
struct gpio_keys_drvdata *ddata = input_get_drvdata(input);
const struct gpio_keys_platform_data *pdata = ddata->pdata;
if (pdata->disable)
pdata->disable(input->dev.parent);
}
static struct gpio_keys_platform_data *
gpio_keys_get_devtree_pdata(struct device *dev)
{
struct gpio_keys_platform_data *pdata;
struct gpio_keys_button *button;
struct fwnode_handle *child;
int nbuttons;
nbuttons = device_get_child_node_count(dev);
if (nbuttons == 0)
return ERR_PTR(-ENODEV);
pdata = devm_kzalloc(dev,
sizeof(*pdata) + nbuttons * sizeof(*button),
GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
button = (struct gpio_keys_button *)(pdata + 1);
pdata->buttons = button;
pdata->nbuttons = nbuttons;
pdata->rep = device_property_read_bool(dev, "autorepeat");
device_property_read_string(dev, "label", &pdata->name);
device_for_each_child_node(dev, child) {
if (is_of_node(child))
button->irq =
irq_of_parse_and_map(to_of_node(child), 0);
if (fwnode_property_read_u32(child, "linux,code",
&button->code)) {
dev_err(dev, "Button without keycode\n");
fwnode_handle_put(child);
return ERR_PTR(-EINVAL);
}
fwnode_property_read_string(child, "label", &button->desc);
if (fwnode_property_read_u32(child, "linux,input-type",
&button->type))
button->type = EV_KEY;
button->wakeup =
fwnode_property_read_bool(child, "wakeup-source") ||
fwnode_property_read_bool(child, "gpio-key,wakeup");
button->can_disable =
fwnode_property_read_bool(child, "linux,can-disable");
if (fwnode_property_read_u32(child, "debounce-interval",
&button->debounce_interval))
button->debounce_interval = 5;
button++;
}
return pdata;
}
static int gpio_keys_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct gpio_keys_platform_data *pdata = dev_get_platdata(dev);
struct fwnode_handle *child = NULL;
struct gpio_keys_drvdata *ddata;
struct input_dev *input;
size_t size;
int i, error;
int wakeup = 0;
if (!pdata) {
pdata = gpio_keys_get_devtree_pdata(dev);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
}
size = sizeof(struct gpio_keys_drvdata) +
pdata->nbuttons * sizeof(struct gpio_button_data);
ddata = devm_kzalloc(dev, size, GFP_KERNEL);
if (!ddata) {
dev_err(dev, "failed to allocate state\n");
return -ENOMEM;
}
ddata->keymap = devm_kcalloc(dev,
pdata->nbuttons, sizeof(ddata->keymap[0]),
GFP_KERNEL);
if (!ddata->keymap)
return -ENOMEM;
input = devm_input_allocate_device(dev);
if (!input) {
dev_err(dev, "failed to allocate input device\n");
return -ENOMEM;
}
ddata->pdata = pdata;
ddata->input = input;
mutex_init(&ddata->disable_lock);
platform_set_drvdata(pdev, ddata);
input_set_drvdata(input, ddata);
input->name = pdata->name ? : pdev->name;
input->phys = "gpio-keys/input0";
input->dev.parent = dev;
input->open = gpio_keys_open;
input->close = gpio_keys_close;
input->id.bustype = BUS_HOST;
input->id.vendor = 0x0001;
input->id.product = 0x0001;
input->id.version = 0x0100;
input->keycode = ddata->keymap;
input->keycodesize = sizeof(ddata->keymap[0]);
input->keycodemax = pdata->nbuttons;
if (pdata->rep)
__set_bit(EV_REP, input->evbit);
for (i = 0; i < pdata->nbuttons; i++) {
const struct gpio_keys_button *button = &pdata->buttons[i];
if (!dev_get_platdata(dev)) {
child = device_get_next_child_node(dev, child);
if (!child) {
dev_err(dev,
"missing child device node for entry %d\n",
i);
return -EINVAL;
}
}
error = gpio_keys_setup_key(pdev, input, ddata,
button, i, child);
if (error) {
fwnode_handle_put(child);
return error;
}
if (button->wakeup)
wakeup = 1;
}
fwnode_handle_put(child);
error = sysfs_create_group(&dev->kobj, &gpio_keys_attr_group);
if (error) {
dev_err(dev, "Unable to export keys/switches, error: %d\n",
error);
return error;
}
error = input_register_device(input);
if (error) {
dev_err(dev, "Unable to register input device, error: %d\n",
error);
goto err_remove_group;
}
device_init_wakeup(dev, wakeup);
return 0;
err_remove_group:
sysfs_remove_group(&dev->kobj, &gpio_keys_attr_group);
return error;
}
static int gpio_keys_remove(struct platform_device *pdev)
{
sysfs_remove_group(&pdev->dev.kobj, &gpio_keys_attr_group);
return 0;
}
static int __maybe_unused gpio_keys_suspend(struct device *dev)
{
struct gpio_keys_drvdata *ddata = dev_get_drvdata(dev);
struct input_dev *input = ddata->input;
int i;
if (device_may_wakeup(dev)) {
for (i = 0; i < ddata->pdata->nbuttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->wakeup)
enable_irq_wake(bdata->irq);
bdata->suspended = true;
}
} else {
mutex_lock(&input->mutex);
if (input->users)
gpio_keys_close(input);
mutex_unlock(&input->mutex);
}
return 0;
}
static int __maybe_unused gpio_keys_resume(struct device *dev)
{
struct gpio_keys_drvdata *ddata = dev_get_drvdata(dev);
struct input_dev *input = ddata->input;
int error = 0;
int i;
if (device_may_wakeup(dev)) {
for (i = 0; i < ddata->pdata->nbuttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->wakeup)
disable_irq_wake(bdata->irq);
bdata->suspended = false;
}
} else {
mutex_lock(&input->mutex);
if (input->users)
error = gpio_keys_open(input);
mutex_unlock(&input->mutex);
}
if (error)
return error;
gpio_keys_report_state(ddata);
return 0;
}
static int __init gpio_keys_init(void)
{
return platform_driver_register(&gpio_keys_device_driver);
}
static void __exit gpio_keys_exit(void)
{
platform_driver_unregister(&gpio_keys_device_driver);
}
