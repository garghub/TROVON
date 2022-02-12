void __init p1010_rdb_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static void __init p1010_rdb_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("p1010_rdb_setup_arch()", 0);
fsl_pci_assign_primary();
printk(KERN_INFO "P1010 RDB board from Freescale Semiconductor\n");
}
static int __init p1010_rdb_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,P1010RDB"))
return 1;
return 0;
}
