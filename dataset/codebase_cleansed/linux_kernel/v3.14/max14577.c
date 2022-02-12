static bool max14577_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX14577_REG_INT1 ... MAX14577_REG_STATUS3:
return true;
default:
break;
}
return false;
}
static int max14577_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max14577 *max14577;
struct max14577_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct device_node *np = i2c->dev.of_node;
u8 reg_data;
int ret = 0;
if (np) {
pdata = devm_kzalloc(&i2c->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
i2c->dev.platform_data = pdata;
}
if (!pdata) {
dev_err(&i2c->dev, "No platform data found.\n");
return -EINVAL;
}
max14577 = devm_kzalloc(&i2c->dev, sizeof(*max14577), GFP_KERNEL);
if (!max14577)
return -ENOMEM;
i2c_set_clientdata(i2c, max14577);
max14577->dev = &i2c->dev;
max14577->i2c = i2c;
max14577->irq = i2c->irq;
max14577->regmap = devm_regmap_init_i2c(i2c, &max14577_regmap_config);
if (IS_ERR(max14577->regmap)) {
ret = PTR_ERR(max14577->regmap);
dev_err(max14577->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = max14577_read_reg(max14577->regmap, MAX14577_REG_DEVICEID,
&reg_data);
if (ret) {
dev_err(max14577->dev, "Device not found on this channel: %d\n",
ret);
return ret;
}
max14577->vendor_id = ((reg_data & DEVID_VENDORID_MASK) >>
DEVID_VENDORID_SHIFT);
max14577->device_id = ((reg_data & DEVID_DEVICEID_MASK) >>
DEVID_DEVICEID_SHIFT);
dev_info(max14577->dev, "Device ID: 0x%x, vendor: 0x%x\n",
max14577->device_id, max14577->vendor_id);
ret = regmap_add_irq_chip(max14577->regmap, max14577->irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT, 0,
&max14577_irq_chip,
&max14577->irq_data);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request IRQ %d: %d\n",
max14577->irq, ret);
return ret;
}
ret = mfd_add_devices(max14577->dev, -1, max14577_devs,
ARRAY_SIZE(max14577_devs), NULL, 0,
regmap_irq_get_domain(max14577->irq_data));
if (ret < 0)
goto err_mfd;
device_init_wakeup(max14577->dev, 1);
return 0;
err_mfd:
regmap_del_irq_chip(max14577->irq, max14577->irq_data);
return ret;
}
static int max14577_i2c_remove(struct i2c_client *i2c)
{
struct max14577 *max14577 = i2c_get_clientdata(i2c);
mfd_remove_devices(max14577->dev);
regmap_del_irq_chip(max14577->irq, max14577->irq_data);
return 0;
}
static int max14577_suspend(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct max14577 *max14577 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev)) {
enable_irq_wake(max14577->irq);
disable_irq(max14577->irq);
}
return 0;
}
static int max14577_resume(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct max14577 *max14577 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev)) {
disable_irq_wake(max14577->irq);
enable_irq(max14577->irq);
}
return 0;
}
static int __init max14577_i2c_init(void)
{
return i2c_add_driver(&max14577_i2c_driver);
}
static void __exit max14577_i2c_exit(void)
{
i2c_del_driver(&max14577_i2c_driver);
}
