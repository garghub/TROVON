void spear_restart(char mode, const char *cmd)
{
if (mode == 's') {
soft_restart(0);
} else {
#ifdef CONFIG_ARCH_SPEAR13XX
writel_relaxed(0x01, SPEAR13XX_SYS_SW_RES);
#else
sysctl_soft_reset((void __iomem *)VA_SPEAR_SYS_CTRL_BASE);
#endif
}
}
