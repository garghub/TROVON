static inline int tps65910_read(struct tps65910_reg *pmic, u8 reg)
{
u8 val;
int err;
err = pmic->mfd->read(pmic->mfd, reg, 1, &val);
if (err)
return err;
return val;
}
static inline int tps65910_write(struct tps65910_reg *pmic, u8 reg, u8 val)
{
return pmic->mfd->write(pmic->mfd, reg, 1, &val);
}
static int tps65910_modify_bits(struct tps65910_reg *pmic, u8 reg,
u8 set_mask, u8 clear_mask)
{
int err, data;
mutex_lock(&pmic->mutex);
data = tps65910_read(pmic, reg);
if (data < 0) {
dev_err(pmic->mfd->dev, "Read from reg 0x%x failed\n", reg);
err = data;
goto out;
}
data &= ~clear_mask;
data |= set_mask;
err = tps65910_write(pmic, reg, data);
if (err)
dev_err(pmic->mfd->dev, "Write for reg 0x%x failed\n", reg);
out:
mutex_unlock(&pmic->mutex);
return err;
}
static int tps65910_reg_read(struct tps65910_reg *pmic, u8 reg)
{
int data;
mutex_lock(&pmic->mutex);
data = tps65910_read(pmic, reg);
if (data < 0)
dev_err(pmic->mfd->dev, "Read from reg 0x%x failed\n", reg);
mutex_unlock(&pmic->mutex);
return data;
}
static int tps65910_reg_write(struct tps65910_reg *pmic, u8 reg, u8 val)
{
int err;
mutex_lock(&pmic->mutex);
err = tps65910_write(pmic, reg, val);
if (err < 0)
dev_err(pmic->mfd->dev, "Write for reg 0x%x failed\n", reg);
mutex_unlock(&pmic->mutex);
return err;
}
static int tps65910_get_ctrl_register(int id)
{
switch (id) {
case TPS65910_REG_VRTC:
return TPS65910_VRTC;
case TPS65910_REG_VIO:
return TPS65910_VIO;
case TPS65910_REG_VDD1:
return TPS65910_VDD1;
case TPS65910_REG_VDD2:
return TPS65910_VDD2;
case TPS65910_REG_VDD3:
return TPS65910_VDD3;
case TPS65910_REG_VDIG1:
return TPS65910_VDIG1;
case TPS65910_REG_VDIG2:
return TPS65910_VDIG2;
case TPS65910_REG_VPLL:
return TPS65910_VPLL;
case TPS65910_REG_VDAC:
return TPS65910_VDAC;
case TPS65910_REG_VAUX1:
return TPS65910_VAUX1;
case TPS65910_REG_VAUX2:
return TPS65910_VAUX2;
case TPS65910_REG_VAUX33:
return TPS65910_VAUX33;
case TPS65910_REG_VMMC:
return TPS65910_VMMC;
default:
return -EINVAL;
}
}
static int tps65911_get_ctrl_register(int id)
{
switch (id) {
case TPS65910_REG_VRTC:
return TPS65910_VRTC;
case TPS65910_REG_VIO:
return TPS65910_VIO;
case TPS65910_REG_VDD1:
return TPS65910_VDD1;
case TPS65910_REG_VDD2:
return TPS65910_VDD2;
case TPS65911_REG_VDDCTRL:
return TPS65911_VDDCTRL;
case TPS65911_REG_LDO1:
return TPS65911_LDO1;
case TPS65911_REG_LDO2:
return TPS65911_LDO2;
case TPS65911_REG_LDO3:
return TPS65911_LDO3;
case TPS65911_REG_LDO4:
return TPS65911_LDO4;
case TPS65911_REG_LDO5:
return TPS65911_LDO5;
case TPS65911_REG_LDO6:
return TPS65911_LDO6;
case TPS65911_REG_LDO7:
return TPS65911_LDO7;
case TPS65911_REG_LDO8:
return TPS65911_LDO8;
default:
return -EINVAL;
}
}
static int tps65910_is_enabled(struct regulator_dev *dev)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int reg, value, id = rdev_get_id(dev);
reg = pmic->get_ctrl_reg(id);
if (reg < 0)
return reg;
value = tps65910_reg_read(pmic, reg);
if (value < 0)
return value;
return value & TPS65910_SUPPLY_STATE_ENABLED;
}
static int tps65910_enable(struct regulator_dev *dev)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
struct tps65910 *mfd = pmic->mfd;
int reg, id = rdev_get_id(dev);
reg = pmic->get_ctrl_reg(id);
if (reg < 0)
return reg;
return tps65910_set_bits(mfd, reg, TPS65910_SUPPLY_STATE_ENABLED);
}
static int tps65910_disable(struct regulator_dev *dev)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
struct tps65910 *mfd = pmic->mfd;
int reg, id = rdev_get_id(dev);
reg = pmic->get_ctrl_reg(id);
if (reg < 0)
return reg;
return tps65910_clear_bits(mfd, reg, TPS65910_SUPPLY_STATE_ENABLED);
}
static int tps65910_set_mode(struct regulator_dev *dev, unsigned int mode)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
struct tps65910 *mfd = pmic->mfd;
int reg, value, id = rdev_get_id(dev);
reg = pmic->get_ctrl_reg(id);
if (reg < 0)
return reg;
switch (mode) {
case REGULATOR_MODE_NORMAL:
return tps65910_modify_bits(pmic, reg, LDO_ST_ON_BIT,
LDO_ST_MODE_BIT);
case REGULATOR_MODE_IDLE:
value = LDO_ST_ON_BIT | LDO_ST_MODE_BIT;
return tps65910_set_bits(mfd, reg, value);
case REGULATOR_MODE_STANDBY:
return tps65910_clear_bits(mfd, reg, LDO_ST_ON_BIT);
}
return -EINVAL;
}
static unsigned int tps65910_get_mode(struct regulator_dev *dev)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int reg, value, id = rdev_get_id(dev);
reg = pmic->get_ctrl_reg(id);
if (reg < 0)
return reg;
value = tps65910_reg_read(pmic, reg);
if (value < 0)
return value;
if (value & LDO_ST_ON_BIT)
return REGULATOR_MODE_STANDBY;
else if (value & LDO_ST_MODE_BIT)
return REGULATOR_MODE_IDLE;
else
return REGULATOR_MODE_NORMAL;
}
static int tps65910_get_voltage_dcdc(struct regulator_dev *dev)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev), voltage = 0;
int opvsel = 0, srvsel = 0, vselmax = 0, mult = 0, sr = 0;
switch (id) {
case TPS65910_REG_VDD1:
opvsel = tps65910_reg_read(pmic, TPS65910_VDD1_OP);
mult = tps65910_reg_read(pmic, TPS65910_VDD1);
mult = (mult & VDD1_VGAIN_SEL_MASK) >> VDD1_VGAIN_SEL_SHIFT;
srvsel = tps65910_reg_read(pmic, TPS65910_VDD1_SR);
sr = opvsel & VDD1_OP_CMD_MASK;
opvsel &= VDD1_OP_SEL_MASK;
srvsel &= VDD1_SR_SEL_MASK;
vselmax = 75;
break;
case TPS65910_REG_VDD2:
opvsel = tps65910_reg_read(pmic, TPS65910_VDD2_OP);
mult = tps65910_reg_read(pmic, TPS65910_VDD2);
mult = (mult & VDD2_VGAIN_SEL_MASK) >> VDD2_VGAIN_SEL_SHIFT;
srvsel = tps65910_reg_read(pmic, TPS65910_VDD2_SR);
sr = opvsel & VDD2_OP_CMD_MASK;
opvsel &= VDD2_OP_SEL_MASK;
srvsel &= VDD2_SR_SEL_MASK;
vselmax = 75;
break;
case TPS65911_REG_VDDCTRL:
opvsel = tps65910_reg_read(pmic, TPS65911_VDDCTRL_OP);
srvsel = tps65910_reg_read(pmic, TPS65911_VDDCTRL_SR);
sr = opvsel & VDDCTRL_OP_CMD_MASK;
opvsel &= VDDCTRL_OP_SEL_MASK;
srvsel &= VDDCTRL_SR_SEL_MASK;
vselmax = 64;
break;
}
if (!mult)
mult=1;
if (sr) {
if (srvsel < 3)
srvsel = 3;
if (srvsel > vselmax)
srvsel = vselmax;
srvsel -= 3;
voltage = (srvsel * VDD1_2_OFFSET + VDD1_2_MIN_VOLT) * 100;
} else {
if (opvsel < 3)
opvsel = 3;
if (opvsel > vselmax)
opvsel = vselmax;
opvsel -= 3;
voltage = (opvsel * VDD1_2_OFFSET + VDD1_2_MIN_VOLT) * 100;
}
voltage *= mult;
return voltage;
}
static int tps65910_get_voltage(struct regulator_dev *dev)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int reg, value, id = rdev_get_id(dev), voltage = 0;
reg = pmic->get_ctrl_reg(id);
if (reg < 0)
return reg;
value = tps65910_reg_read(pmic, reg);
if (value < 0)
return value;
switch (id) {
case TPS65910_REG_VIO:
case TPS65910_REG_VDIG1:
case TPS65910_REG_VDIG2:
case TPS65910_REG_VPLL:
case TPS65910_REG_VDAC:
case TPS65910_REG_VAUX1:
case TPS65910_REG_VAUX2:
case TPS65910_REG_VAUX33:
case TPS65910_REG_VMMC:
value &= LDO_SEL_MASK;
value >>= LDO_SEL_SHIFT;
break;
default:
return -EINVAL;
}
voltage = pmic->info[id]->table[value] * 1000;
return voltage;
}
static int tps65910_get_voltage_vdd3(struct regulator_dev *dev)
{
return 5 * 1000 * 1000;
}
static int tps65911_get_voltage(struct regulator_dev *dev)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int step_mv, id = rdev_get_id(dev);
u8 value, reg;
reg = pmic->get_ctrl_reg(id);
value = tps65910_reg_read(pmic, reg);
switch (id) {
case TPS65911_REG_LDO1:
case TPS65911_REG_LDO2:
case TPS65911_REG_LDO4:
value &= LDO1_SEL_MASK;
value >>= LDO_SEL_SHIFT;
if (value < 5)
value = 0;
else
value -= 4;
step_mv = 50;
break;
case TPS65911_REG_LDO3:
case TPS65911_REG_LDO5:
case TPS65911_REG_LDO6:
case TPS65911_REG_LDO7:
case TPS65911_REG_LDO8:
value &= LDO3_SEL_MASK;
value >>= LDO_SEL_SHIFT;
if (value < 3)
value = 0;
else
value -= 2;
step_mv = 100;
break;
case TPS65910_REG_VIO:
return pmic->info[id]->table[value] * 1000;
break;
default:
return -EINVAL;
}
return (LDO_MIN_VOLT + value * step_mv) * 1000;
}
static int tps65910_set_voltage_dcdc(struct regulator_dev *dev,
unsigned selector)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev), vsel;
int dcdc_mult = 0;
switch (id) {
case TPS65910_REG_VDD1:
dcdc_mult = (selector / VDD1_2_NUM_VOLTS) + 1;
if (dcdc_mult == 1)
dcdc_mult--;
vsel = (selector % VDD1_2_NUM_VOLTS) + 3;
tps65910_modify_bits(pmic, TPS65910_VDD1,
(dcdc_mult << VDD1_VGAIN_SEL_SHIFT),
VDD1_VGAIN_SEL_MASK);
tps65910_reg_write(pmic, TPS65910_VDD1_OP, vsel);
break;
case TPS65910_REG_VDD2:
dcdc_mult = (selector / VDD1_2_NUM_VOLTS) + 1;
if (dcdc_mult == 1)
dcdc_mult--;
vsel = (selector % VDD1_2_NUM_VOLTS) + 3;
tps65910_modify_bits(pmic, TPS65910_VDD2,
(dcdc_mult << VDD2_VGAIN_SEL_SHIFT),
VDD1_VGAIN_SEL_MASK);
tps65910_reg_write(pmic, TPS65910_VDD2_OP, vsel);
break;
case TPS65911_REG_VDDCTRL:
vsel = selector;
tps65910_reg_write(pmic, TPS65911_VDDCTRL_OP, vsel);
}
return 0;
}
static int tps65910_set_voltage(struct regulator_dev *dev, unsigned selector)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int reg, id = rdev_get_id(dev);
reg = pmic->get_ctrl_reg(id);
if (reg < 0)
return reg;
switch (id) {
case TPS65910_REG_VIO:
case TPS65910_REG_VDIG1:
case TPS65910_REG_VDIG2:
case TPS65910_REG_VPLL:
case TPS65910_REG_VDAC:
case TPS65910_REG_VAUX1:
case TPS65910_REG_VAUX2:
case TPS65910_REG_VAUX33:
case TPS65910_REG_VMMC:
return tps65910_modify_bits(pmic, reg,
(selector << LDO_SEL_SHIFT), LDO_SEL_MASK);
}
return -EINVAL;
}
static int tps65911_set_voltage(struct regulator_dev *dev, unsigned selector)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int reg, id = rdev_get_id(dev);
reg = pmic->get_ctrl_reg(id);
if (reg < 0)
return reg;
switch (id) {
case TPS65911_REG_LDO1:
case TPS65911_REG_LDO2:
case TPS65911_REG_LDO4:
return tps65910_modify_bits(pmic, reg,
(selector << LDO_SEL_SHIFT), LDO1_SEL_MASK);
case TPS65911_REG_LDO3:
case TPS65911_REG_LDO5:
case TPS65911_REG_LDO6:
case TPS65911_REG_LDO7:
case TPS65911_REG_LDO8:
case TPS65910_REG_VIO:
return tps65910_modify_bits(pmic, reg,
(selector << LDO_SEL_SHIFT), LDO3_SEL_MASK);
}
return -EINVAL;
}
static int tps65910_list_voltage_dcdc(struct regulator_dev *dev,
unsigned selector)
{
int volt, mult = 1, id = rdev_get_id(dev);
switch (id) {
case TPS65910_REG_VDD1:
case TPS65910_REG_VDD2:
mult = (selector / VDD1_2_NUM_VOLTS) + 1;
volt = VDD1_2_MIN_VOLT +
(selector % VDD1_2_NUM_VOLTS) * VDD1_2_OFFSET;
break;
case TPS65911_REG_VDDCTRL:
volt = VDDCTRL_MIN_VOLT + (selector * VDDCTRL_OFFSET);
break;
default:
BUG();
return -EINVAL;
}
return volt * 100 * mult;
}
static int tps65910_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev), voltage;
if (id < TPS65910_REG_VIO || id > TPS65910_REG_VMMC)
return -EINVAL;
if (selector >= pmic->info[id]->table_len)
return -EINVAL;
else
voltage = pmic->info[id]->table[selector] * 1000;
return voltage;
}
static int tps65911_list_voltage(struct regulator_dev *dev, unsigned selector)
{
struct tps65910_reg *pmic = rdev_get_drvdata(dev);
int step_mv = 0, id = rdev_get_id(dev);
switch(id) {
case TPS65911_REG_LDO1:
case TPS65911_REG_LDO2:
case TPS65911_REG_LDO4:
if (selector < 5)
selector = 0;
else
selector -= 4;
step_mv = 50;
break;
case TPS65911_REG_LDO3:
case TPS65911_REG_LDO5:
case TPS65911_REG_LDO6:
case TPS65911_REG_LDO7:
case TPS65911_REG_LDO8:
if (selector < 3)
selector = 0;
else
selector -= 2;
step_mv = 100;
break;
case TPS65910_REG_VIO:
return pmic->info[id]->table[selector] * 1000;
default:
return -EINVAL;
}
return (LDO_MIN_VOLT + selector * step_mv) * 1000;
}
static __devinit int tps65910_probe(struct platform_device *pdev)
{
struct tps65910 *tps65910 = dev_get_drvdata(pdev->dev.parent);
struct tps_info *info;
struct regulator_init_data *reg_data;
struct regulator_dev *rdev;
struct tps65910_reg *pmic;
struct tps65910_board *pmic_plat_data;
int i, err;
pmic_plat_data = dev_get_platdata(tps65910->dev);
if (!pmic_plat_data)
return -EINVAL;
reg_data = pmic_plat_data->tps65910_pmic_init_data;
pmic = kzalloc(sizeof(*pmic), GFP_KERNEL);
if (!pmic)
return -ENOMEM;
mutex_init(&pmic->mutex);
pmic->mfd = tps65910;
platform_set_drvdata(pdev, pmic);
tps65910_set_bits(pmic->mfd, TPS65910_DEVCTRL,
DEVCTRL_SR_CTL_I2C_SEL_MASK);
switch(tps65910_chip_id(tps65910)) {
case TPS65910:
pmic->get_ctrl_reg = &tps65910_get_ctrl_register;
pmic->num_regulators = ARRAY_SIZE(tps65910_regs);
info = tps65910_regs;
break;
case TPS65911:
pmic->get_ctrl_reg = &tps65911_get_ctrl_register;
pmic->num_regulators = ARRAY_SIZE(tps65911_regs);
info = tps65911_regs;
break;
default:
pr_err("Invalid tps chip version\n");
kfree(pmic);
return -ENODEV;
}
pmic->desc = kcalloc(pmic->num_regulators,
sizeof(struct regulator_desc), GFP_KERNEL);
if (!pmic->desc) {
err = -ENOMEM;
goto err_free_pmic;
}
pmic->info = kcalloc(pmic->num_regulators,
sizeof(struct tps_info *), GFP_KERNEL);
if (!pmic->info) {
err = -ENOMEM;
goto err_free_desc;
}
pmic->rdev = kcalloc(pmic->num_regulators,
sizeof(struct regulator_dev *), GFP_KERNEL);
if (!pmic->rdev) {
err = -ENOMEM;
goto err_free_info;
}
for (i = 0; i < pmic->num_regulators; i++, info++, reg_data++) {
pmic->info[i] = info;
pmic->desc[i].name = info->name;
pmic->desc[i].id = i;
pmic->desc[i].n_voltages = info->table_len;
if (i == TPS65910_REG_VDD1 || i == TPS65910_REG_VDD2) {
pmic->desc[i].ops = &tps65910_ops_dcdc;
} else if (i == TPS65910_REG_VDD3) {
if (tps65910_chip_id(tps65910) == TPS65910)
pmic->desc[i].ops = &tps65910_ops_vdd3;
else
pmic->desc[i].ops = &tps65910_ops_dcdc;
} else {
if (tps65910_chip_id(tps65910) == TPS65910)
pmic->desc[i].ops = &tps65910_ops;
else
pmic->desc[i].ops = &tps65911_ops;
}
pmic->desc[i].type = REGULATOR_VOLTAGE;
pmic->desc[i].owner = THIS_MODULE;
rdev = regulator_register(&pmic->desc[i],
tps65910->dev, reg_data, pmic);
if (IS_ERR(rdev)) {
dev_err(tps65910->dev,
"failed to register %s regulator\n",
pdev->name);
err = PTR_ERR(rdev);
goto err_unregister_regulator;
}
pmic->rdev[i] = rdev;
}
return 0;
err_unregister_regulator:
while (--i >= 0)
regulator_unregister(pmic->rdev[i]);
kfree(pmic->rdev);
err_free_info:
kfree(pmic->info);
err_free_desc:
kfree(pmic->desc);
err_free_pmic:
kfree(pmic);
return err;
}
static int __devexit tps65910_remove(struct platform_device *pdev)
{
struct tps65910_reg *pmic = platform_get_drvdata(pdev);
int i;
for (i = 0; i < pmic->num_regulators; i++)
regulator_unregister(pmic->rdev[i]);
kfree(pmic->rdev);
kfree(pmic->info);
kfree(pmic->desc);
kfree(pmic);
return 0;
}
static int __init tps65910_init(void)
{
return platform_driver_register(&tps65910_driver);
}
static void __exit tps65910_cleanup(void)
{
platform_driver_unregister(&tps65910_driver);
}
