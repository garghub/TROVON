void __init mvme2500_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0,
MPIC_BIG_ENDIAN | MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static void __init mvme2500_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("mvme2500_setup_arch()", 0);
fsl_pci_assign_primary();
pr_info("MVME2500 board from Artesyn\n");
}
static int __init mvme2500_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "artesyn,MVME2500");
}
