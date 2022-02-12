static int bcm590xx_get_vsel_register(int id)
{
if (BCM590XX_REG_IS_LDO(id))
return BCM590XX_RFLDOCTRL + id;
else if (BCM590XX_REG_IS_GPLDO(id))
return BCM590XX_GPLDO1CTRL + id;
else
return BCM590XX_CSRVOUT1 + (id - BCM590XX_REG_CSR) * 3;
}
static int bcm590xx_get_enable_register(int id)
{
int reg = 0;
if (BCM590XX_REG_IS_LDO(id))
reg = BCM590XX_RFLDOPMCTRL1 + id * 2;
else if (BCM590XX_REG_IS_GPLDO(id))
reg = BCM590XX_GPLDO1PMCTRL1 + id * 2;
else
switch (id) {
case BCM590XX_REG_CSR:
reg = BCM590XX_CSRPMCTRL1;
break;
case BCM590XX_REG_IOSR1:
reg = BCM590XX_IOSR1PMCTRL1;
break;
case BCM590XX_REG_IOSR2:
reg = BCM590XX_IOSR2PMCTRL1;
break;
case BCM590XX_REG_MSR:
reg = BCM590XX_MSRPMCTRL1;
break;
case BCM590XX_REG_SDSR1:
reg = BCM590XX_SDSR1PMCTRL1;
break;
case BCM590XX_REG_SDSR2:
reg = BCM590XX_SDSR2PMCTRL1;
break;
case BCM590XX_REG_VBUS:
reg = BCM590XX_OTG_CTRL;
}
return reg;
}
static struct bcm590xx_board *bcm590xx_parse_dt_reg_data(
struct platform_device *pdev,
struct of_regulator_match **bcm590xx_reg_matches)
{
struct bcm590xx_board *data;
struct device_node *np = pdev->dev.parent->of_node;
struct device_node *regulators;
struct of_regulator_match *matches = bcm590xx_matches;
int count = ARRAY_SIZE(bcm590xx_matches);
int idx = 0;
int ret;
if (!np) {
dev_err(&pdev->dev, "of node not found\n");
return NULL;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return NULL;
np = of_node_get(np);
regulators = of_get_child_by_name(np, "regulators");
if (!regulators) {
dev_warn(&pdev->dev, "regulator node not found\n");
return NULL;
}
ret = of_regulator_match(&pdev->dev, regulators, matches, count);
of_node_put(regulators);
if (ret < 0) {
dev_err(&pdev->dev, "Error parsing regulator init data: %d\n",
ret);
return NULL;
}
*bcm590xx_reg_matches = matches;
for (idx = 0; idx < count; idx++) {
if (!matches[idx].init_data || !matches[idx].of_node)
continue;
data->bcm590xx_pmu_init_data[idx] = matches[idx].init_data;
}
return data;
}
static int bcm590xx_probe(struct platform_device *pdev)
{
struct bcm590xx *bcm590xx = dev_get_drvdata(pdev->dev.parent);
struct bcm590xx_board *pmu_data = NULL;
struct bcm590xx_reg *pmu;
struct regulator_config config = { };
struct bcm590xx_info *info;
struct regulator_init_data *reg_data;
struct regulator_dev *rdev;
struct of_regulator_match *bcm590xx_reg_matches = NULL;
int i;
pmu_data = bcm590xx_parse_dt_reg_data(pdev,
&bcm590xx_reg_matches);
pmu = devm_kzalloc(&pdev->dev, sizeof(*pmu), GFP_KERNEL);
if (!pmu)
return -ENOMEM;
pmu->mfd = bcm590xx;
platform_set_drvdata(pdev, pmu);
pmu->desc = devm_kzalloc(&pdev->dev, BCM590XX_NUM_REGS *
sizeof(struct regulator_desc), GFP_KERNEL);
if (!pmu->desc)
return -ENOMEM;
info = bcm590xx_regs;
for (i = 0; i < BCM590XX_NUM_REGS; i++, info++) {
if (pmu_data)
reg_data = pmu_data->bcm590xx_pmu_init_data[i];
else
reg_data = NULL;
pmu->desc[i].name = info->name;
pmu->desc[i].supply_name = info->vin_name;
pmu->desc[i].id = i;
pmu->desc[i].volt_table = info->volt_table;
pmu->desc[i].n_voltages = info->n_voltages;
pmu->desc[i].linear_ranges = info->linear_ranges;
pmu->desc[i].n_linear_ranges = info->n_linear_ranges;
if ((BCM590XX_REG_IS_LDO(i)) || (BCM590XX_REG_IS_GPLDO(i))) {
pmu->desc[i].ops = &bcm590xx_ops_ldo;
pmu->desc[i].vsel_mask = BCM590XX_LDO_VSEL_MASK;
} else if (BCM590XX_REG_IS_VBUS(i))
pmu->desc[i].ops = &bcm590xx_ops_vbus;
else {
pmu->desc[i].ops = &bcm590xx_ops_dcdc;
pmu->desc[i].vsel_mask = BCM590XX_SR_VSEL_MASK;
}
if (BCM590XX_REG_IS_VBUS(i))
pmu->desc[i].enable_mask = BCM590XX_VBUS_ENABLE;
else {
pmu->desc[i].vsel_reg = bcm590xx_get_vsel_register(i);
pmu->desc[i].enable_is_inverted = true;
pmu->desc[i].enable_mask = BCM590XX_REG_ENABLE;
}
pmu->desc[i].enable_reg = bcm590xx_get_enable_register(i);
pmu->desc[i].type = REGULATOR_VOLTAGE;
pmu->desc[i].owner = THIS_MODULE;
config.dev = bcm590xx->dev;
config.init_data = reg_data;
config.driver_data = pmu;
if (BCM590XX_REG_IS_GPLDO(i) || BCM590XX_REG_IS_VBUS(i))
config.regmap = bcm590xx->regmap_sec;
else
config.regmap = bcm590xx->regmap_pri;
if (bcm590xx_reg_matches)
config.of_node = bcm590xx_reg_matches[i].of_node;
rdev = devm_regulator_register(&pdev->dev, &pmu->desc[i],
&config);
if (IS_ERR(rdev)) {
dev_err(bcm590xx->dev,
"failed to register %s regulator\n",
pdev->name);
return PTR_ERR(rdev);
}
}
return 0;
}
