static inline void ux500_cache_wait(void __iomem *reg, unsigned long mask)
{
while (readl_relaxed(reg) & mask)
cpu_relax();
}
static inline void ux500_cache_sync(void)
{
writel_relaxed(0, l2x0_base + L2X0_CACHE_SYNC);
ux500_cache_wait(l2x0_base + L2X0_CACHE_SYNC, 1);
}
static void ux500_l2x0_disable(void)
{
}
static void ux500_l2x0_inv_all(void)
{
uint32_t l2x0_way_mask = (1<<16) - 1;
writel_relaxed(l2x0_way_mask, l2x0_base + L2X0_INV_WAY);
ux500_cache_wait(l2x0_base + L2X0_INV_WAY, l2x0_way_mask);
ux500_cache_sync();
}
static int __init ux500_l2x0_unlock(void)
{
int i;
for (i = 0; i < 8; i++) {
writel_relaxed(0x0, l2x0_base + L2X0_LOCKDOWN_WAY_D_BASE +
i * L2X0_LOCKDOWN_STRIDE);
writel_relaxed(0x0, l2x0_base + L2X0_LOCKDOWN_WAY_I_BASE +
i * L2X0_LOCKDOWN_STRIDE);
}
return 0;
}
static int __init ux500_l2x0_init(void)
{
if (cpu_is_u5500())
l2x0_base = __io_address(U5500_L2CC_BASE);
else if (cpu_is_u8500())
l2x0_base = __io_address(U8500_L2CC_BASE);
else
ux500_unknown_soc();
ux500_l2x0_unlock();
l2x0_init(l2x0_base, 0x3e060000, 0xc0000fff);
outer_cache.disable = ux500_l2x0_disable;
outer_cache.inv_all = ux500_l2x0_inv_all;
return 0;
}
