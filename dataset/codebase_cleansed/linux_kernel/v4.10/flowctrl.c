static void flowctrl_update(u8 offset, u32 value)
{
writel(value, tegra_flowctrl_base + offset);
wmb();
readl_relaxed(tegra_flowctrl_base + offset);
}
u32 flowctrl_read_cpu_csr(unsigned int cpuid)
{
u8 offset = flowctrl_offset_cpu_csr[cpuid];
return readl(tegra_flowctrl_base + offset);
}
void flowctrl_write_cpu_csr(unsigned int cpuid, u32 value)
{
return flowctrl_update(flowctrl_offset_cpu_csr[cpuid], value);
}
void flowctrl_write_cpu_halt(unsigned int cpuid, u32 value)
{
return flowctrl_update(flowctrl_offset_halt_cpu[cpuid], value);
}
void flowctrl_cpu_suspend_enter(unsigned int cpuid)
{
unsigned int reg;
int i;
reg = flowctrl_read_cpu_csr(cpuid);
switch (tegra_get_chip_id()) {
case TEGRA20:
reg &= ~TEGRA20_FLOW_CTRL_CSR_WFE_BITMAP;
reg &= ~TEGRA20_FLOW_CTRL_CSR_WFI_BITMAP;
reg |= TEGRA20_FLOW_CTRL_CSR_WFE_CPU0 << cpuid;
break;
case TEGRA30:
case TEGRA114:
case TEGRA124:
reg &= ~TEGRA30_FLOW_CTRL_CSR_WFE_BITMAP;
reg &= ~TEGRA30_FLOW_CTRL_CSR_WFI_BITMAP;
reg |= TEGRA30_FLOW_CTRL_CSR_WFI_CPU0 << cpuid;
break;
}
reg |= FLOW_CTRL_CSR_INTR_FLAG;
reg |= FLOW_CTRL_CSR_EVENT_FLAG;
reg |= FLOW_CTRL_CSR_ENABLE;
flowctrl_write_cpu_csr(cpuid, reg);
for (i = 0; i < num_possible_cpus(); i++) {
if (i == cpuid)
continue;
reg = flowctrl_read_cpu_csr(i);
reg |= FLOW_CTRL_CSR_EVENT_FLAG;
reg |= FLOW_CTRL_CSR_INTR_FLAG;
flowctrl_write_cpu_csr(i, reg);
}
}
void flowctrl_cpu_suspend_exit(unsigned int cpuid)
{
unsigned int reg;
reg = flowctrl_read_cpu_csr(cpuid);
switch (tegra_get_chip_id()) {
case TEGRA20:
reg &= ~TEGRA20_FLOW_CTRL_CSR_WFE_BITMAP;
reg &= ~TEGRA20_FLOW_CTRL_CSR_WFI_BITMAP;
break;
case TEGRA30:
case TEGRA114:
case TEGRA124:
reg &= ~TEGRA30_FLOW_CTRL_CSR_WFE_BITMAP;
reg &= ~TEGRA30_FLOW_CTRL_CSR_WFI_BITMAP;
break;
}
reg &= ~FLOW_CTRL_CSR_ENABLE;
reg |= FLOW_CTRL_CSR_INTR_FLAG;
reg |= FLOW_CTRL_CSR_EVENT_FLAG;
flowctrl_write_cpu_csr(cpuid, reg);
}
void __init tegra_flowctrl_init(void)
{
unsigned long base = 0x60007000;
unsigned long size = SZ_4K;
struct device_node *np;
np = of_find_matching_node(NULL, matches);
if (np) {
struct resource res;
if (of_address_to_resource(np, 0, &res) == 0) {
size = resource_size(&res);
base = res.start;
}
of_node_put(np);
}
tegra_flowctrl_base = ioremap_nocache(base, size);
}
