int retu_read(struct retu_dev *rdev, u8 reg)
{
int ret;
int value;
mutex_lock(&rdev->mutex);
ret = regmap_read(rdev->regmap, reg, &value);
mutex_unlock(&rdev->mutex);
return ret ? ret : value;
}
int retu_write(struct retu_dev *rdev, u8 reg, u16 data)
{
int ret;
mutex_lock(&rdev->mutex);
ret = regmap_write(rdev->regmap, reg, data);
mutex_unlock(&rdev->mutex);
return ret;
}
static void retu_power_off(void)
{
struct retu_dev *rdev = retu_pm_power_off;
int reg;
mutex_lock(&retu_pm_power_off->mutex);
regmap_read(rdev->regmap, RETU_REG_CC1, &reg);
regmap_write(rdev->regmap, RETU_REG_CC1, reg | 2);
regmap_write(rdev->regmap, RETU_REG_WATCHDOG, 0);
for (;;)
cpu_relax();
mutex_unlock(&retu_pm_power_off->mutex);
}
static int retu_regmap_read(void *context, const void *reg, size_t reg_size,
void *val, size_t val_size)
{
int ret;
struct device *dev = context;
struct i2c_client *i2c = to_i2c_client(dev);
BUG_ON(reg_size != 1 || val_size != 2);
ret = i2c_smbus_read_word_data(i2c, *(u8 const *)reg);
if (ret < 0)
return ret;
*(u16 *)val = ret;
return 0;
}
static int retu_regmap_write(void *context, const void *data, size_t count)
{
u8 reg;
u16 val;
struct device *dev = context;
struct i2c_client *i2c = to_i2c_client(dev);
BUG_ON(count != sizeof(reg) + sizeof(val));
memcpy(&reg, data, sizeof(reg));
memcpy(&val, data + sizeof(reg), sizeof(val));
return i2c_smbus_write_word_data(i2c, reg, val);
}
static int retu_probe(struct i2c_client *i2c, const struct i2c_device_id *id)
{
struct retu_dev *rdev;
int ret;
rdev = devm_kzalloc(&i2c->dev, sizeof(*rdev), GFP_KERNEL);
if (rdev == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, rdev);
rdev->dev = &i2c->dev;
mutex_init(&rdev->mutex);
rdev->regmap = devm_regmap_init(&i2c->dev, &retu_bus, &i2c->dev,
&retu_config);
if (IS_ERR(rdev->regmap))
return PTR_ERR(rdev->regmap);
ret = retu_read(rdev, RETU_REG_ASICR);
if (ret < 0) {
dev_err(rdev->dev, "could not read Retu revision: %d\n", ret);
return ret;
}
dev_info(rdev->dev, "Retu%s v%d.%d found\n",
(ret & RETU_REG_ASICR_VILMA) ? " & Vilma" : "",
(ret >> 4) & 0x7, ret & 0xf);
ret = retu_write(rdev, RETU_REG_IMR, 0xffff);
if (ret < 0)
return ret;
ret = regmap_add_irq_chip(rdev->regmap, i2c->irq, IRQF_ONESHOT, -1,
&retu_irq_chip, &rdev->irq_data);
if (ret < 0)
return ret;
ret = mfd_add_devices(rdev->dev, -1, retu_devs, ARRAY_SIZE(retu_devs),
NULL, regmap_irq_chip_get_base(rdev->irq_data),
NULL);
if (ret < 0) {
regmap_del_irq_chip(i2c->irq, rdev->irq_data);
return ret;
}
if (!pm_power_off) {
retu_pm_power_off = rdev;
pm_power_off = retu_power_off;
}
return 0;
}
static int retu_remove(struct i2c_client *i2c)
{
struct retu_dev *rdev = i2c_get_clientdata(i2c);
if (retu_pm_power_off == rdev) {
pm_power_off = NULL;
retu_pm_power_off = NULL;
}
mfd_remove_devices(rdev->dev);
regmap_del_irq_chip(i2c->irq, rdev->irq_data);
return 0;
}
