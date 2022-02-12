static int dln2_gpio_get_pin_count(struct platform_device *pdev)
{
int ret;
__le16 count;
int len = sizeof(count);
ret = dln2_transfer_rx(pdev, DLN2_GPIO_GET_PIN_COUNT, &count, &len);
if (ret < 0)
return ret;
if (len < sizeof(count))
return -EPROTO;
return le16_to_cpu(count);
}
static int dln2_gpio_pin_cmd(struct dln2_gpio *dln2, int cmd, unsigned pin)
{
struct dln2_gpio_pin req = {
.pin = cpu_to_le16(pin),
};
return dln2_transfer_tx(dln2->pdev, cmd, &req, sizeof(req));
}
static int dln2_gpio_pin_val(struct dln2_gpio *dln2, int cmd, unsigned int pin)
{
int ret;
struct dln2_gpio_pin req = {
.pin = cpu_to_le16(pin),
};
struct dln2_gpio_pin_val rsp;
int len = sizeof(rsp);
ret = dln2_transfer(dln2->pdev, cmd, &req, sizeof(req), &rsp, &len);
if (ret < 0)
return ret;
if (len < sizeof(rsp) || req.pin != rsp.pin)
return -EPROTO;
return rsp.value;
}
static int dln2_gpio_pin_get_in_val(struct dln2_gpio *dln2, unsigned int pin)
{
int ret;
ret = dln2_gpio_pin_val(dln2, DLN2_GPIO_PIN_GET_VAL, pin);
if (ret < 0)
return ret;
return !!ret;
}
static int dln2_gpio_pin_get_out_val(struct dln2_gpio *dln2, unsigned int pin)
{
int ret;
ret = dln2_gpio_pin_val(dln2, DLN2_GPIO_PIN_GET_OUT_VAL, pin);
if (ret < 0)
return ret;
return !!ret;
}
static int dln2_gpio_pin_set_out_val(struct dln2_gpio *dln2,
unsigned int pin, int value)
{
struct dln2_gpio_pin_val req = {
.pin = cpu_to_le16(pin),
.value = value,
};
return dln2_transfer_tx(dln2->pdev, DLN2_GPIO_PIN_SET_OUT_VAL, &req,
sizeof(req));
}
static int dln2_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct dln2_gpio *dln2 = gpiochip_get_data(chip);
struct dln2_gpio_pin req = {
.pin = cpu_to_le16(offset),
};
struct dln2_gpio_pin_val rsp;
int len = sizeof(rsp);
int ret;
ret = dln2_gpio_pin_cmd(dln2, DLN2_GPIO_PIN_ENABLE, offset);
if (ret < 0)
return ret;
ret = dln2_transfer(dln2->pdev, DLN2_GPIO_PIN_GET_DIRECTION,
&req, sizeof(req), &rsp, &len);
if (ret < 0)
return ret;
if (len < sizeof(rsp) || req.pin != rsp.pin) {
ret = -EPROTO;
goto out_disable;
}
switch (rsp.value) {
case DLN2_GPIO_DIRECTION_IN:
clear_bit(offset, dln2->output_enabled);
return 0;
case DLN2_GPIO_DIRECTION_OUT:
set_bit(offset, dln2->output_enabled);
return 0;
default:
ret = -EPROTO;
goto out_disable;
}
out_disable:
dln2_gpio_pin_cmd(dln2, DLN2_GPIO_PIN_DISABLE, offset);
return ret;
}
static void dln2_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct dln2_gpio *dln2 = gpiochip_get_data(chip);
dln2_gpio_pin_cmd(dln2, DLN2_GPIO_PIN_DISABLE, offset);
}
static int dln2_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
struct dln2_gpio *dln2 = gpiochip_get_data(chip);
if (test_bit(offset, dln2->output_enabled))
return GPIOF_DIR_OUT;
return GPIOF_DIR_IN;
}
static int dln2_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct dln2_gpio *dln2 = gpiochip_get_data(chip);
int dir;
dir = dln2_gpio_get_direction(chip, offset);
if (dir < 0)
return dir;
if (dir == GPIOF_DIR_IN)
return dln2_gpio_pin_get_in_val(dln2, offset);
return dln2_gpio_pin_get_out_val(dln2, offset);
}
static void dln2_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct dln2_gpio *dln2 = gpiochip_get_data(chip);
dln2_gpio_pin_set_out_val(dln2, offset, value);
}
static int dln2_gpio_set_direction(struct gpio_chip *chip, unsigned offset,
unsigned dir)
{
struct dln2_gpio *dln2 = gpiochip_get_data(chip);
struct dln2_gpio_pin_val req = {
.pin = cpu_to_le16(offset),
.value = dir,
};
int ret;
ret = dln2_transfer_tx(dln2->pdev, DLN2_GPIO_PIN_SET_DIRECTION,
&req, sizeof(req));
if (ret < 0)
return ret;
if (dir == DLN2_GPIO_DIRECTION_OUT)
set_bit(offset, dln2->output_enabled);
else
clear_bit(offset, dln2->output_enabled);
return ret;
}
static int dln2_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
return dln2_gpio_set_direction(chip, offset, DLN2_GPIO_DIRECTION_IN);
}
static int dln2_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct dln2_gpio *dln2 = gpiochip_get_data(chip);
int ret;
ret = dln2_gpio_pin_set_out_val(dln2, offset, value);
if (ret < 0)
return ret;
return dln2_gpio_set_direction(chip, offset, DLN2_GPIO_DIRECTION_OUT);
}
static int dln2_gpio_set_debounce(struct gpio_chip *chip, unsigned offset,
unsigned debounce)
{
struct dln2_gpio *dln2 = gpiochip_get_data(chip);
__le32 duration = cpu_to_le32(debounce);
return dln2_transfer_tx(dln2->pdev, DLN2_GPIO_SET_DEBOUNCE,
&duration, sizeof(duration));
}
static int dln2_gpio_set_event_cfg(struct dln2_gpio *dln2, unsigned pin,
unsigned type, unsigned period)
{
struct {
__le16 pin;
u8 type;
__le16 period;
} __packed req = {
.pin = cpu_to_le16(pin),
.type = type,
.period = cpu_to_le16(period),
};
return dln2_transfer_tx(dln2->pdev, DLN2_GPIO_PIN_SET_EVENT_CFG,
&req, sizeof(req));
}
static void dln2_irq_unmask(struct irq_data *irqd)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(irqd);
struct dln2_gpio *dln2 = gpiochip_get_data(gc);
int pin = irqd_to_hwirq(irqd);
set_bit(pin, dln2->unmasked_irqs);
}
static void dln2_irq_mask(struct irq_data *irqd)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(irqd);
struct dln2_gpio *dln2 = gpiochip_get_data(gc);
int pin = irqd_to_hwirq(irqd);
clear_bit(pin, dln2->unmasked_irqs);
}
static int dln2_irq_set_type(struct irq_data *irqd, unsigned type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(irqd);
struct dln2_gpio *dln2 = gpiochip_get_data(gc);
int pin = irqd_to_hwirq(irqd);
switch (type) {
case IRQ_TYPE_LEVEL_HIGH:
dln2->irq_type[pin] = DLN2_GPIO_EVENT_LVL_HIGH;
break;
case IRQ_TYPE_LEVEL_LOW:
dln2->irq_type[pin] = DLN2_GPIO_EVENT_LVL_LOW;
break;
case IRQ_TYPE_EDGE_BOTH:
dln2->irq_type[pin] = DLN2_GPIO_EVENT_CHANGE;
break;
case IRQ_TYPE_EDGE_RISING:
dln2->irq_type[pin] = DLN2_GPIO_EVENT_CHANGE_RISING;
break;
case IRQ_TYPE_EDGE_FALLING:
dln2->irq_type[pin] = DLN2_GPIO_EVENT_CHANGE_FALLING;
break;
default:
return -EINVAL;
}
return 0;
}
static void dln2_irq_bus_lock(struct irq_data *irqd)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(irqd);
struct dln2_gpio *dln2 = gpiochip_get_data(gc);
mutex_lock(&dln2->irq_lock);
}
static void dln2_irq_bus_unlock(struct irq_data *irqd)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(irqd);
struct dln2_gpio *dln2 = gpiochip_get_data(gc);
int pin = irqd_to_hwirq(irqd);
int enabled, unmasked;
unsigned type;
int ret;
enabled = test_bit(pin, dln2->enabled_irqs);
unmasked = test_bit(pin, dln2->unmasked_irqs);
if (enabled != unmasked) {
if (unmasked) {
type = dln2->irq_type[pin] & DLN2_GPIO_EVENT_MASK;
set_bit(pin, dln2->enabled_irqs);
} else {
type = DLN2_GPIO_EVENT_NONE;
clear_bit(pin, dln2->enabled_irqs);
}
ret = dln2_gpio_set_event_cfg(dln2, pin, type, 0);
if (ret)
dev_err(dln2->gpio.parent, "failed to set event\n");
}
mutex_unlock(&dln2->irq_lock);
}
static void dln2_gpio_event(struct platform_device *pdev, u16 echo,
const void *data, int len)
{
int pin, irq;
const struct {
__le16 count;
__u8 type;
__le16 pin;
__u8 value;
} __packed *event = data;
struct dln2_gpio *dln2 = platform_get_drvdata(pdev);
if (len < sizeof(*event)) {
dev_err(dln2->gpio.parent, "short event message\n");
return;
}
pin = le16_to_cpu(event->pin);
if (pin >= dln2->gpio.ngpio) {
dev_err(dln2->gpio.parent, "out of bounds pin %d\n", pin);
return;
}
irq = irq_find_mapping(dln2->gpio.irqdomain, pin);
if (!irq) {
dev_err(dln2->gpio.parent, "pin %d not mapped to IRQ\n", pin);
return;
}
switch (dln2->irq_type[pin]) {
case DLN2_GPIO_EVENT_CHANGE_RISING:
if (event->value)
generic_handle_irq(irq);
break;
case DLN2_GPIO_EVENT_CHANGE_FALLING:
if (!event->value)
generic_handle_irq(irq);
break;
default:
generic_handle_irq(irq);
}
}
static int dln2_gpio_probe(struct platform_device *pdev)
{
struct dln2_gpio *dln2;
struct device *dev = &pdev->dev;
int pins;
int ret;
pins = dln2_gpio_get_pin_count(pdev);
if (pins < 0) {
dev_err(dev, "failed to get pin count: %d\n", pins);
return pins;
}
if (pins > DLN2_GPIO_MAX_PINS) {
pins = DLN2_GPIO_MAX_PINS;
dev_warn(dev, "clamping pins to %d\n", DLN2_GPIO_MAX_PINS);
}
dln2 = devm_kzalloc(&pdev->dev, sizeof(*dln2), GFP_KERNEL);
if (!dln2)
return -ENOMEM;
mutex_init(&dln2->irq_lock);
dln2->pdev = pdev;
dln2->gpio.label = "dln2";
dln2->gpio.parent = dev;
dln2->gpio.owner = THIS_MODULE;
dln2->gpio.base = -1;
dln2->gpio.ngpio = pins;
dln2->gpio.can_sleep = true;
dln2->gpio.irq_not_threaded = true;
dln2->gpio.set = dln2_gpio_set;
dln2->gpio.get = dln2_gpio_get;
dln2->gpio.request = dln2_gpio_request;
dln2->gpio.free = dln2_gpio_free;
dln2->gpio.get_direction = dln2_gpio_get_direction;
dln2->gpio.direction_input = dln2_gpio_direction_input;
dln2->gpio.direction_output = dln2_gpio_direction_output;
dln2->gpio.set_debounce = dln2_gpio_set_debounce;
platform_set_drvdata(pdev, dln2);
ret = gpiochip_add_data(&dln2->gpio, dln2);
if (ret < 0) {
dev_err(dev, "failed to add gpio chip: %d\n", ret);
goto out;
}
ret = gpiochip_irqchip_add(&dln2->gpio, &dln2_gpio_irqchip, 0,
handle_simple_irq, IRQ_TYPE_NONE);
if (ret < 0) {
dev_err(dev, "failed to add irq chip: %d\n", ret);
goto out_gpiochip_remove;
}
ret = dln2_register_event_cb(pdev, DLN2_GPIO_CONDITION_MET_EV,
dln2_gpio_event);
if (ret) {
dev_err(dev, "failed to register event cb: %d\n", ret);
goto out_gpiochip_remove;
}
return 0;
out_gpiochip_remove:
gpiochip_remove(&dln2->gpio);
out:
return ret;
}
static int dln2_gpio_remove(struct platform_device *pdev)
{
struct dln2_gpio *dln2 = platform_get_drvdata(pdev);
dln2_unregister_event_cb(pdev, DLN2_GPIO_CONDITION_MET_EV);
gpiochip_remove(&dln2->gpio);
return 0;
}
