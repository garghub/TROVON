void imx_enable_cpu(int cpu, bool enable)
{
u32 mask, val;
cpu = cpu_logical_map(cpu);
mask = 1 << (BP_SRC_SCR_CORE1_ENABLE + cpu - 1);
val = readl_relaxed(src_base + SRC_SCR);
val = enable ? val | mask : val & ~mask;
writel_relaxed(val, src_base + SRC_SCR);
}
void imx_set_cpu_jump(int cpu, void *jump_addr)
{
cpu = cpu_logical_map(cpu);
writel_relaxed(virt_to_phys(jump_addr),
src_base + SRC_GPR1 + cpu * 8);
}
void imx_src_prepare_restart(void)
{
u32 val;
val = readl_relaxed(src_base + SRC_SCR);
val &= ~(0x7 << BP_SRC_SCR_CORE1_ENABLE);
writel_relaxed(val, src_base + SRC_SCR);
writel_relaxed(0, src_base + SRC_GPR1);
}
void __init imx_src_init(void)
{
struct device_node *np;
u32 val;
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-src");
src_base = of_iomap(np, 0);
WARN_ON(!src_base);
val = readl_relaxed(src_base + SRC_SCR);
val &= ~(1 << BP_SRC_SCR_WARM_RESET_ENABLE);
writel_relaxed(val, src_base + SRC_SCR);
}
