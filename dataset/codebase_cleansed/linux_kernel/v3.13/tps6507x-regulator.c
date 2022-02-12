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
static int tps6507x_pmic_is_enabled(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int data, rid = rdev_get_id(dev);
u8 shift;
if (rid < TPS6507X_DCDC_1 || rid > TPS6507X_LDO_2)
return -EINVAL;
shift = TPS6507X_MAX_REG_ID - rid;
data = tps6507x_pmic_reg_read(tps, TPS6507X_REG_CON_CTRL1);
if (data < 0)
return data;
else
return (data & 1<<shift) ? 1 : 0;
}
static int tps6507x_pmic_enable(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int rid = rdev_get_id(dev);
u8 shift;
if (rid < TPS6507X_DCDC_1 || rid > TPS6507X_LDO_2)
return -EINVAL;
shift = TPS6507X_MAX_REG_ID - rid;
return tps6507x_pmic_set_bits(tps, TPS6507X_REG_CON_CTRL1, 1 << shift);
}
static int tps6507x_pmic_disable(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int rid = rdev_get_id(dev);
u8 shift;
if (rid < TPS6507X_DCDC_1 || rid > TPS6507X_LDO_2)
return -EINVAL;
shift = TPS6507X_MAX_REG_ID - rid;
return tps6507x_pmic_clear_bits(tps, TPS6507X_REG_CON_CTRL1,
1 << shift);
}
static int tps6507x_pmic_get_voltage_sel(struct regulator_dev *dev)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int data, rid = rdev_get_id(dev);
u8 reg, mask;
switch (rid) {
case TPS6507X_DCDC_1:
reg = TPS6507X_REG_DEFDCDC1;
mask = TPS6507X_DEFDCDCX_DCDC_MASK;
break;
case TPS6507X_DCDC_2:
if (tps->info[rid]->defdcdc_default)
reg = TPS6507X_REG_DEFDCDC2_HIGH;
else
reg = TPS6507X_REG_DEFDCDC2_LOW;
mask = TPS6507X_DEFDCDCX_DCDC_MASK;
break;
case TPS6507X_DCDC_3:
if (tps->info[rid]->defdcdc_default)
reg = TPS6507X_REG_DEFDCDC3_HIGH;
else
reg = TPS6507X_REG_DEFDCDC3_LOW;
mask = TPS6507X_DEFDCDCX_DCDC_MASK;
break;
case TPS6507X_LDO_1:
reg = TPS6507X_REG_LDO_CTRL1;
mask = TPS6507X_REG_LDO_CTRL1_LDO1_MASK;
break;
case TPS6507X_LDO_2:
reg = TPS6507X_REG_DEFLDO2;
mask = TPS6507X_REG_DEFLDO2_LDO2_MASK;
break;
default:
return -EINVAL;
}
data = tps6507x_pmic_reg_read(tps, reg);
if (data < 0)
return data;
data &= mask;
return data;
}
static int tps6507x_pmic_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
struct tps6507x_pmic *tps = rdev_get_drvdata(dev);
int data, rid = rdev_get_id(dev);
u8 reg, mask;
switch (rid) {
case TPS6507X_DCDC_1:
reg = TPS6507X_REG_DEFDCDC1;
mask = TPS6507X_DEFDCDCX_DCDC_MASK;
break;
case TPS6507X_DCDC_2:
if (tps->info[rid]->defdcdc_default)
reg = TPS6507X_REG_DEFDCDC2_HIGH;
else
reg = TPS6507X_REG_DEFDCDC2_LOW;
mask = TPS6507X_DEFDCDCX_DCDC_MASK;
break;
case TPS6507X_DCDC_3:
if (tps->info[rid]->defdcdc_default)
reg = TPS6507X_REG_DEFDCDC3_HIGH;
else
reg = TPS6507X_REG_DEFDCDC3_LOW;
mask = TPS6507X_DEFDCDCX_DCDC_MASK;
break;
case TPS6507X_LDO_1:
reg = TPS6507X_REG_LDO_CTRL1;
mask = TPS6507X_REG_LDO_CTRL1_LDO1_MASK;
break;
case TPS6507X_LDO_2:
reg = TPS6507X_REG_DEFLDO2;
mask = TPS6507X_REG_DEFLDO2_LDO2_MASK;
break;
default:
return -EINVAL;
}
data = tps6507x_pmic_reg_read(tps, reg);
if (data < 0)
return data;
data &= ~mask;
data |= selector;
return tps6507x_pmic_reg_write(tps, reg, data);
}
static struct tps6507x_board *tps6507x_parse_dt_reg_data(
struct platform_device *pdev,
struct of_regulator_match **tps6507x_reg_matches)
{
struct tps6507x_board *tps_board;
struct device_node *np = pdev->dev.parent->of_node;
struct device_node *regulators;
struct of_regulator_match *matches;
static struct regulator_init_data *reg_data;
int idx = 0, count, ret;
tps_board = devm_kzalloc(&pdev->dev, sizeof(*tps_board),
GFP_KERNEL);
if (!tps_board) {
dev_err(&pdev->dev, "Failure to alloc pdata for regulators.\n");
return NULL;
}
regulators = of_find_node_by_name(np, "regulators");
if (!regulators) {
dev_err(&pdev->dev, "regulator node not found\n");
return NULL;
}
count = ARRAY_SIZE(tps6507x_matches);
matches = tps6507x_matches;
ret = of_regulator_match(&pdev->dev, regulators, matches, count);
if (ret < 0) {
dev_err(&pdev->dev, "Error parsing regulator init data: %d\n",
ret);
return NULL;
}
*tps6507x_reg_matches = matches;
reg_data = devm_kzalloc(&pdev->dev, (sizeof(struct regulator_init_data)
* TPS6507X_NUM_REGULATOR), GFP_KERNEL);
if (!reg_data) {
dev_err(&pdev->dev, "Failure to alloc init data for regulators.\n");
return NULL;
}
tps_board->tps6507x_pmic_init_data = reg_data;
for (idx = 0; idx < count; idx++) {
if (!matches[idx].init_data || !matches[idx].of_node)
continue;
memcpy(&reg_data[idx], matches[idx].init_data,
sizeof(struct regulator_init_data));
}
return tps_board;
}
static inline struct tps6507x_board *tps6507x_parse_dt_reg_data(
struct platform_device *pdev,
struct of_regulator_match **tps6507x_reg_matches)
{
*tps6507x_reg_matches = NULL;
return NULL;
}
static int tps6507x_pmic_probe(struct platform_device *pdev)
{
struct tps6507x_dev *tps6507x_dev = dev_get_drvdata(pdev->dev.parent);
struct tps_info *info = &tps6507x_pmic_regs[0];
struct regulator_config config = { };
struct regulator_init_data *init_data;
struct regulator_dev *rdev;
struct tps6507x_pmic *tps;
struct tps6507x_board *tps_board;
struct of_regulator_match *tps6507x_reg_matches = NULL;
int i;
int error;
unsigned int prop;
tps_board = dev_get_platdata(tps6507x_dev->dev);
if (!tps_board && tps6507x_dev->dev->of_node)
tps_board = tps6507x_parse_dt_reg_data(pdev,
&tps6507x_reg_matches);
if (!tps_board)
return -EINVAL;
init_data = tps_board->tps6507x_pmic_init_data;
if (!init_data)
return -EINVAL;
tps = devm_kzalloc(&pdev->dev, sizeof(*tps), GFP_KERNEL);
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
tps->desc[i].volt_table = info->table;
tps->desc[i].ops = &tps6507x_pmic_ops;
tps->desc[i].type = REGULATOR_VOLTAGE;
tps->desc[i].owner = THIS_MODULE;
config.dev = tps6507x_dev->dev;
config.init_data = init_data;
config.driver_data = tps;
if (tps6507x_reg_matches) {
error = of_property_read_u32(
tps6507x_reg_matches[i].of_node,
"ti,defdcdc_default", &prop);
if (!error)
tps->info[i]->defdcdc_default = prop;
config.of_node = tps6507x_reg_matches[i].of_node;
}
rdev = devm_regulator_register(&pdev->dev, &tps->desc[i],
&config);
if (IS_ERR(rdev)) {
dev_err(tps6507x_dev->dev,
"failed to register %s regulator\n",
pdev->name);
return PTR_ERR(rdev);
}
tps->rdev[i] = rdev;
}
tps6507x_dev->pmic = tps;
platform_set_drvdata(pdev, tps6507x_dev);
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
