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
u32 aux_val = 0x3e000000;
if (cpu_is_u8500_family() || cpu_is_ux540_family())
l2x0_base = __io_address(U8500_L2CC_BASE);
else
ux500_unknown_soc();
ux500_l2x0_unlock();
if (cpu_is_ux540_family())
aux_val |= (0x4 << L2X0_AUX_CTRL_WAY_SIZE_SHIFT);
else
aux_val |= (0x3 << L2X0_AUX_CTRL_WAY_SIZE_SHIFT);
if (of_have_populated_dt())
l2x0_of_init(aux_val, 0xc0000fff);
else
l2x0_init(l2x0_base, aux_val, 0xc0000fff);
outer_cache.disable = NULL;
return 0;
}
