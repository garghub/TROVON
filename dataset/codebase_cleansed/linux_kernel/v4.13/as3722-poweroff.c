static void as3722_pm_power_off(void)
{
int ret;
if (!as3722_pm_poweroff) {
pr_err("AS3722 poweroff is not initialised\n");
return;
}
ret = as3722_update_bits(as3722_pm_poweroff->as3722,
AS3722_RESET_CONTROL_REG, AS3722_POWER_OFF, AS3722_POWER_OFF);
if (ret < 0)
dev_err(as3722_pm_poweroff->dev,
"RESET_CONTROL_REG update failed, %d\n", ret);
}
static int as3722_poweroff_probe(struct platform_device *pdev)
{
struct as3722_poweroff *as3722_poweroff;
struct device_node *np = pdev->dev.parent->of_node;
if (!np)
return -EINVAL;
if (!of_property_read_bool(np, "ams,system-power-controller"))
return 0;
as3722_poweroff = devm_kzalloc(&pdev->dev, sizeof(*as3722_poweroff),
GFP_KERNEL);
if (!as3722_poweroff)
return -ENOMEM;
as3722_poweroff->as3722 = dev_get_drvdata(pdev->dev.parent);
as3722_poweroff->dev = &pdev->dev;
as3722_pm_poweroff = as3722_poweroff;
if (!pm_power_off)
pm_power_off = as3722_pm_power_off;
return 0;
}
static int as3722_poweroff_remove(struct platform_device *pdev)
{
if (pm_power_off == as3722_pm_power_off)
pm_power_off = NULL;
as3722_pm_poweroff = NULL;
return 0;
}
