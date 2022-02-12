static void __init __iomem *win_cfg_base(int win)
{
return (void __iomem *)((win < 8) ? WIN0_OFF(win) : WIN8_OFF(win));
}
void __init mv78xx0_setup_cpu_mbus(void)
{
orion_config_wins(&addr_map_cfg, NULL);
if (mv78xx0_core_index() == 0)
orion_setup_cpu_mbus_target(&addr_map_cfg,
DDR_WINDOW_CPU0_BASE);
else
orion_setup_cpu_mbus_target(&addr_map_cfg,
DDR_WINDOW_CPU1_BASE);
}
void __init mv78xx0_setup_pcie_io_win(int window, u32 base, u32 size,
int maj, int min)
{
orion_setup_cpu_win(&addr_map_cfg, window, base, size,
TARGET_PCIE(maj), ATTR_PCIE_IO(min), -1);
}
void __init mv78xx0_setup_pcie_mem_win(int window, u32 base, u32 size,
int maj, int min)
{
orion_setup_cpu_win(&addr_map_cfg, window, base, size,
TARGET_PCIE(maj), ATTR_PCIE_MEM(min), -1);
}
