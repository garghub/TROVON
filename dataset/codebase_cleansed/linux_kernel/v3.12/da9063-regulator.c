static int da9063_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
const struct da9063_regulator_info *rinfo = regl->info;
int n, tval;
for (n = 0; n < rinfo->n_current_limits; n++) {
tval = rinfo->current_limits[n];
if (tval >= min_uA && tval <= max_uA)
return regmap_field_write(regl->ilimit, n);
}
return -EINVAL;
}
static int da9063_get_current_limit(struct regulator_dev *rdev)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
const struct da9063_regulator_info *rinfo = regl->info;
unsigned int sel;
int ret;
ret = regmap_field_read(regl->ilimit, &sel);
if (ret < 0)
return ret;
if (sel >= rinfo->n_current_limits)
sel = rinfo->n_current_limits - 1;
return rinfo->current_limits[sel];
}
static int da9063_buck_set_mode(struct regulator_dev *rdev, unsigned mode)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
unsigned val;
switch (mode) {
case REGULATOR_MODE_FAST:
val = BUCK_MODE_SYNC;
break;
case REGULATOR_MODE_NORMAL:
val = BUCK_MODE_AUTO;
break;
case REGULATOR_MODE_STANDBY:
val = BUCK_MODE_SLEEP;
break;
default:
return -EINVAL;
}
return regmap_field_write(regl->mode, val);
}
static unsigned da9063_buck_get_mode(struct regulator_dev *rdev)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
struct regmap_field *field;
unsigned int val, mode = 0;
int ret;
ret = regmap_field_read(regl->mode, &val);
if (ret < 0)
return ret;
switch (val) {
default:
case BUCK_MODE_MANUAL:
mode = REGULATOR_MODE_FAST | REGULATOR_MODE_STANDBY;
break;
case BUCK_MODE_SLEEP:
return REGULATOR_MODE_STANDBY;
case BUCK_MODE_SYNC:
return REGULATOR_MODE_FAST;
case BUCK_MODE_AUTO:
return REGULATOR_MODE_NORMAL;
}
ret = regmap_field_read(regl->suspend, &val);
if (ret < 0)
return 0;
if (val)
field = regl->suspend_sleep;
else
field = regl->sleep;
ret = regmap_field_read(field, &val);
if (ret < 0)
return 0;
if (val)
mode &= REGULATOR_MODE_STANDBY;
else
mode &= REGULATOR_MODE_NORMAL | REGULATOR_MODE_FAST;
return mode;
}
static int da9063_ldo_set_mode(struct regulator_dev *rdev, unsigned mode)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
unsigned val;
switch (mode) {
case REGULATOR_MODE_NORMAL:
val = 0;
break;
case REGULATOR_MODE_STANDBY:
val = 1;
break;
default:
return -EINVAL;
}
return regmap_field_write(regl->sleep, val);
}
static unsigned da9063_ldo_get_mode(struct regulator_dev *rdev)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
struct regmap_field *field;
int ret, val;
ret = regmap_field_read(regl->suspend, &val);
if (ret < 0)
return 0;
if (val)
field = regl->suspend_sleep;
else
field = regl->sleep;
ret = regmap_field_read(field, &val);
if (ret < 0)
return 0;
if (val)
return REGULATOR_MODE_STANDBY;
else
return REGULATOR_MODE_NORMAL;
}
static int da9063_buck_get_status(struct regulator_dev *rdev)
{
int ret = regulator_is_enabled_regmap(rdev);
if (ret == 0) {
ret = REGULATOR_STATUS_OFF;
} else if (ret > 0) {
ret = da9063_buck_get_mode(rdev);
if (ret > 0)
ret = regulator_mode_to_status(ret);
else if (ret == 0)
ret = -EIO;
}
return ret;
}
static int da9063_ldo_get_status(struct regulator_dev *rdev)
{
int ret = regulator_is_enabled_regmap(rdev);
if (ret == 0) {
ret = REGULATOR_STATUS_OFF;
} else if (ret > 0) {
ret = da9063_ldo_get_mode(rdev);
if (ret > 0)
ret = regulator_mode_to_status(ret);
else if (ret == 0)
ret = -EIO;
}
return ret;
}
static int da9063_set_suspend_voltage(struct regulator_dev *rdev, int uV)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
const struct da9063_regulator_info *rinfo = regl->info;
int ret, sel;
sel = regulator_map_voltage_linear(rdev, uV, uV);
if (sel < 0)
return -EINVAL;
sel <<= ffs(rdev->desc->vsel_mask) - 1;
ret = regmap_update_bits(regl->hw->regmap, rinfo->suspend_vsel_reg,
rdev->desc->vsel_mask, sel);
return ret;
}
static int da9063_suspend_enable(struct regulator_dev *rdev)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
return regmap_field_write(regl->suspend, 1);
}
static int da9063_suspend_disable(struct regulator_dev *rdev)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
return regmap_field_write(regl->suspend, 0);
}
static int da9063_buck_set_suspend_mode(struct regulator_dev *rdev, unsigned mode)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
int val;
switch (mode) {
case REGULATOR_MODE_FAST:
val = BUCK_MODE_SYNC;
break;
case REGULATOR_MODE_NORMAL:
val = BUCK_MODE_AUTO;
break;
case REGULATOR_MODE_STANDBY:
val = BUCK_MODE_SLEEP;
break;
default:
return -EINVAL;
}
return regmap_field_write(regl->mode, val);
}
static int da9063_ldo_set_suspend_mode(struct regulator_dev *rdev, unsigned mode)
{
struct da9063_regulator *regl = rdev_get_drvdata(rdev);
unsigned val;
switch (mode) {
case REGULATOR_MODE_NORMAL:
val = 0;
break;
case REGULATOR_MODE_STANDBY:
val = 1;
break;
default:
return -EINVAL;
}
return regmap_field_write(regl->suspend_sleep, val);
}
static irqreturn_t da9063_ldo_lim_event(int irq, void *data)
{
struct da9063_regulators *regulators = data;
struct da9063 *hw = regulators->regulator[0].hw;
struct da9063_regulator *regl;
int bits, i , ret;
ret = regmap_read(hw->regmap, DA9063_REG_STATUS_D, &bits);
if (ret < 0)
return IRQ_NONE;
for (i = regulators->n_regulators - 1; i >= 0; i--) {
regl = &regulators->regulator[i];
if (regl->info->oc_event.reg != DA9063_REG_STATUS_D)
continue;
if (BIT(regl->info->oc_event.lsb) & bits)
regulator_notifier_call_chain(regl->rdev,
REGULATOR_EVENT_OVER_CURRENT, NULL);
}
return IRQ_HANDLED;
}
static const struct regulator_init_data *da9063_get_regulator_initdata(
const struct da9063_regulators_pdata *regl_pdata, int id)
{
int i;
for (i = 0; i < regl_pdata->n_regulators; i++) {
if (id == regl_pdata->regulator_data[i].id)
return regl_pdata->regulator_data[i].initdata;
}
return NULL;
}
static struct da9063_regulators_pdata *da9063_parse_regulators_dt(
struct platform_device *pdev,
struct of_regulator_match **da9063_reg_matches)
{
struct da9063_regulators_pdata *pdata;
struct da9063_regulator_data *rdata;
struct device_node *node;
int i, n, num;
node = of_find_node_by_name(pdev->dev.parent->of_node, "regulators");
if (!node) {
dev_err(&pdev->dev, "Regulators device node not found\n");
return ERR_PTR(-ENODEV);
}
num = of_regulator_match(&pdev->dev, node, da9063_matches,
ARRAY_SIZE(da9063_matches));
if (num < 0) {
dev_err(&pdev->dev, "Failed to match regulators\n");
return ERR_PTR(-EINVAL);
}
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
pdata->regulator_data = devm_kzalloc(&pdev->dev,
num * sizeof(*pdata->regulator_data),
GFP_KERNEL);
if (!pdata->regulator_data)
return ERR_PTR(-ENOMEM);
pdata->n_regulators = num;
n = 0;
for (i = 0; i < ARRAY_SIZE(da9063_matches); i++) {
if (!da9063_matches[i].init_data)
continue;
rdata = &pdata->regulator_data[n];
rdata->id = i;
rdata->initdata = da9063_matches[i].init_data;
n++;
};
*da9063_reg_matches = da9063_matches;
return pdata;
}
static struct da9063_regulators_pdata *da9063_parse_regulators_dt(
struct platform_device *pdev,
struct of_regulator_match **da9063_reg_matches)
{
da9063_reg_matches = NULL;
return ERR_PTR(-ENODEV);
}
static int da9063_regulator_probe(struct platform_device *pdev)
{
struct da9063 *da9063 = dev_get_drvdata(pdev->dev.parent);
struct da9063_pdata *da9063_pdata = dev_get_platdata(da9063->dev);
struct of_regulator_match *da9063_reg_matches;
struct da9063_regulators_pdata *regl_pdata;
const struct da9063_dev_model *model;
struct da9063_regulators *regulators;
struct da9063_regulator *regl;
struct regulator_config config;
bool bcores_merged, bmem_bio_merged;
int id, irq, n, n_regulators, ret, val;
size_t size;
regl_pdata = da9063_pdata ? da9063_pdata->regulators_pdata : NULL;
if (!regl_pdata)
regl_pdata = da9063_parse_regulators_dt(pdev,
&da9063_reg_matches);
if (IS_ERR(regl_pdata) || regl_pdata->n_regulators == 0) {
dev_err(&pdev->dev,
"No regulators defined for the platform\n");
return PTR_ERR(regl_pdata);
}
for (model = regulators_models; model->regulator_info; model++) {
if (model->dev_model == da9063->model)
break;
}
if (!model->regulator_info) {
dev_err(&pdev->dev, "Chip model not recognised (%u)\n",
da9063->model);
return -ENODEV;
}
ret = regmap_read(da9063->regmap, DA9063_REG_CONFIG_H, &val);
if (ret < 0) {
dev_err(&pdev->dev,
"Error while reading BUCKs configuration\n");
return -EIO;
}
bcores_merged = val & DA9063_BCORE_MERGE;
bmem_bio_merged = val & DA9063_BUCK_MERGE;
n_regulators = model->n_regulators;
if (bcores_merged)
n_regulators -= 2;
else
n_regulators--;
if (bmem_bio_merged)
n_regulators -= 2;
else
n_regulators--;
size = sizeof(struct da9063_regulators) +
n_regulators * sizeof(struct da9063_regulator);
regulators = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
if (!regulators) {
dev_err(&pdev->dev, "No memory for regulators\n");
return -ENOMEM;
}
regulators->n_regulators = n_regulators;
platform_set_drvdata(pdev, regulators);
n = 0;
id = 0;
while (n < regulators->n_regulators) {
switch (id) {
case DA9063_ID_BCORE1:
case DA9063_ID_BCORE2:
if (bcores_merged) {
id++;
continue;
}
break;
case DA9063_ID_BMEM:
case DA9063_ID_BIO:
if (bmem_bio_merged) {
id++;
continue;
}
break;
case DA9063_ID_BCORES_MERGED:
if (!bcores_merged) {
id++;
continue;
}
break;
case DA9063_ID_BMEM_BIO_MERGED:
if (!bmem_bio_merged) {
id++;
continue;
}
break;
}
regl = &regulators->regulator[n];
regl->hw = da9063;
regl->info = &model->regulator_info[id];
regl->desc = regl->info->desc;
regl->desc.type = REGULATOR_VOLTAGE;
regl->desc.owner = THIS_MODULE;
if (regl->info->mode.reg)
regl->mode = devm_regmap_field_alloc(&pdev->dev,
da9063->regmap, regl->info->mode);
if (regl->info->suspend.reg)
regl->suspend = devm_regmap_field_alloc(&pdev->dev,
da9063->regmap, regl->info->suspend);
if (regl->info->sleep.reg)
regl->sleep = devm_regmap_field_alloc(&pdev->dev,
da9063->regmap, regl->info->sleep);
if (regl->info->suspend_sleep.reg)
regl->suspend_sleep = devm_regmap_field_alloc(&pdev->dev,
da9063->regmap, regl->info->suspend_sleep);
if (regl->info->ilimit.reg)
regl->ilimit = devm_regmap_field_alloc(&pdev->dev,
da9063->regmap, regl->info->ilimit);
memset(&config, 0, sizeof(config));
config.dev = &pdev->dev;
config.init_data = da9063_get_regulator_initdata(regl_pdata, id);
config.driver_data = regl;
if (da9063_reg_matches)
config.of_node = da9063_reg_matches[id].of_node;
config.regmap = da9063->regmap;
regl->rdev = regulator_register(&regl->desc, &config);
if (IS_ERR(regl->rdev)) {
dev_err(&pdev->dev,
"Failed to register %s regulator\n",
regl->desc.name);
ret = PTR_ERR(regl->rdev);
goto err;
}
id++;
n++;
}
irq = platform_get_irq_byname(pdev, "LDO_LIM");
if (irq < 0) {
ret = irq;
dev_err(&pdev->dev, "Failed to get IRQ.\n");
goto err;
}
regulators->irq_ldo_lim = regmap_irq_get_virq(da9063->regmap_irq, irq);
if (regulators->irq_ldo_lim >= 0) {
ret = request_threaded_irq(regulators->irq_ldo_lim,
NULL, da9063_ldo_lim_event,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"LDO_LIM", regulators);
if (ret) {
dev_err(&pdev->dev,
"Failed to request LDO_LIM IRQ.\n");
regulators->irq_ldo_lim = -ENXIO;
}
}
return 0;
err:
while (--n >= 0)
regulator_unregister(regulators->regulator[n].rdev);
return ret;
}
static int da9063_regulator_remove(struct platform_device *pdev)
{
struct da9063_regulators *regulators = platform_get_drvdata(pdev);
struct da9063_regulator *regl;
free_irq(regulators->irq_ldo_lim, regulators);
free_irq(regulators->irq_uvov, regulators);
for (regl = &regulators->regulator[regulators->n_regulators - 1];
regl >= &regulators->regulator[0]; regl--)
regulator_unregister(regl->rdev);
return 0;
}
static int __init da9063_regulator_init(void)
{
return platform_driver_register(&da9063_regulator_driver);
}
static void __exit da9063_regulator_cleanup(void)
{
platform_driver_unregister(&da9063_regulator_driver);
}
