static void flowctrl_update(u8 offset, u32 value)
{
void __iomem *addr = IO_ADDRESS(TEGRA_FLOW_CTRL_BASE) + offset;
writel(value, addr);
wmb();
readl_relaxed(addr);
}
void flowctrl_write_cpu_csr(unsigned int cpuid, u32 value)
{
return flowctrl_update(flowctrl_offset_cpu_csr[cpuid], value);
}
void flowctrl_write_cpu_halt(unsigned int cpuid, u32 value)
{
return flowctrl_update(flowctrl_offset_halt_cpu[cpuid], value);
}
