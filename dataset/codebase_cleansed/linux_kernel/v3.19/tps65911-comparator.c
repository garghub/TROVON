static int comp_threshold_set(struct tps65910 *tps65910, int id, int voltage)
{
struct comparator tps_comp = tps_comparators[id];
int curr_voltage = 0;
int ret;
u8 index = 0, val;
if (id == COMP)
return 0;
while (curr_voltage < tps_comp.uV_max) {
curr_voltage = tps_comp.vsel_table[index];
if (curr_voltage >= voltage)
break;
else if (curr_voltage < voltage)
index ++;
}
if (curr_voltage > tps_comp.uV_max)
return -EINVAL;
val = index << 1;
ret = tps65910->write(tps65910, tps_comp.reg, 1, &val);
return ret;
}
static int comp_threshold_get(struct tps65910 *tps65910, int id)
{
struct comparator tps_comp = tps_comparators[id];
int ret;
u8 val;
if (id == COMP)
return 0;
ret = tps65910->read(tps65910, tps_comp.reg, 1, &val);
if (ret < 0)
return ret;
val >>= 1;
return tps_comp.vsel_table[val];
}
static ssize_t comp_threshold_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tps65910 *tps65910 = dev_get_drvdata(dev->parent);
struct attribute comp_attr = attr->attr;
int id, uVolt;
if (!strcmp(comp_attr.name, "comp1_threshold"))
id = COMP1;
else if (!strcmp(comp_attr.name, "comp2_threshold"))
id = COMP2;
else
return -EINVAL;
uVolt = comp_threshold_get(tps65910, id);
return sprintf(buf, "%d\n", uVolt);
}
static int tps65911_comparator_probe(struct platform_device *pdev)
{
struct tps65910 *tps65910 = dev_get_drvdata(pdev->dev.parent);
struct tps65910_board *pdata = dev_get_platdata(tps65910->dev);
int ret;
ret = comp_threshold_set(tps65910, COMP1, pdata->vmbch_threshold);
if (ret < 0) {
dev_err(&pdev->dev, "cannot set COMP1 threshold\n");
return ret;
}
ret = comp_threshold_set(tps65910, COMP2, pdata->vmbch2_threshold);
if (ret < 0) {
dev_err(&pdev->dev, "cannot set COMP2 threshold\n");
return ret;
}
ret = device_create_file(&pdev->dev, &dev_attr_comp1_threshold);
if (ret < 0)
dev_err(&pdev->dev, "failed to add COMP1 sysfs file\n");
ret = device_create_file(&pdev->dev, &dev_attr_comp2_threshold);
if (ret < 0)
dev_err(&pdev->dev, "failed to add COMP2 sysfs file\n");
return ret;
}
static int tps65911_comparator_remove(struct platform_device *pdev)
{
struct tps65910 *tps65910;
tps65910 = dev_get_drvdata(pdev->dev.parent);
device_remove_file(&pdev->dev, &dev_attr_comp2_threshold);
device_remove_file(&pdev->dev, &dev_attr_comp1_threshold);
return 0;
}
static int __init tps65911_comparator_init(void)
{
return platform_driver_register(&tps65911_comparator_driver);
}
static void __exit tps65911_comparator_exit(void)
{
platform_driver_unregister(&tps65911_comparator_driver);
}
