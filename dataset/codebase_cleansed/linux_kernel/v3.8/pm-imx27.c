static int mx27_suspend_enter(suspend_state_t state)
{
u32 cscr;
switch (state) {
case PM_SUSPEND_MEM:
cscr = __raw_readl(MX27_IO_ADDRESS(MX27_CCM_BASE_ADDR));
cscr &= 0xFFFFFFFC;
__raw_writel(cscr, MX27_IO_ADDRESS(MX27_CCM_BASE_ADDR));
cpu_do_idle();
break;
default:
return -EINVAL;
}
return 0;
}
static int __init mx27_pm_init(void)
{
if (!cpu_is_mx27())
return 0;
suspend_set_ops(&mx27_suspend_ops);
return 0;
}
