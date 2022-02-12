static int rc5t583_regulator_enable_time(struct regulator_dev *rdev)
{
struct rc5t583_regulator *reg = rdev_get_drvdata(rdev);
int vsel = regulator_get_voltage_sel_regmap(rdev);
int curr_uV = regulator_list_voltage_linear(rdev, vsel);
return DIV_ROUND_UP(curr_uV, reg->reg_info->enable_uv_per_us);
}
static int rc5t583_set_voltage_time_sel(struct regulator_dev *rdev,
unsigned int old_selector, unsigned int new_selector)
{
struct rc5t583_regulator *reg = rdev_get_drvdata(rdev);
int old_uV, new_uV;
old_uV = regulator_list_voltage_linear(rdev, old_selector);
if (old_uV < 0)
return old_uV;
new_uV = regulator_list_voltage_linear(rdev, new_selector);
if (new_uV < 0)
return new_uV;
return DIV_ROUND_UP(abs(old_uV - new_uV),
reg->reg_info->change_uv_per_us);
}
static int __devinit rc5t583_regulator_probe(struct platform_device *pdev)
{
struct rc5t583 *rc5t583 = dev_get_drvdata(pdev->dev.parent);
struct rc5t583_platform_data *pdata = dev_get_platdata(rc5t583->dev);
struct regulator_init_data *reg_data;
struct regulator_config config = { };
struct rc5t583_regulator *reg = NULL;
struct rc5t583_regulator *regs;
struct regulator_dev *rdev;
struct rc5t583_regulator_info *ri;
int ret;
int id;
if (!pdata) {
dev_err(&pdev->dev, "No platform data, exiting...\n");
return -ENODEV;
}
regs = devm_kzalloc(&pdev->dev, RC5T583_REGULATOR_MAX *
sizeof(struct rc5t583_regulator), GFP_KERNEL);
if (!regs) {
dev_err(&pdev->dev, "Memory allocation failed exiting..\n");
return -ENOMEM;
}
for (id = 0; id < RC5T583_REGULATOR_MAX; ++id) {
reg_data = pdata->reg_init_data[id];
if (!reg_data)
continue;
reg = &regs[id];
ri = &rc5t583_reg_info[id];
reg->reg_info = ri;
reg->mfd = rc5t583;
reg->dev = &pdev->dev;
if (ri->deepsleep_id == RC5T583_DS_NONE)
goto skip_ext_pwr_config;
ret = rc5t583_ext_power_req_config(rc5t583->dev,
ri->deepsleep_id,
pdata->regulator_ext_pwr_control[id],
pdata->regulator_deepsleep_slot[id]);
if (ret < 0)
dev_warn(&pdev->dev,
"Failed to configure ext control %d\n", id);
skip_ext_pwr_config:
config.dev = &pdev->dev;
config.init_data = reg_data;
config.driver_data = reg;
config.regmap = rc5t583->regmap;
rdev = regulator_register(&ri->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "Failed to register regulator %s\n",
ri->desc.name);
ret = PTR_ERR(rdev);
goto clean_exit;
}
reg->rdev = rdev;
}
platform_set_drvdata(pdev, regs);
return 0;
clean_exit:
while (--id >= 0)
regulator_unregister(regs[id].rdev);
return ret;
}
static int __devexit rc5t583_regulator_remove(struct platform_device *pdev)
{
struct rc5t583_regulator *regs = platform_get_drvdata(pdev);
int id;
for (id = 0; id < RC5T583_REGULATOR_MAX; ++id)
regulator_unregister(regs[id].rdev);
return 0;
}
static int __init rc5t583_regulator_init(void)
{
return platform_driver_register(&rc5t583_regulator_driver);
}
static void __exit rc5t583_regulator_exit(void)
{
platform_driver_unregister(&rc5t583_regulator_driver);
}
