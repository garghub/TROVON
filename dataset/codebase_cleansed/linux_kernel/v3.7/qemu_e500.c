void __init qemu_e500_pic_init(void)
{
struct mpic *mpic;
mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN | MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static void __init qemu_e500_setup_arch(void)
{
ppc_md.progress("qemu_e500_setup_arch()", 0);
fsl_pci_assign_primary();
swiotlb_detect_4g();
mpc85xx_smp_init();
}
static int __init qemu_e500_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return !!of_flat_dt_is_compatible(root, "fsl,qemu-e500");
}
