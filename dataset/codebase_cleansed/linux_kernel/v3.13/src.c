static int imx_src_reset_module(struct reset_controller_dev *rcdev,
unsigned long sw_reset_idx)
{
unsigned long timeout;
unsigned long flags;
int bit;
u32 val;
if (!src_base)
return -ENODEV;
if (sw_reset_idx >= ARRAY_SIZE(sw_reset_bits))
return -EINVAL;
bit = 1 << sw_reset_bits[sw_reset_idx];
spin_lock_irqsave(&scr_lock, flags);
val = readl_relaxed(src_base + SRC_SCR);
val |= bit;
writel_relaxed(val, src_base + SRC_SCR);
spin_unlock_irqrestore(&scr_lock, flags);
timeout = jiffies + msecs_to_jiffies(1000);
while (readl(src_base + SRC_SCR) & bit) {
if (time_after(jiffies, timeout))
return -ETIME;
cpu_relax();
}
return 0;
}
void imx_enable_cpu(int cpu, bool enable)
{
u32 mask, val;
cpu = cpu_logical_map(cpu);
mask = 1 << (BP_SRC_SCR_CORE1_ENABLE + cpu - 1);
spin_lock(&scr_lock);
val = readl_relaxed(src_base + SRC_SCR);
val = enable ? val | mask : val & ~mask;
val |= 1 << (BP_SRC_SCR_CORE1_RST + cpu - 1);
writel_relaxed(val, src_base + SRC_SCR);
spin_unlock(&scr_lock);
}
void imx_set_cpu_jump(int cpu, void *jump_addr)
{
cpu = cpu_logical_map(cpu);
writel_relaxed(virt_to_phys(jump_addr),
src_base + SRC_GPR1 + cpu * 8);
}
u32 imx_get_cpu_arg(int cpu)
{
cpu = cpu_logical_map(cpu);
return readl_relaxed(src_base + SRC_GPR1 + cpu * 8 + 4);
}
void imx_set_cpu_arg(int cpu, u32 arg)
{
cpu = cpu_logical_map(cpu);
writel_relaxed(arg, src_base + SRC_GPR1 + cpu * 8 + 4);
}
void __init imx_src_init(void)
{
struct device_node *np;
u32 val;
np = of_find_compatible_node(NULL, NULL, "fsl,imx51-src");
if (!np)
return;
src_base = of_iomap(np, 0);
WARN_ON(!src_base);
imx_reset_controller.of_node = np;
if (IS_ENABLED(CONFIG_RESET_CONTROLLER))
reset_controller_register(&imx_reset_controller);
spin_lock(&scr_lock);
val = readl_relaxed(src_base + SRC_SCR);
val &= ~(1 << BP_SRC_SCR_WARM_RESET_ENABLE);
writel_relaxed(val, src_base + SRC_SCR);
spin_unlock(&scr_lock);
}
