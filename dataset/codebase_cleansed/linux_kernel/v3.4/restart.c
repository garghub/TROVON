void spear_restart(char mode, const char *cmd)
{
if (mode == 's') {
soft_restart(0);
} else {
sysctl_soft_reset((void __iomem *)VA_SPEAR_SYS_CTRL_BASE);
}
}
