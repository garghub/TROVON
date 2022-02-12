static void flowctrl_update(u8 offset, u32 value)
{
if (WARN_ONCE(IS_ERR_OR_NULL(tegra_flowctrl_base),
"Tegra flowctrl not initialised!\n"))
return;
writel(value, tegra_flowctrl_base + offset);
wmb();
readl_relaxed(tegra_flowctrl_base + offset);
}
u32 flowctrl_read_cpu_csr(unsigned int cpuid)
{
u8 offset = flowctrl_offset_cpu_csr[cpuid];
if (WARN_ONCE(IS_ERR_OR_NULL(tegra_flowctrl_base),
"Tegra flowctrl not initialised!\n"))
return 0;
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
static int tegra_flowctrl_probe(struct platform_device *pdev)
{
void __iomem *base = tegra_flowctrl_base;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
tegra_flowctrl_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(tegra_flowctrl_base))
return PTR_ERR(base);
iounmap(base);
return 0;
}
static int __init tegra_flowctrl_init(void)
{
struct resource res;
struct device_node *np;
if (!soc_is_tegra())
return 0;
np = of_find_matching_node(NULL, tegra_flowctrl_match);
if (np) {
if (of_address_to_resource(np, 0, &res) < 0) {
pr_err("failed to get flowctrl register\n");
return -ENXIO;
}
of_node_put(np);
} else if (IS_ENABLED(CONFIG_ARM)) {
res.start = 0x60007000;
res.end = 0x60007fff;
res.flags = IORESOURCE_MEM;
} else {
return 0;
}
tegra_flowctrl_base = ioremap_nocache(res.start, resource_size(&res));
if (!tegra_flowctrl_base)
return -ENXIO;
return 0;
}
