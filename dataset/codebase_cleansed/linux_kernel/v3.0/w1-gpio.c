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
static int __init w1_gpio_probe(struct platform_device *pdev)
{
struct w1_bus_master *master;
struct w1_gpio_platform_data *pdata = pdev->dev.platform_data;
int err;
if (!pdata)
return -ENXIO;
master = kzalloc(sizeof(struct w1_bus_master), GFP_KERNEL);
if (!master)
return -ENOMEM;
err = gpio_request(pdata->pin, "w1");
if (err)
goto free_master;
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
goto free_gpio;
if (pdata->enable_external_pullup)
pdata->enable_external_pullup(1);
platform_set_drvdata(pdev, master);
return 0;
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
