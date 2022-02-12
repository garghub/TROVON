static inline int tps6507x_pmic_read(struct tps6507x_pmic *tps, u8 reg)
{
u8 val;
int err;
err = tps->mfd->read_dev(tps->mfd, reg, 1, &val);
if (err)
return err;
return val;
}
static inline int tps6507x_pmic_write(struct tps6507x_pmic *tps, u8 reg, u8 val)
{
return tps->mfd->write_dev(tps->mfd, reg, 1, &val);
}
static int tps6507x_pmic_set_bits(struct tps6507x_pmic *tps, u8 reg, u8 mask)
{
int err, data;
mutex_lock(&tps->io_lock);
data = tps6507x_pmic_read(tps, reg);
if (data < 0) {
dev_err(tps->mfd->dev, "Read from reg 0x%x failed\n", reg);
err = data;
goto out;
}
data |= mask;
err = tps6507x_pmic_write(tps, reg, data);
if (err)
dev_err(tps->mfd->dev, "Write for reg 0x%x failed\n", reg);
out:
mutex_unlock(&tps->io_lock);
return err;
}
static int tps6507x_pmic_clear_bits(struct tps6507x_pmic *tps, u8 reg, u8 mask)
{
int err, data;
mutex_lock(&tps->io_lock);
data = tps6507x_pmic_read(tps, reg);
if (data < 0) {
dev_err(tps->mfd->dev, "Read from reg 0x%x failed\n", reg);
err = data;
goto out;
}
data &= ~mask;
err = tps6507x_pmic_write(tps, reg, data);
if (err)
dev_err(tps->mfd->dev, "Write for reg 0x%x failed\n", reg);
out:
mutex_unlock(&tps->io_lock);
return err;
}
static int tps6507x_pmic_reg_read(struct tps6507x_pmic *tps, u8 reg)
{
int data;
mutex_lock(&tps->io_lock);
data = tps6507x_pmic_read(tps, reg);
if (data < 0)
dev_err(tps->mfd->dev, "Read from reg 0x%x failed\n", reg);
mutex_unlock(&tps->io_lock);
return data;
}
static int tps6507x_pmic_reg_write(struct tps6507x_pmic *tps, u8 reg, u8 val)
{
int err;
mutex_lock(&tps->io_lock);
err = tps6507x_pmic_write(tps, reg, val);
if (err < 0)
dev_err(tps->mfd->dev, "Write for reg 0x%x failed\n", reg);
mutex_unlock(&tps->io_lock);
return err;
}
static int tps6507x_pmic_dcdc_is_enabled(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int data, dcdc = rdev_get_id(dev);
u8 shift;
if (dcdc < TPS6507X_DCDC_1 || dcdc > TPS6507X_DCDC_3)
return -EINVAL;
shift = TPS6507X_MAX_REG_ID - dcdc;
data = tps6507x_pmic_reg_read(tps, TPS6507X_REG_CON_CTRL1);
if (data < 0)
return data;
else
return (data & 1<<shift) ? 1 : 0;
}
static int tps6507x_pmic_ldo_is_enabled(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int data, ldo = rdev_get_id(dev);
u8 shift;
if (ldo < TPS6507X_LDO_1 || ldo > TPS6507X_LDO_2)
return -EINVAL;
shift = TPS6507X_MAX_REG_ID - ldo;
data = tps6507x_pmic_reg_read(tps, TPS6507X_REG_CON_CTRL1);
if (data < 0)
return data;
else
return (data & 1<<shift) ? 1 : 0;
}
static int tps6507x_pmic_dcdc_enable(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
u8 shift;
if (dcdc < TPS6507X_DCDC_1 || dcdc > TPS6507X_DCDC_3)
return -EINVAL;
shift = TPS6507X_MAX_REG_ID - dcdc;
return tps6507x_pmic_set_bits(tps, TPS6507X_REG_CON_CTRL1, 1 << shift);
}
static int tps6507x_pmic_dcdc_disable(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
u8 shift;
if (dcdc < TPS6507X_DCDC_1 || dcdc > TPS6507X_DCDC_3)
return -EINVAL;
shift = TPS6507X_MAX_REG_ID - dcdc;
return tps6507x_pmic_clear_bits(tps, TPS6507X_REG_CON_CTRL1,
1 << shift);
}
static int tps6507x_pmic_ldo_enable(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev);
u8 shift;
if (ldo < TPS6507X_LDO_1 || ldo > TPS6507X_LDO_2)
return -EINVAL;
shift = TPS6507X_MAX_REG_ID - ldo;
return tps6507x_pmic_set_bits(tps, TPS6507X_REG_CON_CTRL1, 1 << shift);
}
static int tps6507x_pmic_ldo_disable(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev);
u8 shift;
if (ldo < TPS6507X_LDO_1 || ldo > TPS6507X_LDO_2)
return -EINVAL;
shift = TPS6507X_MAX_REG_ID - ldo;
return tps6507x_pmic_clear_bits(tps, TPS6507X_REG_CON_CTRL1,
1 << shift);
}
static int tps6507x_pmic_dcdc_get_voltage(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int data, dcdc = rdev_get_id(dev);
u8 reg;
switch (dcdc) {
case TPS6507X_DCDC_1:
reg = TPS6507X_REG_DEFDCDC1;
break;
case TPS6507X_DCDC_2:
if (tps->info[dcdc]->defdcdc_default)
reg = TPS6507X_REG_DEFDCDC2_HIGH;
else
reg = TPS6507X_REG_DEFDCDC2_LOW;
break;
case TPS6507X_DCDC_3:
if (tps->info[dcdc]->defdcdc_default)
reg = TPS6507X_REG_DEFDCDC3_HIGH;
else
reg = TPS6507X_REG_DEFDCDC3_LOW;
break;
default:
return -EINVAL;
}
data = tps6507x_pmic_reg_read(tps, reg);
if (data < 0)
return data;
data &= TPS6507X_DEFDCDCX_DCDC_MASK;
return tps->info[dcdc]->table[data] * 1000;
}
static int tps6507x_pmic_dcdc_set_voltage(struct regulator_dev *dev,
int min_uV, int max_uV,
unsigned *selector)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int data, vsel, dcdc = rdev_get_id(dev);
u8 reg;
switch (dcdc) {
case TPS6507X_DCDC_1:
reg = TPS6507X_REG_DEFDCDC1;
break;
case TPS6507X_DCDC_2:
if (tps->info[dcdc]->defdcdc_default)
reg = TPS6507X_REG_DEFDCDC2_HIGH;
else
reg = TPS6507X_REG_DEFDCDC2_LOW;
break;
case TPS6507X_DCDC_3:
if (tps->info[dcdc]->defdcdc_default)
reg = TPS6507X_REG_DEFDCDC3_HIGH;
else
reg = TPS6507X_REG_DEFDCDC3_LOW;
break;
default:
return -EINVAL;
}
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
if (vsel == tps->info[dcdc]->table_len)
return -EINVAL;
*selector = vsel;
data = tps6507x_pmic_reg_read(tps, reg);
if (data < 0)
return data;
data &= ~TPS6507X_DEFDCDCX_DCDC_MASK;
data |= vsel;
return tps6507x_pmic_reg_write(tps, reg, data);
}
static int tps6507x_pmic_ldo_get_voltage(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int data, ldo = rdev_get_id(dev);
u8 reg, mask;
if (ldo < TPS6507X_LDO_1 || ldo > TPS6507X_LDO_2)
return -EINVAL;
else {
reg = (ldo == TPS6507X_LDO_1 ?
TPS6507X_REG_LDO_CTRL1 : TPS6507X_REG_DEFLDO2);
mask = (ldo == TPS6507X_LDO_1 ?
TPS6507X_REG_LDO_CTRL1_LDO1_MASK :
TPS6507X_REG_DEFLDO2_LDO2_MASK);
}
data = tps6507x_pmic_reg_read(tps, reg);
if (data < 0)
return data;
data &= mask;
return tps->info[ldo]->table[data] * 1000;
}
static int tps6507x_pmic_ldo_set_voltage(struct regulator_dev *dev,
int min_uV, int max_uV,
unsigned *selector)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int data, vsel, ldo = rdev_get_id(dev);
u8 reg, mask;
if (ldo < TPS6507X_LDO_1 || ldo > TPS6507X_LDO_2)
return -EINVAL;
else {
reg = (ldo == TPS6507X_LDO_1 ?
TPS6507X_REG_LDO_CTRL1 : TPS6507X_REG_DEFLDO2);
mask = (ldo == TPS6507X_LDO_1 ?
TPS6507X_REG_LDO_CTRL1_LDO1_MASK :
TPS6507X_REG_DEFLDO2_LDO2_MASK);
}
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
data = tps6507x_pmic_reg_read(tps, reg);
if (data < 0)
return data;
data &= ~mask;
data |= vsel;
return tps6507x_pmic_reg_write(tps, reg, data);
}
static int tps6507x_pmic_dcdc_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int dcdc = rdev_get_id(dev);
if (dcdc < TPS6507X_DCDC_1 || dcdc > TPS6507X_DCDC_3)
return -EINVAL;
if (selector >= tps->info[dcdc]->table_len)
return -EINVAL;
else
return tps->info[dcdc]->table[selector] * 1000;
}
static int tps6507x_pmic_ldo_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev);
if (ldo < TPS6507X_LDO_1 || ldo > TPS6507X_LDO_2)
return -EINVAL;
if (selector >= tps->info[ldo]->table_len)
return -EINVAL;
else
return tps->info[ldo]->table[selector] * 1000;
}
static __devinit
int tps6507x_pmic_probe(struct platform_device *pdev)
{
struct tps6507x_dev *tps6507x_dev = dev_get_drvdata(pdev->dev.parent);
struct tps_info *info = &tps6507x_pmic_regs[0];
struct regulator_init_data *init_data;
struct regulator_dev *rdev;
struct tps6507x_pmic *tps;
struct tps6507x_board *tps_board;
int i;
int error;
tps_board = dev_get_platdata(tps6507x_dev->dev);
if (!tps_board)
return -EINVAL;
init_data = tps_board->tps6507x_pmic_init_data;
if (!init_data)
return -EINVAL;
tps = kzalloc(sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
mutex_init(&tps->io_lock);
tps->mfd = tps6507x_dev;
for (i = 0; i < TPS6507X_NUM_REGULATOR; i++, info++, init_data++) {
tps->info[i] = info;
if (init_data->driver_data) {
struct tps6507x_reg_platform_data *data =
init_data->driver_data;
tps->info[i]->defdcdc_default = data->defdcdc_default;
}
tps->desc[i].name = info->name;
tps->desc[i].id = i;
tps->desc[i].n_voltages = info->table_len;
tps->desc[i].ops = (i > TPS6507X_DCDC_3 ?
&tps6507x_pmic_ldo_ops : &tps6507x_pmic_dcdc_ops);
tps->desc[i].type = REGULATOR_VOLTAGE;
tps->desc[i].owner = THIS_MODULE;
rdev = regulator_register(&tps->desc[i],
tps6507x_dev->dev, init_data, tps, NULL);
if (IS_ERR(rdev)) {
dev_err(tps6507x_dev->dev,
"failed to register %s regulator\n",
pdev->name);
error = PTR_ERR(rdev);
goto fail;
}
tps->rdev[i] = rdev;
}
tps6507x_dev->pmic = tps;
platform_set_drvdata(pdev, tps6507x_dev);
return 0;
fail:
while (--i >= 0)
regulator_unregister(tps->rdev[i]);
kfree(tps);
return error;
}
static int __devexit tps6507x_pmic_remove(struct platform_device *pdev)
{
struct tps6507x_dev *tps6507x_dev = platform_get_drvdata(pdev);
struct tps6507x_pmic *tps = tps6507x_dev->pmic;
int i;
for (i = 0; i < TPS6507X_NUM_REGULATOR; i++)
regulator_unregister(tps->rdev[i]);
kfree(tps);
return 0;
}
static int __init tps6507x_pmic_init(void)
{
return platform_driver_register(&tps6507x_pmic_driver);
}
static void __exit tps6507x_pmic_cleanup(void)
{
platform_driver_unregister(&tps6507x_pmic_driver);
}
