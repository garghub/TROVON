void __init tegra_cpuidle_init(void)
{
switch (tegra_chip_id) {
case TEGRA20:
if (IS_ENABLED(CONFIG_ARCH_TEGRA_2x_SOC))
tegra20_cpuidle_init();
break;
case TEGRA30:
if (IS_ENABLED(CONFIG_ARCH_TEGRA_3x_SOC))
tegra30_cpuidle_init();
break;
case TEGRA114:
if (IS_ENABLED(CONFIG_ARCH_TEGRA_114_SOC))
tegra114_cpuidle_init();
break;
}
}
