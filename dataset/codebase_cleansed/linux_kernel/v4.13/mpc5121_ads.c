static void __init mpc5121_ads_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
printk(KERN_INFO "MPC5121 ADS board from Freescale Semiconductor\n");
mpc5121_ads_cpld_map();
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc5121-pci")
mpc83xx_add_bridge(np);
#endif
mpc512x_setup_arch();
}
static void __init mpc5121_ads_init_IRQ(void)
{
mpc512x_init_IRQ();
mpc5121_ads_cpld_pic_init();
}
static int __init mpc5121_ads_probe(void)
{
if (!of_machine_is_compatible("fsl,mpc5121ads"))
return 0;
mpc512x_init_early();
return 1;
}
