static int i2c_arbitrator_select(struct i2c_mux_core *muxc, u32 chan)
{
const struct i2c_arbitrator_data *arb = i2c_mux_priv(muxc);
unsigned long stop_retry, stop_time;
stop_time = jiffies + usecs_to_jiffies(arb->wait_free_us) + 1;
do {
gpio_set_value(arb->our_gpio, !arb->our_gpio_release);
udelay(arb->slew_delay_us);
stop_retry = jiffies + usecs_to_jiffies(arb->wait_retry_us) + 1;
while (time_before(jiffies, stop_retry)) {
int gpio_val = !!gpio_get_value(arb->their_gpio);
if (gpio_val == arb->their_gpio_release) {
return 0;
}
usleep_range(50, 200);
}
gpio_set_value(arb->our_gpio, arb->our_gpio_release);
usleep_range(arb->wait_retry_us, arb->wait_retry_us * 2);
} while (time_before(jiffies, stop_time));
gpio_set_value(arb->our_gpio, arb->our_gpio_release);
udelay(arb->slew_delay_us);
dev_err(muxc->dev, "Could not claim bus, timeout\n");
return -EBUSY;
}
static int i2c_arbitrator_deselect(struct i2c_mux_core *muxc, u32 chan)
{
const struct i2c_arbitrator_data *arb = i2c_mux_priv(muxc);
gpio_set_value(arb->our_gpio, arb->our_gpio_release);
udelay(arb->slew_delay_us);
return 0;
}
static int i2c_arbitrator_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device_node *parent_np;
struct i2c_mux_core *muxc;
struct i2c_arbitrator_data *arb;
enum of_gpio_flags gpio_flags;
unsigned long out_init;
int ret;
if (!np) {
dev_err(dev, "Cannot find device tree node\n");
return -ENODEV;
}
if (dev_get_platdata(dev)) {
dev_err(dev, "Platform data is not supported\n");
return -EINVAL;
}
muxc = i2c_mux_alloc(NULL, dev, 1, sizeof(*arb), I2C_MUX_ARBITRATOR,
i2c_arbitrator_select, i2c_arbitrator_deselect);
if (!muxc)
return -ENOMEM;
arb = i2c_mux_priv(muxc);
platform_set_drvdata(pdev, muxc);
ret = of_get_named_gpio_flags(np, "our-claim-gpio", 0, &gpio_flags);
if (!gpio_is_valid(ret)) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "Error getting our-claim-gpio\n");
return ret;
}
arb->our_gpio = ret;
arb->our_gpio_release = !!(gpio_flags & OF_GPIO_ACTIVE_LOW);
out_init = (gpio_flags & OF_GPIO_ACTIVE_LOW) ?
GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
ret = devm_gpio_request_one(dev, arb->our_gpio, out_init,
"our-claim-gpio");
if (ret) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "Error requesting our-claim-gpio\n");
return ret;
}
ret = of_get_named_gpio_flags(np, "their-claim-gpios", 0, &gpio_flags);
if (!gpio_is_valid(ret)) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "Error getting their-claim-gpio\n");
return ret;
}
arb->their_gpio = ret;
arb->their_gpio_release = !!(gpio_flags & OF_GPIO_ACTIVE_LOW);
ret = devm_gpio_request_one(dev, arb->their_gpio, GPIOF_IN,
"their-claim-gpio");
if (ret) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "Error requesting their-claim-gpio\n");
return ret;
}
if (gpio_is_valid(of_get_named_gpio(np, "their-claim-gpios", 1))) {
dev_err(dev, "Only one other master is supported\n");
return -EINVAL;
}
if (of_property_read_u32(np, "slew-delay-us", &arb->slew_delay_us))
arb->slew_delay_us = 10;
if (of_property_read_u32(np, "wait-retry-us", &arb->wait_retry_us))
arb->wait_retry_us = 3000;
if (of_property_read_u32(np, "wait-free-us", &arb->wait_free_us))
arb->wait_free_us = 50000;
parent_np = of_parse_phandle(np, "i2c-parent", 0);
if (!parent_np) {
dev_err(dev, "Cannot parse i2c-parent\n");
return -EINVAL;
}
muxc->parent = of_get_i2c_adapter_by_node(parent_np);
of_node_put(parent_np);
if (!muxc->parent) {
dev_err(dev, "Cannot find parent bus\n");
return -EPROBE_DEFER;
}
ret = i2c_mux_add_adapter(muxc, 0, 0, 0);
if (ret)
i2c_put_adapter(muxc->parent);
return ret;
}
static int i2c_arbitrator_remove(struct platform_device *pdev)
{
struct i2c_mux_core *muxc = platform_get_drvdata(pdev);
i2c_mux_del_adapters(muxc);
i2c_put_adapter(muxc->parent);
return 0;
}
