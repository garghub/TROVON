static void i2c_versatile_setsda(void *data, int state)
{
struct i2c_versatile *i2c = data;
writel(SDA, i2c->base + (state ? I2C_CONTROLS : I2C_CONTROLC));
}
static void i2c_versatile_setscl(void *data, int state)
{
struct i2c_versatile *i2c = data;
writel(SCL, i2c->base + (state ? I2C_CONTROLS : I2C_CONTROLC));
}
static int i2c_versatile_getsda(void *data)
{
struct i2c_versatile *i2c = data;
return !!(readl(i2c->base + I2C_CONTROL) & SDA);
}
static int i2c_versatile_getscl(void *data)
{
struct i2c_versatile *i2c = data;
return !!(readl(i2c->base + I2C_CONTROL) & SCL);
}
static int i2c_versatile_probe(struct platform_device *dev)
{
struct i2c_versatile *i2c;
struct resource *r;
int ret;
r = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!r) {
ret = -EINVAL;
goto err_out;
}
if (!request_mem_region(r->start, resource_size(r), "versatile-i2c")) {
ret = -EBUSY;
goto err_out;
}
i2c = kzalloc(sizeof(struct i2c_versatile), GFP_KERNEL);
if (!i2c) {
ret = -ENOMEM;
goto err_release;
}
i2c->base = ioremap(r->start, resource_size(r));
if (!i2c->base) {
ret = -ENOMEM;
goto err_free;
}
writel(SCL | SDA, i2c->base + I2C_CONTROLS);
i2c->adap.owner = THIS_MODULE;
strlcpy(i2c->adap.name, "Versatile I2C adapter", sizeof(i2c->adap.name));
i2c->adap.algo_data = &i2c->algo;
i2c->adap.dev.parent = &dev->dev;
i2c->adap.dev.of_node = dev->dev.of_node;
i2c->algo = i2c_versatile_algo;
i2c->algo.data = i2c;
i2c->adap.nr = dev->id;
ret = i2c_bit_add_numbered_bus(&i2c->adap);
if (ret >= 0) {
platform_set_drvdata(dev, i2c);
of_i2c_register_devices(&i2c->adap);
return 0;
}
iounmap(i2c->base);
err_free:
kfree(i2c);
err_release:
release_mem_region(r->start, resource_size(r));
err_out:
return ret;
}
static int i2c_versatile_remove(struct platform_device *dev)
{
struct i2c_versatile *i2c = platform_get_drvdata(dev);
platform_set_drvdata(dev, NULL);
i2c_del_adapter(&i2c->adap);
return 0;
}
static int __init i2c_versatile_init(void)
{
return platform_driver_register(&i2c_versatile_driver);
}
static void __exit i2c_versatile_exit(void)
{
platform_driver_unregister(&i2c_versatile_driver);
}
