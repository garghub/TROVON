static int ab3100_enable_regulator(struct regulator_dev *reg)
{
struct ab3100_regulator *abreg = rdev_get_drvdata(reg);
int err;
u8 regval;
err = abx500_get_register_interruptible(abreg->dev, 0, abreg->regreg,
&regval);
if (err) {
dev_warn(&reg->dev, "failed to get regid %d value\n",
abreg->regreg);
return err;
}
if (regval & AB3100_REG_ON_MASK)
return 0;
regval |= AB3100_REG_ON_MASK;
err = abx500_set_register_interruptible(abreg->dev, 0, abreg->regreg,
regval);
if (err) {
dev_warn(&reg->dev, "failed to set regid %d value\n",
abreg->regreg);
return err;
}
return 0;
}
static int ab3100_disable_regulator(struct regulator_dev *reg)
{
struct ab3100_regulator *abreg = rdev_get_drvdata(reg);
int err;
u8 regval;
pr_info("Called ab3100_disable_regulator\n");
if (abreg->regreg == AB3100_LDO_D) {
dev_info(&reg->dev, "disabling LDO D - shut down system\n");
return abx500_set_register_interruptible(abreg->dev, 0,
AB3100_LDO_D, 0x00U);
}
err = abx500_get_register_interruptible(abreg->dev, 0, abreg->regreg,
&regval);
if (err) {
dev_err(&reg->dev, "unable to get register 0x%x\n",
abreg->regreg);
return err;
}
regval &= ~AB3100_REG_ON_MASK;
return abx500_set_register_interruptible(abreg->dev, 0, abreg->regreg,
regval);
}
static int ab3100_is_enabled_regulator(struct regulator_dev *reg)
{
struct ab3100_regulator *abreg = rdev_get_drvdata(reg);
u8 regval;
int err;
err = abx500_get_register_interruptible(abreg->dev, 0, abreg->regreg,
&regval);
if (err) {
dev_err(&reg->dev, "unable to get register 0x%x\n",
abreg->regreg);
return err;
}
return regval & AB3100_REG_ON_MASK;
}
static int ab3100_get_voltage_regulator(struct regulator_dev *reg)
{
struct ab3100_regulator *abreg = rdev_get_drvdata(reg);
u8 regval;
int err;
err = abx500_get_register_interruptible(abreg->dev, 0,
abreg->regreg, &regval);
if (err) {
dev_warn(&reg->dev,
"failed to get regulator value in register %02x\n",
abreg->regreg);
return err;
}
regval &= 0xE0;
regval >>= 5;
if (regval >= reg->desc->n_voltages) {
dev_err(&reg->dev,
"regulator register %02x contains an illegal voltage setting\n",
abreg->regreg);
return -EINVAL;
}
return reg->desc->volt_table[regval];
}
static int ab3100_set_voltage_regulator_sel(struct regulator_dev *reg,
unsigned selector)
{
struct ab3100_regulator *abreg = rdev_get_drvdata(reg);
u8 regval;
int err;
err = abx500_get_register_interruptible(abreg->dev, 0,
abreg->regreg, &regval);
if (err) {
dev_warn(&reg->dev,
"failed to get regulator register %02x\n",
abreg->regreg);
return err;
}
regval &= ~0xE0;
regval |= (selector << 5);
err = abx500_set_register_interruptible(abreg->dev, 0,
abreg->regreg, regval);
if (err)
dev_warn(&reg->dev, "failed to set regulator register %02x\n",
abreg->regreg);
return err;
}
static int ab3100_set_suspend_voltage_regulator(struct regulator_dev *reg,
int uV)
{
struct ab3100_regulator *abreg = rdev_get_drvdata(reg);
u8 regval;
int err;
int bestindex;
u8 targetreg;
if (abreg->regreg == AB3100_LDO_E)
targetreg = AB3100_LDO_E_SLEEP;
else if (abreg->regreg == AB3100_BUCK)
targetreg = AB3100_BUCK_SLEEP;
else
return -EINVAL;
bestindex = regulator_map_voltage_iterate(reg, uV, uV);
err = abx500_get_register_interruptible(abreg->dev, 0,
targetreg, &regval);
if (err) {
dev_warn(&reg->dev,
"failed to get regulator register %02x\n",
targetreg);
return err;
}
regval &= ~0xE0;
regval |= (bestindex << 5);
err = abx500_set_register_interruptible(abreg->dev, 0,
targetreg, regval);
if (err)
dev_warn(&reg->dev, "failed to set regulator register %02x\n",
abreg->regreg);
return err;
}
static int ab3100_get_voltage_regulator_external(struct regulator_dev *reg)
{
struct ab3100_regulator *abreg = rdev_get_drvdata(reg);
if (abreg->plfdata)
return abreg->plfdata->external_voltage;
else
return 0;
}
static int ab3100_regulator_register(struct platform_device *pdev,
struct ab3100_platform_data *plfdata,
struct regulator_init_data *init_data,
struct device_node *np,
unsigned long id)
{
struct regulator_desc *desc;
struct ab3100_regulator *reg;
struct regulator_dev *rdev;
struct regulator_config config = { };
int err, i;
for (i = 0; i < AB3100_NUM_REGULATORS; i++) {
desc = &ab3100_regulator_desc[i];
if (desc->id == id)
break;
}
if (desc->id != id)
return -ENODEV;
reg = &ab3100_regulators[i];
reg->dev = &pdev->dev;
if (plfdata) {
reg->plfdata = plfdata;
config.init_data = &plfdata->reg_constraints[i];
} else if (np) {
config.of_node = np;
config.init_data = init_data;
}
config.dev = &pdev->dev;
config.driver_data = reg;
rdev = devm_regulator_register(&pdev->dev, desc, &config);
if (IS_ERR(rdev)) {
err = PTR_ERR(rdev);
dev_err(&pdev->dev,
"%s: failed to register regulator %s err %d\n",
__func__, desc->name,
err);
return err;
}
reg->rdev = rdev;
return 0;
}
static int ab3100_regulators_remove(struct platform_device *pdev)
{
int i;
for (i = 0; i < AB3100_NUM_REGULATORS; i++) {
struct ab3100_regulator *reg = &ab3100_regulators[i];
reg->rdev = NULL;
}
return 0;
}
static int
ab3100_regulator_of_probe(struct platform_device *pdev, struct device_node *np)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(ab3100_reg_init_order); i++) {
err = abx500_set_register_interruptible(&pdev->dev, 0,
ab3100_reg_init_order[i],
ab3100_reg_initvals[i]);
if (err) {
dev_err(&pdev->dev, "regulator initialization failed with error %d\n",
err);
return err;
}
}
for (i = 0; i < ARRAY_SIZE(ab3100_regulator_matches); i++) {
err = ab3100_regulator_register(
pdev, NULL, ab3100_regulator_matches[i].init_data,
ab3100_regulator_matches[i].of_node,
(unsigned long)ab3100_regulator_matches[i].driver_data);
if (err) {
ab3100_regulators_remove(pdev);
return err;
}
}
return 0;
}
static int ab3100_regulators_probe(struct platform_device *pdev)
{
struct ab3100_platform_data *plfdata = dev_get_platdata(&pdev->dev);
struct device_node *np = pdev->dev.of_node;
int err = 0;
u8 data;
int i;
err = abx500_get_register_interruptible(&pdev->dev, 0,
AB3100_LDO_D, &data);
if (err) {
dev_err(&pdev->dev, "could not read initial status of LDO_D\n");
return err;
}
if (data & 0x10)
dev_notice(&pdev->dev,
"chip is already in active mode (Warm start)\n");
else
dev_notice(&pdev->dev,
"chip is in inactive mode (Cold start)\n");
if (np) {
err = of_regulator_match(&pdev->dev, np,
ab3100_regulator_matches,
ARRAY_SIZE(ab3100_regulator_matches));
if (err < 0) {
dev_err(&pdev->dev,
"Error parsing regulator init data: %d\n", err);
return err;
}
return ab3100_regulator_of_probe(pdev, np);
}
for (i = 0; i < ARRAY_SIZE(ab3100_reg_init_order); i++) {
err = abx500_set_register_interruptible(&pdev->dev, 0,
ab3100_reg_init_order[i],
plfdata->reg_initvals[i]);
if (err) {
dev_err(&pdev->dev, "regulator initialization failed with error %d\n",
err);
return err;
}
}
for (i = 0; i < AB3100_NUM_REGULATORS; i++) {
struct regulator_desc *desc = &ab3100_regulator_desc[i];
err = ab3100_regulator_register(pdev, plfdata, NULL, NULL,
desc->id);
if (err) {
ab3100_regulators_remove(pdev);
return err;
}
}
return 0;
}
static __init int ab3100_regulators_init(void)
{
return platform_driver_register(&ab3100_regulators_driver);
}
static __exit void ab3100_regulators_exit(void)
{
platform_driver_unregister(&ab3100_regulators_driver);
}
