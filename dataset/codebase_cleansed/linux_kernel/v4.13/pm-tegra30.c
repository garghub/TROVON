void tegra30_lp1_iram_hook(void)
{
tegra_lp1_iram.start_addr = &tegra30_iram_start;
tegra_lp1_iram.end_addr = &tegra30_iram_end;
}
void tegra30_sleep_core_init(void)
{
tegra_sleep_core_finish = tegra30_sleep_core_finish;
}
