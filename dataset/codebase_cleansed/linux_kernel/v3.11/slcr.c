void zynq_slcr_system_reset(void)
{
u32 reboot;
writel(SLCR_UNLOCK_MAGIC, zynq_slcr_base + SLCR_UNLOCK);
reboot = readl(zynq_slcr_base + SLCR_REBOOT_STATUS);
writel(reboot & 0xF0FFFFFF, zynq_slcr_base + SLCR_REBOOT_STATUS);
writel(1, zynq_slcr_base + SLCR_PS_RST_CTRL_OFFSET);
}
void zynq_slcr_cpu_start(int cpu)
{
writel(SLCR_A9_CPU_CLKSTOP << cpu,
zynq_slcr_base + SLCR_A9_CPU_RST_CTRL);
writel(0x0 << cpu, zynq_slcr_base + SLCR_A9_CPU_RST_CTRL);
}
void zynq_slcr_cpu_stop(int cpu)
{
writel((SLCR_A9_CPU_CLKSTOP | SLCR_A9_CPU_RST) << cpu,
zynq_slcr_base + SLCR_A9_CPU_RST_CTRL);
}
int __init zynq_slcr_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "xlnx,zynq-slcr");
if (!np) {
pr_err("%s: no slcr node found\n", __func__);
BUG();
}
zynq_slcr_base = of_iomap(np, 0);
if (!zynq_slcr_base) {
pr_err("%s: Unable to map I/O memory\n", __func__);
BUG();
}
writel(SLCR_UNLOCK_MAGIC, zynq_slcr_base + SLCR_UNLOCK);
pr_info("%s mapped to %p\n", np->name, zynq_slcr_base);
zynq_clock_init(zynq_slcr_base);
of_node_put(np);
return 0;
}
