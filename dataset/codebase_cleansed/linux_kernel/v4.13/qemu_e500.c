void __init qemu_e500_pic_init(void)
{
struct mpic *mpic;
unsigned int flags = MPIC_BIG_ENDIAN | MPIC_SINGLE_DEST_CPU |
MPIC_ENABLE_COREINT;
mpic = mpic_alloc(NULL, 0, flags, 0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static void __init qemu_e500_setup_arch(void)
{
ppc_md.progress("qemu_e500_setup_arch()", 0);
fsl_pci_assign_primary();
swiotlb_detect_4g();
#if defined(CONFIG_FSL_PCI) && defined(CONFIG_ZONE_DMA32)
limit_zone_pfn(ZONE_DMA32, 1UL << (31 - PAGE_SHIFT));
#endif
mpc85xx_smp_init();
}
static int __init qemu_e500_probe(void)
{
return !!of_machine_is_compatible("fsl,qemu-e500");
}
