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
static int __devinit i2c_gpio_probe(struct platform_device *pdev)
{
struct i2c_gpio_platform_data *pdata;
struct i2c_algo_bit_data *bit_data;
struct i2c_adapter *adap;
int ret;
pdata = pdev->dev.platform_data;
if (!pdata)
return -ENXIO;
ret = -ENOMEM;
adap = kzalloc(sizeof(struct i2c_adapter), GFP_KERNEL);
if (!adap)
goto err_alloc_adap;
bit_data = kzalloc(sizeof(struct i2c_algo_bit_data), GFP_KERNEL);
if (!bit_data)
goto err_alloc_bit_data;
ret = gpio_request(pdata->sda_pin, "sda");
if (ret)
goto err_request_sda;
ret = gpio_request(pdata->scl_pin, "scl");
if (ret)
goto err_request_scl;
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
snprintf(adap->name, sizeof(adap->name), "i2c-gpio%d", pdev->id);
adap->algo_data = bit_data;
adap->class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
adap->dev.parent = &pdev->dev;
adap->nr = (pdev->id != -1) ? pdev->id : 0;
ret = i2c_bit_add_numbered_bus(adap);
if (ret)
goto err_add_bus;
platform_set_drvdata(pdev, adap);
dev_info(&pdev->dev, "using pins %u (SDA) and %u (SCL%s)\n",
pdata->sda_pin, pdata->scl_pin,
pdata->scl_is_output_only
? ", no clock stretching" : "");
return 0;
err_add_bus:
gpio_free(pdata->scl_pin);
err_request_scl:
gpio_free(pdata->sda_pin);
err_request_sda:
kfree(bit_data);
err_alloc_bit_data:
kfree(adap);
err_alloc_adap:
return ret;
}
static int __devexit i2c_gpio_remove(struct platform_device *pdev)
{
struct i2c_gpio_platform_data *pdata;
struct i2c_adapter *adap;
adap = platform_get_drvdata(pdev);
pdata = pdev->dev.platform_data;
i2c_del_adapter(adap);
gpio_free(pdata->scl_pin);
gpio_free(pdata->sda_pin);
kfree(adap->algo_data);
kfree(adap);
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
