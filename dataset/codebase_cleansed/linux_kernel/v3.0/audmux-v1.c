int mxc_audmux_v1_configure_port(unsigned int port, unsigned int pcr)
{
if (!audmux_base) {
printk("%s: not configured\n", __func__);
return -ENOSYS;
}
if (port >= ARRAY_SIZE(port_mapping))
return -EINVAL;
writel(pcr, audmux_base + port_mapping[port]);
return 0;
}
static int mxc_audmux_v1_init(void)
{
#ifdef CONFIG_MACH_MX21
if (cpu_is_mx21())
audmux_base = MX21_IO_ADDRESS(MX21_AUDMUX_BASE_ADDR);
else
#endif
#ifdef CONFIG_MACH_MX27
if (cpu_is_mx27())
audmux_base = MX27_IO_ADDRESS(MX27_AUDMUX_BASE_ADDR);
else
#endif
(void)0;
return 0;
}
