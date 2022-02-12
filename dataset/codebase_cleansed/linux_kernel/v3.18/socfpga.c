static void __init socfpga_scu_map_io(void)
{
unsigned long base;
asm("mrc p15, 4, %0, c15, c0, 0" : "=r" (base));
scu_io_desc.pfn = __phys_to_pfn(base);
iotable_init(&scu_io_desc, 1);
}
static void __init socfpga_map_io(void)
{
socfpga_scu_map_io();
iotable_init(&uart_io_desc, 1);
early_printk("Early printk initialized\n");
}
void __init socfpga_sysmgr_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "altr,sys-mgr");
if (of_property_read_u32(np, "cpu1-start-addr",
(u32 *) &socfpga_cpu1start_addr))
pr_err("SMP: Need cpu1-start-addr in device tree.\n");
sys_manager_base_addr = of_iomap(np, 0);
np = of_find_compatible_node(NULL, NULL, "altr,rst-mgr");
rst_manager_base_addr = of_iomap(np, 0);
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
