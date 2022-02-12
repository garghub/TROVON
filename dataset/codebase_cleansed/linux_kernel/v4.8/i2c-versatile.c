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
i2c = devm_kzalloc(&dev->dev, sizeof(struct i2c_versatile), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
r = platform_get_resource(dev, IORESOURCE_MEM, 0);
i2c->base = devm_ioremap_resource(&dev->dev, r);
if (IS_ERR(i2c->base))
return PTR_ERR(i2c->base);
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
if (ret < 0)
return ret;
platform_set_drvdata(dev, i2c);
return 0;
}
static int i2c_versatile_remove(struct platform_device *dev)
{
struct i2c_versatile *i2c = platform_get_drvdata(dev);
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
