static void __init
lite5200_fix_clock_config(void)
{
struct device_node *np;
struct mpc52xx_cdm __iomem *cdm;
np = of_find_matching_node(NULL, mpc5200_cdm_ids);
cdm = of_iomap(np, 0);
of_node_put(np);
if (!cdm) {
printk(KERN_ERR "%s() failed; expect abnormal behaviour\n",
__func__);
return;
}
out_8(&cdm->ext_48mhz_en, 0x00);
out_8(&cdm->fd_enable, 0x01);
if (in_be32(&cdm->rstcfg) & 0x40)
out_be16(&cdm->fd_counters, 0x0001);
else
out_be16(&cdm->fd_counters, 0x5555);
iounmap(cdm);
}
static void __init
lite5200_fix_port_config(void)
{
struct device_node *np;
struct mpc52xx_gpio __iomem *gpio;
u32 port_config;
np = of_find_matching_node(NULL, mpc5200_gpio_ids);
gpio = of_iomap(np, 0);
of_node_put(np);
if (!gpio) {
printk(KERN_ERR "%s() failed. expect abnormal behavior\n",
__func__);
return;
}
port_config = in_be32(&gpio->port_config);
port_config &= ~0x00800000;
port_config &= ~0x00007000;
port_config |= 0x00001000;
port_config &= ~0x03000000;
port_config |= 0x01000000;
pr_debug("port_config: old:%x new:%x\n",
in_be32(&gpio->port_config), port_config);
out_be32(&gpio->port_config, port_config);
iounmap(gpio);
}
static void lite5200_suspend_prepare(void __iomem *mbar)
{
u8 pin = 1;
u8 level = 0;
mpc52xx_set_wakeup_gpio(pin, level);
out_be32(mbar + 0x1048, in_be32(mbar + 0x1048) & ~0x300);
out_be32(mbar + 0x1050, 0x00000001);
}
static void lite5200_resume_finish(void __iomem *mbar)
{
out_be32(mbar + 0x1050, 0x00010000);
}
static void __init lite5200_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("lite5200_setup_arch()", 0);
mpc52xx_map_common_devices();
mpc5200_setup_xlb_arbiter();
lite5200_fix_clock_config();
lite5200_fix_port_config();
#ifdef CONFIG_PM
mpc52xx_suspend.board_suspend_prepare = lite5200_suspend_prepare;
mpc52xx_suspend.board_resume_finish = lite5200_resume_finish;
lite5200_pm_init();
#endif
mpc52xx_setup_pci();
}
static int __init lite5200_probe(void)
{
return of_device_compatible_match(of_root, board);
}
