void __init socfpga_sysmgr_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "altr,sys-mgr");
if (of_property_read_u32(np, "cpu1-start-addr",
(u32 *) &socfpga_cpu1start_addr))
pr_err("SMP: Need cpu1-start-addr in device tree.\n");
smp_wmb();
sync_cache_w(&socfpga_cpu1start_addr);
sys_manager_base_addr = of_iomap(np, 0);
np = of_find_compatible_node(NULL, NULL, "altr,rst-mgr");
rst_manager_base_addr = of_iomap(np, 0);
np = of_find_compatible_node(NULL, NULL, "altr,sdr-ctl");
sdr_ctl_base_addr = of_iomap(np, 0);
}
static void __init socfpga_init_irq(void)
{
irqchip_init();
socfpga_sysmgr_init();
}
static void socfpga_cyclone5_restart(enum reboot_mode mode, const char *cmd)
{
u32 temp;
temp = readl(rst_manager_base_addr + SOCFPGA_RSTMGR_CTRL);
if (mode == REBOOT_HARD)
temp |= RSTMGR_CTRL_SWCOLDRSTREQ;
else
temp |= RSTMGR_CTRL_SWWARMRSTREQ;
writel(temp, rst_manager_base_addr + SOCFPGA_RSTMGR_CTRL);
}
static void socfpga_arria10_restart(enum reboot_mode mode, const char *cmd)
{
u32 temp;
temp = readl(rst_manager_base_addr + SOCFPGA_A10_RSTMGR_CTRL);
if (mode == REBOOT_HARD)
temp |= RSTMGR_CTRL_SWCOLDRSTREQ;
else
temp |= RSTMGR_CTRL_SWWARMRSTREQ;
writel(temp, rst_manager_base_addr + SOCFPGA_A10_RSTMGR_CTRL);
}
