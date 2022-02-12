static inline int tps_65023_read(struct tps_pmic *tps, u8 reg)
{
return i2c_smbus_read_byte_data(tps->client, reg);
}
static inline int tps_65023_write(struct tps_pmic *tps, u8 reg, u8 val)
{
return i2c_smbus_write_byte_data(tps->client, reg, val);
}
static int tps_65023_set_bits(struct tps_pmic *tps, u8 reg, u8 mask)
{
int err, data;
mutex_lock(&tps->io_lock);
data = tps_65023_read(tps, reg);
if (data < 0) {
dev_err(&tps->client->dev, "Read from reg 0x%x failed\n", reg);
err = data;
goto out;
}
data |= mask;
err = tps_65023_write(tps, reg, data);
if (err)
dev_err(&tps->client->dev, "Write for reg 0x%x failed\n", reg);
out:
mutex_unlock(&tps->io_lock);
return err;
}
static int tps_65023_clear_bits(struct tps_pmic *tps, u8 reg, u8 mask)
{
int err, data;
mutex_lock(&tps->io_lock);
data = tps_65023_read(tps, reg);
if (data < 0) {
dev_err(&tps->client->dev, "Read from reg 0x%x failed\n", reg);
err = data;
goto out;
}
data &= ~mask;
err = tps_65023_write(tps, reg, data);
if (err)
dev_err(&tps->client->dev, "Write for reg 0x%x failed\n", reg);
out:
mutex_unlock(&tps->io_lock);
return err;
}
static int tps_65023_reg_read(struct tps_pmic *tps, u8 reg)
{
int data;
mutex_lock(&tps->io_lock);
data = tps_65023_read(tps, reg);
if (data < 0)
dev_err(&tps->client->dev, "Read from reg 0x%x failed\n", reg);
mutex_unlock(&tps->io_lock);
return data;
}
static int tps_65023_reg_write(struct tps_pmic *tps, u8 reg, u8 val)
{
int err;
mutex_lock(&tps->io_lock);
err = tps_65023_write(tps, reg, val);
if (err < 0)
dev_err(&tps->client->dev, "Write for reg 0x%x failed\n", reg);
mutex_unlock(&tps->io_lock);
return err;
}
static int tps65023_dcdc_is_enabled(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int data, dcdc = rdev_get_id(dev);
u8 shift;
if (dcdc < TPS65023_DCDC_1 || dcdc > TPS65023_DCDC_3)
return -EINVAL;
shift = TPS65023_NUM_REGULATOR - dcdc;
data = tps_65023_reg_read(tps, TPS65023_REG_REG_CTRL);
if (data < 0)
return data;
else
return (data & 1<<shift) ? 1 : 0;
}
static int tps65023_ldo_is_enabled(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int data, ldo = rdev_get_id(dev);
u8 shift;
if (ldo < TPS65023_LDO_1 || ldo > TPS65023_LDO_2)
return -EINVAL;
shift = (ldo == TPS65023_LDO_1 ? 1 : 2);
data = tps_65023_reg_read(tps, TPS65023_REG_REG_CTRL);
if (data < 0)
return data;
else
return (data & 1<<shift) ? 1 : 0;
}
static int tps65023_dcdc_enable(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
u8 shift;
if (dcdc < TPS65023_DCDC_1 || dcdc > TPS65023_DCDC_3)
return -EINVAL;
shift = TPS65023_NUM_REGULATOR - dcdc;
return tps_65023_set_bits(tps, TPS65023_REG_REG_CTRL, 1 << shift);
}
static int tps65023_dcdc_disable(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
u8 shift;
if (dcdc < TPS65023_DCDC_1 || dcdc > TPS65023_DCDC_3)
return -EINVAL;
shift = TPS65023_NUM_REGULATOR - dcdc;
return tps_65023_clear_bits(tps, TPS65023_REG_REG_CTRL, 1 << shift);
}
static int tps65023_ldo_enable(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev);
u8 shift;
if (ldo < TPS65023_LDO_1 || ldo > TPS65023_LDO_2)
return -EINVAL;
shift = (ldo == TPS65023_LDO_1 ? 1 : 2);
return tps_65023_set_bits(tps, TPS65023_REG_REG_CTRL, 1 << shift);
}
static int tps65023_ldo_disable(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev);
u8 shift;
if (ldo < TPS65023_LDO_1 || ldo > TPS65023_LDO_2)
return -EINVAL;
shift = (ldo == TPS65023_LDO_1 ? 1 : 2);
return tps_65023_clear_bits(tps, TPS65023_REG_REG_CTRL, 1 << shift);
}
static int tps65023_dcdc_get_voltage(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int data, dcdc = rdev_get_id(dev);
if (dcdc < TPS65023_DCDC_1 || dcdc > TPS65023_DCDC_3)
return -EINVAL;
if (dcdc == TPS65023_DCDC_1) {
data = tps_65023_reg_read(tps, TPS65023_REG_DEF_CORE);
if (data < 0)
return data;
data &= (tps->info[dcdc]->table_len - 1);
return tps->info[dcdc]->table[data] * 1000;
} else
return tps->info[dcdc]->min_uV;
}
static int tps65023_dcdc_set_voltage(struct regulator_dev *dev,
int min_uV, int max_uV,
unsigned *selector)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
int vsel;
if (dcdc != TPS65023_DCDC_1)
return -EINVAL;
if (min_uV < tps->info[dcdc]->min_uV
|| min_uV > tps->info[dcdc]->max_uV)
return -EINVAL;
if (max_uV < tps->info[dcdc]->min_uV
|| max_uV > tps->info[dcdc]->max_uV)
return -EINVAL;
for (vsel = 0; vsel < tps->info[dcdc]->table_len; vsel++) {
int mV = tps->info[dcdc]->table[vsel];
int uV = mV * 1000;
if (min_uV <= uV && uV <= max_uV)
break;
}
*selector = vsel;
if (vsel == tps->info[dcdc]->table_len)
return -EINVAL;
else
return tps_65023_reg_write(tps, TPS65023_REG_DEF_CORE, vsel);
}
static int tps65023_ldo_get_voltage(struct regulator_dev *dev)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int data, ldo = rdev_get_id(dev);
if (ldo < TPS65023_LDO_1 || ldo > TPS65023_LDO_2)
return -EINVAL;
data = tps_65023_reg_read(tps, TPS65023_REG_LDO_CTRL);
if (data < 0)
return data;
data >>= (TPS65023_LDO_CTRL_LDOx_SHIFT(ldo - TPS65023_LDO_1));
data &= (tps->info[ldo]->table_len - 1);
return tps->info[ldo]->table[data] * 1000;
}
static int tps65023_ldo_set_voltage(struct regulator_dev *dev,
int min_uV, int max_uV, unsigned *selector)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int data, vsel, ldo = rdev_get_id(dev);
if (ldo < TPS65023_LDO_1 || ldo > TPS65023_LDO_2)
return -EINVAL;
if (min_uV < tps->info[ldo]->min_uV || min_uV > tps->info[ldo]->max_uV)
return -EINVAL;
if (max_uV < tps->info[ldo]->min_uV || max_uV > tps->info[ldo]->max_uV)
return -EINVAL;
for (vsel = 0; vsel < tps->info[ldo]->table_len; vsel++) {
int mV = tps->info[ldo]->table[vsel];
int uV = mV * 1000;
if (min_uV <= uV && uV <= max_uV)
break;
}
if (vsel == tps->info[ldo]->table_len)
return -EINVAL;
*selector = vsel;
data = tps_65023_reg_read(tps, TPS65023_REG_LDO_CTRL);
if (data < 0)
return data;
data &= TPS65023_LDO_CTRL_LDOx_MASK(ldo - TPS65023_LDO_1);
data |= (vsel << (TPS65023_LDO_CTRL_LDOx_SHIFT(ldo - TPS65023_LDO_1)));
return tps_65023_reg_write(tps, TPS65023_REG_LDO_CTRL, data);
}
static int tps65023_dcdc_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
if (dcdc < TPS65023_DCDC_1 || dcdc > TPS65023_DCDC_3)
return -EINVAL;
if (dcdc == TPS65023_DCDC_1) {
if (selector >= tps->info[dcdc]->table_len)
return -EINVAL;
else
return tps->info[dcdc]->table[selector] * 1000;
} else
return tps->info[dcdc]->min_uV;
}
static int tps65023_ldo_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct tps_pmic *tps = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev);
if (ldo < TPS65023_LDO_1 || ldo > TPS65023_LDO_2)
return -EINVAL;
if (selector >= tps->info[ldo]->table_len)
return -EINVAL;
else
return tps->info[ldo]->table[selector] * 1000;
}
static int __devinit tps_65023_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct tps_info *info = (void *)id->driver_data;
struct regulator_init_data *init_data;
struct regulator_dev *rdev;
struct tps_pmic *tps;
int i;
int error;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
init_data = client->dev.platform_data;
if (!init_data)
return -EIO;
tps = kzalloc(sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
mutex_init(&tps->io_lock);
tps->client = client;
for (i = 0; i < TPS65023_NUM_REGULATOR; i++, info++, init_data++) {
tps->info[i] = info;
tps->desc[i].name = info->name;
tps->desc[i].id = i;
tps->desc[i].n_voltages = num_voltages[i];
tps->desc[i].ops = (i > TPS65023_DCDC_3 ?
&tps65023_ldo_ops : &tps65023_dcdc_ops);
tps->desc[i].type = REGULATOR_VOLTAGE;
tps->desc[i].owner = THIS_MODULE;
rdev = regulator_register(&tps->desc[i], &client->dev,
init_data, tps);
if (IS_ERR(rdev)) {
dev_err(&client->dev, "failed to register %s\n",
id->name);
error = PTR_ERR(rdev);
goto fail;
}
tps->rdev[i] = rdev;
}
i2c_set_clientdata(client, tps);
return 0;
fail:
while (--i >= 0)
regulator_unregister(tps->rdev[i]);
kfree(tps);
return error;
}
static int __devexit tps_65023_remove(struct i2c_client *client)
{
struct tps_pmic *tps = i2c_get_clientdata(client);
int i;
for (i = 0; i < TPS65023_NUM_REGULATOR; i++)
regulator_unregister(tps->rdev[i]);
kfree(tps);
return 0;
}
static int __init tps_65023_init(void)
{
return i2c_add_driver(&tps_65023_i2c_driver);
}
static void __exit tps_65023_cleanup(void)
{
i2c_del_driver(&tps_65023_i2c_driver);
}
