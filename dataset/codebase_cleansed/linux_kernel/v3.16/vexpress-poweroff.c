static void vexpress_reset_do(struct device *dev, const char *what)
{
int err = -ENOENT;
struct regmap *reg = dev_get_drvdata(dev);
if (reg) {
err = regmap_write(reg, 0, 0);
if (!err)
mdelay(1000);
}
dev_emerg(dev, "Unable to %s (%d)\n", what, err);
}
static void vexpress_power_off(void)
{
vexpress_reset_do(vexpress_power_off_device, "power off");
}
static void vexpress_restart(enum reboot_mode reboot_mode, const char *cmd)
{
vexpress_reset_do(vexpress_restart_device, "restart");
}
static ssize_t vexpress_reset_active_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", vexpress_restart_device == dev);
}
static ssize_t vexpress_reset_active_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
long value;
int err = kstrtol(buf, 0, &value);
if (!err && value)
vexpress_restart_device = dev;
return err ? err : count;
}
static int vexpress_reset_probe(struct platform_device *pdev)
{
enum vexpress_reset_func func;
const struct of_device_id *match =
of_match_device(vexpress_reset_of_match, &pdev->dev);
struct regmap *regmap;
if (match)
func = (enum vexpress_reset_func)match->data;
else
func = pdev->id_entry->driver_data;
regmap = devm_regmap_init_vexpress_config(&pdev->dev);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
dev_set_drvdata(&pdev->dev, regmap);
switch (func) {
case FUNC_SHUTDOWN:
vexpress_power_off_device = &pdev->dev;
pm_power_off = vexpress_power_off;
break;
case FUNC_RESET:
if (!vexpress_restart_device)
vexpress_restart_device = &pdev->dev;
arm_pm_restart = vexpress_restart;
device_create_file(&pdev->dev, &dev_attr_active);
break;
case FUNC_REBOOT:
vexpress_restart_device = &pdev->dev;
arm_pm_restart = vexpress_restart;
device_create_file(&pdev->dev, &dev_attr_active);
break;
};
return 0;
}
static int __init vexpress_reset_init(void)
{
return platform_driver_register(&vexpress_reset_driver);
}
