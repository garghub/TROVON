static bool max14577_muic_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case MAX14577_REG_INT1 ... MAX14577_REG_STATUS3:
return true;
default:
break;
}
return false;
}
static bool max77836_muic_volatile_reg(struct device *dev, unsigned int reg)
{
if (max14577_muic_volatile_reg(dev, reg))
return true;
switch (reg) {
case MAX77836_FG_REG_VCELL_MSB ... MAX77836_FG_REG_SOC_LSB:
case MAX77836_FG_REG_CRATE_MSB ... MAX77836_FG_REG_CRATE_LSB:
case MAX77836_FG_REG_STATUS_H ... MAX77836_FG_REG_STATUS_L:
case MAX77836_PMIC_REG_INTSRC:
case MAX77836_PMIC_REG_TOPSYS_INT:
case MAX77836_PMIC_REG_TOPSYS_STAT:
return true;
default:
break;
}
return false;
}
static void max14577_print_dev_type(struct max14577 *max14577)
{
u8 reg_data, vendor_id, device_id;
int ret;
ret = max14577_read_reg(max14577->regmap, MAX14577_REG_DEVICEID,
&reg_data);
if (ret) {
dev_err(max14577->dev,
"Failed to read DEVICEID register: %d\n", ret);
return;
}
vendor_id = ((reg_data & DEVID_VENDORID_MASK) >>
DEVID_VENDORID_SHIFT);
device_id = ((reg_data & DEVID_DEVICEID_MASK) >>
DEVID_DEVICEID_SHIFT);
dev_info(max14577->dev, "Device type: %u (ID: 0x%x, vendor: 0x%x)\n",
max14577->dev_type, device_id, vendor_id);
}
static int max77836_init(struct max14577 *max14577)
{
int ret;
u8 intsrc_mask;
max14577->i2c_pmic = i2c_new_dummy(max14577->i2c->adapter,
I2C_ADDR_PMIC);
if (!max14577->i2c_pmic) {
dev_err(max14577->dev, "Failed to register PMIC I2C device\n");
return -ENODEV;
}
i2c_set_clientdata(max14577->i2c_pmic, max14577);
max14577->regmap_pmic = devm_regmap_init_i2c(max14577->i2c_pmic,
&max77836_pmic_regmap_config);
if (IS_ERR(max14577->regmap_pmic)) {
ret = PTR_ERR(max14577->regmap_pmic);
dev_err(max14577->dev, "Failed to allocate PMIC register map: %d\n",
ret);
goto err;
}
ret = max14577_read_reg(max14577->regmap_pmic,
MAX77836_PMIC_REG_INTSRC_MASK, &intsrc_mask);
if (ret < 0) {
dev_err(max14577->dev, "Failed to read PMIC register\n");
goto err;
}
intsrc_mask &= ~(MAX77836_INTSRC_MASK_TOP_INT_MASK);
intsrc_mask &= ~(MAX77836_INTSRC_MASK_MUIC_CHG_INT_MASK);
ret = max14577_write_reg(max14577->regmap_pmic,
MAX77836_PMIC_REG_INTSRC_MASK, intsrc_mask);
if (ret < 0) {
dev_err(max14577->dev, "Failed to write PMIC register\n");
goto err;
}
ret = regmap_add_irq_chip(max14577->regmap_pmic, max14577->irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT | IRQF_SHARED,
0, &max77836_pmic_irq_chip,
&max14577->irq_data_pmic);
if (ret != 0) {
dev_err(max14577->dev, "Failed to request PMIC IRQ %d: %d\n",
max14577->irq, ret);
goto err;
}
return 0;
err:
i2c_unregister_device(max14577->i2c_pmic);
return ret;
}
static void max77836_remove(struct max14577 *max14577)
{
regmap_del_irq_chip(max14577->irq, max14577->irq_data_pmic);
i2c_unregister_device(max14577->i2c_pmic);
}
static int max14577_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max14577 *max14577;
struct max14577_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct device_node *np = i2c->dev.of_node;
int ret = 0;
const struct regmap_irq_chip *irq_chip;
const struct mfd_cell *mfd_devs;
unsigned int mfd_devs_size;
int irq_flags;
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
max14577->regmap = devm_regmap_init_i2c(i2c,
&max14577_muic_regmap_config);
if (IS_ERR(max14577->regmap)) {
ret = PTR_ERR(max14577->regmap);
dev_err(max14577->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
if (np) {
const struct of_device_id *of_id;
of_id = of_match_device(max14577_dt_match, &i2c->dev);
if (of_id)
max14577->dev_type =
(enum maxim_device_type)of_id->data;
} else {
max14577->dev_type = id->driver_data;
}
max14577_print_dev_type(max14577);
switch (max14577->dev_type) {
case MAXIM_DEVICE_TYPE_MAX77836:
irq_chip = &max77836_muic_irq_chip;
mfd_devs = max77836_devs;
mfd_devs_size = ARRAY_SIZE(max77836_devs);
irq_flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT | IRQF_SHARED;
break;
case MAXIM_DEVICE_TYPE_MAX14577:
default:
irq_chip = &max14577_irq_chip;
mfd_devs = max14577_devs;
mfd_devs_size = ARRAY_SIZE(max14577_devs);
irq_flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT;
break;
}
ret = regmap_add_irq_chip(max14577->regmap, max14577->irq,
irq_flags, 0, irq_chip,
&max14577->irq_data);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request IRQ %d: %d\n",
max14577->irq, ret);
return ret;
}
if (max14577->dev_type == MAXIM_DEVICE_TYPE_MAX77836) {
ret = max77836_init(max14577);
if (ret < 0)
goto err_max77836;
}
ret = mfd_add_devices(max14577->dev, -1, mfd_devs,
mfd_devs_size, NULL, 0,
regmap_irq_get_domain(max14577->irq_data));
if (ret < 0)
goto err_mfd;
device_init_wakeup(max14577->dev, 1);
return 0;
err_mfd:
if (max14577->dev_type == MAXIM_DEVICE_TYPE_MAX77836)
max77836_remove(max14577);
err_max77836:
regmap_del_irq_chip(max14577->irq, max14577->irq_data);
return ret;
}
static int max14577_i2c_remove(struct i2c_client *i2c)
{
struct max14577 *max14577 = i2c_get_clientdata(i2c);
mfd_remove_devices(max14577->dev);
regmap_del_irq_chip(max14577->irq, max14577->irq_data);
if (max14577->dev_type == MAXIM_DEVICE_TYPE_MAX77836)
max77836_remove(max14577);
return 0;
}
static int max14577_suspend(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct max14577 *max14577 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev))
enable_irq_wake(max14577->irq);
disable_irq(max14577->irq);
return 0;
}
static int max14577_resume(struct device *dev)
{
struct i2c_client *i2c = container_of(dev, struct i2c_client, dev);
struct max14577 *max14577 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev))
disable_irq_wake(max14577->irq);
enable_irq(max14577->irq);
return 0;
}
static int __init max14577_i2c_init(void)
{
BUILD_BUG_ON(ARRAY_SIZE(max14577_i2c_id) != MAXIM_DEVICE_TYPE_NUM);
BUILD_BUG_ON(ARRAY_SIZE(max14577_dt_match) != MAXIM_DEVICE_TYPE_NUM);
return i2c_add_driver(&max14577_i2c_driver);
}
static void __exit max14577_i2c_exit(void)
{
i2c_del_driver(&max14577_i2c_driver);
}
