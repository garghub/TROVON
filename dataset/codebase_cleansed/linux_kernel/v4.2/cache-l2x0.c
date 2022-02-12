static int __init ux500_l2x0_unlock(void)
{
int i;
struct device_node *np;
void __iomem *l2x0_base;
np = of_find_compatible_node(NULL, NULL, "arm,pl310-cache");
l2x0_base = of_iomap(np, 0);
of_node_put(np);
if (!l2x0_base)
return -ENODEV;
for (i = 0; i < 8; i++) {
writel_relaxed(0x0, l2x0_base + L2X0_LOCKDOWN_WAY_D_BASE +
i * L2X0_LOCKDOWN_STRIDE);
writel_relaxed(0x0, l2x0_base + L2X0_LOCKDOWN_WAY_I_BASE +
i * L2X0_LOCKDOWN_STRIDE);
}
iounmap(l2x0_base);
return 0;
}
static void ux500_l2c310_write_sec(unsigned long val, unsigned reg)
{
}
static int __init ux500_l2x0_init(void)
{
if (!((cpu_is_u8500_family() || cpu_is_ux540_family())))
return -ENODEV;
ux500_l2x0_unlock();
outer_cache.write_sec = ux500_l2c310_write_sec;
l2x0_of_init(0, ~0);
return 0;
}
