void __init bsc913x_qds_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
if (!mpic)
pr_err("bsc913x: Failed to allocate MPIC structure\n");
else
mpic_init(mpic);
}
static void __init bsc913x_qds_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("bsc913x_qds_setup_arch()", 0);
#if defined(CONFIG_SMP)
mpc85xx_smp_init();
#endif
fsl_pci_assign_primary();
pr_info("bsc913x board from Freescale Semiconductor\n");
}
static int __init bsc9132_qds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,bsc9132qds");
}
