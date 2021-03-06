static void w1_gpio_write_bit_dir(void *data, u8 bit)
{
struct w1_gpio_platform_data *pdata = data;
if (bit)
gpio_direction_input(pdata->pin);
else
gpio_direction_output(pdata->pin, 0);
}
static void w1_gpio_write_bit_val(void *data, u8 bit)
{
struct w1_gpio_platform_data *pdata = data;
gpio_set_value(pdata->pin, bit);
}
static u8 w1_gpio_read_bit(void *data)
{
struct w1_gpio_platform_data *pdata = data;
return gpio_get_value(pdata->pin) ? 1 : 0;
}
static int w1_gpio_probe_dt(struct platform_device *pdev)
{
struct w1_gpio_platform_data *pdata = pdev->dev.platform_data;
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(w1_gpio_dt_ids, &pdev->dev);
if (!of_id)
return 0;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
if (of_get_property(np, "linux,open-drain", NULL))
pdata->is_open_drain = 1;
pdata->pin = of_get_gpio(np, 0);
pdata->ext_pullup_enable_pin = of_get_gpio(np, 1);
pdev->dev.platform_data = pdata;
return 0;
}
static int w1_gpio_probe_dt(struct platform_device *pdev)
{
return 0;
}
static int __init w1_gpio_probe(struct platform_device *pdev)
{
struct w1_bus_master *master;
struct w1_gpio_platform_data *pdata;
int err;
err = w1_gpio_probe_dt(pdev);
if (err < 0)
return err;
pdata = pdev->dev.platform_data;
if (!pdata)
return -ENXIO;
master = kzalloc(sizeof(struct w1_bus_master), GFP_KERNEL);
if (!master)
return -ENOMEM;
err = gpio_request(pdata->pin, "w1");
if (err)
goto free_master;
if (gpio_is_valid(pdata->ext_pullup_enable_pin)) {
err = gpio_request_one(pdata->ext_pullup_enable_pin,
GPIOF_INIT_LOW, "w1 pullup");
if (err < 0)
goto free_gpio;
}
master->data = pdata;
master->read_bit = w1_gpio_read_bit;
if (pdata->is_open_drain) {
gpio_direction_output(pdata->pin, 1);
master->write_bit = w1_gpio_write_bit_val;
} else {
gpio_direction_input(pdata->pin);
master->write_bit = w1_gpio_write_bit_dir;
}
err = w1_add_master_device(master);
if (err)
goto free_gpio_ext_pu;
if (pdata->enable_external_pullup)
pdata->enable_external_pullup(1);
if (gpio_is_valid(pdata->ext_pullup_enable_pin))
gpio_set_value(pdata->ext_pullup_enable_pin, 1);
platform_set_drvdata(pdev, master);
return 0;
free_gpio_ext_pu:
if (gpio_is_valid(pdata->ext_pullup_enable_pin))
gpio_free(pdata->ext_pullup_enable_pin);
free_gpio:
gpio_free(pdata->pin);
free_master:
kfree(master);
return err;
}
static int __exit w1_gpio_remove(struct platform_device *pdev)
{
struct w1_bus_master *master = platform_get_drvdata(pdev);
struct w1_gpio_platform_data *pdata = pdev->dev.platform_data;
if (pdata->enable_external_pullup)
pdata->enable_external_pullup(0);
if (gpio_is_valid(pdata->ext_pullup_enable_pin))
gpio_set_value(pdata->ext_pullup_enable_pin, 0);
w1_remove_master_device(master);
gpio_free(pdata->pin);
kfree(master);
return 0;
}
static int w1_gpio_suspend(struct platform_device *pdev, pm_message_t state)
{
struct w1_gpio_platform_data *pdata = pdev->dev.platform_data;
if (pdata->enable_external_pullup)
pdata->enable_external_pullup(0);
return 0;
}
static int w1_gpio_resume(struct platform_device *pdev)
{
struct w1_gpio_platform_data *pdata = pdev->dev.platform_data;
if (pdata->enable_external_pullup)
pdata->enable_external_pullup(1);
return 0;
}
static int __init w1_gpio_init(void)
{
return platform_driver_probe(&w1_gpio_driver, w1_gpio_probe);
}
static void __exit w1_gpio_exit(void)
{
platform_driver_unregister(&w1_gpio_driver);
}
