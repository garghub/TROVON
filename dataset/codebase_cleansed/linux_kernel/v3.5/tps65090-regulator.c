static inline struct tps65090_regulator *find_regulator_info(int id)
{
struct tps65090_regulator *ri;
int i;
for (i = 0; i < ARRAY_SIZE(TPS65090_regulator); i++) {
ri = &TPS65090_regulator[i];
if (ri->desc.id == id)
return ri;
}
return NULL;
}
static int __devinit tps65090_regulator_probe(struct platform_device *pdev)
{
struct tps65090 *tps65090_mfd = dev_get_drvdata(pdev->dev.parent);
struct tps65090_regulator *ri = NULL;
struct regulator_config config = { };
struct regulator_dev *rdev;
struct tps65090_regulator_platform_data *tps_pdata;
int id = pdev->id;
dev_dbg(&pdev->dev, "Probing regulator %d\n", id);
ri = find_regulator_info(id);
if (ri == NULL) {
dev_err(&pdev->dev, "invalid regulator ID specified\n");
return -EINVAL;
}
tps_pdata = pdev->dev.platform_data;
ri->dev = &pdev->dev;
config.dev = &pdev->dev;
config.init_data = &tps_pdata->regulator;
config.driver_data = ri;
config.regmap = tps65090_mfd->rmap;
rdev = regulator_register(&ri->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
ri->desc.name);
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
return 0;
}
static int __devexit tps65090_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
regulator_unregister(rdev);
return 0;
}
static int __init tps65090_regulator_init(void)
{
return platform_driver_register(&tps65090_regulator_driver);
}
static void __exit tps65090_regulator_exit(void)
{
platform_driver_unregister(&tps65090_regulator_driver);
}
