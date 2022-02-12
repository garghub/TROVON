void __init mpc8536_ds_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static void __init mpc8536_ds_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("mpc8536_ds_setup_arch()", 0);
fsl_pci_assign_primary();
swiotlb_detect_4g();
printk("MPC8536 DS board from Freescale Semiconductor\n");
}
static int __init mpc8536_ds_probe(void)
{
return of_machine_is_compatible("fsl,mpc8536ds");
}
