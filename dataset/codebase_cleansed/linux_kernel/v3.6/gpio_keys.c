static inline int get_n_events_by_type(int type)
{
BUG_ON(type != EV_SW && type != EV_KEY);
return (type == EV_KEY) ? KEY_CNT : SW_CNT;
}
static void gpio_keys_disable_button(struct gpio_button_data *bdata)
{
if (!bdata->disabled) {
disable_irq(bdata->irq);
if (bdata->timer_debounce)
del_timer_sync(&bdata->timer);
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
for (i = 0; i < ddata->n_buttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->type != type)
continue;
if (only_disabled && !bdata->disabled)
continue;
__set_bit(bdata->button->code, bits);
}
ret = bitmap_scnlistprintf(buf, PAGE_SIZE - 2, bits, n_events);
buf[ret++] = '\n';
buf[ret] = '\0';
kfree(bits);
return ret;
}
static ssize_t gpio_keys_attr_store_helper(struct gpio_keys_drvdata *ddata,
const char *buf, unsigned int type)
{
int n_events = get_n_events_by_type(type);
unsigned long *bits;
ssize_t error;
int i;
bits = kcalloc(BITS_TO_LONGS(n_events), sizeof(*bits), GFP_KERNEL);
if (!bits)
return -ENOMEM;
error = bitmap_parselist(buf, bits, n_events);
if (error)
goto out;
for (i = 0; i < ddata->n_buttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->type != type)
continue;
if (test_bit(bdata->button->code, bits) &&
!bdata->button->can_disable) {
error = -EINVAL;
goto out;
}
}
mutex_lock(&ddata->disable_lock);
for (i = 0; i < ddata->n_buttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->type != type)
continue;
if (test_bit(bdata->button->code, bits))
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
int state = (gpio_get_value_cansleep(button->gpio) ? 1 : 0) ^ button->active_low;
if (type == EV_ABS) {
if (state)
input_event(input, type, button->code, button->value);
} else {
input_event(input, type, button->code, !!state);
}
input_sync(input);
}
static void gpio_keys_gpio_work_func(struct work_struct *work)
{
struct gpio_button_data *bdata =
container_of(work, struct gpio_button_data, work);
gpio_keys_gpio_report_event(bdata);
}
static void gpio_keys_gpio_timer(unsigned long _data)
{
struct gpio_button_data *bdata = (struct gpio_button_data *)_data;
schedule_work(&bdata->work);
}
static irqreturn_t gpio_keys_gpio_isr(int irq, void *dev_id)
{
struct gpio_button_data *bdata = dev_id;
BUG_ON(irq != bdata->irq);
if (bdata->timer_debounce)
mod_timer(&bdata->timer,
jiffies + msecs_to_jiffies(bdata->timer_debounce));
else
schedule_work(&bdata->work);
return IRQ_HANDLED;
}
static void gpio_keys_irq_timer(unsigned long _data)
{
struct gpio_button_data *bdata = (struct gpio_button_data *)_data;
struct input_dev *input = bdata->input;
unsigned long flags;
spin_lock_irqsave(&bdata->lock, flags);
if (bdata->key_pressed) {
input_event(input, EV_KEY, bdata->button->code, 0);
input_sync(input);
bdata->key_pressed = false;
}
spin_unlock_irqrestore(&bdata->lock, flags);
}
static irqreturn_t gpio_keys_irq_isr(int irq, void *dev_id)
{
struct gpio_button_data *bdata = dev_id;
const struct gpio_keys_button *button = bdata->button;
struct input_dev *input = bdata->input;
unsigned long flags;
BUG_ON(irq != bdata->irq);
spin_lock_irqsave(&bdata->lock, flags);
if (!bdata->key_pressed) {
input_event(input, EV_KEY, button->code, 1);
input_sync(input);
if (!bdata->timer_debounce) {
input_event(input, EV_KEY, button->code, 0);
input_sync(input);
goto out;
}
bdata->key_pressed = true;
}
if (bdata->timer_debounce)
mod_timer(&bdata->timer,
jiffies + msecs_to_jiffies(bdata->timer_debounce));
out:
spin_unlock_irqrestore(&bdata->lock, flags);
return IRQ_HANDLED;
}
static int __devinit gpio_keys_setup_key(struct platform_device *pdev,
struct input_dev *input,
struct gpio_button_data *bdata,
const struct gpio_keys_button *button)
{
const char *desc = button->desc ? button->desc : "gpio_keys";
struct device *dev = &pdev->dev;
irq_handler_t isr;
unsigned long irqflags;
int irq, error;
bdata->input = input;
bdata->button = button;
spin_lock_init(&bdata->lock);
if (gpio_is_valid(button->gpio)) {
error = gpio_request(button->gpio, desc);
if (error < 0) {
dev_err(dev, "Failed to request GPIO %d, error %d\n",
button->gpio, error);
return error;
}
error = gpio_direction_input(button->gpio);
if (error < 0) {
dev_err(dev,
"Failed to configure direction for GPIO %d, error %d\n",
button->gpio, error);
goto fail;
}
if (button->debounce_interval) {
error = gpio_set_debounce(button->gpio,
button->debounce_interval * 1000);
if (error < 0)
bdata->timer_debounce =
button->debounce_interval;
}
irq = gpio_to_irq(button->gpio);
if (irq < 0) {
error = irq;
dev_err(dev,
"Unable to get irq number for GPIO %d, error %d\n",
button->gpio, error);
goto fail;
}
bdata->irq = irq;
INIT_WORK(&bdata->work, gpio_keys_gpio_work_func);
setup_timer(&bdata->timer,
gpio_keys_gpio_timer, (unsigned long)bdata);
isr = gpio_keys_gpio_isr;
irqflags = IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING;
} else {
if (!button->irq) {
dev_err(dev, "No IRQ specified\n");
return -EINVAL;
}
bdata->irq = button->irq;
if (button->type && button->type != EV_KEY) {
dev_err(dev, "Only EV_KEY allowed for IRQ buttons.\n");
return -EINVAL;
}
bdata->timer_debounce = button->debounce_interval;
setup_timer(&bdata->timer,
gpio_keys_irq_timer, (unsigned long)bdata);
isr = gpio_keys_irq_isr;
irqflags = 0;
}
input_set_capability(input, button->type ?: EV_KEY, button->code);
if (!button->can_disable)
irqflags |= IRQF_SHARED;
error = request_any_context_irq(bdata->irq, isr, irqflags, desc, bdata);
if (error < 0) {
dev_err(dev, "Unable to claim irq %d; error %d\n",
bdata->irq, error);
goto fail;
}
return 0;
fail:
if (gpio_is_valid(button->gpio))
gpio_free(button->gpio);
return error;
}
static int gpio_keys_open(struct input_dev *input)
{
struct gpio_keys_drvdata *ddata = input_get_drvdata(input);
return ddata->enable ? ddata->enable(input->dev.parent) : 0;
}
static void gpio_keys_close(struct input_dev *input)
{
struct gpio_keys_drvdata *ddata = input_get_drvdata(input);
if (ddata->disable)
ddata->disable(input->dev.parent);
}
static int gpio_keys_get_devtree_pdata(struct device *dev,
struct gpio_keys_platform_data *pdata)
{
struct device_node *node, *pp;
int i;
struct gpio_keys_button *buttons;
u32 reg;
node = dev->of_node;
if (node == NULL)
return -ENODEV;
memset(pdata, 0, sizeof *pdata);
pdata->rep = !!of_get_property(node, "autorepeat", NULL);
pp = NULL;
while ((pp = of_get_next_child(node, pp)))
pdata->nbuttons++;
if (pdata->nbuttons == 0)
return -ENODEV;
buttons = kzalloc(pdata->nbuttons * (sizeof *buttons), GFP_KERNEL);
if (!buttons)
return -ENOMEM;
pp = NULL;
i = 0;
while ((pp = of_get_next_child(node, pp))) {
enum of_gpio_flags flags;
if (!of_find_property(pp, "gpios", NULL)) {
pdata->nbuttons--;
dev_warn(dev, "Found button without gpios\n");
continue;
}
buttons[i].gpio = of_get_gpio_flags(pp, 0, &flags);
buttons[i].active_low = flags & OF_GPIO_ACTIVE_LOW;
if (of_property_read_u32(pp, "linux,code", &reg)) {
dev_err(dev, "Button without keycode: 0x%x\n", buttons[i].gpio);
goto out_fail;
}
buttons[i].code = reg;
buttons[i].desc = of_get_property(pp, "label", NULL);
if (of_property_read_u32(pp, "linux,input-type", &reg) == 0)
buttons[i].type = reg;
else
buttons[i].type = EV_KEY;
buttons[i].wakeup = !!of_get_property(pp, "gpio-key,wakeup", NULL);
if (of_property_read_u32(pp, "debounce-interval", &reg) == 0)
buttons[i].debounce_interval = reg;
else
buttons[i].debounce_interval = 5;
i++;
}
pdata->buttons = buttons;
return 0;
out_fail:
kfree(buttons);
return -ENODEV;
}
static int gpio_keys_get_devtree_pdata(struct device *dev,
struct gpio_keys_platform_data *altp)
{
return -ENODEV;
}
static void gpio_remove_key(struct gpio_button_data *bdata)
{
free_irq(bdata->irq, bdata);
if (bdata->timer_debounce)
del_timer_sync(&bdata->timer);
cancel_work_sync(&bdata->work);
if (gpio_is_valid(bdata->button->gpio))
gpio_free(bdata->button->gpio);
}
static int __devinit gpio_keys_probe(struct platform_device *pdev)
{
const struct gpio_keys_platform_data *pdata = pdev->dev.platform_data;
struct gpio_keys_drvdata *ddata;
struct device *dev = &pdev->dev;
struct gpio_keys_platform_data alt_pdata;
struct input_dev *input;
int i, error;
int wakeup = 0;
if (!pdata) {
error = gpio_keys_get_devtree_pdata(dev, &alt_pdata);
if (error)
return error;
pdata = &alt_pdata;
}
ddata = kzalloc(sizeof(struct gpio_keys_drvdata) +
pdata->nbuttons * sizeof(struct gpio_button_data),
GFP_KERNEL);
input = input_allocate_device();
if (!ddata || !input) {
dev_err(dev, "failed to allocate state\n");
error = -ENOMEM;
goto fail1;
}
ddata->input = input;
ddata->n_buttons = pdata->nbuttons;
ddata->enable = pdata->enable;
ddata->disable = pdata->disable;
mutex_init(&ddata->disable_lock);
platform_set_drvdata(pdev, ddata);
input_set_drvdata(input, ddata);
input->name = pdata->name ? : pdev->name;
input->phys = "gpio-keys/input0";
input->dev.parent = &pdev->dev;
input->open = gpio_keys_open;
input->close = gpio_keys_close;
input->id.bustype = BUS_HOST;
input->id.vendor = 0x0001;
input->id.product = 0x0001;
input->id.version = 0x0100;
if (pdata->rep)
__set_bit(EV_REP, input->evbit);
for (i = 0; i < pdata->nbuttons; i++) {
const struct gpio_keys_button *button = &pdata->buttons[i];
struct gpio_button_data *bdata = &ddata->data[i];
error = gpio_keys_setup_key(pdev, input, bdata, button);
if (error)
goto fail2;
if (button->wakeup)
wakeup = 1;
}
error = sysfs_create_group(&pdev->dev.kobj, &gpio_keys_attr_group);
if (error) {
dev_err(dev, "Unable to export keys/switches, error: %d\n",
error);
goto fail2;
}
error = input_register_device(input);
if (error) {
dev_err(dev, "Unable to register input device, error: %d\n",
error);
goto fail3;
}
for (i = 0; i < pdata->nbuttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (gpio_is_valid(bdata->button->gpio))
gpio_keys_gpio_report_event(bdata);
}
input_sync(input);
device_init_wakeup(&pdev->dev, wakeup);
return 0;
fail3:
sysfs_remove_group(&pdev->dev.kobj, &gpio_keys_attr_group);
fail2:
while (--i >= 0)
gpio_remove_key(&ddata->data[i]);
platform_set_drvdata(pdev, NULL);
fail1:
input_free_device(input);
kfree(ddata);
if (!pdev->dev.platform_data)
kfree(pdata->buttons);
return error;
}
static int __devexit gpio_keys_remove(struct platform_device *pdev)
{
struct gpio_keys_drvdata *ddata = platform_get_drvdata(pdev);
struct input_dev *input = ddata->input;
int i;
sysfs_remove_group(&pdev->dev.kobj, &gpio_keys_attr_group);
device_init_wakeup(&pdev->dev, 0);
for (i = 0; i < ddata->n_buttons; i++)
gpio_remove_key(&ddata->data[i]);
input_unregister_device(input);
if (!pdev->dev.platform_data)
kfree(ddata->data[0].button);
kfree(ddata);
return 0;
}
static int gpio_keys_suspend(struct device *dev)
{
struct gpio_keys_drvdata *ddata = dev_get_drvdata(dev);
int i;
if (device_may_wakeup(dev)) {
for (i = 0; i < ddata->n_buttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->wakeup)
enable_irq_wake(bdata->irq);
}
}
return 0;
}
static int gpio_keys_resume(struct device *dev)
{
struct gpio_keys_drvdata *ddata = dev_get_drvdata(dev);
int i;
for (i = 0; i < ddata->n_buttons; i++) {
struct gpio_button_data *bdata = &ddata->data[i];
if (bdata->button->wakeup && device_may_wakeup(dev))
disable_irq_wake(bdata->irq);
if (gpio_is_valid(bdata->button->gpio))
gpio_keys_gpio_report_event(bdata);
}
input_sync(ddata->input);
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
