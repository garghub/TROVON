static inline int ixp2000_scl_pin(void *data)
{
return ((struct ixp2000_i2c_pins*)data)->scl_pin;
}
static inline int ixp2000_sda_pin(void *data)
{
return ((struct ixp2000_i2c_pins*)data)->sda_pin;
}
static void ixp2000_bit_setscl(void *data, int val)
{
int i = 5000;
if (val) {
gpio_line_config(ixp2000_scl_pin(data), GPIO_IN);
while(!gpio_line_get(ixp2000_scl_pin(data)) && i--);
} else {
gpio_line_config(ixp2000_scl_pin(data), GPIO_OUT);
}
}
static void ixp2000_bit_setsda(void *data, int val)
{
if (val) {
gpio_line_config(ixp2000_sda_pin(data), GPIO_IN);
} else {
gpio_line_config(ixp2000_sda_pin(data), GPIO_OUT);
}
}
static int ixp2000_bit_getscl(void *data)
{
return gpio_line_get(ixp2000_scl_pin(data));
}
static int ixp2000_bit_getsda(void *data)
{
return gpio_line_get(ixp2000_sda_pin(data));
}
static int ixp2000_i2c_remove(struct platform_device *plat_dev)
{
struct ixp2000_i2c_data *drv_data = platform_get_drvdata(plat_dev);
platform_set_drvdata(plat_dev, NULL);
i2c_del_adapter(&drv_data->adapter);
kfree(drv_data);
return 0;
}
static int ixp2000_i2c_probe(struct platform_device *plat_dev)
{
int err;
struct ixp2000_i2c_pins *gpio = plat_dev->dev.platform_data;
struct ixp2000_i2c_data *drv_data =
kzalloc(sizeof(struct ixp2000_i2c_data), GFP_KERNEL);
if (!drv_data)
return -ENOMEM;
drv_data->gpio_pins = gpio;
drv_data->algo_data.data = gpio;
drv_data->algo_data.setsda = ixp2000_bit_setsda;
drv_data->algo_data.setscl = ixp2000_bit_setscl;
drv_data->algo_data.getsda = ixp2000_bit_getsda;
drv_data->algo_data.getscl = ixp2000_bit_getscl;
drv_data->algo_data.udelay = 6;
drv_data->algo_data.timeout = HZ;
strlcpy(drv_data->adapter.name, plat_dev->dev.driver->name,
sizeof(drv_data->adapter.name));
drv_data->adapter.algo_data = &drv_data->algo_data,
drv_data->adapter.dev.parent = &plat_dev->dev;
gpio_line_config(gpio->sda_pin, GPIO_IN);
gpio_line_config(gpio->scl_pin, GPIO_IN);
gpio_line_set(gpio->scl_pin, 0);
gpio_line_set(gpio->sda_pin, 0);
if ((err = i2c_bit_add_bus(&drv_data->adapter)) != 0) {
dev_err(&plat_dev->dev, "Could not install, error %d\n", err);
kfree(drv_data);
return err;
}
platform_set_drvdata(plat_dev, drv_data);
return 0;
}
static int __init ixp2000_i2c_init(void)
{
return platform_driver_register(&ixp2000_i2c_driver);
}
static void __exit ixp2000_i2c_exit(void)
{
platform_driver_unregister(&ixp2000_i2c_driver);
}
