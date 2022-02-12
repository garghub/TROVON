static int gpio_ir_tx_set_duty_cycle(struct rc_dev *dev, u32 duty_cycle)
{
struct gpio_ir *gpio_ir = dev->priv;
gpio_ir->duty_cycle = duty_cycle;
return 0;
}
static int gpio_ir_tx_set_carrier(struct rc_dev *dev, u32 carrier)
{
struct gpio_ir *gpio_ir = dev->priv;
if (!carrier)
return -EINVAL;
gpio_ir->carrier = carrier;
return 0;
}
static int gpio_ir_tx(struct rc_dev *dev, unsigned int *txbuf,
unsigned int count)
{
struct gpio_ir *gpio_ir = dev->priv;
unsigned long flags;
ktime_t edge;
s32 delta;
int i;
unsigned int pulse, space;
pulse = DIV_ROUND_CLOSEST(gpio_ir->duty_cycle * (NSEC_PER_SEC / 100),
gpio_ir->carrier);
space = DIV_ROUND_CLOSEST((100 - gpio_ir->duty_cycle) *
(NSEC_PER_SEC / 100), gpio_ir->carrier);
spin_lock_irqsave(&gpio_ir->lock, flags);
edge = ktime_get();
for (i = 0; i < count; i++) {
if (i % 2) {
edge = ktime_add_us(edge, txbuf[i]);
delta = ktime_us_delta(edge, ktime_get());
if (delta > 10) {
spin_unlock_irqrestore(&gpio_ir->lock, flags);
usleep_range(delta, delta + 10);
spin_lock_irqsave(&gpio_ir->lock, flags);
} else if (delta > 0) {
udelay(delta);
}
} else {
ktime_t last = ktime_add_us(edge, txbuf[i]);
while (ktime_before(ktime_get(), last)) {
gpiod_set_value(gpio_ir->gpio, 1);
edge = ktime_add_ns(edge, pulse);
delta = ktime_to_ns(ktime_sub(edge,
ktime_get()));
if (delta > 0)
ndelay(delta);
gpiod_set_value(gpio_ir->gpio, 0);
edge = ktime_add_ns(edge, space);
delta = ktime_to_ns(ktime_sub(edge,
ktime_get()));
if (delta > 0)
ndelay(delta);
}
edge = last;
}
}
spin_unlock_irqrestore(&gpio_ir->lock, flags);
return count;
}
static int gpio_ir_tx_probe(struct platform_device *pdev)
{
struct gpio_ir *gpio_ir;
struct rc_dev *rcdev;
int rc;
gpio_ir = devm_kmalloc(&pdev->dev, sizeof(*gpio_ir), GFP_KERNEL);
if (!gpio_ir)
return -ENOMEM;
rcdev = devm_rc_allocate_device(&pdev->dev, RC_DRIVER_IR_RAW_TX);
if (!rcdev)
return -ENOMEM;
gpio_ir->gpio = devm_gpiod_get(&pdev->dev, NULL, GPIOD_OUT_LOW);
if (IS_ERR(gpio_ir->gpio)) {
if (PTR_ERR(gpio_ir->gpio) != -EPROBE_DEFER)
dev_err(&pdev->dev, "Failed to get gpio (%ld)\n",
PTR_ERR(gpio_ir->gpio));
return PTR_ERR(gpio_ir->gpio);
}
rcdev->priv = gpio_ir;
rcdev->driver_name = DRIVER_NAME;
rcdev->device_name = DEVICE_NAME;
rcdev->tx_ir = gpio_ir_tx;
rcdev->s_tx_duty_cycle = gpio_ir_tx_set_duty_cycle;
rcdev->s_tx_carrier = gpio_ir_tx_set_carrier;
gpio_ir->carrier = 38000;
gpio_ir->duty_cycle = 50;
spin_lock_init(&gpio_ir->lock);
rc = devm_rc_register_device(&pdev->dev, rcdev);
if (rc < 0)
dev_err(&pdev->dev, "failed to register rc device\n");
return rc;
}
