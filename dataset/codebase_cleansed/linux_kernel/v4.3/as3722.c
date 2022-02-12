static int as3722_check_device_id(struct as3722 *as3722)
{
u32 val;
int ret;
ret = as3722_read(as3722, AS3722_ASIC_ID1_REG, &val);
if (ret < 0) {
dev_err(as3722->dev, "ASIC_ID1 read failed: %d\n", ret);
return ret;
}
if (val != AS3722_DEVICE_ID) {
dev_err(as3722->dev, "Device is not AS3722, ID is 0x%x\n", val);
return -ENODEV;
}
ret = as3722_read(as3722, AS3722_ASIC_ID2_REG, &val);
if (ret < 0) {
dev_err(as3722->dev, "ASIC_ID2 read failed: %d\n", ret);
return ret;
}
dev_info(as3722->dev, "AS3722 with revision 0x%x found\n", val);
return 0;
}
static int as3722_configure_pullups(struct as3722 *as3722)
{
int ret;
u32 val = 0;
if (as3722->en_intern_int_pullup)
val |= AS3722_INT_PULL_UP;
if (as3722->en_intern_i2c_pullup)
val |= AS3722_I2C_PULL_UP;
ret = as3722_update_bits(as3722, AS3722_IOVOLTAGE_REG,
AS3722_INT_PULL_UP | AS3722_I2C_PULL_UP, val);
if (ret < 0)
dev_err(as3722->dev, "IOVOLTAGE_REG update failed: %d\n", ret);
return ret;
}
static int as3722_i2c_of_probe(struct i2c_client *i2c,
struct as3722 *as3722)
{
struct device_node *np = i2c->dev.of_node;
struct irq_data *irq_data;
if (!np) {
dev_err(&i2c->dev, "Device Tree not found\n");
return -EINVAL;
}
irq_data = irq_get_irq_data(i2c->irq);
if (!irq_data) {
dev_err(&i2c->dev, "Invalid IRQ: %d\n", i2c->irq);
return -EINVAL;
}
as3722->en_intern_int_pullup = of_property_read_bool(np,
"ams,enable-internal-int-pullup");
as3722->en_intern_i2c_pullup = of_property_read_bool(np,
"ams,enable-internal-i2c-pullup");
as3722->irq_flags = irqd_get_trigger_type(irq_data);
dev_dbg(&i2c->dev, "IRQ flags are 0x%08lx\n", as3722->irq_flags);
return 0;
}
static int as3722_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct as3722 *as3722;
unsigned long irq_flags;
int ret;
as3722 = devm_kzalloc(&i2c->dev, sizeof(struct as3722), GFP_KERNEL);
if (!as3722)
return -ENOMEM;
as3722->dev = &i2c->dev;
as3722->chip_irq = i2c->irq;
i2c_set_clientdata(i2c, as3722);
ret = as3722_i2c_of_probe(i2c, as3722);
if (ret < 0)
return ret;
as3722->regmap = devm_regmap_init_i2c(i2c, &as3722_regmap_config);
if (IS_ERR(as3722->regmap)) {
ret = PTR_ERR(as3722->regmap);
dev_err(&i2c->dev, "regmap init failed: %d\n", ret);
return ret;
}
ret = as3722_check_device_id(as3722);
if (ret < 0)
return ret;
irq_flags = as3722->irq_flags | IRQF_ONESHOT;
ret = regmap_add_irq_chip(as3722->regmap, as3722->chip_irq,
irq_flags, -1, &as3722_irq_chip,
&as3722->irq_data);
if (ret < 0) {
dev_err(as3722->dev, "Failed to add regmap irq: %d\n", ret);
return ret;
}
ret = as3722_configure_pullups(as3722);
if (ret < 0)
goto scrub;
ret = mfd_add_devices(&i2c->dev, -1, as3722_devs,
ARRAY_SIZE(as3722_devs), NULL, 0,
regmap_irq_get_domain(as3722->irq_data));
if (ret) {
dev_err(as3722->dev, "Failed to add MFD devices: %d\n", ret);
goto scrub;
}
dev_dbg(as3722->dev, "AS3722 core driver initialized successfully\n");
return 0;
scrub:
regmap_del_irq_chip(as3722->chip_irq, as3722->irq_data);
return ret;
}
static int as3722_i2c_remove(struct i2c_client *i2c)
{
struct as3722 *as3722 = i2c_get_clientdata(i2c);
mfd_remove_devices(as3722->dev);
regmap_del_irq_chip(as3722->chip_irq, as3722->irq_data);
return 0;
}
