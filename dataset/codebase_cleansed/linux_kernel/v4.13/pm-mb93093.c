static void mb93093_power_switch_setup(void)
{
imask = *(volatile unsigned long *)0xfeff9820;
*(volatile unsigned long *)0xfeff9820 = ~(1 << (IRQ_XIRQ2_LEVEL + 16)) & 0xfffe0000;
}
static void mb93093_power_switch_cleanup(void)
{
*(volatile unsigned long *)0xfeff9820 = imask;
}
static int mb93093_power_switch_check(void)
{
return 1;
}
static int __init mb93093_pm_init(void)
{
__power_switch_wake_setup = mb93093_power_switch_setup;
__power_switch_wake_check = mb93093_power_switch_check;
__power_switch_wake_cleanup = mb93093_power_switch_cleanup;
return 0;
}
