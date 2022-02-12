static int aat2870_ldo_list_voltage(struct regulator_dev *rdev,
unsigned selector)
{
struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
return ri->voltages[selector];
}
static int aat2870_ldo_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
struct aat2870_data *aat2870 = ri->aat2870;
return aat2870->update(aat2870, ri->voltage_addr, ri->voltage_mask,
selector << ri->voltage_shift);
}
static int aat2870_ldo_get_voltage_sel(struct regulator_dev *rdev)
{
struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
struct aat2870_data *aat2870 = ri->aat2870;
u8 val;
int ret;
ret = aat2870->read(aat2870, ri->voltage_addr, &val);
if (ret)
return ret;
return (val & ri->voltage_mask) >> ri->voltage_shift;
}
static int aat2870_ldo_enable(struct regulator_dev *rdev)
{
struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
struct aat2870_data *aat2870 = ri->aat2870;
return aat2870->update(aat2870, ri->enable_addr, ri->enable_mask,
ri->enable_mask);
}
static int aat2870_ldo_disable(struct regulator_dev *rdev)
{
struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
struct aat2870_data *aat2870 = ri->aat2870;
return aat2870->update(aat2870, ri->enable_addr, ri->enable_mask, 0);
}
static int aat2870_ldo_is_enabled(struct regulator_dev *rdev)
{
struct aat2870_regulator *ri = rdev_get_drvdata(rdev);
struct aat2870_data *aat2870 = ri->aat2870;
u8 val;
int ret;
ret = aat2870->read(aat2870, ri->enable_addr, &val);
if (ret)
return ret;
return val & ri->enable_mask ? 1 : 0;
}
static struct aat2870_regulator *aat2870_get_regulator(int id)
{
struct aat2870_regulator *ri = NULL;
int i;
for (i = 0; i < ARRAY_SIZE(aat2870_regulators); i++) {
ri = &aat2870_regulators[i];
if (ri->desc.id == id)
break;
}
if (i == ARRAY_SIZE(aat2870_regulators))
return NULL;
ri->enable_addr = AAT2870_LDO_EN;
ri->enable_shift = id - AAT2870_ID_LDOA;
ri->enable_mask = 0x1 << ri->enable_shift;
ri->voltage_addr = (id - AAT2870_ID_LDOA) / 2 ?
AAT2870_LDO_CD : AAT2870_LDO_AB;
ri->voltage_shift = (id - AAT2870_ID_LDOA) % 2 ? 0 : 4;
ri->voltage_mask = 0xF << ri->voltage_shift;
return ri;
}
static int aat2870_regulator_probe(struct platform_device *pdev)
{
struct aat2870_regulator *ri;
struct regulator_dev *rdev;
ri = aat2870_get_regulator(pdev->id);
if (!ri) {
dev_err(&pdev->dev, "Invalid device ID, %d\n", pdev->id);
return -EINVAL;
}
ri->aat2870 = dev_get_drvdata(pdev->dev.parent);
rdev = regulator_register(&ri->desc, &pdev->dev,
pdev->dev.platform_data, ri, NULL);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "Failed to register regulator %s\n",
ri->desc.name);
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
return 0;
}
static int __devexit aat2870_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
regulator_unregister(rdev);
return 0;
}
static int __init aat2870_regulator_init(void)
{
return platform_driver_register(&aat2870_regulator_driver);
}
static void __exit aat2870_regulator_exit(void)
{
platform_driver_unregister(&aat2870_regulator_driver);
}
