static bool max77802_pmic_is_accessible_reg(struct device *dev,
unsigned int reg)
{
return reg < MAX77802_REG_PMIC_END;
}
static bool max77802_rtc_is_accessible_reg(struct device *dev,
unsigned int reg)
{
return (reg >= MAX77802_RTC_INT && reg < MAX77802_RTC_END);
}
static bool max77802_is_accessible_reg(struct device *dev, unsigned int reg)
{
return (max77802_pmic_is_accessible_reg(dev, reg) ||
max77802_rtc_is_accessible_reg(dev, reg));
}
static bool max77802_pmic_is_precious_reg(struct device *dev, unsigned int reg)
{
return (reg == MAX77802_REG_INTSRC || reg == MAX77802_REG_INT1 ||
reg == MAX77802_REG_INT2);
}
static bool max77802_rtc_is_precious_reg(struct device *dev, unsigned int reg)
{
return (reg == MAX77802_RTC_INT ||
reg == MAX77802_RTC_UPDATE0 ||
reg == MAX77802_RTC_UPDATE1);
}
static bool max77802_is_precious_reg(struct device *dev, unsigned int reg)
{
return (max77802_pmic_is_precious_reg(dev, reg) ||
max77802_rtc_is_precious_reg(dev, reg));
}
static bool max77802_pmic_is_volatile_reg(struct device *dev, unsigned int reg)
{
return (max77802_is_precious_reg(dev, reg) ||
reg == MAX77802_REG_STATUS1 || reg == MAX77802_REG_STATUS2 ||
reg == MAX77802_REG_PWRON);
}
static bool max77802_rtc_is_volatile_reg(struct device *dev, unsigned int reg)
{
return (max77802_rtc_is_precious_reg(dev, reg) ||
reg == MAX77802_RTC_SEC ||
reg == MAX77802_RTC_MIN ||
reg == MAX77802_RTC_HOUR ||
reg == MAX77802_RTC_WEEKDAY ||
reg == MAX77802_RTC_MONTH ||
reg == MAX77802_RTC_YEAR ||
reg == MAX77802_RTC_DATE);
}
static bool max77802_is_volatile_reg(struct device *dev, unsigned int reg)
{
return (max77802_pmic_is_volatile_reg(dev, reg) ||
max77802_rtc_is_volatile_reg(dev, reg));
}
static int max77686_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct max77686_dev *max77686 = NULL;
const struct of_device_id *match;
unsigned int data;
int ret = 0;
const struct regmap_config *config;
const struct regmap_irq_chip *irq_chip;
const struct mfd_cell *cells;
int n_devs;
max77686 = devm_kzalloc(&i2c->dev,
sizeof(struct max77686_dev), GFP_KERNEL);
if (!max77686)
return -ENOMEM;
if (i2c->dev.of_node) {
match = of_match_node(max77686_pmic_dt_match, i2c->dev.of_node);
if (!match)
return -EINVAL;
max77686->type = (unsigned long)match->data;
} else
max77686->type = id->driver_data;
i2c_set_clientdata(i2c, max77686);
max77686->dev = &i2c->dev;
max77686->i2c = i2c;
max77686->irq = i2c->irq;
if (max77686->type == TYPE_MAX77686) {
config = &max77686_regmap_config;
irq_chip = &max77686_irq_chip;
cells = max77686_devs;
n_devs = ARRAY_SIZE(max77686_devs);
} else {
config = &max77802_regmap_config;
irq_chip = &max77802_irq_chip;
cells = max77802_devs;
n_devs = ARRAY_SIZE(max77802_devs);
}
max77686->regmap = devm_regmap_init_i2c(i2c, config);
if (IS_ERR(max77686->regmap)) {
ret = PTR_ERR(max77686->regmap);
dev_err(max77686->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = regmap_read(max77686->regmap, MAX77686_REG_DEVICE_ID, &data);
if (ret < 0) {
dev_err(max77686->dev,
"device not found on this channel (this is not an error)\n");
return -ENODEV;
}
ret = regmap_add_irq_chip(max77686->regmap, max77686->irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT |
IRQF_SHARED, 0, irq_chip,
&max77686->irq_data);
if (ret < 0) {
dev_err(&i2c->dev, "failed to add PMIC irq chip: %d\n", ret);
return ret;
}
ret = mfd_add_devices(max77686->dev, -1, cells, n_devs, NULL, 0, NULL);
if (ret < 0) {
dev_err(&i2c->dev, "failed to add MFD devices: %d\n", ret);
goto err_del_irqc;
}
return 0;
err_del_irqc:
regmap_del_irq_chip(max77686->irq, max77686->irq_data);
return ret;
}
static int max77686_i2c_remove(struct i2c_client *i2c)
{
struct max77686_dev *max77686 = i2c_get_clientdata(i2c);
mfd_remove_devices(max77686->dev);
regmap_del_irq_chip(max77686->irq, max77686->irq_data);
return 0;
}
static int max77686_suspend(struct device *dev)
{
struct i2c_client *i2c = to_i2c_client(dev);
struct max77686_dev *max77686 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev))
enable_irq_wake(max77686->irq);
disable_irq(max77686->irq);
return 0;
}
static int max77686_resume(struct device *dev)
{
struct i2c_client *i2c = to_i2c_client(dev);
struct max77686_dev *max77686 = i2c_get_clientdata(i2c);
if (device_may_wakeup(dev))
disable_irq_wake(max77686->irq);
enable_irq(max77686->irq);
return 0;
}
static int __init max77686_i2c_init(void)
{
return i2c_add_driver(&max77686_i2c_driver);
}
static void __exit max77686_i2c_exit(void)
{
i2c_del_driver(&max77686_i2c_driver);
}
