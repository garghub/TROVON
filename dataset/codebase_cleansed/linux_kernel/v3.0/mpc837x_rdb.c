static void mpc837x_rdb_sd_cfg(void)
{
void __iomem *im;
im = ioremap(get_immrbase(), 0x1000);
if (!im) {
WARN_ON(1);
return;
}
clrsetbits_be32(im + MPC83XX_SICRL_OFFS, MPC837X_SICRL_USBB_MASK,
MPC837X_SICRL_SD);
clrsetbits_be32(im + MPC83XX_SICRH_OFFS, MPC837X_SICRH_SPI_MASK,
MPC837X_SICRH_SD);
iounmap(im);
}
static void __init mpc837x_rdb_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("mpc837x_rdb_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8349-pci")
mpc83xx_add_bridge(np);
for_each_compatible_node(np, "pci", "fsl,mpc8314-pcie")
mpc83xx_add_bridge(np);
#endif
mpc837x_usb_cfg();
mpc837x_rdb_sd_cfg();
}
static int __init mpc837x_declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, mpc837x_ids, NULL);
return 0;
}
static void __init mpc837x_rdb_init_IRQ(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "fsl,ipic");
if (!np)
return;
ipic_init(np, 0);
ipic_set_default_priority();
}
static int __init mpc837x_rdb_probe(void)
{
return of_flat_dt_match(of_get_flat_dt_root(), board);
}
