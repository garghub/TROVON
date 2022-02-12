static int mx27_suspend_enter(suspend_state_t state)
{
u32 cscr;
switch (state) {
case PM_SUSPEND_MEM:
cscr = imx_readl(MX27_IO_ADDRESS(MX27_CCM_BASE_ADDR));
cscr &= 0xFFFFFFFC;
imx_writel(cscr, MX27_IO_ADDRESS(MX27_CCM_BASE_ADDR));
cpu_do_idle();
break;
default:
return -EINVAL;
}
return 0;
}
void __init imx27_pm_init(void)
{
suspend_set_ops(&mx27_suspend_ops);
}
