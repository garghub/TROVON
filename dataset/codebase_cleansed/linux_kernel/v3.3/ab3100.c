static int ab3100_enable_regulator(struct regulator_dev *reg)
{
struct ab3100_regulator *abreg = reg->reg_data;
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
struct ab3100_regulator *abreg = reg->reg_data;
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
struct ab3100_regulator *abreg = reg->reg_data;
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
static int ab3100_list_voltage_regulator(struct regulator_dev *reg,
unsigned selector)
{
struct ab3100_regulator *abreg = reg->reg_data;
if (selector >= abreg->voltages_len)
return -EINVAL;
return abreg->typ_voltages[selector];
}
static int ab3100_get_voltage_regulator(struct regulator_dev *reg)
{
struct ab3100_regulator *abreg = reg->reg_data;
u8 regval;
int err;
if (abreg->fixed_voltage)
return abreg->fixed_voltage;
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
if (regval >= abreg->voltages_len) {
dev_err(&reg->dev,
"regulator register %02x contains an illegal voltage setting\n",
abreg->regreg);
return -EINVAL;
}
return abreg->typ_voltages[regval];
}
static int ab3100_get_best_voltage_index(struct regulator_dev *reg,
int min_uV, int max_uV)
{
struct ab3100_regulator *abreg = reg->reg_data;
int i;
int bestmatch;
int bestindex;
bestmatch = INT_MAX;
bestindex = -1;
for (i = 0; i < abreg->voltages_len; i++) {
if (abreg->typ_voltages[i] <= max_uV &&
abreg->typ_voltages[i] >= min_uV &&
abreg->typ_voltages[i] < bestmatch) {
bestmatch = abreg->typ_voltages[i];
bestindex = i;
}
}
if (bestindex < 0) {
dev_warn(&reg->dev, "requested %d<=x<=%d uV, out of range!\n",
min_uV, max_uV);
return -EINVAL;
}
return bestindex;
}
static int ab3100_set_voltage_regulator(struct regulator_dev *reg,
int min_uV, int max_uV,
unsigned *selector)
{
struct ab3100_regulator *abreg = reg->reg_data;
u8 regval;
int err;
int bestindex;
bestindex = ab3100_get_best_voltage_index(reg, min_uV, max_uV);
if (bestindex < 0)
return bestindex;
*selector = bestindex;
err = abx500_get_register_interruptible(abreg->dev, 0,
abreg->regreg, &regval);
if (err) {
dev_warn(&reg->dev,
"failed to get regulator register %02x\n",
abreg->regreg);
return err;
}
regval &= ~0xE0;
regval |= (bestindex << 5);
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
struct ab3100_regulator *abreg = reg->reg_data;
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
bestindex = ab3100_get_best_voltage_index(reg, uV, uV);
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
struct ab3100_regulator *abreg = reg->reg_data;
return abreg->plfdata->external_voltage;
}
static int ab3100_enable_time_regulator(struct regulator_dev *reg)
{
struct ab3100_regulator *abreg = reg->reg_data;
switch (abreg->regreg) {
case AB3100_LDO_A:
case AB3100_LDO_C:
case AB3100_LDO_D:
case AB3100_LDO_E:
case AB3100_LDO_H:
case AB3100_LDO_K:
return 200;
case AB3100_LDO_F:
return 600;
case AB3100_LDO_G:
return 400;
case AB3100_BUCK:
return 1000;
default:
break;
}
return 0;
}
static int __devinit ab3100_regulators_probe(struct platform_device *pdev)
{
struct ab3100_platform_data *plfdata = pdev->dev.platform_data;
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
struct ab3100_regulator *reg = &ab3100_regulators[i];
struct regulator_dev *rdev;
reg->dev = &pdev->dev;
reg->plfdata = plfdata;
rdev = regulator_register(&ab3100_regulator_desc[i],
&pdev->dev,
&plfdata->reg_constraints[i],
reg, NULL);
if (IS_ERR(rdev)) {
err = PTR_ERR(rdev);
dev_err(&pdev->dev,
"%s: failed to register regulator %s err %d\n",
__func__, ab3100_regulator_desc[i].name,
err);
while (--i >= 0)
regulator_unregister(ab3100_regulators[i].rdev);
return err;
}
reg->rdev = rdev;
}
return 0;
}
static int __devexit ab3100_regulators_remove(struct platform_device *pdev)
{
int i;
for (i = 0; i < AB3100_NUM_REGULATORS; i++) {
struct ab3100_regulator *reg = &ab3100_regulators[i];
regulator_unregister(reg->rdev);
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
