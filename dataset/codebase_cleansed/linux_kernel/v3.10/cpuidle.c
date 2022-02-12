static int __init tegra_cpuidle_init(void)
{
int ret;
switch (tegra_chip_id) {
case TEGRA20:
ret = tegra20_cpuidle_init();
break;
case TEGRA30:
ret = tegra30_cpuidle_init();
break;
case TEGRA114:
ret = tegra114_cpuidle_init();
break;
default:
ret = -ENODEV;
break;
}
return ret;
}
