static void lsxl_power_off(void)
{
kirkwood_restart('h', NULL);
}
void __init lsxl_init(void)
{
kirkwood_ge00_init(&lsxl_ge00_data);
kirkwood_ge01_init(&lsxl_ge01_data);
pm_power_off = lsxl_power_off;
}
