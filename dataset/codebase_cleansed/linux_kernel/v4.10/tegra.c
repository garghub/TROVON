static void __init tegra_init_early(void)
{
of_register_trusted_foundations();
tegra_cpu_reset_handler_init();
tegra_flowctrl_init();
}
static void __init tegra_dt_init_irq(void)
{
tegra_init_irq();
irqchip_init();
}
static void __init tegra_dt_init(void)
{
struct soc_device_attribute *soc_dev_attr;
struct soc_device *soc_dev;
struct device *parent = NULL;
soc_dev_attr = kzalloc(sizeof(*soc_dev_attr), GFP_KERNEL);
if (!soc_dev_attr)
goto out;
soc_dev_attr->family = kasprintf(GFP_KERNEL, "Tegra");
soc_dev_attr->revision = kasprintf(GFP_KERNEL, "%d",
tegra_sku_info.revision);
soc_dev_attr->soc_id = kasprintf(GFP_KERNEL, "%u", tegra_get_chip_id());
soc_dev = soc_device_register(soc_dev_attr);
if (IS_ERR(soc_dev)) {
kfree(soc_dev_attr->family);
kfree(soc_dev_attr->revision);
kfree(soc_dev_attr->soc_id);
kfree(soc_dev_attr);
goto out;
}
parent = soc_device_to_device(soc_dev);
out:
of_platform_default_populate(NULL, NULL, parent);
}
static void __init tegra_dt_init_late(void)
{
tegra_init_suspend();
tegra_cpuidle_init();
if (IS_ENABLED(CONFIG_ARCH_TEGRA_2x_SOC) &&
of_machine_is_compatible("compal,paz00"))
tegra_paz00_wifikill_init();
}
