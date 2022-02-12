int __init tegra114_cpuidle_init(void)
{
return cpuidle_register(&tegra_idle_driver, NULL);
}
