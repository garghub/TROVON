static int lp3972_i2c_read(struct i2c_client *i2c, char reg, int count,
u16 *dest)
{
int ret;
if (count != 1)
return -EIO;
ret = i2c_smbus_read_byte_data(i2c, reg);
if (ret < 0)
return ret;
*dest = ret;
return 0;
}
static int lp3972_i2c_write(struct i2c_client *i2c, char reg, int count,
const u16 *src)
{
if (count != 1)
return -EIO;
return i2c_smbus_write_byte_data(i2c, reg, *src);
}
static u8 lp3972_reg_read(struct lp3972 *lp3972, u8 reg)
{
u16 val = 0;
mutex_lock(&lp3972->io_lock);
lp3972_i2c_read(lp3972->i2c, reg, 1, &val);
dev_dbg(lp3972->dev, "reg read 0x%02x -> 0x%02x\n", (int)reg,
(unsigned)val & 0xff);
mutex_unlock(&lp3972->io_lock);
return val & 0xff;
}
static int lp3972_set_bits(struct lp3972 *lp3972, u8 reg, u16 mask, u16 val)
{
u16 tmp;
int ret;
mutex_lock(&lp3972->io_lock);
ret = lp3972_i2c_read(lp3972->i2c, reg, 1, &tmp);
tmp = (tmp & ~mask) | val;
if (ret == 0) {
ret = lp3972_i2c_write(lp3972->i2c, reg, 1, &tmp);
dev_dbg(lp3972->dev, "reg write 0x%02x -> 0x%02x\n", (int)reg,
(unsigned)val & 0xff);
}
mutex_unlock(&lp3972->io_lock);
return ret;
}
static int lp3972_ldo_list_voltage(struct regulator_dev *dev, unsigned index)
{
int ldo = rdev_get_id(dev) - LP3972_LDO1;
return 1000 * LP3972_LDO_VOL_VALUE_MAP(ldo)[index];
}
static int lp3972_ldo_is_enabled(struct regulator_dev *dev)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3972_LDO1;
u16 mask = LP3972_LDO_OUTPUT_ENABLE_MASK(ldo);
u16 val;
val = lp3972_reg_read(lp3972, LP3972_LDO_OUTPUT_ENABLE_REG(ldo));
return !!(val & mask);
}
static int lp3972_ldo_enable(struct regulator_dev *dev)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3972_LDO1;
u16 mask = LP3972_LDO_OUTPUT_ENABLE_MASK(ldo);
return lp3972_set_bits(lp3972, LP3972_LDO_OUTPUT_ENABLE_REG(ldo),
mask, mask);
}
static int lp3972_ldo_disable(struct regulator_dev *dev)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3972_LDO1;
u16 mask = LP3972_LDO_OUTPUT_ENABLE_MASK(ldo);
return lp3972_set_bits(lp3972, LP3972_LDO_OUTPUT_ENABLE_REG(ldo),
mask, 0);
}
static int lp3972_ldo_get_voltage(struct regulator_dev *dev)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3972_LDO1;
u16 mask = LP3972_LDO_VOL_MASK(ldo);
u16 val, reg;
reg = lp3972_reg_read(lp3972, LP3972_LDO_VOL_CONTR_REG(ldo));
val = (reg >> LP3972_LDO_VOL_CONTR_SHIFT(ldo)) & mask;
return 1000 * LP3972_LDO_VOL_VALUE_MAP(ldo)[val];
}
static int lp3972_ldo_set_voltage(struct regulator_dev *dev,
int min_uV, int max_uV,
unsigned int *selector)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev) - LP3972_LDO1;
int min_vol = min_uV / 1000, max_vol = max_uV / 1000;
const int *vol_map = LP3972_LDO_VOL_VALUE_MAP(ldo);
u16 val;
int shift, ret;
if (min_vol < vol_map[LP3972_LDO_VOL_MIN_IDX(ldo)] ||
min_vol > vol_map[LP3972_LDO_VOL_MAX_IDX(ldo)])
return -EINVAL;
for (val = LP3972_LDO_VOL_MIN_IDX(ldo);
val <= LP3972_LDO_VOL_MAX_IDX(ldo); val++)
if (vol_map[val] >= min_vol)
break;
if (val > LP3972_LDO_VOL_MAX_IDX(ldo) || vol_map[val] > max_vol)
return -EINVAL;
*selector = val;
shift = LP3972_LDO_VOL_CONTR_SHIFT(ldo);
ret = lp3972_set_bits(lp3972, LP3972_LDO_VOL_CONTR_REG(ldo),
LP3972_LDO_VOL_MASK(ldo) << shift, val << shift);
if (ret)
return ret;
switch (ldo) {
case LP3972_LDO1:
case LP3972_LDO5:
shift = LP3972_LDO_VOL_CHANGE_SHIFT(ldo);
ret = lp3972_set_bits(lp3972, LP3972_VOL_CHANGE_REG,
LP3972_VOL_CHANGE_FLAG_MASK << shift,
LP3972_VOL_CHANGE_FLAG_GO << shift);
if (ret)
return ret;
ret = lp3972_set_bits(lp3972, LP3972_VOL_CHANGE_REG,
LP3972_VOL_CHANGE_FLAG_MASK << shift, 0);
break;
}
return ret;
}
static int lp3972_dcdc_list_voltage(struct regulator_dev *dev, unsigned index)
{
int buck = rdev_get_id(dev) - LP3972_DCDC1;
return 1000 * buck_voltage_map[buck][index];
}
static int lp3972_dcdc_is_enabled(struct regulator_dev *dev)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3972_DCDC1;
u16 mask = 1 << (buck * 2);
u16 val;
val = lp3972_reg_read(lp3972, LP3972_BUCK_VOL_ENABLE_REG(buck));
return !!(val & mask);
}
static int lp3972_dcdc_enable(struct regulator_dev *dev)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3972_DCDC1;
u16 mask = 1 << (buck * 2);
u16 val;
val = lp3972_set_bits(lp3972, LP3972_BUCK_VOL_ENABLE_REG(buck),
mask, mask);
return val;
}
static int lp3972_dcdc_disable(struct regulator_dev *dev)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3972_DCDC1;
u16 mask = 1 << (buck * 2);
u16 val;
val = lp3972_set_bits(lp3972, LP3972_BUCK_VOL_ENABLE_REG(buck),
mask, 0);
return val;
}
static int lp3972_dcdc_get_voltage(struct regulator_dev *dev)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3972_DCDC1;
u16 reg;
int val;
reg = lp3972_reg_read(lp3972, LP3972_BUCK_VOL1_REG(buck));
reg &= LP3972_BUCK_VOL_MASK;
if (reg <= LP3972_BUCK_VOL_MAX_IDX(buck))
val = 1000 * buck_voltage_map[buck][reg];
else {
val = 0;
dev_warn(&dev->dev, "chip reported incorrect voltage value."
" reg = %d\n", reg);
}
return val;
}
static int lp3972_dcdc_set_voltage(struct regulator_dev *dev,
int min_uV, int max_uV,
unsigned int *selector)
{
struct lp3972 *lp3972 = rdev_get_drvdata(dev);
int buck = rdev_get_id(dev) - LP3972_DCDC1;
int min_vol = min_uV / 1000, max_vol = max_uV / 1000;
const int *vol_map = buck_voltage_map[buck];
u16 val;
int ret;
if (min_vol < vol_map[LP3972_BUCK_VOL_MIN_IDX(buck)] ||
min_vol > vol_map[LP3972_BUCK_VOL_MAX_IDX(buck)])
return -EINVAL;
for (val = LP3972_BUCK_VOL_MIN_IDX(buck);
val <= LP3972_BUCK_VOL_MAX_IDX(buck); val++)
if (vol_map[val] >= min_vol)
break;
if (val > LP3972_BUCK_VOL_MAX_IDX(buck) ||
vol_map[val] > max_vol)
return -EINVAL;
*selector = val;
ret = lp3972_set_bits(lp3972, LP3972_BUCK_VOL1_REG(buck),
LP3972_BUCK_VOL_MASK, val);
if (ret)
return ret;
if (buck != 0)
return ret;
ret = lp3972_set_bits(lp3972, LP3972_VOL_CHANGE_REG,
LP3972_VOL_CHANGE_FLAG_MASK, LP3972_VOL_CHANGE_FLAG_GO);
if (ret)
return ret;
return lp3972_set_bits(lp3972, LP3972_VOL_CHANGE_REG,
LP3972_VOL_CHANGE_FLAG_MASK, 0);
}
static int __devinit setup_regulators(struct lp3972 *lp3972,
struct lp3972_platform_data *pdata)
{
int i, err;
lp3972->num_regulators = pdata->num_regulators;
lp3972->rdev = kcalloc(pdata->num_regulators,
sizeof(struct regulator_dev *), GFP_KERNEL);
if (!lp3972->rdev) {
err = -ENOMEM;
goto err_nomem;
}
for (i = 0; i < pdata->num_regulators; i++) {
struct lp3972_regulator_subdev *reg = &pdata->regulators[i];
lp3972->rdev[i] = regulator_register(&regulators[reg->id],
lp3972->dev, reg->initdata, lp3972, NULL);
if (IS_ERR(lp3972->rdev[i])) {
err = PTR_ERR(lp3972->rdev[i]);
dev_err(lp3972->dev, "regulator init failed: %d\n",
err);
goto error;
}
}
return 0;
error:
while (--i >= 0)
regulator_unregister(lp3972->rdev[i]);
kfree(lp3972->rdev);
lp3972->rdev = NULL;
err_nomem:
return err;
}
static int __devinit lp3972_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct lp3972 *lp3972;
struct lp3972_platform_data *pdata = i2c->dev.platform_data;
int ret;
u16 val;
if (!pdata) {
dev_dbg(&i2c->dev, "No platform init data supplied\n");
return -ENODEV;
}
lp3972 = kzalloc(sizeof(struct lp3972), GFP_KERNEL);
if (!lp3972)
return -ENOMEM;
lp3972->i2c = i2c;
lp3972->dev = &i2c->dev;
mutex_init(&lp3972->io_lock);
ret = lp3972_i2c_read(i2c, LP3972_SYS_CONTROL1_REG, 1, &val);
if (ret == 0 &&
(val & SYS_CONTROL1_INIT_MASK) != SYS_CONTROL1_INIT_VAL) {
ret = -ENODEV;
dev_err(&i2c->dev, "chip reported: val = 0x%x\n", val);
}
if (ret < 0) {
dev_err(&i2c->dev, "failed to detect device. ret = %d\n", ret);
goto err_detect;
}
ret = setup_regulators(lp3972, pdata);
if (ret < 0)
goto err_detect;
i2c_set_clientdata(i2c, lp3972);
return 0;
err_detect:
kfree(lp3972);
return ret;
}
static int __devexit lp3972_i2c_remove(struct i2c_client *i2c)
{
struct lp3972 *lp3972 = i2c_get_clientdata(i2c);
int i;
for (i = 0; i < lp3972->num_regulators; i++)
regulator_unregister(lp3972->rdev[i]);
kfree(lp3972->rdev);
kfree(lp3972);
return 0;
}
static int __init lp3972_module_init(void)
{
return i2c_add_driver(&lp3972_i2c_driver);
}
static void __exit lp3972_module_exit(void)
{
i2c_del_driver(&lp3972_i2c_driver);
}
