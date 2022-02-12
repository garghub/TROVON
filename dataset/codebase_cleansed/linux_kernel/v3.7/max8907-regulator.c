static int max8907_regulator_parse_dt(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.parent->of_node;
struct device_node *regulators;
int ret;
if (!pdev->dev.parent->of_node)
return 0;
regulators = of_find_node_by_name(np, "regulators");
if (!regulators) {
dev_err(&pdev->dev, "regulators node not found\n");
return -EINVAL;
}
ret = of_regulator_match(pdev->dev.parent, regulators,
max8907_matches,
ARRAY_SIZE(max8907_matches));
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
static __devinit int max8907_regulator_probe(struct platform_device *pdev)
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
if (!pmic) {
dev_err(&pdev->dev, "Failed to alloc pmic\n");
return -ENOMEM;
}
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
pmic->rdev[i] = regulator_register(&pmic->desc[i], &config);
if (IS_ERR(pmic->rdev[i])) {
dev_err(&pdev->dev,
"failed to register %s regulator\n",
pmic->desc[i].name);
ret = PTR_ERR(pmic->rdev[i]);
goto err_unregister_regulator;
}
}
return 0;
err_unregister_regulator:
while (--i >= 0)
regulator_unregister(pmic->rdev[i]);
return ret;
}
static __devexit int max8907_regulator_remove(struct platform_device *pdev)
{
struct max8907_regulator *pmic = platform_get_drvdata(pdev);
int i;
for (i = 0; i < MAX8907_NUM_REGULATORS; i++)
regulator_unregister(pmic->rdev[i]);
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
