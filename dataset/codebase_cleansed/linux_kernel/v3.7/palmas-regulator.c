static int palmas_smps_read(struct palmas *palmas, unsigned int reg,
unsigned int *dest)
{
unsigned int addr;
addr = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE, reg);
return regmap_read(palmas->regmap[REGULATOR_SLAVE], addr, dest);
}
static int palmas_smps_write(struct palmas *palmas, unsigned int reg,
unsigned int value)
{
unsigned int addr;
addr = PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE, reg);
return regmap_write(palmas->regmap[REGULATOR_SLAVE], addr, value);
}
static int palmas_ldo_read(struct palmas *palmas, unsigned int reg,
unsigned int *dest)
{
unsigned int addr;
addr = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE, reg);
return regmap_read(palmas->regmap[REGULATOR_SLAVE], addr, dest);
}
static int palmas_ldo_write(struct palmas *palmas, unsigned int reg,
unsigned int value)
{
unsigned int addr;
addr = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE, reg);
return regmap_write(palmas->regmap[REGULATOR_SLAVE], addr, value);
}
static int palmas_is_enabled_smps(struct regulator_dev *dev)
{
struct palmas_pmic *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev);
unsigned int reg;
palmas_smps_read(pmic->palmas, palmas_regs_info[id].ctrl_addr, &reg);
reg &= PALMAS_SMPS12_CTRL_STATUS_MASK;
reg >>= PALMAS_SMPS12_CTRL_STATUS_SHIFT;
return !!(reg);
}
static int palmas_enable_smps(struct regulator_dev *dev)
{
struct palmas_pmic *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev);
unsigned int reg;
palmas_smps_read(pmic->palmas, palmas_regs_info[id].ctrl_addr, &reg);
reg &= ~PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;
reg |= SMPS_CTRL_MODE_ON;
palmas_smps_write(pmic->palmas, palmas_regs_info[id].ctrl_addr, reg);
return 0;
}
static int palmas_disable_smps(struct regulator_dev *dev)
{
struct palmas_pmic *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev);
unsigned int reg;
palmas_smps_read(pmic->palmas, palmas_regs_info[id].ctrl_addr, &reg);
reg &= ~PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;
palmas_smps_write(pmic->palmas, palmas_regs_info[id].ctrl_addr, reg);
return 0;
}
static int palmas_set_mode_smps(struct regulator_dev *dev, unsigned int mode)
{
struct palmas_pmic *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev);
unsigned int reg;
palmas_smps_read(pmic->palmas, palmas_regs_info[id].ctrl_addr, &reg);
reg &= ~PALMAS_SMPS12_CTRL_MODE_ACTIVE_MASK;
switch (mode) {
case REGULATOR_MODE_NORMAL:
reg |= SMPS_CTRL_MODE_ON;
break;
case REGULATOR_MODE_IDLE:
reg |= SMPS_CTRL_MODE_ECO;
break;
case REGULATOR_MODE_FAST:
reg |= SMPS_CTRL_MODE_PWM;
break;
default:
return -EINVAL;
}
palmas_smps_write(pmic->palmas, palmas_regs_info[id].ctrl_addr, reg);
return 0;
}
static unsigned int palmas_get_mode_smps(struct regulator_dev *dev)
{
struct palmas_pmic *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev);
unsigned int reg;
palmas_smps_read(pmic->palmas, palmas_regs_info[id].ctrl_addr, &reg);
reg &= PALMAS_SMPS12_CTRL_STATUS_MASK;
reg >>= PALMAS_SMPS12_CTRL_STATUS_SHIFT;
switch (reg) {
case SMPS_CTRL_MODE_ON:
return REGULATOR_MODE_NORMAL;
case SMPS_CTRL_MODE_ECO:
return REGULATOR_MODE_IDLE;
case SMPS_CTRL_MODE_PWM:
return REGULATOR_MODE_FAST;
}
return 0;
}
static int palmas_list_voltage_smps(struct regulator_dev *dev,
unsigned selector)
{
struct palmas_pmic *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev);
int mult = 1;
if (!selector)
return 0;
if (pmic->range[id])
mult = 2;
return (490000 + (selector * 10000)) * mult;
}
static int palmas_get_voltage_smps_sel(struct regulator_dev *dev)
{
struct palmas_pmic *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev);
int selector;
unsigned int reg;
unsigned int addr;
addr = palmas_regs_info[id].vsel_addr;
palmas_smps_read(pmic->palmas, addr, &reg);
selector = reg & PALMAS_SMPS12_VOLTAGE_VSEL_MASK;
if ((selector > 0) && (selector < 6))
selector = 6;
if (!selector)
selector = 5;
if (selector > 121)
selector = 121;
selector -= 5;
return selector;
}
static int palmas_set_voltage_smps_sel(struct regulator_dev *dev,
unsigned selector)
{
struct palmas_pmic *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev);
unsigned int reg = 0;
unsigned int addr;
addr = palmas_regs_info[id].vsel_addr;
if (pmic->range[id])
reg |= PALMAS_SMPS12_VOLTAGE_RANGE;
if (selector)
reg |= selector + 5;
palmas_smps_write(pmic->palmas, addr, reg);
return 0;
}
static int palmas_map_voltage_smps(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
struct palmas_pmic *pmic = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
int ret, voltage;
if (min_uV == 0)
return 0;
if (pmic->range[id]) {
if (min_uV < 1000000)
min_uV = 1000000;
ret = DIV_ROUND_UP(min_uV - 1000000, 20000) + 1;
} else {
if (min_uV < 500000)
min_uV = 500000;
ret = DIV_ROUND_UP(min_uV - 500000, 10000) + 1;
}
voltage = palmas_list_voltage_smps(rdev, ret);
if (voltage < min_uV || voltage > max_uV)
return -EINVAL;
return ret;
}
static int palmas_is_enabled_ldo(struct regulator_dev *dev)
{
struct palmas_pmic *pmic = rdev_get_drvdata(dev);
int id = rdev_get_id(dev);
unsigned int reg;
palmas_ldo_read(pmic->palmas, palmas_regs_info[id].ctrl_addr, &reg);
reg &= PALMAS_LDO1_CTRL_STATUS;
return !!(reg);
}
static int palmas_list_voltage_ldo(struct regulator_dev *dev,
unsigned selector)
{
if (!selector)
return 0;
return 850000 + (selector * 50000);
}
static int palmas_map_voltage_ldo(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
int ret, voltage;
if (min_uV == 0)
return 0;
if (min_uV < 900000)
min_uV = 900000;
ret = DIV_ROUND_UP(min_uV - 900000, 50000) + 1;
voltage = palmas_list_voltage_ldo(rdev, ret);
if (voltage < min_uV || voltage > max_uV)
return -EINVAL;
return ret;
}
static int palmas_smps_init(struct palmas *palmas, int id,
struct palmas_reg_init *reg_init)
{
unsigned int reg;
unsigned int addr;
int ret;
addr = palmas_regs_info[id].ctrl_addr;
ret = palmas_smps_read(palmas, addr, &reg);
if (ret)
return ret;
switch (id) {
case PALMAS_REG_SMPS10:
if (reg_init->mode_sleep) {
reg &= ~PALMAS_SMPS10_CTRL_MODE_SLEEP_MASK;
reg |= reg_init->mode_sleep <<
PALMAS_SMPS10_CTRL_MODE_SLEEP_SHIFT;
}
break;
default:
if (reg_init->warm_reset)
reg |= PALMAS_SMPS12_CTRL_WR_S;
if (reg_init->roof_floor)
reg |= PALMAS_SMPS12_CTRL_ROOF_FLOOR_EN;
if (reg_init->mode_sleep) {
reg &= ~PALMAS_SMPS12_CTRL_MODE_SLEEP_MASK;
reg |= reg_init->mode_sleep <<
PALMAS_SMPS12_CTRL_MODE_SLEEP_SHIFT;
}
}
ret = palmas_smps_write(palmas, addr, reg);
if (ret)
return ret;
if (palmas_regs_info[id].tstep_addr && reg_init->tstep) {
addr = palmas_regs_info[id].tstep_addr;
reg = reg_init->tstep & PALMAS_SMPS12_TSTEP_TSTEP_MASK;
ret = palmas_smps_write(palmas, addr, reg);
if (ret)
return ret;
}
if (palmas_regs_info[id].vsel_addr && reg_init->vsel) {
addr = palmas_regs_info[id].vsel_addr;
reg = reg_init->vsel;
ret = palmas_smps_write(palmas, addr, reg);
if (ret)
return ret;
}
return 0;
}
static int palmas_ldo_init(struct palmas *palmas, int id,
struct palmas_reg_init *reg_init)
{
unsigned int reg;
unsigned int addr;
int ret;
addr = palmas_regs_info[id].ctrl_addr;
ret = palmas_ldo_read(palmas, addr, &reg);
if (ret)
return ret;
if (reg_init->warm_reset)
reg |= PALMAS_LDO1_CTRL_WR_S;
if (reg_init->mode_sleep)
reg |= PALMAS_LDO1_CTRL_MODE_SLEEP;
ret = palmas_ldo_write(palmas, addr, reg);
if (ret)
return ret;
return 0;
}
static void __devinit palmas_dt_to_pdata(struct device *dev,
struct device_node *node,
struct palmas_pmic_platform_data *pdata)
{
struct device_node *regulators;
u32 prop;
int idx, ret;
regulators = of_find_node_by_name(node, "regulators");
if (!regulators) {
dev_info(dev, "regulator node not found\n");
return;
}
ret = of_regulator_match(dev, regulators, palmas_matches,
PALMAS_NUM_REGS);
if (ret < 0) {
dev_err(dev, "Error parsing regulator init data: %d\n", ret);
return;
}
for (idx = 0; idx < PALMAS_NUM_REGS; idx++) {
if (!palmas_matches[idx].init_data ||
!palmas_matches[idx].of_node)
continue;
pdata->reg_data[idx] = palmas_matches[idx].init_data;
pdata->reg_init[idx] = devm_kzalloc(dev,
sizeof(struct palmas_reg_init), GFP_KERNEL);
ret = of_property_read_u32(palmas_matches[idx].of_node,
"ti,warm_reset", &prop);
if (!ret)
pdata->reg_init[idx]->warm_reset = prop;
ret = of_property_read_u32(palmas_matches[idx].of_node,
"ti,roof_floor", &prop);
if (!ret)
pdata->reg_init[idx]->roof_floor = prop;
ret = of_property_read_u32(palmas_matches[idx].of_node,
"ti,mode_sleep", &prop);
if (!ret)
pdata->reg_init[idx]->mode_sleep = prop;
ret = of_property_read_u32(palmas_matches[idx].of_node,
"ti,warm_reset", &prop);
if (!ret)
pdata->reg_init[idx]->warm_reset = prop;
ret = of_property_read_u32(palmas_matches[idx].of_node,
"ti,tstep", &prop);
if (!ret)
pdata->reg_init[idx]->tstep = prop;
ret = of_property_read_u32(palmas_matches[idx].of_node,
"ti,vsel", &prop);
if (!ret)
pdata->reg_init[idx]->vsel = prop;
}
ret = of_property_read_u32(node, "ti,ldo6_vibrator", &prop);
if (!ret)
pdata->ldo6_vibrator = prop;
}
static __devinit int palmas_probe(struct platform_device *pdev)
{
struct palmas *palmas = dev_get_drvdata(pdev->dev.parent);
struct palmas_pmic_platform_data *pdata = pdev->dev.platform_data;
struct device_node *node = pdev->dev.of_node;
struct regulator_dev *rdev;
struct regulator_config config = { };
struct palmas_pmic *pmic;
struct palmas_reg_init *reg_init;
int id = 0, ret;
unsigned int addr, reg;
if (node && !pdata) {
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
palmas_dt_to_pdata(&pdev->dev, node, pdata);
}
pmic = devm_kzalloc(&pdev->dev, sizeof(*pmic), GFP_KERNEL);
if (!pmic)
return -ENOMEM;
pmic->dev = &pdev->dev;
pmic->palmas = palmas;
palmas->pmic = pmic;
platform_set_drvdata(pdev, pmic);
ret = palmas_smps_read(palmas, PALMAS_SMPS_CTRL, &reg);
if (ret)
return ret;
if (reg & PALMAS_SMPS_CTRL_SMPS12_SMPS123_EN)
pmic->smps123 = 1;
if (reg & PALMAS_SMPS_CTRL_SMPS45_SMPS457_EN)
pmic->smps457 = 1;
config.regmap = palmas->regmap[REGULATOR_SLAVE];
config.dev = &pdev->dev;
config.driver_data = pmic;
for (id = 0; id < PALMAS_REG_LDO1; id++) {
switch (id) {
case PALMAS_REG_SMPS12:
case PALMAS_REG_SMPS3:
if (pmic->smps123)
continue;
break;
case PALMAS_REG_SMPS123:
if (!pmic->smps123)
continue;
break;
case PALMAS_REG_SMPS45:
case PALMAS_REG_SMPS7:
if (pmic->smps457)
continue;
break;
case PALMAS_REG_SMPS457:
if (!pmic->smps457)
continue;
}
pmic->desc[id].name = palmas_regs_info[id].name;
pmic->desc[id].id = id;
switch (id) {
case PALMAS_REG_SMPS10:
pmic->desc[id].n_voltages = PALMAS_SMPS10_NUM_VOLTAGES;
pmic->desc[id].ops = &palmas_ops_smps10;
pmic->desc[id].vsel_reg =
PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE,
PALMAS_SMPS10_CTRL);
pmic->desc[id].vsel_mask = SMPS10_VSEL;
pmic->desc[id].enable_reg =
PALMAS_BASE_TO_REG(PALMAS_SMPS_BASE,
PALMAS_SMPS10_STATUS);
pmic->desc[id].enable_mask = SMPS10_BOOST_EN;
pmic->desc[id].min_uV = 3750000;
pmic->desc[id].uV_step = 1250000;
break;
default:
pmic->desc[id].ops = &palmas_ops_smps;
pmic->desc[id].n_voltages = PALMAS_SMPS_NUM_VOLTAGES;
}
pmic->desc[id].type = REGULATOR_VOLTAGE;
pmic->desc[id].owner = THIS_MODULE;
if (pdata) {
reg_init = pdata->reg_init[id];
if (reg_init) {
ret = palmas_smps_init(palmas, id, reg_init);
if (ret)
goto err_unregister_regulator;
}
}
if (id != PALMAS_REG_SMPS10) {
addr = palmas_regs_info[id].vsel_addr;
ret = palmas_smps_read(pmic->palmas, addr, &reg);
if (ret)
goto err_unregister_regulator;
if (reg & PALMAS_SMPS12_VOLTAGE_RANGE)
pmic->range[id] = 1;
}
if (pdata)
config.init_data = pdata->reg_data[id];
else
config.init_data = NULL;
config.of_node = palmas_matches[id].of_node;
rdev = regulator_register(&pmic->desc[id], &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev,
"failed to register %s regulator\n",
pdev->name);
ret = PTR_ERR(rdev);
goto err_unregister_regulator;
}
pmic->rdev[id] = rdev;
}
for (; id < PALMAS_NUM_REGS; id++) {
pmic->desc[id].name = palmas_regs_info[id].name;
pmic->desc[id].id = id;
pmic->desc[id].n_voltages = PALMAS_LDO_NUM_VOLTAGES;
pmic->desc[id].ops = &palmas_ops_ldo;
pmic->desc[id].type = REGULATOR_VOLTAGE;
pmic->desc[id].owner = THIS_MODULE;
pmic->desc[id].vsel_reg = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE,
palmas_regs_info[id].vsel_addr);
pmic->desc[id].vsel_mask = PALMAS_LDO1_VOLTAGE_VSEL_MASK;
pmic->desc[id].enable_reg = PALMAS_BASE_TO_REG(PALMAS_LDO_BASE,
palmas_regs_info[id].ctrl_addr);
pmic->desc[id].enable_mask = PALMAS_LDO1_CTRL_MODE_ACTIVE;
if (pdata)
config.init_data = pdata->reg_data[id];
else
config.init_data = NULL;
config.of_node = palmas_matches[id].of_node;
rdev = regulator_register(&pmic->desc[id], &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev,
"failed to register %s regulator\n",
pdev->name);
ret = PTR_ERR(rdev);
goto err_unregister_regulator;
}
pmic->rdev[id] = rdev;
if (pdata) {
reg_init = pdata->reg_init[id];
if (reg_init) {
ret = palmas_ldo_init(palmas, id, reg_init);
if (ret) {
regulator_unregister(pmic->rdev[id]);
goto err_unregister_regulator;
}
}
}
}
return 0;
err_unregister_regulator:
while (--id >= 0)
regulator_unregister(pmic->rdev[id]);
return ret;
}
static int __devexit palmas_remove(struct platform_device *pdev)
{
struct palmas_pmic *pmic = platform_get_drvdata(pdev);
int id;
for (id = 0; id < PALMAS_NUM_REGS; id++)
regulator_unregister(pmic->rdev[id]);
return 0;
}
static int __init palmas_init(void)
{
return platform_driver_register(&palmas_driver);
}
static void __exit palmas_exit(void)
{
platform_driver_unregister(&palmas_driver);
}
