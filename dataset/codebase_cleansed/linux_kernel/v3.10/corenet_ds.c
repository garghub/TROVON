void __init corenet_ds_pic_init(void)
{
struct mpic *mpic;
unsigned int flags = MPIC_BIG_ENDIAN | MPIC_SINGLE_DEST_CPU |
MPIC_NO_RESET;
if (ppc_md.get_irq == mpic_get_coreint_irq)
flags |= MPIC_ENABLE_COREINT;
mpic = mpic_alloc(NULL, 0, flags, 0, 512, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
void __init corenet_ds_setup_arch(void)
{
mpc85xx_smp_init();
#if defined(CONFIG_PCI) && defined(CONFIG_PPC64)
pci_devs_phb_init();
#endif
fsl_pci_assign_primary();
swiotlb_detect_4g();
pr_info("%s board from Freescale Semiconductor\n", ppc_md.name);
}
int __init corenet_ds_publish_devices(void)
{
return of_platform_bus_probe(NULL, of_device_ids, NULL);
}
