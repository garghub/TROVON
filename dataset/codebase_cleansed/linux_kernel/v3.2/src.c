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
writel_relaxed(BSYM(virt_to_phys(jump_addr)),
src_base + SRC_GPR1 + cpu * 8);
}
void __init imx_src_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-src");
src_base = of_iomap(np, 0);
WARN_ON(!src_base);
}
