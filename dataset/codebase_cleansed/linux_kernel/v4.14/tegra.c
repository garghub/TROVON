static void __init tegra_init_early(void)
{
of_register_trusted_foundations();
tegra_cpu_reset_handler_init();
}
static void __init tegra_dt_init_irq(void)
{
tegra_init_irq();
irqchip_init();
}
static void __init tegra_dt_init(void)
{
struct device *parent = tegra_soc_device_register();
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
