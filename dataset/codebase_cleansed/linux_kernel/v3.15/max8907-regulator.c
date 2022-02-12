static int max8907_regulator_parse_dt(struct platform_device *pdev)
{
struct device_node *np, *regulators;
int ret;
np = of_node_get(pdev->dev.parent->of_node);
if (!np)
return 0;
regulators = of_get_child_by_name(np, "regulators");
if (!regulators) {
dev_err(&pdev->dev, "regulators node not found\n");
return -EINVAL;
}
ret = of_regulator_match(&pdev->dev, regulators, max8907_matches,
ARRAY_SIZE(max8907_matches));
of_node_put(regulators);
if (ret < 0) {
dev_err(&pdev->dev, "Error parsing regulator init data: %d\n",
ret);
return ret;
}
return 0;
}
static inline struct regulator_init_data *match_init_data(int index)
{
return max8907_matches[index].init_data;
}
static inline struct device_node *match_of_node(int index)
{
return max8907_matches[index].of_node;
}
static int max8907_regulator_parse_dt(struct platform_device *pdev)
{
return 0;
}
static inline struct regulator_init_data *match_init_data(int index)
{
return NULL;
}
static inline struct device_node *match_of_node(int index)
{
return NULL;
}
static int max8907_regulator_probe(struct platform_device *pdev)
{
struct max8907 *max8907 = dev_get_drvdata(pdev->dev.parent);
struct max8907_platform_data *pdata = dev_get_platdata(max8907->dev);
int ret;
struct max8907_regulator *pmic;
unsigned int val;
int i;
struct regulator_config config = {};
struct regulator_init_data *idata;
const char *mbatt_rail_name = NULL;
ret = max8907_regulator_parse_dt(pdev);
if (ret)
return ret;
pmic = devm_kzalloc(&pdev->dev, sizeof(*pmic), GFP_KERNEL);
if (!pmic)
return -ENOMEM;
platform_set_drvdata(pdev, pmic);
memcpy(pmic->desc, max8907_regulators, sizeof(pmic->desc));
regmap_read(max8907->regmap_gen, MAX8907_REG_II2RR, &val);
if ((val & MAX8907_II2RR_VERSION_MASK) ==
MAX8907_II2RR_VERSION_REV_B) {
pmic->desc[MAX8907_SD1].min_uV = 637500;
pmic->desc[MAX8907_SD1].uV_step = 12500;
pmic->desc[MAX8907_SD1].n_voltages =
(1425000 - 637500) / 12500 + 1;
}
for (i = 0; i < MAX8907_NUM_REGULATORS; i++) {
struct regulator_dev *rdev;
config.dev = pdev->dev.parent;
if (pdata)
idata = pdata->init_data[i];
else
idata = match_init_data(i);
config.init_data = idata;
config.driver_data = pmic;
config.regmap = max8907->regmap_gen;
config.of_node = match_of_node(i);
switch (pmic->desc[i].id) {
case MAX8907_MBATT:
if (idata && idata->constraints.name)
mbatt_rail_name = idata->constraints.name;
else
mbatt_rail_name = pmic->desc[i].name;
break;
case MAX8907_BBAT:
case MAX8907_SDBY:
case MAX8907_VRTC:
idata->supply_regulator = mbatt_rail_name;
break;
}
if (pmic->desc[i].ops == &max8907_ldo_ops) {
regmap_read(config.regmap, pmic->desc[i].enable_reg,
&val);
if ((val & MAX8907_MASK_LDO_SEQ) !=
MAX8907_MASK_LDO_SEQ)
pmic->desc[i].ops = &max8907_ldo_hwctl_ops;
} else if (pmic->desc[i].ops == &max8907_out5v_ops) {
regmap_read(config.regmap, pmic->desc[i].enable_reg,
&val);
if ((val & (MAX8907_MASK_OUT5V_VINEN |
MAX8907_MASK_OUT5V_ENSRC)) !=
MAX8907_MASK_OUT5V_ENSRC)
pmic->desc[i].ops = &max8907_out5v_hwctl_ops;
}
rdev = devm_regulator_register(&pdev->dev,
&pmic->desc[i], &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev,
"failed to register %s regulator\n",
pmic->desc[i].name);
return PTR_ERR(rdev);
}
}
return 0;
}
static int __init max8907_regulator_init(void)
{
return platform_driver_register(&max8907_regulator_driver);
}
static void __exit max8907_reg_exit(void)
{
platform_driver_unregister(&max8907_regulator_driver);
}
