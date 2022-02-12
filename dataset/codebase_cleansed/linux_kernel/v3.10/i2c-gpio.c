static void i2c_gpio_setsda_dir(void *data, int state)
{
struct i2c_gpio_platform_data *pdata = data;
if (state)
gpio_direction_input(pdata->sda_pin);
else
gpio_direction_output(pdata->sda_pin, 0);
}
static void i2c_gpio_setsda_val(void *data, int state)
{
struct i2c_gpio_platform_data *pdata = data;
gpio_set_value(pdata->sda_pin, state);
}
static void i2c_gpio_setscl_dir(void *data, int state)
{
struct i2c_gpio_platform_data *pdata = data;
if (state)
gpio_direction_input(pdata->scl_pin);
else
gpio_direction_output(pdata->scl_pin, 0);
}
static void i2c_gpio_setscl_val(void *data, int state)
{
struct i2c_gpio_platform_data *pdata = data;
gpio_set_value(pdata->scl_pin, state);
}
static int i2c_gpio_getsda(void *data)
{
struct i2c_gpio_platform_data *pdata = data;
return gpio_get_value(pdata->sda_pin);
}
static int i2c_gpio_getscl(void *data)
{
struct i2c_gpio_platform_data *pdata = data;
return gpio_get_value(pdata->scl_pin);
}
static int of_i2c_gpio_get_pins(struct device_node *np,
unsigned int *sda_pin, unsigned int *scl_pin)
{
if (of_gpio_count(np) < 2)
return -ENODEV;
*sda_pin = of_get_gpio(np, 0);
*scl_pin = of_get_gpio(np, 1);
if (!gpio_is_valid(*sda_pin) || !gpio_is_valid(*scl_pin)) {
pr_err("%s: invalid GPIO pins, sda=%d/scl=%d\n",
np->full_name, *sda_pin, *scl_pin);
return -ENODEV;
}
return 0;
}
static void of_i2c_gpio_get_props(struct device_node *np,
struct i2c_gpio_platform_data *pdata)
{
u32 reg;
of_property_read_u32(np, "i2c-gpio,delay-us", &pdata->udelay);
if (!of_property_read_u32(np, "i2c-gpio,timeout-ms", &reg))
pdata->timeout = msecs_to_jiffies(reg);
pdata->sda_is_open_drain =
of_property_read_bool(np, "i2c-gpio,sda-open-drain");
pdata->scl_is_open_drain =
of_property_read_bool(np, "i2c-gpio,scl-open-drain");
pdata->scl_is_output_only =
of_property_read_bool(np, "i2c-gpio,scl-output-only");
}
static int i2c_gpio_probe(struct platform_device *pdev)
{
struct i2c_gpio_private_data *priv;
struct i2c_gpio_platform_data *pdata;
struct i2c_algo_bit_data *bit_data;
struct i2c_adapter *adap;
unsigned int sda_pin, scl_pin;
int ret;
if (pdev->dev.of_node) {
ret = of_i2c_gpio_get_pins(pdev->dev.of_node,
&sda_pin, &scl_pin);
if (ret)
return ret;
} else {
if (!pdev->dev.platform_data)
return -ENXIO;
pdata = pdev->dev.platform_data;
sda_pin = pdata->sda_pin;
scl_pin = pdata->scl_pin;
}
ret = gpio_request(sda_pin, "sda");
if (ret) {
if (ret == -EINVAL)
ret = -EPROBE_DEFER;
goto err_request_sda;
}
ret = gpio_request(scl_pin, "scl");
if (ret) {
if (ret == -EINVAL)
ret = -EPROBE_DEFER;
goto err_request_scl;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto err_add_bus;
}
adap = &priv->adap;
bit_data = &priv->bit_data;
pdata = &priv->pdata;
if (pdev->dev.of_node) {
pdata->sda_pin = sda_pin;
pdata->scl_pin = scl_pin;
of_i2c_gpio_get_props(pdev->dev.of_node, pdata);
} else {
memcpy(pdata, pdev->dev.platform_data, sizeof(*pdata));
}
if (pdata->sda_is_open_drain) {
gpio_direction_output(pdata->sda_pin, 1);
bit_data->setsda = i2c_gpio_setsda_val;
} else {
gpio_direction_input(pdata->sda_pin);
bit_data->setsda = i2c_gpio_setsda_dir;
}
if (pdata->scl_is_open_drain || pdata->scl_is_output_only) {
gpio_direction_output(pdata->scl_pin, 1);
bit_data->setscl = i2c_gpio_setscl_val;
} else {
gpio_direction_input(pdata->scl_pin);
bit_data->setscl = i2c_gpio_setscl_dir;
}
if (!pdata->scl_is_output_only)
bit_data->getscl = i2c_gpio_getscl;
bit_data->getsda = i2c_gpio_getsda;
if (pdata->udelay)
bit_data->udelay = pdata->udelay;
else if (pdata->scl_is_output_only)
bit_data->udelay = 50;
else
bit_data->udelay = 5;
if (pdata->timeout)
bit_data->timeout = pdata->timeout;
else
bit_data->timeout = HZ / 10;
bit_data->data = pdata;
adap->owner = THIS_MODULE;
if (pdev->dev.of_node)
strlcpy(adap->name, dev_name(&pdev->dev), sizeof(adap->name));
else
snprintf(adap->name, sizeof(adap->name), "i2c-gpio%d", pdev->id);
adap->algo_data = bit_data;
adap->class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
adap->nr = pdev->id;
ret = i2c_bit_add_numbered_bus(adap);
if (ret)
goto err_add_bus;
of_i2c_register_devices(adap);
platform_set_drvdata(pdev, priv);
dev_info(&pdev->dev, "using pins %u (SDA) and %u (SCL%s)\n",
pdata->sda_pin, pdata->scl_pin,
pdata->scl_is_output_only
? ", no clock stretching" : "");
return 0;
err_add_bus:
gpio_free(scl_pin);
err_request_scl:
gpio_free(sda_pin);
err_request_sda:
return ret;
}
static int i2c_gpio_remove(struct platform_device *pdev)
{
struct i2c_gpio_private_data *priv;
struct i2c_gpio_platform_data *pdata;
struct i2c_adapter *adap;
priv = platform_get_drvdata(pdev);
adap = &priv->adap;
pdata = &priv->pdata;
i2c_del_adapter(adap);
gpio_free(pdata->scl_pin);
gpio_free(pdata->sda_pin);
return 0;
}
static int __init i2c_gpio_init(void)
{
int ret;
ret = platform_driver_register(&i2c_gpio_driver);
if (ret)
printk(KERN_ERR "i2c-gpio: probe failed: %d\n", ret);
return ret;
}
static void __exit i2c_gpio_exit(void)
{
platform_driver_unregister(&i2c_gpio_driver);
}
