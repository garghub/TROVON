void tegra20_lp1_iram_hook(void)
{
tegra_lp1_iram.start_addr = &tegra20_iram_start;
tegra_lp1_iram.end_addr = &tegra20_iram_end;
}
void tegra20_sleep_core_init(void)
{
tegra_sleep_core_finish = tegra20_sleep_core_finish;
}
