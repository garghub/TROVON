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
mpc512x_setup_diu();
}
static void __init mpc5121_ads_init_IRQ(void)
{
mpc512x_init_IRQ();
mpc5121_ads_cpld_pic_init();
}
static int __init mpc5121_ads_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,mpc5121ads");
}
