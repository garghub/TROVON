void spear_restart(enum reboot_mode mode, const char *cmd)
{
if (mode == REBOOT_SOFT) {
soft_restart(0);
} else {
#ifdef CONFIG_ARCH_SPEAR13XX
writel_relaxed(0x01, SPEAR13XX_SYS_SW_RES);
#endif
#if defined(CONFIG_ARCH_SPEAR3XX) || defined(CONFIG_ARCH_SPEAR6XX)
sysctl_soft_reset((void __iomem *)VA_SPEAR_SYS_CTRL_BASE);
#endif
}
}
