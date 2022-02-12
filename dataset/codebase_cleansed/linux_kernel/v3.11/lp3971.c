static int lp3971_ldo_is_enabled(struct regulator_dev *dev)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3971_LDO1;
u16 mask = 1 << (1 + ldo);
u16 val;
val = lp3971_reg_read(lp3971, LP3971_LDO_ENABLE_REG);
return (val & mask) != 0;
}
static int lp3971_ldo_enable(struct regulator_dev *dev)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3971_LDO1;
u16 mask = 1 << (1 + ldo);
return lp3971_set_bits(lp3971, LP3971_LDO_ENABLE_REG, mask, mask);
}
static int lp3971_ldo_disable(struct regulator_dev *dev)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3971_LDO1;
u16 mask = 1 << (1 + ldo);
return lp3971_set_bits(lp3971, LP3971_LDO_ENABLE_REG, mask, 0);
}
static int lp3971_ldo_get_voltage_sel(struct regulator_dev *dev)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3971_LDO1;
u16 val, reg;
reg = lp3971_reg_read(lp3971, LP3971_LDO_VOL_CONTR_REG(ldo));
val = (reg >> LDO_VOL_CONTR_SHIFT(ldo)) & LDO_VOL_CONTR_MASK;
return val;
}
static int lp3971_ldo_set_voltage_sel(struct regulator_dev *dev,
unsigned int selector)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3971_LDO1;
return lp3971_set_bits(lp3971, LP3971_LDO_VOL_CONTR_REG(ldo),
LDO_VOL_CONTR_MASK << LDO_VOL_CONTR_SHIFT(ldo),
selector << LDO_VOL_CONTR_SHIFT(ldo));
}
static int lp3971_dcdc_is_enabled(struct regulator_dev *dev)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3971_DCDC1;
u16 mask = 1 << (buck * 2);
u16 val;
val = lp3971_reg_read(lp3971, LP3971_BUCK_VOL_ENABLE_REG);
return (val & mask) != 0;
}
static int lp3971_dcdc_enable(struct regulator_dev *dev)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3971_DCDC1;
u16 mask = 1 << (buck * 2);
return lp3971_set_bits(lp3971, LP3971_BUCK_VOL_ENABLE_REG, mask, mask);
}
static int lp3971_dcdc_disable(struct regulator_dev *dev)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3971_DCDC1;
u16 mask = 1 << (buck * 2);
return lp3971_set_bits(lp3971, LP3971_BUCK_VOL_ENABLE_REG, mask, 0);
}
static int lp3971_dcdc_get_voltage_sel(struct regulator_dev *dev)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3971_DCDC1;
u16 reg;
reg = lp3971_reg_read(lp3971, LP3971_BUCK_TARGET_VOL1_REG(buck));
reg &= BUCK_TARGET_VOL_MASK;
return reg;
}
static int lp3971_dcdc_set_voltage_sel(struct regulator_dev *dev,
unsigned int selector)
{
struct lp3971 *lp3971 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3971_DCDC1;
int ret;
ret = lp3971_set_bits(lp3971, LP3971_BUCK_TARGET_VOL1_REG(buck),
BUCK_TARGET_VOL_MASK, selector);
if (ret)
return ret;
ret = lp3971_set_bits(lp3971, LP3971_BUCK_VOL_CHANGE_REG,
BUCK_VOL_CHANGE_FLAG_MASK << BUCK_VOL_CHANGE_SHIFT(buck),
BUCK_VOL_CHANGE_FLAG_GO << BUCK_VOL_CHANGE_SHIFT(buck));
if (ret)
return ret;
return lp3971_set_bits(lp3971, LP3971_BUCK_VOL_CHANGE_REG,
BUCK_VOL_CHANGE_FLAG_MASK << BUCK_VOL_CHANGE_SHIFT(buck),
0 << BUCK_VOL_CHANGE_SHIFT(buck));
}
static int lp3971_i2c_read(struct i2c_client *i2c, char reg, int count,
u16 *dest)
{
int ret;
if (count != 1)
return -EIO;
ret = i2c_smbus_read_byte_data(i2c, reg);
if (ret < 0)
return -EIO;
*dest = ret;
return 0;
}
static int lp3971_i2c_write(struct i2c_client *i2c, char reg, int count,
const u16 *src)
{
if (count != 1)
return -EIO;
return i2c_smbus_write_byte_data(i2c, reg, *src);
}
static u8 lp3971_reg_read(struct lp3971 *lp3971, u8 reg)
{
u16 val = 0;
mutex_lock(&lp3971->io_lock);
lp3971_i2c_read(lp3971->i2c, reg, 1, &val);
dev_dbg(lp3971->dev, "reg read 0x%02x -> 0x%02x\n", (int)reg,
(unsigned)val&0xff);
mutex_unlock(&lp3971->io_lock);
return val & 0xff;
}
static int lp3971_set_bits(struct lp3971 *lp3971, u8 reg, u16 mask, u16 val)
{
u16 tmp;
int ret;
mutex_lock(&lp3971->io_lock);
ret = lp3971_i2c_read(lp3971->i2c, reg, 1, &tmp);
tmp = (tmp & ~mask) | val;
if (ret == 0) {
ret = lp3971_i2c_write(lp3971->i2c, reg, 1, &tmp);
dev_dbg(lp3971->dev, "reg write 0x%02x -> 0x%02x\n", (int)reg,
(unsigned)val&0xff);
}
mutex_unlock(&lp3971->io_lock);
return ret;
}
static int setup_regulators(struct lp3971 *lp3971,
struct lp3971_platform_data *pdata)
{
int i, err;
lp3971->num_regulators = pdata->num_regulators;
lp3971->rdev = kcalloc(pdata->num_regulators,
sizeof(struct regulator_dev *), GFP_KERNEL);
if (!lp3971->rdev) {
err = -ENOMEM;
goto err_nomem;
}
for (i = 0; i < pdata->num_regulators; i++) {
struct regulator_config config = { };
struct lp3971_regulator_subdev *reg = &pdata->regulators[i];
config.dev = lp3971->dev;
config.init_data = reg->initdata;
config.driver_data = lp3971;
lp3971->rdev[i] = regulator_register(&regulators[reg->id],
&config);
if (IS_ERR(lp3971->rdev[i])) {
err = PTR_ERR(lp3971->rdev[i]);
dev_err(lp3971->dev, "regulator init failed: %d\n",
err);
goto error;
}
}
return 0;
error:
while (--i >= 0)
regulator_unregister(lp3971->rdev[i]);
kfree(lp3971->rdev);
lp3971->rdev = NULL;
err_nomem:
return err;
}
static int lp3971_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct lp3971 *lp3971;
struct lp3971_platform_data *pdata = i2c->dev.platform_data;
int ret;
u16 val;
if (!pdata) {
dev_dbg(&i2c->dev, "No platform init data supplied\n");
return -ENODEV;
}
lp3971 = devm_kzalloc(&i2c->dev, sizeof(struct lp3971), GFP_KERNEL);
if (lp3971 == NULL)
return -ENOMEM;
lp3971->i2c = i2c;
lp3971->dev = &i2c->dev;
mutex_init(&lp3971->io_lock);
ret = lp3971_i2c_read(i2c, LP3971_SYS_CONTROL1_REG, 1, &val);
if (ret == 0 && (val & SYS_CONTROL1_INIT_MASK) != SYS_CONTROL1_INIT_VAL)
ret = -ENODEV;
if (ret < 0) {
dev_err(&i2c->dev, "failed to detect device\n");
return ret;
}
ret = setup_regulators(lp3971, pdata);
if (ret < 0)
return ret;
i2c_set_clientdata(i2c, lp3971);
return 0;
}
static int lp3971_i2c_remove(struct i2c_client *i2c)
{
struct lp3971 *lp3971 = i2c_get_clientdata(i2c);
int i;
for (i = 0; i < lp3971->num_regulators; i++)
regulator_unregister(lp3971->rdev[i]);
kfree(lp3971->rdev);
return 0;
}
